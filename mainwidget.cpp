#include "mainwidget.h"
#include "cellwidget.h"
#include "extrafunction.h"

#include <QGridLayout>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color:#BFAD97");

    A1 = new CellWidget(this, "A1");
    A2 = new CellWidget(this, "A2");
    A3 = new CellWidget(this, "A3");
    A4 = new CellWidget(this, "A4");
    B1 = new CellWidget(this, "B1");
    B2 = new CellWidget(this, "B2");
    B3 = new CellWidget(this, "B3");
    B4 = new CellWidget(this, "B4");
    C1 = new CellWidget(this, "C1");
    C2 = new CellWidget(this, "C2");
    C3 = new CellWidget(this, "C3");
    C4 = new CellWidget(this, "C4");
    D1 = new CellWidget(this, "D1");
    D2 = new CellWidget(this, "D2");
    D3 = new CellWidget(this, "D3");
    D4 = new CellWidget(this, "D4");

    cellVector.append(A1);
    cellVector.append(A2);
    cellVector.append(A3);
    cellVector.append(A4);
    cellVector.append(B1);
    cellVector.append(B2);
    cellVector.append(B3);
    cellVector.append(B4);
    cellVector.append(C1);
    cellVector.append(C2);
    cellVector.append(C3);
    cellVector.append(C4);
    cellVector.append(D1);
    cellVector.append(D2);
    cellVector.append(D3);
    cellVector.append(D4);

    QGridLayout* main_widet_layout = new QGridLayout(this);
    main_widet_layout->addWidget(A1, 0, 0, 1, 1);
    main_widet_layout->addWidget(A2, 0, 1, 1, 1);
    main_widet_layout->addWidget(A3, 0, 2, 1, 1);
    main_widet_layout->addWidget(A4, 0, 3, 1, 1);
    main_widet_layout->addWidget(B1, 1, 0, 1, 1);
    main_widet_layout->addWidget(B2, 1, 1, 1, 1);
    main_widet_layout->addWidget(B3, 1, 2, 1, 1);
    main_widet_layout->addWidget(B4, 1, 3, 1, 1);
    main_widet_layout->addWidget(C1, 2, 0, 1, 1);
    main_widet_layout->addWidget(C2, 2, 1, 1, 1);
    main_widet_layout->addWidget(C3, 2, 2, 1, 1);
    main_widet_layout->addWidget(C4, 2, 3, 1, 1);
    main_widet_layout->addWidget(D1, 3, 0, 1, 1);
    main_widet_layout->addWidget(D2, 3, 1, 1, 1);
    main_widet_layout->addWidget(D3, 3, 2, 1, 1);
    main_widet_layout->addWidget(D4, 3, 3, 1, 1);
    setLayout(main_widet_layout);

    InitData();}

MainWidget::~MainWidget()
{
    delete A1;
    delete A2;
    delete A3;
    delete A4;
    delete B1;
    delete B2;
    delete B3;
    delete B4;
    delete C1;
    delete C2;
    delete C3;
    delete C4;
    delete D1;
    delete D2;
    delete D3;
    delete D4;
}

void MainWidget::Restert()
{
    for(int index = 0; index < cellVector.count(); index++)
    {
        cellVector.at(index)->clear();
    }
    InitData();
}

void MainWidget::InitData()
{
    int count = cellVector.count();
    int first_num = Function::GetRand(count);
    cellVector.at(first_num)->SetInitionalNumber();
    for(;;)
    {
        int second_num = Function::GetRand(count);
        if(second_num != first_num)
        {
            cellVector.at(second_num)->SetInitionalNumber();
            break;
        }
    }
}

void MainWidget::CreateRandNumber()
{
    int rand_num = -1;
    for(;;)
    {
        rand_num = Function::GetRand(cellVector.count());
        if(cellVector.at(rand_num)->GetNumber() == 0)
        {
            cellVector.at(rand_num)->SetInitionalNumber();
            break;
        }
    }
}

bool MainWidget::UpdateNumber(const QVector<CellWidget *> &widget_vec)
{
    bool status = false;
    for(int index = 0; index < 4; index++)
    {
        int num = -1;
        for(int i = index + 1; i < 4 ; i++)  //从后一个开始，找到第一个不为0的数
        {
            if(widget_vec.at(i)->GetNumber() != 0)
            {
                num = i;
                break;
            }
        }
        if(num < 0) //未找到第一个不为0的数
        {
            continue;
        }
        if(widget_vec.at(index)->GetNumber() == 0)
        {
            widget_vec.at(index)->SetNumber(widget_vec.at(num)->GetNumber());
            widget_vec.at(num)->SetNumber(0);
            index--;
            status = true;
        }
        else if(widget_vec.at(index)->GetNumber() == widget_vec.at(num)->GetNumber())
        {
            widget_vec.at(index)->SetNumber(widget_vec.at(index)->GetNumber() * 2);
            widget_vec.at(num)->SetNumber(0);
            status = true;
        }
    }
    return status;
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    return QWidget::paintEvent(event);
}

void MainWidget::SlotOnClickUpButton()
{
    bool any_changed = false;
    for(int colum = 1; colum < 5; colum++)
    {
        QVector<CellWidget*> colum_object;
        colum_object.append(cellVector.at(colum -1));
        colum_object.append(cellVector.at(colum -1 + 4));
        colum_object.append(cellVector.at(colum -1 + 8));
        colum_object.append(cellVector.at(colum -1 + 12));
        any_changed = UpdateNumber(colum_object)? true: any_changed;
    }
    if(any_changed)
    {
        CreateRandNumber();
    }
}

void MainWidget::SlotOnClickDownButton()
{
    bool any_changed = false;
    for(int colum = 1; colum < 5; colum++)
    {
        QVector<CellWidget*> colum_object;
        colum_object.append(cellVector.at(colum -1 + 12));
        colum_object.append(cellVector.at(colum -1 + 8));
        colum_object.append(cellVector.at(colum -1 + 4));
        colum_object.append(cellVector.at(colum -1));
        any_changed = UpdateNumber(colum_object)? true: any_changed;
    }
    if(any_changed)
    {
        CreateRandNumber();
    }
}

void MainWidget::SlotOnClickLeftButton()
{
    bool any_changed = false;
    for(int row = 1; row <= 16;)
    {
        QVector<CellWidget*> colum_object;
        colum_object.append(cellVector.at(row -1));
        colum_object.append(cellVector.at(row -1 + 1));
        colum_object.append(cellVector.at(row -1 + 2));
        colum_object.append(cellVector.at(row -1 + 3));
        any_changed = UpdateNumber(colum_object)? true: any_changed;
        row = row + 4;
    }
    if(any_changed)
    {
        CreateRandNumber();
    }
}

void MainWidget::SlotOnClickRightButton()
{
    bool any_changed = false;
    for(int row = 1; row <= 16;)
    {
        QVector<CellWidget*> colum_object;
        colum_object.append(cellVector.at(row -1 + 3));
        colum_object.append(cellVector.at(row -1 + 2));
        colum_object.append(cellVector.at(row -1 + 1));
        colum_object.append(cellVector.at(row -1));
        any_changed = UpdateNumber(colum_object)? true: any_changed;
        row = row + 4;
    }
    if(any_changed)
    {
        CreateRandNumber();
    }
}


