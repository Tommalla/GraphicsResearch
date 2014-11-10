#include <vector>

#include "GraphicalObject.hpp"

#include "common.hpp"

using std::vector;

GraphicalObject::GraphicalObject() {
	entities.push_back(&sprite);
}

std::vector< const sf::Drawable* > GraphicalObject::getDrawable() const {
	return vector<const sf::Drawable*>{&sprite};
}

void GraphicalObject::setLogicalPosition(const sf::Vector2f& pos) {
	position = pos;
	float realx, realy;
	realx = pos.x * BASE_WIDTH;
	realy = pos.y * BASE_HEIGHT;
	for (auto& entity: entities) {
		entity->setPosition(sf::Vector2f(realx, realy));
	}
}

void GraphicalObject::setTexture(const sf::Texture& texture) {
	sprite.setTexture(texture);
	float scale = BASE_WIDTH / texture.getSize().x;
	sprite.setScale(scale, scale);
}

void GraphicalObject::update(const float& deltaTime) {}