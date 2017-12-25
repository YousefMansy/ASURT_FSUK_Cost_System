#ifndef SYSTEM_H
#define SYSTEM_H

#include <QList>
#include <QString>
#include <QStandardItemModel>
#include <assembly.h>

class System{

public:
    System(QString, QString, int);
    void addAssembly(Assembly);
    QStandardItemModel* getQBoxItemsModel();
    void initAssemblies();

private:
    QString name, prefix;
    int numOfAssemblies;
    QList<Assembly> assemblies;
    QStandardItemModel* QBoxItemsModel;

};

#endif // SYSTEM_H
