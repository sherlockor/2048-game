#ifndef CELLWIDGET_H
#define CELLWIDGET_H

#include <QLabel>
#include <QPaintEvent>
#include <QMap>

class CellWidget : public QLabel
{
    Q_OBJECT
public:
    explicit CellWidget(QWidget *parent, QString id);

signals:

public:
    /*
     * @brief 获取当前数字
     */
    int GetNumber();

    /*
     * @brief 设置数字
     */
    void SetNumber(int num);

    /*
     * @brief 初始化数字，设置为2
     */
    void SetInitionalNumber();

    /*
     * @brief 清零
     */
    void Clear();

    /*
     * 返回上一次的数字
     */
    void ReturnLastNumber();

    /*
     * @brief 获取ID
     */
    QString GetID();

    void SetID(const QString& id);

public slots:
    /*
     * @brief 刷新数字和颜色
     */
    void Update();

private:
    int number;
    int lastNumber;

    QString ID;

    QMap<int, QString> backgroundColor;
};

#endif // CELLWIDGET_H
