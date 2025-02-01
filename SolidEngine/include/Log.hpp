#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // For class that returns std::string

namespace SolidEngine {

    class Log 
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
#define SOLID_CORE_TRACE(...) SolidEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SOLID_CORE_INFO(...)  SolidEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SOLID_CORE_WARN(...)  SolidEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SOLID_CORE_ERROR(...) SolidEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SOLID_CORE_FATAL(...) SolidEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SOLID_TRACE(...) SolidEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SOLID_INFO(...)  SolidEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SOLID_WARN(...)  SolidEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SOLID_ERROR(...) SolidEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SOLID_FATAL(...) SolidEngine::Log::GetClientLogger()->critical(__VA_ARGS__)