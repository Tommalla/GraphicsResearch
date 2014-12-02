/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch MainWindow implementation
 */
#include "MainWindow.hpp"

#include <QtWidgets/QLabel>


MainWindow::MainWindow()
: QFrame() {
	setWindowTitle("Qt SFML");
	resize(840, 670);

	// Create a SFML view inside the frame
	SFMLView = new BenchmarkCanvas(this, QPoint(20, 50), QSize(800, 600));
	SFMLView->show();

	// Create the edit and the button to set the number of characters on the screen
	QLabel* label = new QLabel(this);
	label->setText("Change the number of characters: ");
	label->move(20, 15);

	textEdit = new QTextEdit(this);
	textEdit->move(250, 10);
	textEdit->resize(200, 25);
	textEdit->setText("500");
	textEdit->show();

	QPushButton* button = new QPushButton(this);
	button->move(475, 10);
	button->setText("Ok");
	button->show();
}


void MainWindow::changeScene() {
	QString text = textEdit->toPlainText();
	bool ok = true;
	long int num = text.toLong(&ok);
	if (ok) {
		SFMLView->setCharactersNumber(num);
	}
}

