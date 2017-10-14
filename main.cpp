#include "My2048Game.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("://style.qss");
    if( file.open(QFile::ReadOnly))
    {
        QString styleSheet = QLatin1String(file.readAll());

        a.setStyleSheet(styleSheet);
        file.close();
    }

    Widget w;
    w.show();

    return a.exec();
}
