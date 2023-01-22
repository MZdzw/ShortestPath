#include "myCity.h"


myCity::myCity(int x, int y)
	:m_x(x), m_y(y)
{
	Pressed = false;
	setFlag(ItemIsMovable);
	m_radius = 60;
}

QRectF myCity::boundingRect() const
{
	return QRectF(m_x,m_y,50,50);
	/*return { -m_radius / 2. + .5,
			-m_radius / 2. + .5,
			static_cast<qreal>(m_radius + 4),
			static_cast<qreal>(m_radius + 4)*/
	//};
}

void myCity::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QRectF rec = boundingRect();
	QBrush brush(Qt::blue);

	if (Pressed)
	{
		brush.setColor(Qt::red);
	}
	else
	{
		brush.setColor(Qt::green);
	}
	painter->fillRect(rec, brush);
	
	painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
	//painter->drawText(0, 0, "jou");
	painter->drawEllipse(rec);
	//painter->drawRect(rec);
	
	

}


void myCity::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	Pressed = true;
	update();
	QGraphicsItem::mousePressEvent(event);
}

void myCity::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	Pressed = false;
	update();
	QGraphicsItem::mouseReleaseEvent(event);
}
