#include <Atelier/OpenGL/Debug.hpp>
#include <Atelier/Core/Log.hpp>
#include <glad/glad.h>

namespace Atelier::OpenGL
{
    namespace
    {
        const Core::Logger s_logger("OpenGL");

        const char *sourceName(GLenum source)
        {
            switch (source)
            {
            case GL_DEBUG_SOURCE_API:
                return "API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                return "Window system";
            case GL_DEBUG_SOURCE_SHADER_COMPILER:
                return "Shader compiler";
            case GL_DEBUG_SOURCE_THIRD_PARTY:
                return "Third party";
            case GL_DEBUG_SOURCE_APPLICATION:
                return "Application";
            default:
                return "Other";
            }
        }

        const char *typeName(GLenum type)
        {
            switch (type)
            {
            case GL_DEBUG_TYPE_ERROR:
                return "Error";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                return "Deprecated";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                return "Undefined behavior";
            case GL_DEBUG_TYPE_PORTABILITY:
                return "Portability";
            case GL_DEBUG_TYPE_PERFORMANCE:
                return "Performance";
            case GL_DEBUG_TYPE_MARKER:
                return "Marker";
            default:
                return "Other";
            }
        }

        void APIENTRY debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                    GLsizei /*length*/, const GLchar *message, const void * /*userParam*/)
        {
            switch (severity)
            {
            case GL_DEBUG_SEVERITY_HIGH:
                s_logger.error("[", sourceName(source), "/", typeName(type), " #", id, "] ", message);
                break;
            case GL_DEBUG_SEVERITY_MEDIUM:
            case GL_DEBUG_SEVERITY_LOW:
                s_logger.warning("[", sourceName(source), "/", typeName(type), " #", id, "] ", message);
                break;
            default:
                s_logger.debug("[", sourceName(source), "/", typeName(type), " #", id, "] ", message);
                break;
            }
        }
    }

    void enableDebugOutput()
    {
        if (!GLAD_GL_KHR_debug)
        {
            s_logger.warning("KHR_debug is not supported, OpenGL debug output disabled");
            return;
        }

        GLint flags = 0;
        glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (!(flags & GL_CONTEXT_FLAG_DEBUG_BIT))
        {
            s_logger.warning("Not a debug context, some OpenGL messages may be missing");
        }

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(debugCallback, nullptr);

        // Drop the purely informative messages (very noisy on NVIDIA drivers).
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);

        s_logger.info("OpenGL debug output enabled");
    }
}