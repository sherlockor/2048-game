#include "qcustomlabel.h"

#include <QPixmap>
#include <QFont>
#include <QPalette>

QCustomLabel::QCustomLabel(QWidget *parent) : QLabel(parent)
{
    setMaximumSize(70, 50);
}

void QCustomLabel::SetText(const QString &text)
{
    QFont font;
    font.setPointSize(12);
    font.setBold(true);

    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);

    setFont(font);
    setPalette(palette);

    setAlignment(Qt::AlignCenter);
    setText(text);
}

void QCustomLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit SignalClicked();
    }
}

