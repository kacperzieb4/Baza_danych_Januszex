#include "displaywindow.h"

DisplayWindow::DisplayWindow(const std::vector<Person>& people, QWidget* parent) :
    QWidget(parent),
    layout(new QVBoxLayout(this)),
    scrollArea(new QScrollArea(this)),
    scrollWidget(new QWidget()),
    scrollLayout(new QVBoxLayout(scrollWidget)),
    backButton(new QPushButton("Powrót do strony głównej", this))
{
    int index = 1;
    for (const auto& person : people) {
        QString personInfo = QString("%1. Nazwa użytkownika: %2\nImię i Nazwisko: %3 %4\nData urodzenia: %5-%6-%7\nAdres: %8 %9, %10\nKod pocztowy: %11\nWiek: %12\n\n")
            .arg(index++)
            .arg(QString::fromStdString(person.username))
            .arg(QString::fromStdString(person.firstName))
            .arg(QString::fromStdString(person.lastName))
            .arg(person.day)
            .arg(person.month)
            .arg(person.year)
            .arg(QString::fromStdString(person.street))
            .arg(QString::fromStdString(person.houseNumber))
            .arg(QString::fromStdString(person.city))
            .arg(QString::fromStdString(person.postalCode))
            .arg(person.calculateAge());
        QLabel* label = new QLabel(personInfo);
        scrollLayout->addWidget(label);
    }
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    layout->addWidget(scrollArea);
    layout->addWidget(backButton);
    setLayout(layout);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::white);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    setWindowTitle("Podgląd osób");
    resize(400, 300);
    connect(backButton, &QPushButton::clicked, this, &DisplayWindow::on_backButton_clicked);
}

void DisplayWindow::on_backButton_clicked(){
    close();
}