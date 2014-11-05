/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class implementation.
 */
#include "AnimatedCharacter.hpp"
#include "common.hpp"

using std::random_device;
using std::uniform_real_distribution;

AnimatedCharacter::AnimatedCharacter(const std::vector< std::vector< sf::Texture > >& frames)
: frames{frames}, frame{0}, currentFrameDelay{frameDelay}, currentTurnDelay{0}, velocity{0, 0}, gen{random_device{}()}, dis{-3.0f, 3.0f} {
	updateTexture();
	setVelocity({dis(gen), dis(gen)});
	setTurnDelay(fabs(dis(gen)));
	uniform_real_distribution<float> distX(3, WIDTH / BASE_WIDTH - 3);
	uniform_real_distribution<float> distY(3, HEIGHT / BASE_HEIGHT - 3);
	setLogicalPosition({distX(gen), distY(gen)});
}

void AnimatedCharacter::setTurnDelay(const float& turnDelay) {
	this->turnDelay = turnDelay;
	currentTurnDelay = 0;
}

void AnimatedCharacter::update(const float& deltaTime) {
	GraphicalObject::update(deltaTime);
	currentFrameDelay += deltaTime;
	updateTexture();
	currentTurnDelay += deltaTime;
	// if it's time to turn, turn in random direction with random velocity
	if (currentTurnDelay >= turnDelay) {
		currentTurnDelay -= turnDelay;
		setVelocity({dis(gen), dis(gen)});
		setTurnDelay(fabs(dis(gen)));
	}

	// check the bounds of the screen
	float xbegin = sprite.getPosition().x;
	float xend = xbegin + sprite.getGlobalBounds().width;
	float ybegin = sprite.getPosition().y;
	float yend = ybegin + sprite.getGlobalBounds().height;
	if (xend >= WIDTH || xbegin <= 0 || yend >= HEIGHT || ybegin <= 0) {
		setVelocity(-velocity);	//turn back if you can't walk anymore
	}
	sprite.move(velocity);
}

void AnimatedCharacter::setVelocity(const sf::Vector2f& v) {
	velocity = v;
	frameDelay = 0.1f / length(v);
}

void AnimatedCharacter::updateTexture() {
	// calculate current direction
	// due to the poor naming of the knight model, the directions are as written below:
	// 4 3 2
	// 5 x 1
	// 6 7 0
	// Bear in mind that SFML's coordinates are inverted, so e.g.: vector (1, 1) corresponds to direction 0.
	int direction;
	if (velocity.y >= 0.0f) {

	}
	direction = 0;

	// update frame number if necessary
	if (currentFrameDelay >= frameDelay) {
		currentFrameDelay -= frameDelay;
		if (fabs(velocity.x) > EPS || fabs(velocity.y) > EPS) {
			frame++;
			frame %= frames[direction].size();
			setTexture(frames[direction][frame]);
		}
	}
}


