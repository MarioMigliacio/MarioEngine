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

#ifdef MARIOENGINE_ENABLE_ASSERTS
    #define MARIOENGINE_CLIENT_ASSERT(x, ...) { if(!(x)) { MARIOENGINE_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define MARIOENGINE_CORE_ASSERT(x, ...) { if(!(x)) { MARIOENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define MARIOENGINE_CLIENT_ASSERT(x, ...)
    #define MARIOENGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)