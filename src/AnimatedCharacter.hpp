/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class representing a character that can move on the map and has some animation.
 */
#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP
#include <memory>
#include <random>
#include <vector>

#include "GraphicalObject.hpp"

class AnimatedCharacter: public GraphicalObject {
public:
	AnimatedCharacter(const std::shared_ptr< std::vector< std::vector< sf::Texture > > >& frames);
	virtual std::vector< const sf::Drawable* > getDrawable() const;
	void setTurnDelay(const float& turnDelay);
	virtual void update(const float& deltaTime) override;
	void setVelocity(const sf::Vector2f& v);

private:
	/**
	 * @brief Updates the texture of the object depending on it's current
	 * velocity vector and time elapsed.
	 */
	void updateTexture();

	std::shared_ptr<std::vector<std::vector<sf::Texture>>> frames;
	int frame;
	float frameDelay;
	float currentFrameDelay;
	float turnDelay;
	float currentTurnDelay;
	float moveDelay;
	float currentMoveDelay;
	float sines[8];
	float cosines[8];
	sf::Vector2f velocity;
	std::mt19937 gen;
	std::uniform_real_distribution<float> dis;
	sf::CircleShape circle;
};
#endif