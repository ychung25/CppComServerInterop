

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for Spotify.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Spotify_h__
#define __Spotify_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISpotify_FWD_DEFINED__
#define __ISpotify_FWD_DEFINED__
typedef interface ISpotify ISpotify;

#endif 	/* __ISpotify_FWD_DEFINED__ */


#ifndef __ISpotify_FWD_DEFINED__
#define __ISpotify_FWD_DEFINED__
typedef interface ISpotify ISpotify;

#endif 	/* __ISpotify_FWD_DEFINED__ */


#ifndef __Spotify_FWD_DEFINED__
#define __Spotify_FWD_DEFINED__

#ifdef __cplusplus
typedef class Spotify Spotify;
#else
typedef struct Spotify Spotify;
#endif /* __cplusplus */

#endif 	/* __Spotify_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISpotify_INTERFACE_DEFINED__
#define __ISpotify_INTERFACE_DEFINED__

/* interface ISpotify */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_ISpotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7b2b16c6-edde-4c8e-87c4-614960b71b10")
    ISpotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpotify * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *Play )( 
            ISpotify * This);
        
        END_INTERFACE
    } ISpotifyVtbl;

    interface ISpotify
    {
        CONST_VTBL struct ISpotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpotify_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpotify_INTERFACE_DEFINED__ */



#ifndef __SpotifyInterface_LIBRARY_DEFINED__
#define __SpotifyInterface_LIBRARY_DEFINED__

/* library SpotifyInterface */
/* [uuid] */ 



EXTERN_C const IID LIBID_SpotifyInterface;

EXTERN_C const CLSID CLSID_Spotify;

#ifdef __cplusplus

class DECLSPEC_UUID("1d3d393d-4700-4414-aeb5-7eb1a73c4de6")
Spotify;
#endif
#endif /* __SpotifyInterface_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


