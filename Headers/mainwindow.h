#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "TcpServer.h"
#include "TcpClient.h"
#include "Reader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    /**
     * Estructura de la ventana principal especificada en el archivo .ui
     */
    Ui::MainWindow *ui;
    /**
     * Objeto server de QT
     */
    TcpServer *m_server;
    /**
     * Objeto cliente de QT
     */
    TcpClient *m_client1;
    /**
     * Lee e interpreta strings que vienen del editor
     */
    Reader *read = new Reader();

public:
    /**
     * Crea la interfaz de la ventana principal del IDE
     * @param parent Widget de QT
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * Elimina la ventana
     */
    ~MainWindow();

private slots:
    /**
     * Función asignara al botón "OK" que define el puerto donde se conecta el IDE y la memoria a utilizar en el editor.
     */
    void on_startButton_clicked();
    /**
     * Función asignada al botón "Run" que envía el código al editor de texto para compilarla en el server
     */
    void on_runButton_clicked();
    /**
     * Función donde el server recibe el mensaje del cliente y lo altera en el reader
     * @param message Mensaje a modificar
     */
    void onServerMessageReceived(QString message);
};
#endif // MAINWINDOW_H
