#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene.hpp"
#include "constants.hpp"
#include "sphere.hpp"

#include "color.hpp"

#include "vector.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // settings of scene
    scene = new FP::scene::Scene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    // Smoothing
    ui->graphicsView->setRenderHints(QPainter::Antialiasing |
                                     QPainter::SmoothPixmapTransform);
    scene->setSceneRect(0, 0, 1, 1);

    //Time and FPS
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(start_render()));
    timer->start(FPS60);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_render()
{
    if (mode == on)
        scene->render();
}

void MainWindow::on_start_btn_clicked()
{
    mode = on;

    scene->render();


//    FP::color::Color color;
//    color.set(255, 40, 60);
//    QPen line_color(color);
//    scene->draw_pix(0, 0, color);
//    std::cout << width() << std::endl;
//    std::cout << height() << std::endl;
//    line = scene->addLine(0, 0, 510, 510, line_color);

}


void MainWindow::on_stop_btn_clicked()
{
    mode = off;
}

