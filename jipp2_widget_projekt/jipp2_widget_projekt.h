#ifndef JIPP2_WIDGET_PROJEKT_H
#define JIPP2_WIDGET_PROJEKT_H

#include <QMainWindow>
#include "database.h"
#include "displaywindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_addPersonButton_clicked();
    void on_deletePersonButton_clicked();
    void on_displayPeopleButton_clicked();
    void on_sortByLastNameButton_clicked();
    void on_sortByAgeButton_clicked();
    void on_saveAndExitButton_clicked();

private:
    Ui::MainWindow* ui;
    Database db;
    DisplayWindow* displayWindow;

    bool validateName(const std::string& name);
    bool validateDate(int day, int month, int year);
};

#endif // JIPP2_WIDGET_PROJEKT_H
