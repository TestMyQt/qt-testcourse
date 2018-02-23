#include <QTest>
#include "test.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent) : QObject(parent)
{

}

void test_runner::multiply_positive() {

    useful test_useful;

    POINT(multiply_positive, 1.1);
    QVERIFY(test_useful.mul(5, 10) == 50);

}

void test_runner::multiply_negative() {

    useful test_useful;

    POINT(multiply_negative, 1.2);
    QVERIFY(test_useful.mul(-5, -10) == 50);

}
