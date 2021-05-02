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

//    m_client2 = new TcpClient(this);
//    if (m_client2->connectTo("localhost", 21579))
//        ui->lstClient2->addItem("Connected.");
//    else
//        ui->lstClient2->addItem("Failed to connect.");

    connect(m_server,  &TcpServer::messageReceived, this, &MainWindow::onServerMessageReceived);
    connect(m_client1, &TcpClient::messageReceived, this, &MainWindow::onClientMessageReceived);
//    connect(m_client2, &TcpClient::messageReceived, this, &NetSndRcv::onClient2MessageReceived);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{
    m_client1->sendMessage(ui->TextEditor->toPlainText()); //enviar al servidor
    ui->StdoutList->addItem(ui->TextEditor->toPlainText());
//    ui->StdoutBrowser->addItem(ui->StdoutBrowser->text());
}

void MainWindow::onClientMessageReceived(QString message)
{
    ui->StdoutList->addItem(message);
}

void MainWindow::onServerMessageReceived(QString message)
{
    ui->StdoutList->addItem(message);
}
