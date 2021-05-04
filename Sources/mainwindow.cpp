#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->runButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    QString port = ui->PortLine->text();
    bool isConnected = false;

    m_server = new TcpServer(this);
    if (m_server->startListening(port.toInt()))
        ui->ApplogList->addItem("Server started on port " + port + ".");
    else
        ui->ApplogList->addItem("Server failed. Please restart.");

    m_client1 = new TcpClient(this);
    if (m_client1->connectTo("localhost", port.toInt())) {
        ui->ApplogList->addItem("Client connected on port " + port + ".");
        isConnected = true;
    }
    else
        ui->ApplogList->addItem("Client failed to connect. Please restart.");

    connect(m_server,  &TcpServer::messageReceived, this, &MainWindow::onServerMessageReceived);

    ui->runButton->setEnabled(isConnected);
    ui->startButton->setEnabled(false);
}

void MainWindow::on_runButton_clicked()
{
    m_client1->sendMessage(ui->TextEditor->toPlainText()); //enviar al servidor
//    ui->RamList->addItem(ui->TextEditor->toPlainText()); // muestra lo que le envía al servidor

}

void MainWindow::onServerMessageReceived(QString message)
{
    std::string stdMessage = message.toUtf8().constData();
    std::vector<std::string::size_type> types = reader.find_type(stdMessage);
    QString a = QString::fromStdString("a");
    for (std::string::size_type i:types) {
//        std::string typei = types[i];
//        ui->StdoutList->addItem(QString::fromStdString());
        ui->StdoutList->addItem(a);
    }
    ui->StdoutList->addItem(message); // el servidor devuelve el resultado al cliente
}
