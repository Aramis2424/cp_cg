// FP - foucault 's pendulum
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1500, 985);
    w.showMaximized();
    return a.exec();
}

/*
    <-;:. TODO .:;->
разобраться с пределами обработки пикселей в scene.cpp

    <<<<===--- Troubles ---===>>>>
Нет тени от второго источника
за шаром видны линии траектории

    <>=-<>=-:; Extra_material ;:-=<>-=<>
Sphere sphere(10, _width/2, _height/2, 0); // так было изначально
ui->graphicsView->setAlignment(Qt::AlignCenter); //Начало координат в центре холста

*/
