//
// Created by James Conway on 12/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CoffeeInput.h" resolved

#include <QStackedWidget>
#include "coffeeinput.h"
#include "ui_CoffeeInput.h"
#include "mainwindow.h"


CoffeeInput::CoffeeInput(QWidget *parent) :
        QWidget(parent), ui(new Ui::CoffeeInput) {
    ui->setupUi(this);
}

CoffeeInput::~CoffeeInput() {
    delete ui;
}

void CoffeeInput::nextPage() {
    auto *parent = qobject_cast<QStackedWidget *>(parentWidget());
    if (parent) {
        auto *mainWindow = qobject_cast<MainWindow *>(window());
        if (mainWindow) {
            mainWindow->setup.addMeasurement(ui->inputGrindWeight->value(), ui->inputExtractionTime->value());
            parent->setCurrentIndex(parent->currentIndex() + 1);
        }
    }
}
