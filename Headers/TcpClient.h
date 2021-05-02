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
    QTcpSocket *m_socket;
    quint16 m_blockSize = 0;
    bool m_isValid;

public:
    explicit TcpClient(QObject *parent = nullptr);    ///< for client usage
    TcpClient(QObject *parent, QTcpSocket *socket);   ///< for server usage

    const bool &isValid();

    void sendMessage(QString message);
    bool connectTo(QString host, quint16 port);

signals:
    void messageReceived(QString message);

private slots:
    void onReadyRead();
    void onDisconnected();

};


#endif //C_TEXT_EDITOR_TCPCLIENT_H
