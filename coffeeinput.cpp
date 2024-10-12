//
// Created by James Conway on 12/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CoffeeInput.h" resolved

#include "coffeeinput.h"
#include "ui_CoffeeInput.h"


CoffeeInput::CoffeeInput(QWidget *parent) :
        QWidget(parent), ui(new Ui::CoffeeInput) {
    ui->setupUi(this);
}

CoffeeInput::~CoffeeInput() {
    delete ui;
}
