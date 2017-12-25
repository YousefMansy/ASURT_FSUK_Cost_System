#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <QString>
#include <QStandardItemModel>

class Assembly
{
public:
    Assembly(QString);

private:
    QString name;
    QStandardItemModel* partModel;
    QStandardItemModel* materialModel;
    QStandardItemModel* processModel;
    QStandardItemModel* fastenerModel;
    QStandardItemModel* toolingModel;
};

#endif // ASSEMBLY_H
