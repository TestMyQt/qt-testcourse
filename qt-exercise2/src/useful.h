#ifndef USEFUL_H
#define USEFUL_H

#include <QObject>

class useful : public QObject
{
    Q_OBJECT

public:
    explicit useful(QObject *parent = nullptr) : QObject(parent)
    {

    }
    ~useful();

    void hello(QString helloText);

signals:
    void usefulSignal(QString hello);

};

#endif //USEFUL_H
