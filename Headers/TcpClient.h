//
// Created by mavros on 30/4/21.
//

#ifndef C_TEXT_EDITOR_TCPCLIENT_H
#define C_TEXT_EDITOR_TCPCLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QString>


class TcpClient : public QObject{
    Q_OBJECT

private:
    /**
     * Conexión entre el server y el socket
     */
    QTcpSocket *m_socket;
    /**
     * Tamaño del mensaje
     */
    quint16 m_blockSize = 0;
    /**
     * Verifica si es válido
     */
    bool m_isValid;

public:
    /**
     * Se crea el cliente junto con el socket
     * @param parent Hereda de QObject
     */
    explicit TcpClient(QObject *parent = nullptr);    /// para uso del cliente
    /**
     * Crea un cliente aceptando un socket
     * @param parent Hereda de QObject
     * @param socket Socket heredado
     */
    TcpClient(QObject *parent, QTcpSocket *socket);   /// para uso del cliente
    /**
     * Verifica si el cliente es válido
     * @return booleano
     */
    const bool &isValid();
    /**
     * Envía un mensaje al server
     * @param message
     */
    void sendMessage(QString message);
    /**
     * Busca un server a conectar
     * @param host Dirección IP del server anfitrión
     * @param port Número del puerto donde está conectado el server
     * @return
     */
    bool connectTo(QString host, quint16 port);

signals:
    /**
     * Confirma que el mensaje ha sido recibido
     * @param message
     */
    void messageReceived(QString message);

private slots:
    /**
     * Procesa los datos que recibe del cliente
     */
    void onReadyRead();
    /**
     * Desconecta el cliente
     */
    void onDisconnected();

};


#endif //C_TEXT_EDITOR_TCPCLIENT_H
