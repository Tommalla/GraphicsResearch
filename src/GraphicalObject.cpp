#include "GraphicalObject.hpp"

#include "common.hpp"

const sf::Drawable& GraphicalObject::getDrawable() const {
	return sprite;
}

void GraphicalObject::setLogicalPosition(const sf::Vector2f& pos) {
	position = pos;
	float realx, realy;
	realx = pos.x * BASE_WIDTH;
	realy = pos.y * BASE_HEIGHT;
	sprite.setPosition(sf::Vector2f(realx, realy));
}

void GraphicalObject::setTexture(const sf::Texture& texture) {
	sprite.setTexture(texture);
}

void GraphicalObject::update(const float& deltaTime) {}