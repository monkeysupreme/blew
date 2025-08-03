#pragma once

#include <iostream>
#include <memory.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace blew {

    class Logger {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& Get();

    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
    };

}

#define BLEW_TRACE(x) blew::Logger::Get()->trace(x)