#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){

double ang1,ang2,ang3,ang4;
double gx,gy;
gx=100,gy=100;

cinematica_inversa(posx,posy,&ang1,&ang2,&ang3,&ang4);

    QPainter painter(this);

     painter.setPen(QPen(Qt::black,3));


QLineF angL1;
angL1.setP1(QPointF(centrox,centroy));
angL1.setAngle(ang1);angL1.setLength(100);

QLineF angL2;
angL2.setP1(angL1.p2());
angL2.setAngle(ang2+angL1.angle()-180);angL2.setLength(100);

painter.setPen(QPen(Qt::blue,3));
QLineF angL3;
angL3.setP1(QPointF(centrox,centroy));
angL3.setAngle(ang3);angL3.setLength(100);

QLineF angL4;
angL4.setP1(angL3.p2());
angL4.setAngle(ang4+angL3.angle()-180);angL4.setLength(100);

if(ui->radioButton->isChecked() || ui->radioButton_2->isChecked()){
    painter.drawLine(angL1);
    painter.drawLine(angL2);
}
if(ui->radioButton_2->isChecked() || ui->radioButton_3->isChecked()){
    painter.drawLine(angL3);
    painter.drawLine(angL4);
}

painter.setPen(QPen(Qt::red,3));
painter.drawEllipse(QPointF(centrox,centroy),200,200);

}

void MainWindow::mousePressEvent(QMouseEvent *e){
    if(e->buttons() == Qt::LeftButton){
        posx=e->pos().x()-centrox;
        posy=centroy-e->pos().y();
ui->spinBox_3->setValue(posx);
ui->spinBox_4->setValue(posy);
update();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *e){
    if(e->buttons() == Qt::LeftButton){
        posx=e->pos().x()-centrox;
        posy=centroy-e->pos().y();
ui->spinBox_3->setValue(posx);
ui->spinBox_4->setValue(posy);
update();
    }

}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{


}

void MainWindow::on_spinBox_2_valueChanged(const QString &arg1)
{

}

void MainWindow::on_radioButton_2_clicked()
{
    update();
}

void MainWindow::on_radioButton_clicked()
{
    update();
}

void MainWindow::on_radioButton_3_clicked()
{
        update();
}

void MainWindow::on_spinBox_3_valueChanged(const QString &arg1)
{
    posx=ui->spinBox_3->value();
update();
}

void MainWindow::on_spinBox_4_valueChanged(const QString &arg1)
{
    posy=ui->spinBox_4->value();
update();
}
