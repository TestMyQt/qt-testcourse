// BEGIN SOLUTION
#ifndef DIRMANAGER_H
#define DIRMANAGER_H

#include <QObject>
#include <QDir>
#include <QFileInfoList>

class DirManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dirName MEMBER m_dirName NOTIFY dirNameChanged)
    Q_PROPERTY(int filesInDir MEMBER m_filesInDir NOTIFY filesInDirChanged)

public:
    explicit DirManager(QObject *parent = nullptr);

protected:
    bool refreshDirEntries(const QString &dirName);

Q_SIGNALS:
    void entryClicked(const QString &entry);
    void dataChanged();
    void dirNameChanged();
    void filesInDirChanged();
    void fileContentChanged();

public Q_SLOTS:
    QStringList model() const;
    QString fileContent() const;
    void entryChanged(const QString &entry);
    void sort();

private:
    QStringList m_fileInfoList;
    QDir m_currentDirectory;
    QFileInfoList m_fileList;
    QString m_dirName;
    int m_filesInDir;
    bool m_sortAscending;
    QString m_fileContent;
};

#endif // DIRMANAGER_H
// END SOLUTION
