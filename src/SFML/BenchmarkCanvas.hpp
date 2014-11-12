/* Tomasz [Tommalla] Zakrzewski, 2014
 * Based on http://sfml-dev.org/tutorials/1.6/graphics-qt.php
 */
#ifndef BENCHMARK_CANVAS_HPP
#define BENCHMARK_CANVAS_HPP
#include <memory>
#include <vector>

#include "QSFMLCanvas.hpp"
#include "../GraphicalObject.hpp"


class BenchmarkCanvas : public QSFMLCanvas {
Q_OBJECT;
public:
	BenchmarkCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size): QSFMLCanvas{Parent, Position, Size} {}

protected:
	virtual void OnInit();
	virtual void OnUpdate();

	sf::Clock clock;
	float timeElapsed;
	int frames;
	sf::Text fpsText;
	sf::Font font;
	std::vector<std::shared_ptr<GraphicalObject>> objects;
	sf::Texture tile;
	std::vector<std::vector<sf::Texture>> knightFrames;
};

#endif	// BENCHMARK_CANVAS_HPP