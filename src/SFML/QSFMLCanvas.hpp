/* Tomasz [Tommalla] Zakrzewski, 2014
 * Based on http://sfml-dev.org/tutorials/1.6/graphics-qt.php
 */
#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H
#include <SFML/Graphics.hpp>
#include <QtWidgets/QWidget>
#include <QtCore/QTimer>

class QSFMLCanvas : public QWidget, public sf::RenderWindow {
Q_OBJECT;
public:
	QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);

protected:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual QPaintEngine* paintEngine() const;
	virtual void showEvent(QShowEvent*);
	virtual void paintEvent(QPaintEvent*);
	QTimer myTimer;
	bool   myInitialized;
};

#endif	// QSMLCANVAS_H