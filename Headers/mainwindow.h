#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "TcpServer.h"
#include "TcpClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_runButton_clicked();

    void onServerMessageReceived(QString message);
//    void onClientMessageReceived(QString message);

private:
    Ui::MainWindow *ui;

    TcpServer *m_server;
    TcpClient *m_client1;
};
#endif // MAINWINDOW_H
