//
// Created by James Conway on 13/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SettingsUpdate.h" resolved

#include "settingsupdate.h"
#include "ui_SettingsUpdate.h"


SettingsUpdate::SettingsUpdate(QWidget *parent) :
        QWidget(parent), ui(new Ui::SettingsUpdate) {
    ui->setupUi(this);

    // compute values and load into ui
    ui->inputFineCoarse->setValue(1);
    ui->inputGrindTime->setValue(1); // (temp)
}

SettingsUpdate::~SettingsUpdate() {
    delete ui;
}
