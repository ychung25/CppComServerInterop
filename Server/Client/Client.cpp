#include "Precompiled.h"
#include "../../idl/Spotify.h"

using namespace Microsoft::WRL;

static DWORD g_gitCookie = 0;

static void printMsg(std::string str)
{
	printf(str.c_str());
	printf("");
	OutputDebugStringA(str.c_str());
}


struct ComException
{
	HRESULT result;
	explicit ComException(HRESULT const value) : result(value) {}
};

inline void HR(HRESULT const result)
{
	if (S_OK != result) { throw ComException(result); }
}

struct ComRuntime
{
	ComRuntime()
	{
		HR(CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));
	}
	~ComRuntime()
	{
		CoUninitialize();
	}
};


int main()
{
	/******************************************************
	Instantiates Spotify COM server and and play some music
	*******************************************************/

	ComRuntime runtime; // We are setting main thread to be an apartment thread (COINIT_APARTMENTTHREADED)

	ComPtr<IUnknown> unknown;
	HR(CoCreateInstance(__uuidof(Spotify), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IUnknown), (void**)unknown.GetAddressOf()));

	ComPtr<ISpotify> spotify;
	if (unknown.As(&spotify) == S_OK)
	{
		printMsg("C++ COM client playing spotify from an APARTMENT thread\n\n");
		spotify->Play();
	}

	

	ComPtr<IGlobalInterfaceTable> gpGIT;
	HR(CoCreateInstance(CLSID_StdGlobalInterfaceTable,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IGlobalInterfaceTable,
		(void**)gpGIT.GetAddressOf()));

	HR(gpGIT->RegisterInterfaceInGlobal(unknown.Get(), __uuidof(ISpotify), &g_gitCookie));

	std::thread t1([] {
		// We are setting main thread NOT to be an apartment thread, but instead a regular thread
		HR(CoInitializeEx(nullptr, COINIT_MULTITHREADED));

		ComPtr<IGlobalInterfaceTable> gpGIT;
		HR(CoCreateInstance(CLSID_StdGlobalInterfaceTable,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_IGlobalInterfaceTable,
			(void**)gpGIT.GetAddressOf()));

		ComPtr<ISpotify> spotify;
		HR(gpGIT->GetInterfaceFromGlobal(g_gitCookie, __uuidof(ISpotify), (void**)spotify.GetAddressOf()));

		// This will only work if spotify COM server was 'marshalled' from one thread context to another
		// This is where tlib comes into play. Tlib does the magic of marshalling.
		printMsg("C++ COM client playing spotify from an MULTI thread\n\n");
		HR(spotify->Play());

		CoUninitialize();
	});

	MSG message;
	while (BOOL result = GetMessage(&message, 0, 0, 0))
	{
		if (-1 != result)
		{
			printMsg("DispatchMessage...");
			DispatchMessage(&message);
		}
	}
}