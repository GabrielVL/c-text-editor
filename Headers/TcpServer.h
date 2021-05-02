//
// Created by mavros on 30/4/21.
//

#ifndef C_TEXT_EDITOR_TCPSERVER_H
#define C_TEXT_EDITOR_TCPSERVER_H

#include <QObject>
#include "TcpClient.h"

class TcpServer : public QObject{
    Q_OBJECT
private:
    QTcpServer *m_server = nullptr;

    QSet<TcpClient*> m_connections;

public:
    TcpServer(QObject *parent = nullptr);

    bool startListening(const quint16 &port);

    void sendMessage(const QString &message);

signals:
    void messageReceived(const QString &message);

private slots:
    void onNewConnection();
    void onMessageReceived(QString message);  ///< all clients connected here

};


#endif //C_TEXT_EDITOR_TCPSERVER_H
