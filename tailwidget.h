#ifndef TAILWIDGET_H
#define TAILWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class QPushButton;

class TailWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TailWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent* event);

private:
    QPushButton* restartButton;
};

#endif // TAILWIDGET_H
