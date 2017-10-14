#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVector>

class CellWidget;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

public:

public slots:
    /*
     * @brief 重新开始
     */
    void SlotRestart();

    /*
     * @brief 上一步
     */
    void SlotRevoke();

    /*
     * @brief 按键槽函数
     */
    void SlotOnClickUpButton();
    void SlotOnClickDownButton();
    void SlotOnClickLeftButton();
    void SlotOnClickRightButton();

protected:
    void paintEvent(QPaintEvent* event);

private:
    /*
     * @brief 初始化随机开始数据
     */
    void InitData();

    /*
     * @brief 产生一个随位置机数据
     */
    void CreateRandNumber();

    /*
     * @brief 更新数字
     */
    bool UpdateNumber(const QVector<CellWidget*>& widget_vec);

private:
    QVector<CellWidget*> cellVector;
    CellWidget* A1;
    CellWidget* A2;
    CellWidget* A3;
    CellWidget* A4;
    CellWidget* B1;
    CellWidget* B2;
    CellWidget* B3;
    CellWidget* B4;
    CellWidget* C1;
    CellWidget* C2;
    CellWidget* C3;
    CellWidget* C4;
    CellWidget* D1;
    CellWidget* D2;
    CellWidget* D3;
    CellWidget* D4;
};

#endif // MAINWIDGET_H
