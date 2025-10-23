#include "SFML/Graphics.hpp"  
#include <SFML/Config.hpp>
#include <mutex>
#include "../elementary_data/Color.hpp"

class Window {
    public:
        Window();
        Window(const unsigned int width, const unsigned int height);
        ~Window() = default;
        void resize(const unsigned int width, const unsigned int height);
        void render();
        void pushAt(const unsigned int x, const unsigned int y, const Color &color);

    private:
        unsigned int _width;
        unsigned int _height;
        sf::RenderWindow _window;
        sf::VertexArray _pixels;
        std::mutex _mutex;
};
