#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "person.h"

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindow(const std::vector<Person>& people, QWidget* parent = nullptr);

private slots:
    void on_backButton_clicked();

private:
    QVBoxLayout* layout;
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
    QVBoxLayout* scrollLayout;
    QPushButton* backButton; 
};

#endif // DISPLAYWINDOW_H
