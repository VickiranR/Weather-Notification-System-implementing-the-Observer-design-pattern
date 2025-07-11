#include <iostream>
#include <vector>
#include <algorithm>

// Observer interface - any component interested in weather updates
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() = default;
};

// Subject interface - data source to which observers can subscribe
class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

// Concrete Subject representing the weather station in the vehicle middleware
class WeatherStation : public Subject {
private:
    std::vector<Observer*> observers; // List of subscribed observers
    float temperature;
    float humidity;
    float pressure;

public:
    // Register a new observer
    void registerObserver(Observer* o) override {
        observers.push_back(o);
    }

    // Notify all observers of a change
    void notifyObservers() override {
        for (auto* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    // Update weather data and notify observers
    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers();
    }
};

// Concrete Observer representing a vehicle display unit subscribing to weather updates
class VehicleDisplay : public Observer {
private:
    std::string displayName;

public:
    explicit VehicleDisplay(const std::string& name) : displayName(name) {}

    // Called when WeatherStation data updates
    void update(float temperature, float humidity, float pressure) override {
        std::cout << "[" << displayName << "] Weather Update - "
                  << "Temp: " << temperature << " C, "
                  << "Humidity: " << humidity << "%, "
                  << "Pressure: " << pressure << " hPa\n";
    }
};

int main() {
    // Instantiate weather station (subject)
    WeatherStation weatherStation;

    // Create vehicle displays (observers)
    VehicleDisplay dashboard("Dashboard Display");
    VehicleDisplay mobileApp("Mobile App Display");

    // Register observers to receive updates
    weatherStation.registerObserver(&dashboard);
    weatherStation.registerObserver(&mobileApp);

    // Simulate weather data updates inside the vehicle middleware
    weatherStation.setMeasurements(25.5f, 60.0f, 1013.1f);
    weatherStation.setMeasurements(26.0f, 58.0f, 1012.5f);

    // Another update, only dashboard receives it
    weatherStation.setMeasurements(24.5f, 65.0f, 1014.0f);

    return 0;
}