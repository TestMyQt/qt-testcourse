#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <QObject>

class test_runner : public QObject
{

	Q_OBJECT

	public:
		explicit test_runner(QObject *parent = nullptr);

	signals:

	public slots:

	private slots:
    void list_modified_correctly();
    void correct_heights_returned();
    void correct_names_returned();

};

#endif
