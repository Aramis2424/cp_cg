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

    <<<<===--- Troubles ---===>>>>
Нет тени от второго источника
за шаром видны линии траектории
не работаеит isTrajectory
линии траектории на шаре
линии траектории не исчезают на втором круге


    <>=-<>=-:; Extra_material ;:-=<>-=<>

*/
