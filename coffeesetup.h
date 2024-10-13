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

// todo make all this robust to vector lengths and allow deletion/undo

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

    double computeFineCoarse() {
        // since fine/coarse in an arbitrary number depending on grinder burrs etc, we rely on interpolation
        // if we only have one measurement we simply return the previous val
        // it would be helpful to at least give an up/down indication based on the extraction time
        if (measurements.size() <= 1) {
            return settings.back().fineCoarse;
        }

        // otherwise, perform interpolation
        double deltaExtractionTime = measurements.back().extractionTime - measurements.rbegin()[1].extractionTime;
        double deltaFineCoarse = settings.back().fineCoarse - settings.rbegin()[1].fineCoarse;

        double grad = deltaExtractionTime / deltaFineCoarse;
        double icept = measurements.back().extractionTime - grad * settings.back().fineCoarse;

        return (targetTime - icept) / grad;
    }

    double computeGrindTime() {
        double prevTime = settings.back().grindTime;
        double prevWeight = measurements.back().grindWeight;

        return prevTime * (targetWeight / prevWeight);
    }

};

#endif //COFFEE_COFFEESETUP_H
