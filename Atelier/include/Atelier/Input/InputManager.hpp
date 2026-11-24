#include <unordered_map>
#include <string>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

namespace Atelier::Input
{
    class InputManager
    {
    private:
        std::unordered_map<std::string, int> m_actions;
        std::unordered_map<int, bool> m_current;
        std::unordered_map<int, bool> m_previous;

        std::unordered_map<int, bool> m_currentMouse;
        std::unordered_map<int, bool> m_previousMouse;

        glm::vec2 m_mousePosition = {0.0f, 0.0f};
        glm::vec2 m_mouseMovement = {0.0f, 0.0f};

        float m_scroll = 0.0f;

        bool firstPosition = true;

    public:
        InputManager();
        ~InputManager();

        InputManager(const InputManager &) = delete;
        InputManager &operator=(const InputManager &) = delete;

        void onKey(int key, bool pressed);

        void onMouseMovement(double xOffset, double yOffset);

        void onScroll(double xOffset, double yOffset);

        void onMouseButton(int key, bool pressed);

        void update();

        void setAction(std::string &name, int key);

        bool isDown(std::string &action);

        bool isUp(std::string &action);

        bool hasBeenPressed(std::string &action);

        glm::vec2 getMousePosition();

        glm::vec2 getMouseMovement();

        float getMouseScroll();

        bool isMouseButtonDown(int key);

        bool isMouseButtonPressed(int key);
    };
}