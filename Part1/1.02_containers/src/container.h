#ifndef CONTAINER_H
#define CONTAINER_H
#include <QList>
#include <QMap>
#include <QString>

class Container
{

	public:

        Container();

        QList<int> listPractise(QList<int> list);
        QList<float> heights(QMap<QString, float> heights);
        QList<QString> names(QMap<QString, float> heights);
};

#endif //CONTAINER_H
