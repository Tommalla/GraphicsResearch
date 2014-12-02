/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch main
 */
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include <QtWidgets/QApplication>
#include <SFML/Graphics.hpp>

#include "MainWindow.hpp"

using std::shared_ptr;
using std::string;
using std::to_string;
using std::vector;

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();

	return app.exec();
}