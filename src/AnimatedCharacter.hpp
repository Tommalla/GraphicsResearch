/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class representing a character that can move on the map and has some animation.
 */
#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP
#include <vector>

#include "GraphicalObject.hpp"

class AnimatedCharacter: public GraphicalObject {
public:
	AnimatedCharacter();
	virtual void update(const float& deltaTime) override;
	void setVelocity(const sf::Vector2f& v);

private:
	std::vector<std::vector<sf::Texture>> frames;
	int direction;
	int frame;
	const float frameDelay = 0.5;
	float currentDelay;
	sf::Vector2f velocity;
};

#endif