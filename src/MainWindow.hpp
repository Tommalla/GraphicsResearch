/* Tomasz [Tommalla] Zakrzewski, 2014
 * GraphicsResearch MainWindow
 */
#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP
#include <QtWidgets/QFrame>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>


#include "SFML/BenchmarkCanvas.hpp"


class MainWindow: public QFrame {
Q_OBJECT;
public:
	MainWindow();

private:
	QTextEdit* textEdit;
	BenchmarkCanvas* SFMLView;

private slots:
	void changeScene();

};


#endif