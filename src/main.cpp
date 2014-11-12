/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch main
 */
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include <QtWidgets/QFrame>
#include <QtWidgets/QApplication>
#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "AnimatedCharacter.hpp"
#include "GraphicalObject.hpp"
#include "SFML/BenchmarkCanvas.hpp"

using std::shared_ptr;
using std::string;
using std::to_string;
using std::vector;

int main(int argc, char **argv) {
	QApplication App(argc, argv);

	// Create the main frame
	QFrame* MainFrame = new QFrame;
	MainFrame->setWindowTitle("Qt SFML");
	MainFrame->resize(900, 700);
	MainFrame->show();

	// Create a SFML view inside the main frame
	BenchmarkCanvas* SFMLView = new BenchmarkCanvas(MainFrame, QPoint(20, 20), QSize(800, 600));
	SFMLView->show();

	return App.exec();
}