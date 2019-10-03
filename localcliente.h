#ifndef LOCALCLIENTE_H
#define LOCALCLIENTE_H

#include <QTcpSocket>

class LocalCliente : public QTcpSocket
{
    Q_OBJECT
public:
    explicit LocalCliente(QObject *parent = nullptr);
    void enviar(const QString &mensaje );
signals:

public slots:

private:
    QTcpSocket *mSocket;
};

#endif // LOCALCLIENTE_H
