#include "extrafunction.h"

#include <QTime>

int Function::GetRand(int max_value)
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);

    return qrand()%max_value;
}
