/* Tomasz [Tommalla] Zakrzewski, 2014
 * Common definitions.
 */
#ifndef COMMON_HPP
#define COMMON_HPP
#include <SFML/Graphics.hpp>

const float WIDTH = 800.0;
const float HEIGHT = 600.0;
const float BASE_WIDTH = 64.0;
const float BASE_HEIGHT = 32.0;
const float EPS = 0.0001;
const float PI = 3.14159265f;

inline float length(const sf::Vector2f &vect) {
	return sqrt(vect.x * vect.x + vect.y * vect.y);
}

#endif