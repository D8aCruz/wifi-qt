#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(mSocket);
        ui->listWidget->addItem(T.readAll());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enviar(const QString &mensaje)
{
    QTextStream T(mSocket);
    T << mensaje;
    mSocket->flush();
}


void MainWindow::on_conectarButton_clicked()
{
    mSocket->connectToHost(ui->lineEdit_IP->text(),(quint16)ui->spinBox_puerto->value());
    ui->lineEdit_IP->setDisabled(true);
    ui->spinBox_puerto->setDisabled(true);
    ui->line_texto->setEnabled(true);
    ui->EnviarButton->setEnabled(true);
    ui->conectarButton->setDisabled(true);
    ui->desconectarButton->setEnabled(true);
}

void MainWindow::on_salirButton_clicked()
{
    close();
}

void MainWindow::on_desconectarButton_clicked()
{
    mSocket->close();
    ui->lineEdit_IP->setEnabled(true);
    ui->spinBox_puerto->setEnabled(true);
    ui->line_texto->setDisabled(true);
    ui->EnviarButton->setDisabled(true);
    ui->conectarButton->setEnabled(true);
    ui->desconectarButton->setDisabled(true);
}

void MainWindow::on_EnviarButton_clicked()
{
    enviar(ui->line_texto->text());
    ui->line_texto->clear();
}
