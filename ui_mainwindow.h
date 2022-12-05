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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_place;
    QRadioButton *radio_north;
    QRadioButton *radio_equator;
    QRadioButton *radio_south;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *isAcceleration;
    QCheckBox *isTrajectory;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *start_btn;
    QPushButton *stop_btn;
    QPushButton *stop_btn_2;
    QGraphicsView *graphicsView;

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
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_place = new QLabel(centralwidget);
        label_place->setObjectName(QString::fromUtf8("label_place"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_place->setFont(font);

        verticalLayout->addWidget(label_place);

        radio_north = new QRadioButton(centralwidget);
        radio_north->setObjectName(QString::fromUtf8("radio_north"));
        QFont font1;
        font1.setPointSize(14);
        radio_north->setFont(font1);

        verticalLayout->addWidget(radio_north);

        radio_equator = new QRadioButton(centralwidget);
        radio_equator->setObjectName(QString::fromUtf8("radio_equator"));
        radio_equator->setFont(font1);

        verticalLayout->addWidget(radio_equator);

        radio_south = new QRadioButton(centralwidget);
        radio_south->setObjectName(QString::fromUtf8("radio_south"));
        radio_south->setFont(font1);

        verticalLayout->addWidget(radio_south);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        isAcceleration = new QCheckBox(centralwidget);
        isAcceleration->setObjectName(QString::fromUtf8("isAcceleration"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(14);
        isAcceleration->setFont(font2);

        verticalLayout_3->addWidget(isAcceleration);

        isTrajectory = new QCheckBox(centralwidget);
        isTrajectory->setObjectName(QString::fromUtf8("isTrajectory"));
        isTrajectory->setFont(font2);

        verticalLayout_3->addWidget(isTrajectory);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);

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

        stop_btn_2 = new QPushButton(centralwidget);
        stop_btn_2->setObjectName(QString::fromUtf8("stop_btn_2"));
        stop_btn_2->setMinimumSize(QSize(187, 70));
        stop_btn_2->setMaximumSize(QSize(400, 400));
        stop_btn_2->setFont(font1);

        verticalLayout_2->addWidget(stop_btn_2);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_4);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(950, 934));
        graphicsView->setMaximumSize(QSize(950, 934));
        graphicsView->setBaseSize(QSize(710, 710));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272 \320\244\321\203\320\272\320\276", nullptr));
        label_place->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\274\320\260\321\217\321\202\320\275\320\270\320\272\320\260", nullptr));
        radio_north->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\262\320\265\321\200\320\275\321\213\320\271 \320\277\320\276\320\273\321\216\321\201", nullptr));
        radio_equator->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\320\262\320\260\321\202\320\276\321\200", nullptr));
        radio_south->setText(QCoreApplication::translate("MainWindow", "\320\256\320\266\320\275\321\213\320\271 \320\277\320\276\320\273\321\216\321\201", nullptr));
        isAcceleration->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\320\272\320\276\321\200\320\270\321\202\321\214 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\227\320\265\320\274\320\273\320\270", nullptr));
        isTrajectory->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\202\321\200\320\260\320\265\320\272\321\202\320\276\321\200\320\270\321\216", nullptr));
        start_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
        stop_btn->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
        stop_btn_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
