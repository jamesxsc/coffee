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

// todo make all this robust to vector lengths and allow deletion/undo (encapsulate)

struct CoffeeSetup {

private:
    double targetTime_ = 25;
    double targetWeight_ = 18;

    // we want to guarantee that the indices align, that is, a coffee at index i was made with the settings_ at index i
    std::vector<CoffeeMeasurement> measurements_;
    std::vector<CoffeeSettings> settings_;

public:
    [[nodiscard]] double getTargetTime() const {
        return targetTime_;
    }

    [[nodiscard]] double getTargetWeight() const {
        return targetWeight_;
    }

    void addSettings(double fineCoarse, double grindTime) {
        CoffeeSettings s(fineCoarse, grindTime);
        this->settings_.push_back(s);
    }

    void addMeasurement(double grindWeight, double extractionTime) {
        CoffeeMeasurement m(grindWeight, extractionTime);
        this->measurements_.push_back(m);
    }

    double computeFineCoarse() const {
        // since fine/coarse in an arbitrary number depending on grinder burrs etc, we rely on interpolation
        // if we only have one measurement we simply return the previous val
        // it would be helpful to at least give an up/down indication based on the extraction time
        if (measurements_.size() <= 1) {
            return settings_.back().fineCoarse;
        }

        // otherwise, perform interpolation
        double deltaExtractionTime = measurements_.back().extractionTime - measurements_.rbegin()[1].extractionTime;
        double deltaFineCoarse = settings_.back().fineCoarse - settings_.rbegin()[1].fineCoarse;

        double grad = deltaExtractionTime / deltaFineCoarse;
        double icept = measurements_.back().extractionTime - grad * settings_.back().fineCoarse;

        return (targetTime_ - icept) / grad;
    }

    [[nodiscard]] double computeGrindTime() const {
        double prevTime = settings_.back().grindTime;
        double prevWeight = measurements_.back().grindWeight;

        return prevTime * (targetWeight_ / prevWeight);
    }

    // note that the length of measurements may be 1 smaller
    [[nodiscard]] int entries() const {
        return (int) settings_.size();
    }

    [[nodiscard]] bool latestHasMeasurement() const {
        return measurements_.size() == settings_.size();
    }

    CoffeeSettings* latestSettings() {
        if (settings_.empty()) {
            return nullptr;
        }
        return &settings_.back();
    }

    CoffeeMeasurement* latestMeasurement() {
        if (measurements_.empty()) {
            return nullptr;
        }
        return &measurements_.back();
    }

    void deleteAt(int i) {
        if (i >= settings_.size()) return;

        settings_.erase(settings_.begin() + i);

        // recall settings is never shorter than measurements so we won't always delete it
        if (i < measurements_.size()) {
            measurements_.erase(measurements_.begin() + i);
        }
    }

    [[nodiscard]] CoffeeSettings settingsAt(size_t i) const {
        if (i >= settings_.size()) {
            throw std::range_error("Index out of range");
        }
        return settings_[i];
    }

    [[nodiscard]] CoffeeMeasurement measurementAt(size_t i) const {
        if (i >= measurements_.size()) {
            throw std::range_error("Index out of range");
        }
        return measurements_[i];
    }
};

#endif //COFFEE_COFFEESETUP_H
