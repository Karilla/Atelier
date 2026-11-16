#pragma once

#include <string>
#include <utility>
#include <sstream>

namespace Atelier::Core
{

    enum class LogLevel
    {
        Debug,
        Info,
        Warning,
        Error
    };

    class Logger
    {
    private:
        std::string m_moduleName;

        static inline LogLevel s_levelMin = LogLevel::Debug;

        template <typename... Args>
        void write(LogLevel level, Args &&...args) const
        {
            if (level < s_levelMin)
            {
                return;
            }

            std::ostringstream oss;
            (oss << ... << std::forward<Args>(args));
            print(level, oss.str());
        }

        void print(LogLevel level, const std::string &message) const;

        const char *nameLevel(LogLevel level) const;

        const char *color(LogLevel level) const;

    public:
        explicit Logger(std::string module_name) : m_moduleName(std::move(module_name))
        {
        }

        template <typename... Args>
        void debug(Args &&...args) const { write(LogLevel::Debug, std::forward<Args>(args)...); }
        template <typename... Args>
        void info(Args &&...args) const { write(LogLevel::Info, std::forward<Args>(args)...); }
        template <typename... Args>
        void warning(Args &&...args) const { write(LogLevel::Warning, std::forward<Args>(args)...); }
        template <typename... Args>
        void error(Args &&...args) const { write(LogLevel::Error, std::forward<Args>(args)...); }

        static void setMinLevel(LogLevel level);
    };

}