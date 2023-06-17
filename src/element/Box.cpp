#include "element/Box.hpp"
#include "element/config/Flags.hpp"

using namespace reng;

// Constructor
Box::Box(Attributes attributes)
    : Element(attributes)
{
    // Create the box shape
    boxShape.setSize(sf::Vector2f(this->getWidth(), this->getHeight()));
    boxShape.setPosition(this->getPosnX(), this->getPosnY());

    // Set the background color
    boxShape.setFillColor(sf::Color(0xF7, 0xF7, 0xF7)); // Default: white-ish

    // Set the border color and thickness
    boxShape.setOutlineColor(sf::Color(0xDE, 0xDE, 0xDE)); // Default: darker white
    boxShape.setOutlineThickness(1.f);

    // Set the border radius (rounded corners): this doesn't exist in SFML 2.4.2
    // sf::Vector2f cornerRadii(cornerRadius, cornerRadius);
    // boxShape.setCornerRadii(cornerRadii);
}

// Render the box and its elements
void Box::render(sf::RenderWindow& window)
{
    reng::Flags::reRender = false;

    if (this->isHidden()) return;

    boxShape.setSize(sf::Vector2f(this->getWidth(), this->getHeight()));
    boxShape.setPosition(this->getPosnX(), this->getPosnY());

    // Render the box
    window.draw(boxShape);

    // Render the elements
    for (auto element : elements)
        element->render(window);
}

void Box::addElement(Element* element)
{
    elements.push_back(element);
}

// overriden

void Box::setPosnX(int x) {
    for (auto element : elements) {
        int x_this = this->getPosnX();
        int x_element = element->getPosnX();
        // Set children posnx accordingly
        element->setPosnX(x + (x_this - x_element));
    }
    Element::setPosnX(x);
}

void Box::setPosnY(int y) {
    for (auto element : elements) {
        int y_this = this->getPosnY();
        int y_element = element->getPosnY();
        // Set children posny accordingly
        element->setPosnX(y + (y_this - y_element));
    }
    Element::setPosnY(y);
}

void Box::moveTo(int x, int y) {
    for (auto element : elements) {
        int x_this = this->getPosnX();
        int x_element = element->getPosnX();
        int y_this = this->getPosnY();
        int y_element = element->getPosnY();
        // Set children posn accordingly
        element->moveTo(x + (x_this - x_element), y + (y_this - y_element));
    }
    Element::moveTo(x, y);
}

void Box::moveBy(int dx, int dy) {
    for (auto element : elements)
        element->moveBy(dx, dy);
    Element::moveBy(dx, dy);
}

void Box::setWidth(int width) {
    for (auto element : elements) {
        int w_this = this->getWidth();
        int w_element = element->getWidth();
        // Set children width accordingly
        element->setWidth(width + (w_this - w_element));
    }
    Element::setWidth(width);
}

void Box::setHeight(int height) {
    for (auto element : elements) {
        int h_this = this->getHeight();
        int h_element = element->getHeight();
        // Set children height accordingly
        element->setHeight(height + (h_this - h_element));
    }
    Element::setHeight(height);
}

/** Sets the width and height to new values */
void Box::resize(int width, int height) {
    for (auto element : elements) {
        int w_this = this->getWidth();
        int w_element = element->getWidth();
        int h_this = this->getHeight();
        int h_element = element->getHeight();
        // Set children dimension accordingly
        element->resize(width + (w_this - w_element), height + (h_this - h_element));
    }
    Element::resize(width, height);
}

/** Increments the width and height by given values */
void Box::scale(int dWidth, int dHeight) {
    for (auto element : elements)
        element->scale(dWidth, dHeight);
    Element::scale(dWidth, dHeight);
}

/** Scales the image by a multiplier */
void Box::scale(double multiplier) {
    for (auto element : elements)
        element->scale(multiplier);
    Element::scale(multiplier);
}
