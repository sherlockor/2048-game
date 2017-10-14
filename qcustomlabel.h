#ifndef QCUSTOMLABEL_H
#define QCUSTOMLABEL_H

#include <QLabel>
#include <QMouseEvent>

class QCustomLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QCustomLabel(QWidget *parent = 0);

signals:
    void SignalClicked();

public slots:

public:
    /*
     * 设置文字
     */
    void SetText(const QString& text);

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // QCUSTOMLABEL_H
