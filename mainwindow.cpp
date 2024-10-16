//
// Created by James Conway on 12/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QAbstractButton>
#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "SetupTableModel.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    setupTableModel.setup = &setup;

    ui->tableView->setModel(&setupTableModel);

    // todo design decision required - how many prev measurements_ do we use and how does deleting impact results? if so to 1), just recalc

}

void MainWindow::tableDelete() {
    auto selected = ui->tableView->selectionModel()->selectedIndexes();

    // just delete 1 - avoid awkward indexing
    if (selected.empty()) return;

    setup.deleteAt(selected[0].row());

    this->updateTable();
}

void MainWindow::updateTable() {
    setupTableModel.layoutChanged();
    ui->tableView->update();
}

MainWindow::~MainWindow() {
    delete ui;
}

