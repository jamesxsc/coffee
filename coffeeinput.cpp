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

void CoffeeInput::showEvent(QShowEvent *event) {
    auto *mainWindow = qobject_cast<MainWindow *>(window());
    if (mainWindow) {
        CoffeeSetup setup = mainWindow->setup;
        double currentFineCoarse = setup.settings.back().fineCoarse;
        double currentGrindTime = setup.settings.back().grindTime;

        ui->tipFineCoarse->setText(QString("Fine/coarse should be set to %1").arg(currentFineCoarse));
        ui->tipGrindTime->setText(QString("Grind time should be set to %1").arg(currentGrindTime));
    }
}

// this widget and SettingsUpdate switch from one to the other
void CoffeeInput::nextPage() {
    auto *parent = qobject_cast<QStackedWidget *>(parentWidget());
    if (parent) {
        auto *mainWindow = qobject_cast<MainWindow *>(window());
        if (mainWindow) {
            mainWindow->setup.addMeasurement(ui->inputGrindWeight->value(), ui->inputExtractionTime->value());
            parent->setCurrentIndex(parent->currentIndex() + 1);
            mainWindow->updateTable();
        }
    }
}
