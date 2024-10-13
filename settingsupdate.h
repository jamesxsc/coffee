//
// Created by James Conway on 13/10/2024.
//

#ifndef COFFEE_SETTINGSUPDATE_H
#define COFFEE_SETTINGSUPDATE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class SettingsUpdate; }
QT_END_NAMESPACE

class SettingsUpdate : public QWidget {
Q_OBJECT

public:
    explicit SettingsUpdate(QWidget *parent = nullptr);

    ~SettingsUpdate() override;

private:
    Ui::SettingsUpdate *ui;
};


#endif //COFFEE_SETTINGSUPDATE_H
