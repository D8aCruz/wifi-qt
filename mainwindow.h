#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void enviar(const QString &mensaje);
private slots:
    void on_conectarButton_clicked();

    void on_salirButton_clicked();

    void on_desconectarButton_clicked();

    void on_EnviarButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *mSocket;
};

#endif // MAINWINDOW_H
