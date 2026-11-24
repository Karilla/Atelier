#include <Atelier/Input/InputManager.hpp>

namespace Atelier::Input
{
    InputManager::InputManager()
    {
    }

    InputManager::~InputManager()
    {
    }

    bool InputManager::hasBeenPressed(std::string &action)
    {
        int key = m_actions[action];
        return m_current[key] && !m_previous[key];
    }

    void InputManager::setAction(std::string &action, int key)
    {
        m_actions[action] = key;
        m_current[m_actions[action]] = false;
    }

    void InputManager::update()
    {
        m_previous = m_current;
        m_previousMouse = m_currentMouse;

        m_mouseMovement = {0.0f, 0.0f};
        m_scroll = 0.0f;
    }

    void InputManager::onKey(int key, bool pressed)
    {
        m_current[key] = pressed;
    }

    void InputManager::onMouseMovement(double xOffset, double yOffset)
    {
        glm::vec2 newPosition = {static_cast<float>(xOffset), static_cast<float>(yOffset)};

        if (firstPosition)
        {
            m_mousePosition = newPosition;
            firstPosition = false;
            return;
        }

        m_mouseMovement += newPosition - m_mousePosition;
        m_mousePosition = newPosition;
    }

    void InputManager::onScroll(double xOffset, double yOffset)
    {
        m_scroll += static_cast<float>(yOffset);
    }

    void InputManager::onMouseButton(int key, bool pressed)
    {
        m_currentMouse[key] = pressed;
    }

    bool InputManager::isDown(std::string &action)
    {
        return m_current[m_actions[action]];
    }

    bool InputManager::isUp(std::string &action)
    {
        return !m_current[m_actions[action]];
    }

    glm::vec2 InputManager::getMousePosition()
    {
        return m_mousePosition;
    }

    glm::vec2 InputManager::getMouseMovement()
    {
        return m_mouseMovement;
    }

    float InputManager::getMouseScroll()
    {
        return m_scroll;
    }

    bool InputManager::isMouseButtonDown(int key)
    {
        return m_currentMouse[key];
    }

    bool InputManager::isMouseButtonPressed(int key)
    {
        return m_currentMouse[key] && !m_previousMouse[key];
    }
}