/* Tomasz [Tommalla] Zakrzewski, 2014
 * Based on http://sfml-dev.org/tutorials/1.6/graphics-qt.php
 */
#include "BenchmarkCanvas.hpp"

#include <cstdio>
#include <exception>
#include <memory>
#include <string>
#include <vector>


#include "../AnimatedCharacter.hpp"
#include "../common.hpp"


using std::runtime_error;
using std::shared_ptr;
using std::string;
using std::to_string;
using std::vector;


void BenchmarkCanvas::OnInit() {
	string textureFilePrefix = "../resources/Isometric/Walk/Tuscan_Walk_";
	string tileFile = "../resources/Tiles/ts_beach0/straight/edited.png";
	string fontFile = "../resources/fonts/Montserrat-Regular.ttf";
	for (int dir = 0; dir < 8; ++dir) {
		knightFrames.push_back({});
		for (int id = 0; id <= 14; ++id) {
			sf::Texture texture;
			string filename = textureFilePrefix + to_string(100000 + 10000 * dir + id).substr(1, 5) + ".png";
			if (!texture.loadFromFile(filename)) {
				throw runtime_error("Failed to load " + filename);
			}
			texture.setSmooth(true);
			knightFrames.back().push_back(texture);
		}
	}
	if (!tile.loadFromFile(tileFile)) {
		throw runtime_error("Failed to load " + tileFile);
	}
	tile.setSmooth(true);

	if (!font.loadFromFile(fontFile)) {
		throw runtime_error("Failed to load " + fontFile);
	}

	fpsText.setFont(font);
	printf("Font loaded and set\n");
	fpsText.setCharacterSize(24);
	fpsText.setColor(sf::Color::Red);
	fpsText.setPosition(10, 10);

	//create tiles
	int xtiles = WIDTH / BASE_WIDTH;
	int ytiles = 2 * (HEIGHT - (BASE_HEIGHT / 2.0f)) / BASE_HEIGHT;
	float sumYOffset = 0.0f;
	for (int y = 0; y < ytiles; ++y) {
		float offset = y % 2 ? 0.5f : 0.0f;
		int numOffset = offset ? 1 : 0;
		for (int x = 0; x < xtiles - numOffset; ++x) {
			shared_ptr<GraphicalObject> p{new GraphicalObject()};
			p->setTexture(tile);
			p->setLogicalPosition(sf::Vector2f(x + offset, y - offset - sumYOffset));
			objects.push_back(p);
		}
		sumYOffset += offset ? 1.0f : 0.0f;
	}

	frames_ptr = shared_ptr<vector<vector<sf::Texture>>>{new vector<vector<sf::Texture>>{knightFrames}};

	addCharacters(200);

	timeElapsed = 0.0f;
	frames = 0;
}


void BenchmarkCanvas::OnUpdate() {
	QSFMLCanvas::OnUpdate();
	// the drawing logic
	clear(sf::Color::Black);

	float deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	timeElapsed += deltaTime;
	if (timeElapsed >= 1.0f) {
		fpsText.setString(std::to_string(frames));
		frames = 0;
		timeElapsed = 0.0f;
	}

	for (auto& obj: objects) {
		obj->update(deltaTime);
		for (auto drawable: obj->getDrawable()) {
			draw(*drawable);
		}
	}

	for (auto& obj: dynamicObjects) {
		obj->update(deltaTime);
		for (auto drawable: obj->getDrawable()) {
			draw(*drawable);
		}
	}

	draw(fpsText);
	++frames;
}


void BenchmarkCanvas::setCharactersNumber(const int number) {
	int size = static_cast<int>(dynamicObjects.size());
	if (number > size) {
		addCharacters(number - size);
	} else if (number < size) {
		removeCharacters(size - number);
	}
}


void BenchmarkCanvas::addCharacters(int number)
{
	while(number--) {
		shared_ptr<AnimatedCharacter> p{new AnimatedCharacter(frames_ptr)};
		dynamicObjects.push_back(p);
	}
}

void BenchmarkCanvas::removeCharacters(int number)
{
	while(number--) {
		dynamicObjects.pop_back();
	}
}
