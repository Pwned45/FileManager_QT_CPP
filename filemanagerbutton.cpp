#include "filemanagerbutton.h"
FileManagerButton::FileManagerButton(QString m_path, QString m_name, int m_stage, bool m_ismarked)
{
    this->m_path = m_path;
    this->m_name =m_name;
    this->m_stage = m_stage;
    this->m_ismarked =m_ismarked;

}

FileManagerButton::FileManagerButton(QString m_path, QString m_name)
{
    this->m_path = m_path;
    this->m_name =m_name;
    this->m_stage = 0;
    this->m_ismarked =false;
}

bool FileManagerButton::getMarked()
{
    return this->m_ismarked;
}

void FileManagerButton::setMarked(bool mark)
{
    this->m_ismarked = mark;
}

void FileManagerButton::setStage(int index)
{
    this->m_stage = index;
}

const QString &FileManagerButton::getPath() const
{
    return m_path;
}

const QString &FileManagerButton::getName() const
{
    return m_name;
}

int FileManagerButton::getStage() const
{
    return m_stage;
}

int FileManagerButton::getMarked() const
{
    return this->m_ismarked;
}
