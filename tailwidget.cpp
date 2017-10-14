#include "tailwidget.h"
#include "qcustomlabel.h"

#include <QStyleOption>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>

TailWidget::TailWidget(QWidget *parent) : QWidget(parent)
{
    restartButton = new QCustomLabel(this);
    revokeButton = new QCustomLabel(this);

    restartButton->SetText(tr("Restart"));
    revokeButton->SetText(tr("Revoke"));

    revokeButton->setEnabled(false);
    restartButton->setToolTip(tr("Restart"));
    revokeButton->setToolTip(tr("Revoke to be implemented"));

    QHBoxLayout* main_layout = new QHBoxLayout(this);
    main_layout->addWidget(revokeButton);
    main_layout->addWidget(restartButton);

    setLayout(main_layout);

    connect(restartButton, SIGNAL(SignalClicked()), this, SLOT(SlotOnClickRestartButton()));
    connect(revokeButton, SIGNAL(SignalClicked()), this, SLOT(SlotOnClickRevokeButton()));
}

void TailWidget::SlotOnClickRestartButton()
{
    if(QMessageBox::Yes == QMessageBox::question(NULL, tr("Restart"), tr("Sure to restart"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No))
    {
        emit SignalRestart();
    }
}

void TailWidget::SlotOnClickRevokeButton()
{
    emit SignalRevoke();
}

void TailWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    return QWidget::paintEvent(event);
}

