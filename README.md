# Weather-Notification-System-implementing-the-Observer-design-pattern

## Overview

This project demonstrates the **Observer Design Pattern** implemented in C++ as a simple weather notification system for vehicle middleware.

- **WeatherStation** acts as the data source providing weather updates (temperature, humidity, pressure).
- Multiple **VehicleDisplay** units subscribe to updates and react accordingly.
- Observers can dynamically register and unregister for updates.
  
## Why Observer Pattern?

In vehicle middleware, sensor data must be efficiently and flexibly distributed to various modules:

- Dashboard displays, climate control, and safety systems all react to environmental data.
- Observer pattern decouples data producers from consumers, allowing modular and maintainable code.

## How to Build & Run

```bash
g++ main.cpp -o weather_observer -std=c++11
./weather_observer
Output:
[Dashboard Display] Weather Update - Temp: 25.5 C, Humidity: 60%, Pressure: 1013.1 hPa
[Mobile App Display] Weather Update - Temp: 25.5 C, Humidity: 60%, Pressure: 1013.1 hPa
[Dashboard Display] Weather Update - Temp: 26 C, Humidity: 58%, Pressure: 1012.5 hPa
[Mobile App Display] Weather Update - Temp: 26 C, Humidity: 58%, Pressure: 1012.5 hPa
[Dashboard Display] Weather Update - Temp: 24.5 C, Humidity: 65%, Pressure: 1014 hPa
[Mobile App Display] Weather Update - Temp: 24.5 C, Humidity: 65%, Pressure: 1014 hPa
