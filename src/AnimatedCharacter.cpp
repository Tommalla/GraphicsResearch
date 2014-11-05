/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class implementation.
 */
#include "AnimatedCharacter.hpp"
#include "common.hpp"

AnimatedCharacter::AnimatedCharacter(const std::vector< std::vector< sf::Texture > >& frames)
: frames{frames}, frame{0}, currentDelay{frameDelay}, velocity{0, 0} {
	updateTexture();
	setVelocity({0, 1});
}

void AnimatedCharacter::update(const float& deltaTime) {
	GraphicalObject::update(deltaTime);
	currentDelay += deltaTime;
	updateTexture();
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
	int direction;
	direction = 0;

	// update frame number if necessary
	if (currentDelay >= frameDelay) {
		printf("%f\n", frameDelay);
		currentDelay -= frameDelay;
		if (velocity.x > EPS || velocity.y > EPS) {
			frame++;
			frame %= frames[direction].size();
			setTexture(frames[direction][frame]);
		}
	}
}


