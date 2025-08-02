//
// Created by caleb on 8/2/25.
//

#include "blew/log.h"

#include <filesystem>

namespace blew {

    std::shared_ptr<spdlog::logger> Logger::s_Logger;

    void Logger::Init()
    {
        std::filesystem::create_directories("logs");
        s_Logger = spdlog::basic_logger_mt("blew_logger", "logs/app.log");

        s_Logger->set_level(spdlog::level::trace);
        s_Logger->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");

        spdlog::set_default_logger(s_Logger);
    }

    std::shared_ptr<spdlog::logger>& Logger::Get()
    {
        return s_Logger;
    }

}