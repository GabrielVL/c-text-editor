//
// Created by mavros on 30/4/21.
//

#include <QByteArray>
#include <QDataStream>
#include "../Headers/TcpClient.h"


TcpClient::TcpClient(QObject *parent) :
        QObject(parent),
        m_socket(new QTcpSocket(this)),
        m_isValid(false)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
}

TcpClient::TcpClient(QObject *parent, QTcpSocket *socket) :
        QObject(parent),
        m_socket(socket),
        m_isValid(true)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
}

void TcpClient::onReadyRead()
{
    QDataStream receive(m_socket);
    receive.setVersion(QDataStream::Qt_4_0);

    if (m_blockSize == 0)  // on first call: only read the block size
    {
        if (m_socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        receive >> m_blockSize;
    }

    if (m_socket->bytesAvailable() < m_blockSize)   // Partial data received?
        return;

    // at this point: all data received, we can process it

    QString message;
    receive >> message;

    emit messageReceived(message);
    m_blockSize = 0;  // reset for next message
}

void TcpClient::onDisconnected()
{
    m_isValid = false;
    m_socket->deleteLater();
    m_socket = nullptr;
}

const bool &TcpClient::isValid()
{
    return m_isValid;
}

void TcpClient::sendMessage(QString message)
{
    QByteArray data;
    QDataStream dataStream(&data, QTcpSocket::WriteOnly);
    dataStream.setVersion(QDataStream::Qt_4_0);

    dataStream << (quint16)0;  // placeholder for blocksize
    dataStream << message;     // append the message
    dataStream.device()->seek(0);  // go back to beginning
    // overwrite placeholder with actual blocksize
    dataStream << (quint16)(data.size() - sizeof(quint16));

    m_socket->write(data);
}

bool TcpClient::connectTo(QString host, quint16 port)
{
    m_socket->connectToHost(host, port);
    m_isValid = m_socket->waitForConnected(5000);

    return m_isValid;
}