/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch MainWindow implementation
 */
#include "MainWindow.hpp"

#include "SFML/BenchmarkCanvas.hpp"

MainWindow::MainWindow()
: QFrame() {
	setWindowTitle("Qt SFML");
	resize(840, 680);

	// Create a SFML view inside the frame
	BenchmarkCanvas* SFMLView = new BenchmarkCanvas(this, QPoint(20, 70), QSize(800, 600));
	SFMLView->show();

	// Create the edit and the button to set the number of characters on the screen
	// NEEDS A WINDOW!
	// TODO
}
