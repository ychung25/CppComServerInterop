#include "Precompiled.h"
#include "..\..\idl\Spotify.h"

using namespace Microsoft::WRL;

static long s_serverLock;

static void printMsg(std::string str)
{
	printf(str.c_str());
	OutputDebugStringA(str.c_str());
}

class Spotify : public ISpotify
{
private:
	ULONG m_count = 0;

public:
	Spotify()
	{
		printMsg("> Spotify COM server created\n\n");
		_InterlockedIncrement(&s_serverLock);
	}
	~Spotify()
	{
		_InterlockedDecrement(&s_serverLock);
	}

	HRESULT STDMETHODCALLTYPE Play(void)
	{
		printMsg("> Spotify COM server playing C.R.E.A.M by Wu-tang!\n\n");
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
	{
		if (riid == __uuidof(ISpotify) || riid == __uuidof(IUnknown))
		{
			*ppvObject = static_cast<ISpotify*>(this);
		}
		else
		{
			*ppvObject = 0;
			return E_NOINTERFACE;
		}

		static_cast<IUnknown*>(*ppvObject)->AddRef();

		return S_OK;
	}

	ULONG STDMETHODCALLTYPE AddRef(void)
	{
		return _InterlockedIncrement(&m_count);
	}

	ULONG STDMETHODCALLTYPE Release(void)
	{
		ULONG const result = _InterlockedDecrement(&m_count);
		if (result == 0)
		{
			delete this;
		}

		return result;
	}
};

class SpotifyClassFactory : public IClassFactory
{
public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
	{
		if (riid == __uuidof(IClassFactory) || riid == __uuidof(IUnknown))
		{
			*ppvObject = static_cast<IClassFactory*>(this);
		}
		else
		{
			*ppvObject = 0;
			return E_NOINTERFACE;
		}

		return S_OK;
	}

	ULONG STDMETHODCALLTYPE AddRef(void) { return 2; }

	ULONG STDMETHODCALLTYPE Release(void) { return 1; }

	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* outer, IID const& iid, void** result)
	{
		*result = nullptr;
		if (outer) { return CLASS_E_NOAGGREGATION; }

		auto spotify = new (std::nothrow) Spotify();
		if (!spotify) { return E_OUTOFMEMORY; }

		spotify->AddRef();
		auto hr = spotify->QueryInterface(iid, result);
		spotify->Release();

		return hr;
	}

	HRESULT STDMETHODCALLTYPE LockServer(BOOL lock)
	{
		if (lock)
		{
			_InterlockedIncrement(&s_serverLock);
		}
		else
		{
			_InterlockedDecrement(&s_serverLock);
		}
		return S_OK;
	}
};

HRESULT STDMETHODCALLTYPE DllGetClassObject(CLSID const& clsid, IID const& iid, void** result)
{
	*result = nullptr;
	if (__uuidof(Spotify) == clsid)
	{
		static SpotifyClassFactory spotifyClassFactory;
		return spotifyClassFactory.QueryInterface(iid, result);
	}

	return CLASS_E_CLASSNOTAVAILABLE;
}

HRESULT STDMETHODCALLTYPE DllCanUnloadNow()
{
	return s_serverLock ? S_FALSE : S_OK;
}



