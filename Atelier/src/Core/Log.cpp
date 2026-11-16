#include <Atelier/Core/Log.hpp>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

namespace Atelier::Core
{

    const char *Logger::nameLevel(LogLevel level) const
    {
        switch (level)
        {
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Warning:
            return "WARNING";
        case LogLevel::Error:
            return "ERROR";
        }
        return "";
    }

    const char *Logger::color(LogLevel level) const
    {
        switch (level)
        {
        case LogLevel::Debug:
            return "\033[90m";
        case LogLevel::Info:
            return "\033[32m";
        case LogLevel::Warning:
            return "\033[33m";
        case LogLevel::Error:
            return "\033[31m";
        }
        return "";
    }

    void Logger::print(LogLevel level, const std::string &message) const
    {
        std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm tm{};

        localtime_r(&t, &tm);

        std::ostream &out = (level == LogLevel::Error) ? std::cerr : std::cout;

        out << color(level)
            << "[" << std::put_time(&tm, "%H:%M:%S") << "] "
            << "[" << std::left << std::setw(5) << nameLevel(level) << "] "
            << "[" << m_moduleName << "] "
            << message
            << "\033[0m\n";
    }

    void Logger::setMinLevel(LogLevel level)
    {
        s_levelMin = level;
    }
}