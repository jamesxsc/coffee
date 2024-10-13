//
// Created by James Conway on 12/10/2024.
//

#include <vector>

#ifndef COFFEE_COFFEESETUP_H
#define COFFEE_COFFEESETUP_H

struct CoffeeMeasurement {
    double grindWeight;
    double extractionTime;

    CoffeeMeasurement(double grindWeight, double extractionTime) : grindWeight(grindWeight),
                                                                   extractionTime(extractionTime) {}
};

struct CoffeeSettings {
    double fineCoarse;
    double grindTime;

    CoffeeSettings(double fineCoarse, double grindTime) : fineCoarse(fineCoarse), grindTime(grindTime) {}
};

struct CoffeeSetup {
    // we want to guarantee that the indices align, that is, a coffee at index i was made with the settings at index i
    std::vector<CoffeeMeasurement> measurements;
    std::vector<CoffeeSettings> settings;

    double targetTime = 25;
    double targetWeight = 18;

public:
    void addSettings(double fineCoarse, double grindTime) {
        CoffeeSettings s(fineCoarse, grindTime);
        this->settings.push_back(s);
    }

    void addMeasurement(double grindWeight, double extractionTime) {
        CoffeeMeasurement m(grindWeight, extractionTime);
        this->measurements.push_back(m);
    }
};

#endif //COFFEE_COFFEESETUP_H
