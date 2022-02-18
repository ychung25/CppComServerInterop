This is an example of authoring COM C++ server and consuming from C++ client and C# client using typelib marshalling and registration free activation.

Note:
For both client and server project
Manifest Tool -> Input and Output -> Additional Manifest File = Manifest.xml and Embed Manifest = No. And Build Events -> Post-Build Event -> Command Line = "mt -manifest Manifest.xml -outputresource:"$(TargetPath)";2 -nologo"


[Generating header and tlib from idl]
From idl, generate header and tlib
1) Spotify.idl defines IDL and coclass for typelib
2) Midl Spotify.idl to generate Spotify.h and Spotify.tlb

[Implementing registry free C++ COM server with tlb marshalling]
1) Implement COM server using Spotify.h (empty win32 dll project using exports.def)
2) Implement coclass 
3) Create Manifest.xml to define exposed comClass and exposed interface marshalled by tlib

[Implementing C++ COM client consuming registry free com sever]
1) Create Manifest.xml to define consumption of registry free com server
2) Pass com pointer between apartments to verify that marshalling is working via tlib

[To run the C++ example]
Make sure
Client.exe
Server.dll
Client.exe.manifest
Server.dll.manifest
Spotify.tlb
are in the same folder



[Implementing C# COM client]
1) Generated RCW assembly from Spotify.tlb. 'tlbimp Spotify.tlb' will generate SpotifyInterfaces.dll
2) CS client references SpotifyInterfaces.dll
3) Create app.manifest and define registry comserver comsuption <dependentAssembly> just like you did for c++ client.
4) Consume Spotify just like any other C# class.

[To run the C# example]
Make sure
CSClient.exe
Server.dll
Spotify.tlb
SpotifyInterface.dll 
Server.dll.manifest 
are in the same folder

