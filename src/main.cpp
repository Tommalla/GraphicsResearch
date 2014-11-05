/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch main
 */
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "AnimatedCharacter.hpp"
#include "GraphicalObject.hpp"

using std::shared_ptr;
using std::string;
using std::vector;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

	sf::Texture texture, tile;
	string textureFile = "../resources/Isometric/Walk/Tuscan_Walk_00000.png";
	string tileFile = "../resources/Tiles/ts_beach0/straight/edited.png";
	string fontFile = "../resources/fonts/Montserrat-Regular.ttf";
	if (!texture.loadFromFile(textureFile)) {
		fprintf(stderr, "Failed to load %s\n", textureFile.c_str());
		return 1;
	}
	if (!tile.loadFromFile(tileFile)) {
		fprintf(stderr, "Failed to load %s\n", tileFile.c_str());
		return 1;
	}
	texture.setSmooth(true);
	tile.setSmooth(true);

	sf::Font font;
	if (!font.loadFromFile(fontFile)) {
		fprintf(stderr, "Failed to load %s\n", fontFile.c_str());
		return 1;
	}

	sf::Text fpsText;
	fpsText.setFont(font);
	fpsText.setCharacterSize(24);
	fpsText.setColor(sf::Color::Red);
	fpsText.setPosition(10, 10);

	vector<shared_ptr<GraphicalObject>> objects;
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

	{
		shared_ptr<GraphicalObject> p{new AnimatedCharacter()};
		p->setTexture(texture);
		p->setLogicalPosition(sf::Vector2f(2, 3));
		objects.push_back(p);
	}

	sf::Clock clock;
	float timeElapsed = 0.0f;
	int frames = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		timeElapsed += deltaTime;
		if (timeElapsed >= 1.0f) {
			fpsText.setString(std::to_string(frames));
			frames = 0;
			timeElapsed = 0.0f;
		}

		window.clear();
		for (auto& obj: objects) {
			obj->update(deltaTime);
			window.draw(obj->getDrawable());
		}
		window.draw(fpsText);
		window.display();
		++frames;
	}

	return 0;
}