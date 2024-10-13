//
// Created by James Conway on 12/10/2024.
//

#ifndef COFFEE_COFFEEINPUT_H
#define COFFEE_COFFEEINPUT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CoffeeInput; }
QT_END_NAMESPACE

class CoffeeInput : public QWidget {
Q_OBJECT

public:
    explicit CoffeeInput(QWidget *parent = nullptr);

    ~CoffeeInput() override;

private:
    Ui::CoffeeInput *ui;

    void showEvent(QShowEvent *event) override;

private slots:
    void nextPage();
};


#endif //COFFEE_COFFEEINPUT_H
