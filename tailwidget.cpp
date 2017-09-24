#include "tailwidget.h"

#include <QStyleOption>
#include <QPainter>
#include <QPushButton>

TailWidget::TailWidget(QWidget *parent) : QWidget(parent)
{

}

void TailWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    return QWidget::paintEvent(event);
}

