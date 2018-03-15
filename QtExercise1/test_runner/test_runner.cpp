#include <QTest>
#include "test_runner.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent) : QObject(parent)
{

}

void test_runner::hello_worlds() {

    useful test_useful;

    POINT(hello_worlds, 1);
    QVERIFY(!strcmp(test_useful.hello(), "Hello, world!"));

}

void test_runner::add_adds() {

    useful test_useful;

    POINT(add_adds, 2);
    QVERIFY2(test_useful.add(666, 1337) == 2003, "woot");

}

void test_runner::add_adds_more() {
    useful test_useful;

    POINT(add_adds_more, 3);
    QVERIFY2(test_useful.add(667, 1337) == 2004, "woot2");

}

void test_runner::add_still_adds() {
    useful test_useful;

    POINT(add_still_adds, 4);
    QVERIFY2(test_useful.add(123, 456) == 579, "wootwoot");

}

void test_runner::hello_still_worlds() {
    useful test_useful;

    POINT(hello_still_worlds, 5);
    QVERIFY2(!strcmp(test_useful.hello(), "Hello, world!", "world"));

}
