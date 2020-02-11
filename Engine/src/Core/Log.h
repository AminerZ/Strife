#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Engine {
	class HOS_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

// Core Log macros
#define HOS_CORE_TRACE(...)  ::Engine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HOS_CORE_INFO(...)   ::Engine::Log::getCoreLogger()->info(__VA_ARGS__)
#define HOS_CORE_WARN(...)   ::Engine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HOS_CORE_ERROR(...)  ::Engine::Log::getCoreLogger()->error(__VA_ARGS__)
#define HOS_CORE_FATAL(...)  ::Engine::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define HOS_TRACE(...)       ::Engine::Log::getClientLogger()->trace(__VA_ARGS__)
#define HOS_INFO(...)        ::Engine::Log::getClientLogger()->info(__VA_ARGS__)
#define HOS_WARN(...)        ::Engine::Log::getClientLogger()->warn(__VA_ARGS__)
#define HOS_ERROR(...)       ::Engine::Log::getClientLogger()->error(__VA_ARGS__)
#define HOS_FATAL(...)       ::Engine::Log::getClientLogger()->fatal(__VA_ARGS__)