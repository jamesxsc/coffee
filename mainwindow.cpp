//
// Created by James Conway on 12/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::iteratePress() {
    // fix grind time
    int newTime = ui->timeIO->text().toInt() * (ui->targetWeightIn->text().toInt() / ui->actualWeightIn->text().toInt());
    ui->timeIO->setText(QString::number(newTime));

}
