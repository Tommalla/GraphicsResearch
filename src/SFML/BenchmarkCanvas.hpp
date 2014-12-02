/* Tomasz [Tommalla] Zakrzewski, 2014
 * Based on http://sfml-dev.org/tutorials/1.6/graphics-qt.php
 */
#ifndef BENCHMARK_CANVAS_HPP
#define BENCHMARK_CANVAS_HPP
#include <memory>
#include <vector>

#include "QSFMLCanvas.hpp"
#include "../GraphicalObject.hpp"
#include "../AnimatedCharacter.hpp"


class BenchmarkCanvas : public QSFMLCanvas {
Q_OBJECT;
public:
	BenchmarkCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size)
			: QSFMLCanvas{Parent, Position, Size}{}
	void setCharactersNumber(const int number);

protected:
	virtual void OnInit();
	virtual void OnUpdate();

	sf::Clock clock;
	float timeElapsed;
	int frames;
	sf::Text fpsText;
	sf::Font font;
	std::vector<std::shared_ptr<GraphicalObject>> objects;
	std::vector<std::shared_ptr<AnimatedCharacter>> dynamicObjects;
	sf::Texture tile;
	std::vector<std::vector<sf::Texture>> knightFrames;
	std::shared_ptr<std::vector<std::vector<sf::Texture>>> frames_ptr;

private:
	void addCharacters(int number);
	void removeCharacters(int number);
};

#endif	// BENCHMARK_CANVAS_HPP