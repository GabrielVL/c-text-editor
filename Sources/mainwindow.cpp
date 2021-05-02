#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_server = new TcpServer(this);

    if (m_server->startListening(21579))
        ui->StdoutList->addItem("Server started.");
    else
        ui->StdoutList->addItem("Server failed to start.");

    m_client1 = new TcpClient(this);
    if (m_client1->connectTo("localhost", 21579))
        ui->StdoutList->addItem("Client connected.");
    else
        ui->StdoutList->addItem("Client failed to connect.");

    connect(m_server,  &TcpServer::messageReceived, this, &MainWindow::onServerMessageReceived);
//    connect(m_client1, &TcpClient::messageReceived, this, &MainWindow::onClientMessageReceived);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{
    m_client1->sendMessage(ui->TextEditor->toPlainText()); //enviar al servidor
    ui->RamList->addItem(ui->TextEditor->toPlainText()); // muestra lo que le envía al servidor
}

//void MainWindow::onClientMessageReceived(QString message)
//{
//    ui->RamList->addItem(message);
//}

void MainWindow::onServerMessageReceived(QString message)
{
    ui->StdoutList->addItem(message); // el servidor devuelve el resultado al cliente
}
