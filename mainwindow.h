#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xlsxdocument.h"
#include <QDebug>
#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_systemComboBox_currentIndexChanged(int);
    void on_assemblyComboBox_currentIndexChanged(QString);

private:
    Ui::MainWindow *ui;
    void initQBoxItems();
    void initAssemblyData();
    QStandardItemModel
        *brakesAssmQBoxModel,
        *engineAssmQBoxModel,
        *frameAssmQBoxModel,
        *instrumentsAssmQBoxModel,
        *miscAssmQBoxModel,
        *steeringAssmQBoxModel,
        *suspensionAssmQBoxModel,
        *wheelsAssmQBoxModel;

    struct assembly{
        QString name;
        QStandardItemModel* part;
        QStandardItemModel* material;
        QStandardItemModel* process;
        QStandardItemModel* fastener;
        QStandardItemModel* tooling;
    };

    struct system{
        QString prefix;
        int noOfAssemblies;
        QList<assembly>* assemblies;
    };

    QList<system> systems;

    QStandardItemModel
        *brakeAssmebliesPartData[4],
        *brakeAssmebliesMaterialData[4],
        *brakeAssmebliesProcessData[4],
        *brakeAssmebliesFastenerData[4],
        *brakeAssmebliesToolingData[4],
        *engineAssembliesPartData[9],
        *engineAssmebliesMaterialData[9],
        *engineAssmebliesProcessData[9],
        *engineAssmebliesFastenerData[9],
        *engineAssmebliesToolingData[9],
        *frameAssembliesPartData[6],
        *frameAssmebliesMaterialData[6],
        *frameAssmebliesProcessData[6],
        *frameAssmebliesFastenerData[6],
        *frameAssmebliesToolingData[6],
        *instrumentsAssembliesPartData[9],
        *instrumentsAssmebliesMaterialData[9],
        *instrumentsAssmebliesProcessData[9],
        *instrumentsAssmebliesFastenerData[9],
        *instrumentsAssmebliesToolingData[9],
        *miscAssembliesPartData[6],
        *miscAssmebliesMaterialData[6],
        *miscAssmebliesProcessData[6],
        *miscAssmebliesFastenerData[6],
        *miscAssmebliesToolingData[6],
        *steeringAssembliesPartData[4],
        *steeringAssmebliesMaterialData[4],
        *steeringAssmebliesProcessData[4],
        *steeringAssmebliesFastenerData[4],
        *steeringAssmebliesToolingData[4],
        *suspensionAssembliesPartData[10],
        *suspensionAssmebliesMaterialData[10],
        *suspensionAssmebliesProcessData[10],
        *suspensionAssmebliesFastenerData[10],
        *suspensionAssmebliesToolingData[10],
        *wheelsAssembliesPartData[3],
        *wheelsAssmebliesMaterialData[3],
        *wheelsAssmebliesProcessData[3],
        *wheelsAssmebliesFastenerData[3],
        *wheelsAssmebliesToolingData[3];
    void updatePartTable(QString);
    void updateMaterialTable(QString);
    void updateProcessTable(QString);
    void updateFastenersTable(QString);
    void updateToolingTable(QString);
};

#endif // MAINWINDOW_H
