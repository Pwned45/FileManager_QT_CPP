#ifndef FILEMANAGERBUTTON_H
#define FILEMANAGERBUTTON_H

#include <QString>



class FileManagerButton
{
public:
    FileManagerButton(QString m_path,QString m_name,int m_stage,bool m_ismarked);
    FileManagerButton(QString m_path,QString m_name);
    bool getMarked();
    void setMarked(bool mark);
    void setStage(int index);

    const QString &getPath() const;

    const QString &getName() const;

    int getStage() const;

    int getMarked() const;


private:
    QString m_path;
    QString m_name;
    int m_stage;// 0 - root, 1 - start, 2 - can't delete
    bool m_ismarked;
};

#endif // FILEMANAGERBUTTON_H
