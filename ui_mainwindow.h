/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_place;
    QRadioButton *radio_north;
    QRadioButton *radio_south;
    QRadioButton *radio_Moscow;
    QRadioButton *radio_equator;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *start_btn;
    QPushButton *stop_btn;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(1500, 1000));
        MainWindow->setBaseSize(QSize(970, 725));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(800, 480));
        centralwidget->setMaximumSize(QSize(1000000, 1000000));
        centralwidget->setBaseSize(QSize(970, 725));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_place = new QLabel(centralwidget);
        label_place->setObjectName(QString::fromUtf8("label_place"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_place->setFont(font);

        verticalLayout->addWidget(label_place);

        radio_north = new QRadioButton(centralwidget);
        radio_north->setObjectName(QString::fromUtf8("radio_north"));
        QFont font1;
        font1.setPointSize(14);
        radio_north->setFont(font1);

        verticalLayout->addWidget(radio_north);

        radio_south = new QRadioButton(centralwidget);
        radio_south->setObjectName(QString::fromUtf8("radio_south"));
        radio_south->setFont(font1);

        verticalLayout->addWidget(radio_south);

        radio_Moscow = new QRadioButton(centralwidget);
        radio_Moscow->setObjectName(QString::fromUtf8("radio_Moscow"));
        radio_Moscow->setFont(font1);

        verticalLayout->addWidget(radio_Moscow);

        radio_equator = new QRadioButton(centralwidget);
        radio_equator->setObjectName(QString::fromUtf8("radio_equator"));
        radio_equator->setFont(font1);

        verticalLayout->addWidget(radio_equator);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(950, 934));
        graphicsView->setMaximumSize(QSize(950, 934));
        graphicsView->setBaseSize(QSize(710, 710));

        gridLayout->addWidget(graphicsView, 0, 2, 4, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        start_btn = new QPushButton(centralwidget);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));
        start_btn->setMinimumSize(QSize(187, 70));
        start_btn->setMaximumSize(QSize(400, 400));
        start_btn->setFont(font1);

        verticalLayout_2->addWidget(start_btn);

        stop_btn = new QPushButton(centralwidget);
        stop_btn->setObjectName(QString::fromUtf8("stop_btn"));
        stop_btn->setMinimumSize(QSize(187, 70));
        stop_btn->setMaximumSize(QSize(400, 400));
        stop_btn->setFont(font1);

        verticalLayout_2->addWidget(stop_btn);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 2, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_5, 4, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272 \320\244\321\203\320\272\320\276", nullptr));
        label_place->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\274\320\260\321\217\321\202\320\275\320\270\320\272\320\260", nullptr));
        radio_north->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\262\320\265\321\200\320\275\321\213\320\271 \320\277\320\276\320\273\321\216\321\201", nullptr));
        radio_south->setText(QCoreApplication::translate("MainWindow", "\320\256\320\266\320\275\321\213\320\271 \320\277\320\276\320\273\321\216\321\201", nullptr));
        radio_Moscow->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        radio_equator->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\320\262\320\260\321\202\320\276\321\200", nullptr));
        start_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
        stop_btn->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
