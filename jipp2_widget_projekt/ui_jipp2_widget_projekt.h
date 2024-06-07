/********************************************************************************
** Form generated from reading UI file 'jipp2_widget_projekt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget* centralwidget;
    QVBoxLayout* verticalLayout;
    QPushButton* addPersonButton;
    QPushButton* deletePersonButton;
    QPushButton* displayPeopleButton;
    QPushButton* sortByLastNameButton;
    QPushButton* sortByAgeButton;
    QPushButton* saveAndExitButton;

    void setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addPersonButton = new QPushButton(centralwidget);
        addPersonButton->setObjectName(QString::fromUtf8("addPersonButton"));

        verticalLayout->addWidget(addPersonButton);

        deletePersonButton = new QPushButton(centralwidget);
        deletePersonButton->setObjectName(QString::fromUtf8("deletePersonButton"));

        verticalLayout->addWidget(deletePersonButton);

        displayPeopleButton = new QPushButton(centralwidget);
        displayPeopleButton->setObjectName(QString::fromUtf8("displayPeopleButton"));

        verticalLayout->addWidget(displayPeopleButton);

        sortByLastNameButton = new QPushButton(centralwidget);
        sortByLastNameButton->setObjectName(QString::fromUtf8("sortByLastNameButton"));

        verticalLayout->addWidget(sortByLastNameButton);

        sortByAgeButton = new QPushButton(centralwidget);
        sortByAgeButton->setObjectName(QString::fromUtf8("sortByAgeButton"));

        verticalLayout->addWidget(sortByAgeButton);

        saveAndExitButton = new QPushButton(centralwidget);
        saveAndExitButton->setObjectName(QString::fromUtf8("saveAndExitButton"));

        verticalLayout->addWidget(saveAndExitButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }

    void retranslateUi(QMainWindow* MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Baza danych Januszex", nullptr));
        addPersonButton->setText(QCoreApplication::translate("MainWindow", "Dodaj osobę", nullptr));
        deletePersonButton->setText(QCoreApplication::translate("MainWindow", "Usuń osobę", nullptr));
        displayPeopleButton->setText(QCoreApplication::translate("MainWindow", "Wyświetl ludzi", nullptr));
        sortByLastNameButton->setText(QCoreApplication::translate("MainWindow", "Sortuj po nazwisku", nullptr));
        sortByAgeButton->setText(QCoreApplication::translate("MainWindow", "Sortuj po wieku", nullptr));
        saveAndExitButton->setText(QCoreApplication::translate("MainWindow", "Zapisz i zamknij", nullptr));
    }

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
}

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
