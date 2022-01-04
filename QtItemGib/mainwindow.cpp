#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtDebug>
#include <QString>
#include <string>

#include "items.h"

int listLength = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for ( std::string item : itemArr)
    {
        ui->itemList->addItem(QString::fromStdString( item ));
        listLength++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_activated(const QModelIndex &index)
{}

void MainWindow::on_itemList_activated(const QModelIndex &index)
{
    qDebug() << "Activated " << ui->itemList->item(index.row())->text();
}

void MainWindow::on_itemFilter_textChanged()
{
    if (ui->itemFilter->toPlainText().length())
    {
        for (int i = 0; i < listLength; i++)
        {
            if (ui->itemList->item(i)->text().contains(ui->itemFilter->toPlainText()))
            {
                qDebug() << ui->itemList->item(i)->text();
            }
        }
    }

    //qDebug() << ui->itemList->item(0)->text().contains("and");
}
