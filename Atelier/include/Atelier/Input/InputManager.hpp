#include <unordered_map>
#include <string>

namespace Atelier::Input
{
    class InputManager
    {
    private:
        std::unordered_map<std::string, int> m_actions;
        std::unordered_map<int, bool> m_current;
        std::unordered_map<int, bool> m_previous;

    public:
        InputManager();
        ~InputManager();

        InputManager(const InputManager &) = delete;
        InputManager &operator=(const InputManager &) = delete;

        void onKey(int key, bool pressed);

        void onMouseMovement(double xOffset, double yOffset);

        void onScroll(double xOffset, double yOffset);

        void update();

        void setAction(std::string &name, int key);

        bool isDown(std::string &action);

        bool isUp(std::string &action);

        bool hasBeenPressed(std::string &action);
    };
}