#include "SFML/Graphics.hpp"  
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include "Window.hpp"

Window::Window() : _width(0), _height(0) {}

Window::Window(const unsigned int width, const unsigned int height) :
    _width(width), _height(height) {}

void Window::resize(const unsigned int width, const unsigned int height)
{
    this->_width = width;
    this->_height = height;
    _window.create(sf::VideoMode(_width, _height), "Raytracer");
    _window.setFramerateLimit(60);
    _pixels = sf::VertexArray(sf::Points, _width * _height);
}

void Window::render()
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        {
            std::lock_guard<std::mutex> lock(_mutex);
            _window.draw(_pixels);
        }
        _window.display();
    }
}

void Window::pushAt(const unsigned int x, const unsigned int y, const Color &color)
{
    std::lock_guard<std::mutex> lock(_mutex);
    size_t index = y * _width + x;
    if (index < _pixels.getVertexCount()) {
        _pixels[index].position = sf::Vector2f(x, y);
        _pixels[index].color = sf::Color(color.get(Color::R), color.get(Color::G), color.get(Color::B));
    }
}

