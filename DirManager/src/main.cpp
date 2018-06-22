// BEGIN SOLUTION
#include <dirmanager.h>
// END SOLUTION
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Expose dirManager here to engine
    // BEGIN SOLUTION
    DirManager dirManager;
    engine.rootContext()->setContextProperty("dirManager", &dirManager);
    // END SOLUTION

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
