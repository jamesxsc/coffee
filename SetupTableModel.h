//
// Created by James Conway on 14/10/2024.
//

#ifndef COFFEE_SETUPTABLEMODEL_H
#define COFFEE_SETUPTABLEMODEL_H


#include <QAbstractTableModel>
#include "coffeesetup.h"

class SetupTableModel : public QAbstractTableModel {

Q_OBJECT


public:
    CoffeeSetup* setup = nullptr;
    explicit SetupTableModel(QObject *parent = nullptr);

    [[nodiscard]] int rowCount(const QModelIndex &index) const override;
    [[nodiscard]] int columnCount(const QModelIndex &index) const override;

    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
    [[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

//    QHash<int, QByteArray> roleNames() const override;

};


#endif //COFFEE_SETUPTABLEMODEL_H
