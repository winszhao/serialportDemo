#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_BtnOpen_clicked();
    void on_serialPort_readyRead();

    void on_BtnClose_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
};
#endif // MAINWINDOW_H
