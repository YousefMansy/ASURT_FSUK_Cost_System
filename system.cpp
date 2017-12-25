#include "system.h"
#include <QString>
#include <QList>

System::System(QString name, QString prefix, int numOfAssemblies){
    this->name = name;
    this->prefix = prefix;
    this->numOfAssemblies = numOfAssemblies;
    QBoxItemsModel = new QStandardItemModel();
    initAssemblies();
}

void System::initAssemblies(){
    for(int i=0;i<numOfAssemblies;i++){
//        assemblies.append(new QStandardItem(QString()));
    }
}

void System::addAssembly(Assembly assembly){
    numOfAssemblies++;
    assemblies.append(assembly);
    QBoxItemsModel->setItem(0, new QStandardItem(QString(prefix + "-A" + numOfAssemblies)));
}

QStandardItemModel* System::getQBoxItemsModel(){
    return QBoxItemsModel;
}
