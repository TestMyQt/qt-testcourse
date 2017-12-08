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
    void multiply_positive();
    void multiply_negative();

};

#endif
