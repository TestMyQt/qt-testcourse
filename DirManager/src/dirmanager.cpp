// BEGIN SOLUTION
#include "dirmanager.h"
#include <QDir>
#include <QFileInfo>
#include <QtDebug>

DirManager::DirManager(QObject *parent)
    : QObject(parent)
    , m_sortAscending(true)
{
    if (refreshDirEntries(QDir::homePath()))
        connect(this, &DirManager::entryClicked, this, &DirManager::entryChanged);
}

bool DirManager::refreshDirEntries(const QString &dirName)
{
    if (m_currentDirectory.cd(dirName)) {
        m_fileList = m_currentDirectory.entryInfoList();
        m_fileInfoList.clear();

        for (auto iterator = m_fileList.cbegin(); iterator != m_fileList.cend(); iterator++) {
            QFileInfo fileInfo = *iterator;
            QString row(QString("%1 %2").arg(fileInfo.fileName()).arg(fileInfo.size()));
            m_fileInfoList.append(row);
        }
        m_dirName = m_currentDirectory.dirName();
        Q_EMIT dirNameChanged();
        m_filesInDir = m_fileInfoList.count();
        Q_EMIT filesInDirChanged();
        return true;
    }
    else
        return false;
}

QStringList DirManager::model() const
{
    return m_fileInfoList;
}

void DirManager::entryChanged(const QString &entry)
{
    QString fileName(entry.left(entry.indexOf(' ')));

    for (auto iterator = m_fileList.cbegin(); iterator != m_fileList.cend(); iterator++) {
        QFileInfo fileInfo = *iterator;

        if (fileName == fileInfo.fileName()) {
            if (fileInfo.isDir()) {
                if (refreshDirEntries(fileInfo.fileName()))
                    Q_EMIT dataChanged();
            }
            else {
                QFile file(fileInfo.absoluteFilePath());
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    return;
                m_fileContent = file.readAll();
                Q_EMIT fileContentChanged();
            }
            break;
        }
    }
}

QString DirManager::fileContent() const
{
    return m_fileContent;
}

void DirManager::sort()
{
    if (m_sortAscending) {
        std::sort(m_fileInfoList.begin(), m_fileInfoList.end(), std::greater<QString>());
        m_sortAscending = false;
    }
    else {
        std::sort(m_fileInfoList.begin(), m_fileInfoList.end(), std::less<QString>());
        m_sortAscending = true;
    }
    Q_EMIT dataChanged();
}
// END SOLUTION
