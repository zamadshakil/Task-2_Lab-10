#include <iostream>
#include <string>
using namespace std;

// Engine class
class Engine {
private:
    int horsepower;
    string fuelType;

public:
    // Constructor to initialize both values
    Engine(int hp, string fuel) : horsepower(hp), fuelType(fuel) {}

    // Function to display engine information
    void displayEngineInfo() {
        cout << "Horsepower: " << horsepower << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Car class - has-an Engine (composition)
class Car {
private:
    string brand;
    string model;
    Engine engine;  // Engine object created inside Car (composition)

public:
    // Constructor that initializes all members including Engine
    Car(string b, string m, int horsepower, string fuelType)
        : brand(b), model(m), engine(horsepower, fuelType) {}

    // Function to display car information
    void displayCarInfo() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        engine.displayEngineInfo();  // Call Engine's display function
    }
};

int main() {
    // Create a Car object (Engine is created inside via composition)
    Car car1("Toyota", "Camry", 301, "Gasoline");
    Car car2("Tesla", "Model S", 670, "Electric");

    cout << "=== Car 1 Information ===" << endl;
    car1.displayCarInfo();

    cout << endl;

    cout << "=== Car 2 Information ===" << endl;
    car2.displayCarInfo();

    return 0;
}
