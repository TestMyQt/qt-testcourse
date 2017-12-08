#include <QTest>
#include <QSignalSpy>
#include "test_runner.h"
#include "useful.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent) : QObject(parent)
{

}

void test_runner::hello_emits() {

    useful test_useful;

    POINT(hello_emits, 1);
    QSignalSpy helloSpy(&test_useful, &useful::usefulSignal);

    test_useful.hello("hello");

    QVERIFY2(helloSpy.count() == 1, "Signal emitted!");
    QList<QVariant> arguments = helloSpy.takeFirst();

    QVERIFY2(arguments.takeFirst() == "hello", "Hello emitted");

}

void test_runner::hello_emits_twice() {

    useful test_useful;

    POINT(hello_emits_twice, 1);
    QSignalSpy helloSpy(&test_useful, &useful::usefulSignal);

    test_useful.hello("hello");
    test_useful.hello("world");

    QVERIFY2(helloSpy.count() == 2, "Signals emitted!");
    QList<QVariant> arguments = helloSpy.takeFirst();
    QVERIFY2(arguments.takeFirst() == "hello", "Hello emitted");
    arguments = helloSpy.takeFirst();
    QVERIFY2(arguments.takeFirst() == "world", "World emitted");
}
