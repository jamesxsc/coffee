//
// Created by James Conway on 12/10/2024.
//

#ifndef COFFEE_MAINWINDOW_H
#define COFFEE_MAINWINDOW_H

#include <QMainWindow>
#include "coffeesetup.h"
#include "SetupTableModel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    CoffeeSetup setup;

    void updateTable();

private:
    Ui::MainWindow *ui;
    SetupTableModel setupTableModel;


private slots:
    void tableDelete();
};


#endif //COFFEE_MAINWINDOW_H
