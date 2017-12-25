#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initQBoxItems();
    initAssemblyData();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_systemComboBox_currentIndexChanged(int systemIndex)
{
    switch(systemIndex){
        case 0:
            ui->assemblyComboBox->setModel(brakesAssmQBoxModel);
            break;
        case 1:
            ui->assemblyComboBox->setModel(engineAssmQBoxModel);
            break;
        case 2:
            ui->assemblyComboBox->setModel(frameAssmQBoxModel);
            break;
        case 3:
            ui->assemblyComboBox->setModel(instrumentsAssmQBoxModel);
            break;
        case 4:
            ui->assemblyComboBox->setModel(miscAssmQBoxModel);
            break;
        case 5:
            ui->assemblyComboBox->setModel(steeringAssmQBoxModel);
            break;
        case 6:
            ui->assemblyComboBox->setModel(suspensionAssmQBoxModel);
            break;
        case 7:
            ui->assemblyComboBox->setModel(wheelsAssmQBoxModel);
            break;
    }

}

void MainWindow::on_assemblyComboBox_currentIndexChanged(QString assemblyName)
{
    updatePartTable(assemblyName);
    updateMaterialTable(assemblyName);
    updateProcessTable(assemblyName);
    updateFastenersTable(assemblyName);
    updateToolingTable(assemblyName);
}

void MainWindow::initQBoxItems()
{
    brakesAssmQBoxModel = new QStandardItemModel();
    brakesAssmQBoxModel->setItem(0, new QStandardItem(QString("BR-A01")));
    brakesAssmQBoxModel->setItem(1, new QStandardItem(QString("BR-A02")));
    brakesAssmQBoxModel->setItem(2, new QStandardItem(QString("BR-A03")));
    brakesAssmQBoxModel->setItem(3, new QStandardItem(QString("BR-A04")));
    engineAssmQBoxModel = new QStandardItemModel();
    engineAssmQBoxModel->setItem(0, new QStandardItem(QString("EN-A01")));
    engineAssmQBoxModel->setItem(1, new QStandardItem(QString("EN-A02")));
    engineAssmQBoxModel->setItem(2, new QStandardItem(QString("EN-A03")));
    engineAssmQBoxModel->setItem(3, new QStandardItem(QString("EN-A04")));
    engineAssmQBoxModel->setItem(4, new QStandardItem(QString("EN-A05")));
    engineAssmQBoxModel->setItem(5, new QStandardItem(QString("EN-A06")));
    engineAssmQBoxModel->setItem(6, new QStandardItem(QString("EN-A07")));
    engineAssmQBoxModel->setItem(7, new QStandardItem(QString("EN-A08")));
    engineAssmQBoxModel->setItem(8, new QStandardItem(QString("EN-A09")));
    frameAssmQBoxModel = new QStandardItemModel();
    frameAssmQBoxModel->setItem(0, new QStandardItem(QString("FR-AO1")));
    frameAssmQBoxModel->setItem(1, new QStandardItem(QString("FR-AO2")));
    frameAssmQBoxModel->setItem(2, new QStandardItem(QString("FR-AO3")));
    frameAssmQBoxModel->setItem(3, new QStandardItem(QString("FR-AO4")));
    frameAssmQBoxModel->setItem(4, new QStandardItem(QString("FR-AO5")));
    frameAssmQBoxModel->setItem(5, new QStandardItem(QString("FR-AO6")));
    instrumentsAssmQBoxModel = new QStandardItemModel();
    instrumentsAssmQBoxModel->setItem(0, new QStandardItem(QString("EL-AO1")));
    instrumentsAssmQBoxModel->setItem(1, new QStandardItem(QString("EL-AO2")));
    instrumentsAssmQBoxModel->setItem(2, new QStandardItem(QString("EL-AO3")));
    instrumentsAssmQBoxModel->setItem(3, new QStandardItem(QString("EL-AO4")));
    instrumentsAssmQBoxModel->setItem(4, new QStandardItem(QString("EL-AO5")));
    instrumentsAssmQBoxModel->setItem(5, new QStandardItem(QString("EL-AO6")));
    instrumentsAssmQBoxModel->setItem(6, new QStandardItem(QString("EL-AO7")));
    instrumentsAssmQBoxModel->setItem(7, new QStandardItem(QString("EL-AO8")));
    instrumentsAssmQBoxModel->setItem(8, new QStandardItem(QString("EL-AO9")));
    miscAssmQBoxModel = new QStandardItemModel();
    miscAssmQBoxModel->setItem(0, new QStandardItem(QString("MS-A01")));
    miscAssmQBoxModel->setItem(1, new QStandardItem(QString("MS-A02")));
    miscAssmQBoxModel->setItem(2, new QStandardItem(QString("MS-A03")));
    miscAssmQBoxModel->setItem(3, new QStandardItem(QString("MS-A04")));
    miscAssmQBoxModel->setItem(4, new QStandardItem(QString("MS-A05")));
    miscAssmQBoxModel->setItem(5, new QStandardItem(QString("MS-A06")));
    steeringAssmQBoxModel = new QStandardItemModel();
    steeringAssmQBoxModel->setItem(0, new QStandardItem(QString("ST-A01")));
    steeringAssmQBoxModel->setItem(1, new QStandardItem(QString("ST-A02")));
    steeringAssmQBoxModel->setItem(2, new QStandardItem(QString("ST-A03")));
    steeringAssmQBoxModel->setItem(3, new QStandardItem(QString("ST-A04")));
    suspensionAssmQBoxModel = new QStandardItemModel();
    suspensionAssmQBoxModel->setItem(0, new QStandardItem(QString("SU-A01")));
    suspensionAssmQBoxModel->setItem(1, new QStandardItem(QString("SU-A02")));
    suspensionAssmQBoxModel->setItem(2, new QStandardItem(QString("SU-A03")));
    suspensionAssmQBoxModel->setItem(3, new QStandardItem(QString("SU-A04")));
    suspensionAssmQBoxModel->setItem(4, new QStandardItem(QString("SU-A05")));
    suspensionAssmQBoxModel->setItem(5, new QStandardItem(QString("SU-A06")));
    suspensionAssmQBoxModel->setItem(6, new QStandardItem(QString("SU-A07")));
    suspensionAssmQBoxModel->setItem(7, new QStandardItem(QString("SU-A08")));
    suspensionAssmQBoxModel->setItem(8, new QStandardItem(QString("SU-A09")));
    suspensionAssmQBoxModel->setItem(9, new QStandardItem(QString("SU-A10")));
    suspensionAssmQBoxModel->setItem(10, new QStandardItem(QString("SU-A11")));
    wheelsAssmQBoxModel = new QStandardItemModel();
    wheelsAssmQBoxModel->setItem(0, new QStandardItem(QString("WT-A01")));
    wheelsAssmQBoxModel->setItem(1, new QStandardItem(QString("WT-A02")));
    wheelsAssmQBoxModel->setItem(2, new QStandardItem(QString("WT-A03")));
}

