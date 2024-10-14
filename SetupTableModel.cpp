//
// Created by James Conway on 14/10/2024.
//

#include "SetupTableModel.h"

SetupTableModel::SetupTableModel(QObject *parent) : QAbstractTableModel(parent) {
    qDebug() << "SetupTableModel created";
}

int SetupTableModel::rowCount(const QModelIndex &) const {
    return (int) setup->entries();
}

int SetupTableModel::columnCount(const QModelIndex &) const {
    return 4;
}

QVariant SetupTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }

    CoffeeSettings* latestSettings = setup->latestSettings();
    if (!latestSettings) {
        return {};
    }
    CoffeeMeasurement* latestMeasurement = setup->latestMeasurement();

    switch (index.column()) {
        case 0:
            return latestSettings->fineCoarse;
        case 1:
            return latestSettings->grindTime;
        case 2:
            if (latestMeasurement)
                return latestMeasurement->extractionTime;
            else
                return "-"; // display as empty
        case 3:
            if (latestMeasurement)
                return latestMeasurement->grindWeight;
            else
                return "-";
        default:
            return {};
    }
}

QVariant SetupTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    // todo consider orientation for best practice

    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) {
        return {};
    }

    switch (section) {
        case 0:
            return "Fine/Coarse";
        case 1:
            return "Grind Time";
        case 2:
            return "Extraction Time";
        case 3:
            return "Grind Weight";
        default:
            return {};
    }
}
