#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    // Настройки для checkBox
    ui->radio_north->setChecked(true);
    ui->isTrajectory->setChecked(false);
    ui->isAcceleration->setChecked(false);
    ui->stop_btn->setEnabled(false);
    ui->reset_btn->setEnabled(false);

    // Расположение маятника по умолчанию
    scene->set_place(90);
    scene->render();

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
    // Ускорение Земли
    if (ui->isAcceleration->isChecked())
        scene->set_acceleration(true);
    else
        scene->set_acceleration(false);

    // Основные параметры
    if (ui->radio_north->isChecked())
        scene->set_place(90);
    else if (ui->radio_south->isChecked())
        scene->set_place(-90);
    else if (ui->radio_equator->isChecked())
        scene->set_place(0);

    // Блокировка элементов
    ui->isAcceleration->setEnabled(false);
    if (!ui->radio_north->isChecked())
        ui->radio_north->setEnabled(false);
    if (!ui->radio_south->isChecked())
        ui->radio_south->setEnabled(false);
    if (!ui->radio_equator->isChecked())
        ui->radio_equator->setEnabled(false);
    ui->start_btn->setEnabled(false);
    ui->stop_btn->setEnabled(true);
    ui->reset_btn->setEnabled(true);

    mode = on;

    scene->render();
}

void MainWindow::on_stop_btn_clicked()
{
    mode = off;
    ui->start_btn->setEnabled(true);
    ui->stop_btn->setEnabled(false);
}

void MainWindow::on_reset_btn_clicked()
{
    // Разблокировка элементов
    ui->isAcceleration->setEnabled(true);
    ui->radio_north->setEnabled(true);
    ui->radio_south->setEnabled(true);
    ui->radio_equator->setEnabled(true);
    ui->reset_btn->setEnabled(false);
    ui->start_btn->setEnabled(true);
    ui->stop_btn->setEnabled(false);

    mode = off;

    scene->reset_scene();

    // Расположение маятника по умолчанию
    scene->set_place(90);
    scene->render();
}

void MainWindow::on_isTrajectory_clicked()
{
    // Траектория
    if (ui->isTrajectory->isChecked())
        scene->set_trajectory(true);
    else
        scene->set_trajectory(false);
}
