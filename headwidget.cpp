#include "headwidget.h"

#include <QStyleOption>
#include <QPainter>

HeadWidget::HeadWidget(QWidget *parent) : QWidget(parent)
{

}

void HeadWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    return QWidget::paintEvent(event);
}

