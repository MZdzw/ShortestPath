#pragma once
#include <qpainter.h>
#include <qgraphicsitem.h>
#include <qdebug.h>


class myCity : public QGraphicsItem
{
public:
	myCity(int x, int y);

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	bool Pressed;


	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
	int m_x;
	int m_y;
	int m_radius;
};

