#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{
    QString data = ui->TextEditor->toPlainText();
    qDebug() << data;
}
