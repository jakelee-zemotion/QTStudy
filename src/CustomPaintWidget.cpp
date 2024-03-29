#include "CustomPaintWidget.h"
#include <QPainter>

CustomPaintWidget::CustomPaintWidget()
{
    this->setMinimumSize(200, 100);
}

void CustomPaintWidget::paintEvent(QPaintEvent* event)
{
    QPainter MyPainter(this);
    MyPainter.setPen(Qt::blue);
    MyPainter.setFont(QFont("Arial", 80));
    MyPainter.drawText(rect(), Qt::AlignCenter, "Qt");

    QPen LinePen(Qt::green);
    LinePen.setWidth(2);

    QPoint p1(0, 0);
    QPoint p2(this->size().width(), this->size().height());

    MyPainter.setPen(LinePen);
    MyPainter.drawLine(p1, p2);

}
