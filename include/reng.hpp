#ifndef RENDER_HPP
#define RENDER_HPP

#include <element/Box.hpp>
#include <functional>

namespace reng
{
    void reng(Box box, std::function<void (sf::Window& window)> callback = nullptr);
};

#endif // RENDER_HPP
