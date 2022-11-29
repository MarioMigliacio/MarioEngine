#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MarioEngine {

    class MARIOENGINE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define MARIOENGINE_CORE_TRACE(...)         ::MarioEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MARIOENGINE_CORE_INFO(...)          ::MarioEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MARIOENGINE_CORE_WARN(...)          ::MarioEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MARIOENGINE_CORE_ERROR(...)         ::MarioEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MARIOENGINE_CORE_CRITICAL(...)      ::MarioEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MARIOENGINE_CLIENT_TRACE(...)       ::MarioEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MARIOENGINE_CLIENT_INFO(...)        ::MarioEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define MARIOENGINE_CLIENT_WARN(...)        ::MarioEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MARIOENGINE_CLIENT_ERROR(...)       ::MarioEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define MARIOENGINE_CLIENT_CRITICAL(...)    ::MarioEngine::Log::GetClientLogger()->critical(__VA_ARGS__)