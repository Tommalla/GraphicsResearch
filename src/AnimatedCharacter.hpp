/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class representing a character that can move on the map and has some animation.
 */
#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP
#include <vector>

#include "GraphicalObject.hpp"

class AnimatedCharacter: public GraphicalObject {
public:
	AnimatedCharacter(const std::vector<std::vector<sf::Texture>>& frames);
	virtual void update(const float& deltaTime) override;
	void setVelocity(const sf::Vector2f& v);

private:
	/**
	 * @brief Updates the texture of the object depending on it's current
	 * velocity vector and time elapsed.
	 */
	void updateTexture();

	std::vector<std::vector<sf::Texture>> frames;
	int frame;
	float frameDelay;
	float currentDelay;
	sf::Vector2f velocity;
};

#endif