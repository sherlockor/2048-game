#include "cellwidget.h"
#include <QDebug>
#include <QFont>

CellWidget::CellWidget(QWidget *parent, QString id) : QLabel(parent)
  ,number(0), ID(id), lastNumber(0)
{
    QFont font;
    font.setPointSize(25);
    font.setFamily("微软雅黑");
    setFont(font);

    setAlignment(Qt::AlignCenter);

    backgroundColor.insert(0, "CCC3B4");
    backgroundColor.insert(2, "EEE3DD");
    backgroundColor.insert(4, "EEE3C5");
    backgroundColor.insert(8, "F6B271");
    backgroundColor.insert(16, "F6965C");
    backgroundColor.insert(32, "F57D5A");
    backgroundColor.insert(64, "F75D39");
    backgroundColor.insert(128, "EED06E");
    backgroundColor.insert(256, "EECF5B");
    backgroundColor.insert(512, "EECA4F");
    backgroundColor.insert(1024, "EEC640");
    backgroundColor.insert(2048, "EEC329");
    backgroundColor.insert(4096, "383830");
    backgroundColor.insert(8192, "36382A");
    backgroundColor.insert(16384, "35382D");

    Update();
}

int CellWidget::GetNumber()
{
    return number;
}

void CellWidget::SetNumber(int num)
{
    lastNumber = number;
    number = num;
    Update();
}

void CellWidget::SetInitionalNumber()
{
    lastNumber = number;
    number = 2;
    Update();
}

void CellWidget::Clear()
{
    lastNumber = 0;
    number = 0;
    Update();
}

void CellWidget::ReturnLastNumber()
{
    number = lastNumber;
    Update();
}

void CellWidget::Update()
{
    setText(QString::number(number));
    QString style_sheet = QString("background-color:#%1").arg(backgroundColor.value(number));
    setStyleSheet(style_sheet);
    if(0 == number)
    {
        setText("");
    }
}

QString CellWidget::GetID()
{
    return ID;
}

void CellWidget::SetID(const QString &id)
{
    ID = id;
}
