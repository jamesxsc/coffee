//
// Created by James Conway on 13/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SettingsUpdate.h" resolved

#include "settingsupdate.h"
#include "ui_SettingsUpdate.h"
#include "coffeesetup.h"
#include "mainwindow.h"


SettingsUpdate::SettingsUpdate(QWidget *parent) :
        QWidget(parent), ui(new Ui::SettingsUpdate) {
    ui->setupUi(this);
}

void SettingsUpdate::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    // compute values and load into ui

    auto* mainWindow = qobject_cast<MainWindow*>(window());
    if (mainWindow) {
        CoffeeSetup setup = mainWindow->setup;
        double fineCoarse = setup.computeFineCoarse();
        double grindTime = setup.computeGrindTime();

        ui->inputFineCoarse->setValue(fineCoarse);
        ui->inputGrindTime->setValue(grindTime);
    }
}

SettingsUpdate::~SettingsUpdate() {
    delete ui;
}
