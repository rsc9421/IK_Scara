#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include <QMainWindow>
#include<QMouseEvent>
#include<math.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void cinematica_inversa(double x2, double y2, double* paso1,double* paso2, double* paso3, double* paso4)//funcion que recibe el punto (x,y) y devuelve los pasos de los 2 motores para llegar a ese punto
         {
          double hip,alfa,beta,gama,angL1,angL2;//angL1 y angL2 en sentido anti horario
          uint32_t L1=100,L2=100;//longitudes de cada brazo, tienen que ser iguales
          double angL1R,angL2R,d,D,theta,i,j,newx,newy;
          //angL1R y angL2R en sentido horario,
          //d y D https://www.universoformulas.com/matematicas/geometria/rombo/
          //i y j son los valores del pto K del eje rotado
          //newx y newy son los valores del pto K respeto del eje rotado
          hip=sqrt((x2*x2) + (y2*y2));
          alfa=atan2(y2,x2)*180.0 / 3.1415;
          beta=acos((L1*L1) - (L2*L2) +(hip*hip) / (2 * L1 * hip))*180.0 / 3.1415;
          angL1=alfa+beta;
          gama=acos(((L1*L1)+(L2*L2)-(hip*hip))/(2*L1*L2))*180.0 / 3.1415 ;
          angL2=gama;
    //valido para scaras tipo nachi, sumarle 180 o 360 a los angulos finales(ver)
              d=hip;
              D=sqrt(4*(L1*L1)-(d*d));
              i=d/2.0;
              j=(D/2.0)*-1;
              newx=(i*cos(atan2(y2,x2)))-(j*sin(atan2(y2,x2)));
              newy=(i*sin(atan2(y2,x2)))+(j*cos(atan2(y2,x2)));
              angL1R=atan2(newy,newx)*180.0 / 3.1415;
              angL2R=angL2*-1;
              angL2R=angL2R+360.0;//esto no hace falta en los scaras que se mueven 360ºcomo los nacni
          *paso3=angL1R;
          *paso4=angL2R;
         // }
          //cinematica en sentido antihorario
            *paso1 =angL1;//pasos que tiene que dar el motor 1
            *paso2 =(angL2);//pasos que tiene que dar el motor 2
          }

    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    int centrox=200,centroy=200;
    double posx=0,posy=0;

private slots:
    void on_spinBox_valueChanged(const QString &arg1);
    void on_spinBox_2_valueChanged(const QString &arg1);
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_radioButton_3_clicked();
    void on_spinBox_3_valueChanged(const QString &arg1);
    void on_spinBox_4_valueChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
