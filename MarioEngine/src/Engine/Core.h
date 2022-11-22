#pragma once

#ifdef MARIOENGINE_PLATFORM_WINDOWS
    #ifdef MARIOENGINE_BUILD_DLL
        #define MARIOENGINE_API __declspec(dllexport)
    #else
        #define MARIOENGINE_API __declspec(dllimport)
    #endif
#else
    #error MARIOENGINE only supports windows for now!
#endif