//
// Created by James Conway on 12/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InitialSettings.h" resolved

#include <QStackedWidget>
#include "initialsettings.h"
#include "ui_InitialSettings.h"
#include "mainwindow.h"


InitialSettings::InitialSettings(QWidget *parent) :
        QWidget(parent), ui(new Ui::InitialSettings) {
    ui->setupUi(this);

}

InitialSettings::~InitialSettings() {
    delete ui;
}

void InitialSettings::nextPage() {
    auto* parent = qobject_cast<QStackedWidget*>(parentWidget());
    if (parent) {
        parent->setCurrentIndex(parent->currentIndex() + 1);
        auto* mainWindow = qobject_cast<MainWindow*>(window());
        if (mainWindow) {
            // maybe this should call a signal... unsure
            mainWindow->setup.addSettings(ui->inputFineCoarse->value(), ui->inputGrindTime->value());
        }
    }
}
