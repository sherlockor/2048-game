#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class HeadWidget;
class CellWidget;
class MainWidget;
class TailWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:
    /*
     * @brief 按键
     */
    void SignalOnClickUpButton();
    void SignalOnClickDownButton();
    void SignalOnClickLeftButton();
    void SignalOnClickRightButton();

private:
    /*
     * @brief 数据初始化
     */
    void InitData();

    /*
     * @brief 样式初始化
     */
    void InitStyle();

    /*
     * @brief 信号槽初始化
     */
    void InitConnection();

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::Widget *ui;
    HeadWidget* headWidget;
    MainWidget* mainWidget;
    TailWidget* tailWidget;
};

#endif // WIDGET_H
