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
Подобрать цвета плитки
Поменять скорость при ускорении
убрать лишние headers
FPS какой вариант лучше

    <<<<===--- Troubles ---===>>>>
Стало слабым отражение на плоскости

*/
