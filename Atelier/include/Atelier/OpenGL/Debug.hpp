#pragma once

namespace Atelier::OpenGL
{
    // Routes OpenGL debug messages (KHR_debug) to the logger.
    // Must be called after glad has been loaded.
    void enableDebugOutput();
}
