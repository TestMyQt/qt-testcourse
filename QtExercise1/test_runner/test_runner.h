#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QObject>

class test_runner : public QObject {

	Q_OBJECT

	public:
		explicit test_runner(QObject *parent = nullptr);

	signals:

	public slots:

	private slots:
    void hello_worlds();
    void add_adds();
    void add_adds_more();
    void add_still_adds();
    void hello_still_worlds();

};

#endif
