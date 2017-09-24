#ifndef HEADWIDGET_H
#define HEADWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class HeadWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HeadWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent* event);
};

#endif // HEADWIDGET_H
