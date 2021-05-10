//
// Created by mavros on 30/4/21.
//

#ifndef C_TEXT_EDITOR_TCPSERVER_H
#define C_TEXT_EDITOR_TCPSERVER_H

#include <QObject>
#include "TcpClient.h"

/**
 * Clase server que procesa los datos recibidos
 */
class TcpServer : public QObject{
    Q_OBJECT

private:

    /**
     * Objeto server de QT
     */
    QTcpServer *m_server = nullptr;

    /**
     * Conexiones establecidas con el cliente
     */
    QSet<TcpClient*> m_connections;

public:

    /**
     * Constructor del server
     * @param parent Hereda de QObject
     */
    TcpServer(QObject *parent = nullptr);

    /**
     * Destructor del server
     */
    virtual ~TcpServer();

    /**
     * Empieza a escuchar en el puerto que se asigna
     * @param port puerto a escuchar
     * @return booleano que confirma que está escuchando
     */
    bool startListening(const quint16 &port);

    /**
     * Sends a message to the client connected
     * @param message Message to send
     */
    void sendMessage(const QString &message);

signals:

    /**
     * Confirma que el mensaje ha sido recibido
     * @param message
     */
    void messageReceived(const QString &message);

private slots:

    /**
     * Acción que realiza al conectarse a un cliente
     */
    void onNewConnection();

    /**
     * Determina cómo reacciona el server al recibir un mensaje. Los clientes se conectan aquí.
     * @param message Mensaje recibido
     */
    void onMessageReceived(QString message);

};


#endif //C_TEXT_EDITOR_TCPSERVER_H
