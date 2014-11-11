/* Tomasz [Tommalla] Zakrzewski, 2014
 * AnimatedCharacter class implementation.
 */
#include <vector>

#include "AnimatedCharacter.hpp"
#include "common.hpp"

using std::random_device;
using std::shared_ptr;
using std::uniform_real_distribution;
using std::vector;

AnimatedCharacter::AnimatedCharacter(const shared_ptr<std::vector< std::vector< sf::Texture > >>& frames)
: GraphicalObject{}, frames{frames}, frame{0}, currentFrameDelay{0.0f}, currentTurnDelay{0}, moveDelay{0.02}
, currentMoveDelay{0.0f}, velocity{0, 0}, gen{random_device{}()}, dis{-3.0f, 3.0f}, circle{10} {
	entities.push_back(&circle);
	updateTexture();
	setVelocity({dis(gen), dis(gen)});
	setTurnDelay(fabs(dis(gen)));
	uniform_real_distribution<float> distX(3, WIDTH / BASE_WIDTH - 3);
	uniform_real_distribution<float> distY(3, HEIGHT / BASE_HEIGHT - 3);
	setLogicalPosition({distX(gen), distY(gen)});
	auto circlePos = circle.getPosition();
	circle.setPosition(circlePos.x + 21.0f, circlePos.y + 46.0f);

	const float radPart = 2 * PI / 8.0f;	// the part of the circle per one direction
	float currentAngleRad = 0.0f;
	for (int i = 0; i < 8; ++i, currentAngleRad += radPart) {
		sines[i] = sin(2 * PI - currentAngleRad);
		cosines[i] = cos(2 * PI - currentAngleRad);
	}

	circle.setFillColor(sf::Color::Green);
}

std::vector< const sf::Drawable* > AnimatedCharacter::getDrawable() const {
	return {&circle, &sprite};
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

	currentMoveDelay += deltaTime;
	if (currentMoveDelay >= moveDelay) {
		currentMoveDelay -= moveDelay;
		sprite.move(velocity);
		circle.move(velocity);
	}
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
	int direction = 0;
	float cp = velocity.y - velocity.x;	// cross product of vectors (1, 1) and (x, y) is y - x
	float dp = velocity.x + velocity.y;	// dot product of the same vectors
	float ab = sqrt(2.0f) * length(velocity);	// |(1, 1)| * |(x, y)|
	float sinVal = cp / ab;	// the value of the sin of the angle between vectors a and b is: cross product / (length a * length b)
	float cosVal = dp / ab;

	// we have the sin of the angle, now we need to find the closest direction
	for (int i = 0; i < 8; ++i) {
		if (fabs(sinVal - sines[i]) + fabs(cosVal - cosines[i]) <= fabs(sinVal - sines[direction]) + fabs(cosVal - cosines[direction])) {
			direction = i;
		}
	}

	// update frame number if necessary
	if (currentFrameDelay >= frameDelay) {
		currentFrameDelay -= frameDelay;
		if (fabs(velocity.x) > EPS || fabs(velocity.y) > EPS) {
			frame++;
			frame %= (*frames)[direction].size();
			setTexture((*frames)[direction][frame]);
		}
	}
}


