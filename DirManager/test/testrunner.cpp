#include "testrunner.h"
#include <QTest>

TestRunner::TestRunner(QObject *parent)
    : QObject(parent)
{

}

void TestRunner::testDirManager()
{
    POINT(testDirManager, 1);
    // No tests for this project
}
