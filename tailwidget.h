#ifndef TAILWIDGET_H
#define TAILWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class QPushButton;
class QToolButton;
class QCustomLabel;

class TailWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TailWidget(QWidget *parent = 0);

signals:
    void SignalRestart();
    void SignalRevoke();

public slots:
    void SlotOnClickRestartButton();
    void SlotOnClickRevokeButton();

protected:
    void paintEvent(QPaintEvent* event);

private:
    QCustomLabel* restartButton;
    QCustomLabel* revokeButton;
};

#endif // TAILWIDGET_H
