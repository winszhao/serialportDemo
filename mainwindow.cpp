#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //To do my work.
    //智能识别当前窗口下的有效串口号
    QList<QSerialPortInfo>serialPortinfo=QSerialPortInfo::availablePorts();
    //List<QSerialPortInfo> QSerialPortInfo::availablePorts()
    int count = serialPortinfo.count();
    for(int i = 0;i<count;i++){
        ui->CboxSerialPort->addItem(serialPortinfo.at(i).portName());
     //QSerialPort serialPort;
     serialPort.setPortName("com3");
     serialPort.setBaudRate(QSerialPort::Baud9600);
     serialPort.setParity(QSerialPort::NoParity);
     serialPort.setDataBits(QSerialPort::Data8);
     serialPort.setStopBits(QSerialPort::OneStop);
     serialPort.setFlowControl(QSerialPort::NoFlowControl);
     serialPort.open(QIODevice::ReadWrite);
     connect(&serialPort,SIGNAL(readyRead()),this,SLOT(on_serialPort_readyRead()));

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_BtnOpen_clicked()
{

}

void MainWindow::on_serialPort_readyRead()
{
    QByteArray recvData=serialPort.readAll();


    ui->TexitRecv->append(recvData.toHex());
}

void MainWindow::on_BtnClose_clicked()
{
    MainWindow::close();
}
