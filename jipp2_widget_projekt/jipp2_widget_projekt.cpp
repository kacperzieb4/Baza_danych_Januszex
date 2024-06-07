#include "jipp2_widget_projekt.h"
#include "ui_jipp2_widget_projekt.h"
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>
#include <regex>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , displayWindow(nullptr)
{
    ui->setupUi(this);
    db.loadFromFile();

    connect(ui->sortByLastNameButton, &QPushButton::clicked, this, &MainWindow::on_sortByLastNameButton_clicked);
    connect(ui->sortByAgeButton, &QPushButton::clicked, this, &MainWindow::on_sortByAgeButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::validateName(const std::string& name) {
    return !std::regex_search(name, std::regex("[0-9]"));
}

bool MainWindow::validateDate(int day, int month, int year) {
    time_t now = time(0);
    tm ltm = {};
    localtime_s(&ltm, &now);
    int currentYear = 1900 + ltm.tm_year;

    if (day < 1 || day > 31 || month < 1 || month > 12 || year >= currentYear) {
        return false;
    }
    return true;
}

void MainWindow::on_addPersonButton_clicked()
{
    Person p;
    bool ok;

    QString firstName = QInputDialog::getText(this, "Dodaj osobę", "Imię:", QLineEdit::Normal, "", &ok);
    if (ok && !validateName(firstName.toStdString())) {
        QMessageBox::warning(this, "Błąd wejścia", "Imię nie może zawierać cyfr!");
        return;
    }
    p.firstName = firstName.toStdString();

    QString lastName = QInputDialog::getText(this, "Dodaj osobę", "Nazwisko:", QLineEdit::Normal, "", &ok);
    if (ok && !validateName(lastName.toStdString())) {
        QMessageBox::warning(this, "Błąd wejścia", "Nazwisko nie może zawierać cyfr!");
        return;
    }
    p.lastName = lastName.toStdString();

    p.day = QInputDialog::getInt(this, "Dodaj osobę", "Dzień urodzenia (1-31):", 1, 1, 31, 1, &ok);
    p.month = QInputDialog::getInt(this, "Dodaj osobę", "Miesiąc urodzenia (1-12):", 1, 1, 12, 1, &ok);
    p.year = QInputDialog::getInt(this, "Dodaj osobę", "Rok urodzenia:", 1900, 1900, 2100, 1, &ok);

    if (!validateDate(p.day, p.month, p.year)) {
        QMessageBox::warning(this, "Błąd wejścia", "Nieprawidłowa data urodzenia!");
        return;
    }

    p.street = QInputDialog::getText(this, "Dodaj osobę", "Ulica:", QLineEdit::Normal, "", &ok).toStdString();
    p.houseNumber = QInputDialog::getText(this, "Dodaj osobę", "Numer domu:", QLineEdit::Normal, "", &ok).toStdString();
    p.city = QInputDialog::getText(this, "Dodaj osobę", "Miasto:", QLineEdit::Normal, "", &ok).toStdString();
    p.postalCode = QInputDialog::getText(this, "Dodaj osobę", "Kod pocztowy:", QLineEdit::Normal, "", &ok).toStdString(); // Dodanie kodu pocztowego

    db.addPerson(p);
    QMessageBox::information(this, "Sukces", "Dodano osobę: " + QString::fromStdString(p.firstName) + " " + QString::fromStdString(p.lastName));
}

void MainWindow::on_deletePersonButton_clicked()
{
    std::string username = QInputDialog::getText(this, "Usuń osobę", "Nazwa użytkownika:").toStdString();
    auto people = db.getPeople();
    auto it = std::find_if(people.begin(), people.end(), [&username](const Person& p) { return p.username == username; });
    if (it != people.end()) {
        db.deletePerson(username);
        QMessageBox::information(this, "Sukces", "Usunięto osobę z nazwą użytkownika: " + QString::fromStdString(username));
    }
    else {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono osoby z nazwą użytkownika: " + QString::fromStdString(username));
    }
}

void MainWindow::on_displayPeopleButton_clicked()
{
    if (displayWindow) {
        delete displayWindow;
    }
    displayWindow = new DisplayWindow(db.getPeople(), this);
    displayWindow->show();
}

void MainWindow::on_sortByLastNameButton_clicked()
{
    db.sortPeople(2);
    QMessageBox::information(this, "Sukces", "Posortowano osoby po nazwisku.");
}

void MainWindow::on_sortByAgeButton_clicked()
{
    db.sortPeople(3);
    QMessageBox::information(this, "Sukces", "Posortowano osoby po wieku.");
}

void MainWindow::on_saveAndExitButton_clicked()
{
    db.saveToFile();
    close();
}
