//
// Created by James Conway on 12/10/2024.
//

#ifndef COFFEE_MAINWINDOW_H
#define COFFEE_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

private slots:
    void iteratePress();

};


#endif //COFFEE_MAINWINDOW_H
