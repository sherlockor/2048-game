#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>

class Function : public QObject
{
    Q_OBJECT
private:
    explicit Function(QObject *parent = 0);

public:
    static int GetRand(int max_value);
};

#endif // FUNCTION_H