void MainWindow::initAssemblyData()
{
    system Brakes;
    Brakes.noOfAssemblies=4;
    Brakes.prefix = "BR";
    systems.append(Brakes);

    system Engine;
    Engine.noOfAssemblies=9;
    Engine.prefix = "EN";
    systems.append(Engine);

    system Frame;
    Frame.noOfAssemblies=6;
    Frame.prefix = "FR";
    systems.append(Frame);

    system Instruments;
    Instruments.noOfAssemblies=9;
    Instruments.prefix = "EL";
    systems.append(Instruments);

    system Misc;
    Misc.noOfAssemblies=6;
    Misc.prefix = "MS";
    systems.append(Misc);

    system Steering;
    Steering.noOfAssemblies=4;
    Steering.prefix = "ST";
    systems.append(Steering);

    system Suspension;
    Suspension.noOfAssemblies=10;
    Suspension.prefix = "SU";
    systems.append(Suspension);

    system Wheels;
    Wheels.noOfAssemblies=3;
    Wheels.prefix = "WT";
    systems.append(Wheels);

    for(int i=0;i<4;i++){
        brakeAssmebliesPartData[i] = new QStandardItemModel();
        brakeAssmebliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        brakeAssmebliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        brakeAssmebliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        brakeAssmebliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        brakeAssmebliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
        brakeAssmebliesMaterialData[i] = new QStandardItemModel();
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Item Order")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Material")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Unit Cost")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Size1")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Unit1")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Size2")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Unit2")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Area Name")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Area(mm)")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Length(mm)")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Density")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Quantity")));
        brakeAssmebliesMaterialData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<9;i++){
        engineAssembliesPartData[i] = new QStandardItemModel();
        engineAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        engineAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        engineAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        engineAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        engineAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<6;i++){
        frameAssembliesPartData[i] = new QStandardItemModel();
        frameAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        frameAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        frameAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        frameAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        frameAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<9;i++){
        instrumentsAssembliesPartData[i] = new QStandardItemModel();
        instrumentsAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        instrumentsAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        instrumentsAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        instrumentsAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        instrumentsAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<6;i++){
        miscAssembliesPartData[i] = new QStandardItemModel();
        miscAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        miscAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        miscAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        miscAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        miscAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<4;i++){
        steeringAssembliesPartData[i] = new QStandardItemModel();
        steeringAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        steeringAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        steeringAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        steeringAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        steeringAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<10;i++){
        suspensionAssembliesPartData[i] = new QStandardItemModel();
        suspensionAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        suspensionAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        suspensionAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        suspensionAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        suspensionAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    for(int i=0;i<3;i++){
        wheelsAssembliesPartData[i] = new QStandardItemModel();
        wheelsAssembliesPartData[i]->setHorizontalHeaderItem(0, new QStandardItem(QString("Item Order")));
        wheelsAssembliesPartData[i]->setHorizontalHeaderItem(1, new QStandardItem(QString("Part")));
        wheelsAssembliesPartData[i]->setHorizontalHeaderItem(2, new QStandardItem(QString("Part Cost")));
        wheelsAssembliesPartData[i]->setHorizontalHeaderItem(3, new QStandardItem(QString("Quantity")));
        wheelsAssembliesPartData[i]->setHorizontalHeaderItem(4, new QStandardItem(QString("Subtotal")));
    }
    ui->partTableView->setModel(brakeAssmebliesPartData[0]);
}

void MainWindow::updatePartTable(QString assemblyName)
{

}

void MainWindow::updateMaterialTable(QString assemblyName)
{

}

void MainWindow::updateProcessTable(QString assemblyName)
{

}

void MainWindow::updateFastenersTable(QString assemblyName)
{

}

void MainWindow::updateToolingTable(QString assemblyName)
{

}

//void MainWindow::on_pushButton_clicked()
//{
//    QXlsx::Document xlsx("/home/yuzo-san/Desktop/CostSystemBeta/Output/Test2.xlsx");
//    xlsx.write(ui->cell->text(), ui->value->text());
//    xlsx.save();
//    xlsx.saveAs("/home/yuzo-san/Desktop/CostSystemBeta/Output/Test2.xlsx");
//}
