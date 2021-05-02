//
// Created by mavros on 30/4/21.
//

#include "../Headers/TcpServer.h"

TcpServer::TcpServer(QObject *parent) :
        QObject(parent)
{
}

void TcpServer::onNewConnection()
{
    TcpClient *connection = new TcpClient(this, m_server->nextPendingConnection());
    m_connections.insert(connection);

    connect(connection, &TcpClient::messageReceived, this, &TcpServer::onMessageReceived);
}

bool TcpServer::startListening(const quint16 &port)
{
    bool isListening = false;

    if (! m_server)
    {
        m_server = new QTcpServer(this);
        isListening = m_server->listen(QHostAddress::AnyIPv4, port);

        if (isListening)
        {
            connect(m_server, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);
        }
    }

    return isListening;
}

void TcpServer::sendMessage(const QString &message)
{
            foreach (TcpClient *connection, m_connections)
        {
            if (connection->isValid())
                connection->sendMessage(message);
        }
}

void TcpServer::onMessageReceived(QString message)
{
    emit messageReceived(message);
}