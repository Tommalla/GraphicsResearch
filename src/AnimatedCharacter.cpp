/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class implementation.
 */
#include "AnimatedCharacter.hpp"

AnimatedCharacter::AnimatedCharacter()
: direction{0}, frame{0}, currentDelay{0.0f}, velocity{1, 0} {}

void AnimatedCharacter::update(const float& deltaTime) {
    GraphicalObject::update(deltaTime);
    currentDelay += deltaTime;
    if (currentDelay >= frameDelay) {
	    currentDelay -= frameDelay;
	    frame++;
    }
    sprite.move(velocity);
}

void AnimatedCharacter::setVelocity(const sf::Vector2f& v) {
	velocity = v;
}

