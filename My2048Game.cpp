#include "My2048Game.h"
#include "ui_widget.h"
#include "cellwidget.h"
#include "headwidget.h"
#include "mainwidget.h"
#include "tailwidget.h"

#include <QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    InitData();
    InitStyle();
    InitConnection();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::InitData()
{
    headWidget = new HeadWidget(this);
    mainWidget = new MainWidget(this);
    tailWidget = new TailWidget(this);
}

void Widget::InitStyle()
{
    QGridLayout* main_layout = new QGridLayout(this);
    main_layout->addWidget(headWidget, 0, 0, 1, 1);
    main_layout->addWidget(mainWidget, 1, 0, 3, 1);
    main_layout->addWidget(tailWidget, 4, 0, 1, 1);
    setLayout(main_layout);
}

void Widget::InitConnection()
{
    connect(this, SIGNAL(SignalOnClickUpButton()), mainWidget, SLOT(SlotOnClickUpButton()));
    connect(this, SIGNAL(SignalOnClickDownButton()), mainWidget, SLOT(SlotOnClickDownButton()));
    connect(this, SIGNAL(SignalOnClickLeftButton()), mainWidget, SLOT(SlotOnClickLeftButton()));
    connect(this, SIGNAL(SignalOnClickRightButton()), mainWidget, SLOT(SlotOnClickRightButton()));

    connect(tailWidget, SIGNAL(SignalRestart()), mainWidget, SLOT(SlotRestart()));
    connect(tailWidget, SIGNAL(SignalRevoke()), mainWidget, SLOT(SlotRevoke()));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        emit SignalOnClickUpButton();
    }
    else if(event->key() == Qt::Key_Down)
    {
        emit SignalOnClickDownButton();
    }
    else if(event->key() == Qt::Key_Left)
    {
        emit SignalOnClickLeftButton();
    }
    else if(event->key() == Qt::Key_Right)
    {
        emit SignalOnClickRightButton();
    }
}
