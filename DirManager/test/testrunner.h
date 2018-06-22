#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point);

#include <QObject>

class TestRunner : public QObject
{

    Q_OBJECT

public:
    explicit TestRunner(QObject *parent = nullptr);

public slots:

private slots:
    void testDirManager();
};

#endif
