#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "scene.hpp"
#include "sphere.hpp"

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
    void on_start_btn_clicked();
    void on_stop_btn_clicked();

    void start_render();

    void on_isTrajectory_clicked();

    void on_reset_btn_clicked();

private:
    FP::scene::Scene *scene;
    QGraphicsLineItem *line;

    state_t mode;

private:
    Ui::MainWindow *ui;

    QTimer* timer;
};
#endif // MAINWINDOW_H
