/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch main
 */
#include <cstdio>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "GraphicalObject.hpp"

using std::string;
using std::vector;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

	sf::Texture texture, tile;
	string textureFile = "../resources/Isometric/Walk/Tuscan_Walk_00000.png";
	string tileFile = "../resources/Tiles/ts_beach0/straight/edited.png";
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

	vector<GraphicalObject> objects;
	//create tiles
	int xtiles = WIDTH / BASE_WIDTH;
	int ytiles = 2 * (HEIGHT - (BASE_HEIGHT / 2.0f)) / BASE_HEIGHT;
	float sumYOffset = 0.0f;
	for (int y = 0; y < ytiles; ++y) {
		float offset = y % 2 ? 0.5f : 0.0f;
		int numOffset = offset ? 1 : 0;
		for (int x = 0; x < xtiles - numOffset; ++x) {
			GraphicalObject obj;
			obj.setTexture(tile);
			obj.setLogicalPosition(sf::Vector2f(x + offset, y - offset - sumYOffset));
			objects.push_back(obj);
		}
		sumYOffset += offset ? 1.0f : 0.0f;
	}

	{
		GraphicalObject obj;
		obj.setTexture(texture);
		obj.setLogicalPosition(sf::Vector2f(2, 3));
		objects.push_back(obj);
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		for (const auto& obj: objects) {
			window.draw(obj.getDrawable());
		}
		window.display();
	}

	return 0;
}