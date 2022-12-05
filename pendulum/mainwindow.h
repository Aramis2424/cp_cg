#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "scene.hpp"
#include "sphere.hpp"
#include "placment.hpp"

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

private:
    FP::scene::Scene *scene;
    QGraphicsLineItem *line;

    state_t mode;
    Placment p;

private:
    Ui::MainWindow *ui;

    QTimer* timer;
};
#endif // MAINWINDOW_H
