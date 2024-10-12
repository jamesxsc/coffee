//
// Created by James Conway on 12/10/2024.
//

#ifndef COFFEE_INITIALSETTINGS_H
#define COFFEE_INITIALSETTINGS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class InitialSettings; }
QT_END_NAMESPACE

class InitialSettings : public QWidget {
Q_OBJECT

public:
    explicit InitialSettings(QWidget *parent = nullptr);

    ~InitialSettings() override;

private:
    Ui::InitialSettings *ui;

private slots:
    void nextPage();
};


#endif //COFFEE_INITIALSETTINGS_H
