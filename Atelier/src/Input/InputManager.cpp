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
    }

    void InputManager::onKey(int key, bool pressed)
    {
        m_current[key] = pressed;
    }

    bool InputManager::isDown(std::string &action)
    {
        return m_current[m_actions[action]];
    }

    bool InputManager::isUp(std::string &action)
    {
        return !m_current[m_actions[action]];
    }
}