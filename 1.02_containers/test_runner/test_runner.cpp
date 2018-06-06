#include <QTest>
#include <QList>
#include <QDebug>
#include "test_runner.h"
#include "container.h"

#define POINT(test_name, point) qInfo("TMC:"#test_name"."#point)

test_runner::test_runner(QObject *parent)
    : QObject(parent)
{
    class Container;

}

void test_runner::list_modified_correctly()
{
    Container test_useful;
    POINT(list_modified_correctly, 3.1);

    QList<int> list;
    QList<int> correctList;
    for (int i = 0; i < 1000; i++) {
        list.append(i);
        if (i % 5 == 0) {
            correctList.append(i*3);
        } else {
            correctList.append(i);
        }
    }
    list = test_useful.listPractise(list);
    for (int i = 0; i < 1000; i++) {
        QVERIFY(list[i] == correctList[i]);
    }
}

void test_runner::correct_heights_returned()
{
    Container test_useful;
    POINT(correct_heights_returned, 3.2);
    QMap<QString, float> map;
    map.insert("Mark", 1.82f);
    map.insert("Anton", 1.90f);
    map.insert("Liisa", 1.59f);
    map.insert("Anna", 1.64f);
    QList<float> correctHeights;
    correctHeights.append(1.64f);
    correctHeights.append(1.90f);
    QList<float> returned = test_useful.heights(map);
    QVERIFY(correctHeights.size() == returned.size());
    for (int i = 0; i < returned.size(); i++)
        QVERIFY(qFuzzyCompare(returned[i], correctHeights[i]));
}

void test_runner::correct_names_returned()
{
    Container test_useful;
    POINT(correct_names_returned, 3.3);
    QMap<QString, float> map;
    map.insert("Mark", 1.82f);
    map.insert("Anton", 1.90f);
    map.insert("Liisa", 1.59f);
    map.insert("Anna", 1.64f);
    QList<QString> correctNames;
    correctNames.append("Anton");
    correctNames.append("Mark");
    QList<QString> returned = test_useful.names(map);
    QVERIFY(correctNames.size() == returned.size());
    for (int i = 0; i < returned.size(); i++) {
        QVERIFY(returned[i] == correctNames[i]);
    }
}
