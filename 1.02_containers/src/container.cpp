#include "container.h"
#include <QDebug>

Container::Container()
{

}

// 1) Make a function listPractice(QList<int> list) that
// uses a mutable iterator to multiply all numbers divisible by 5 by 3,
// and then returns the list.
// 2) Make a function heights(QMap<QString, float> heights) that
// returns a QList<float> of heights of people whose name starts with 'A'.
// Return them in the order QMap holds them (by key).
// 3) Make a function names(QMap<QString, float> heights) that returns
// a QList<QString> of names of people who are taller than 1.80m. You
// can assume that heights are unique. Use alphabetical order here as well.

// BEGIN SOLUTION
QList<int> Container::listPractise(QList<int> list)
{
    QMutableListIterator<int> i(list);
    while (i.hasNext()) {
        int j = i.next();
        if (list[j] % 5 == 0) {
            list[j] = list[j] * 3;
        }
    }
    return list;
}

QList<float> Container::heights(QMap<QString, float> heights)
{
    QList<float> heightList;
    for (QMap<QString, float>::iterator i = heights.begin(); i != heights.end(); i++) {
        if (i.key().startsWith('A'))
            heightList.append(heights.value(i.key()));
    }
    return heightList;
}

QList<QString> Container::names(QMap<QString, float> heights)
{
    QList<QString> nameList;
    for (QMap<QString, float>::iterator i = heights.begin(); i != heights.end(); i++) {
        if (i.value() > 1.80f)
            nameList.append(heights.key(i.value()));
    }
    return nameList;
}
// END SOLUTION

