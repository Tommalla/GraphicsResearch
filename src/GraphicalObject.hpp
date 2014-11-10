/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicalObject class to represent an abstract object to be displayed.
 */
#ifndef GRAPHICAL_OBJECT_HPP
#define GRAPHICAL_OBJECT_HPP
#include <vector>

#include <SFML/Graphics.hpp>

class GraphicalObject {
public:
	GraphicalObject();
	virtual std::vector<const sf::Drawable*> getDrawable() const;
	virtual void update(const float& deltaTime);
	void setTexture(const sf::Texture& texture);
	void setLogicalPosition(const sf::Vector2f& pos);

protected:
	std::vector<sf::Transformable*> entities;
	sf::Sprite sprite;
	sf::Vector2f position;
};

#endif // GRAPHICAL_OBJECT_HPP