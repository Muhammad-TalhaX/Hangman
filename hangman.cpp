#include <iostream>
#include <vector>
#include <string>

class Vehicle {
protected:
    std::string type;
    std::string name;
    bool isAvailable;

public:
    Vehicle(std::string type, std::string name) : type(type), name(name), isAvailable(true) {}

    void displayInfo() const {
        std::cout << "Type: " << type << ", Name: " << name << ", Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
    }

    bool rent() {
        if (isAvailable) {
            isAvailable = false;
            std::cout << name << " has been rented." << std::endl;
            return true;
        } else {
            std::cout << name << " is not available." << std::endl;
            return false;
        }
    }

    void returnVehicle() {
        isAvailable = true;
        std::cout << name << " has been returned." << std::endl;
    }

    std::string getName() const {
        return name;
    }
};

class Car : public Vehicle {
public:
    Car(std::string name) : Vehicle("Car", name) {}
};

class Bike : public Vehicle {
public:
    Bike(std::string name) : Vehicle("Bike", name) {}
};

void displayVehicles(const std::vector<Vehicle*>& vehicles) {
    for (size_t i = 0; i < vehicles.size(); ++i) {
        vehicles[i]->displayInfo();
    }
}

int main() {
    std::vector<Vehicle*> vehicles = {
        new Car("Mini Car 1"), new Car("Mini Car 2"), new Car("Mini Car 3"),
        new Car("Ordinary Car 1"), new Car("Ordinary Car 2"), new Car("Ordinary Car 3"),
        new Car("SUV 1"), new Car("SUV 2"), new Car("SUV 3"),
        new Car("VIP Car 1"), new Car("VIP Car 2"), new Car("VIP Car 3"),
        new Car("Sports Car 1"), new Car("Sports Car 2"), new Car("Sports Car 3"),
        new Bike("Normal Bike 1"), new Bike("Normal Bike 2"), new Bike("Normal Bike 3"),
        new Bike("Cycle 1"), new Bike("Cycle 2"), new Bike("Cycle 3"),
        new Bike("Heavy Bike 1"), new Bike("Heavy Bike 2"), new Bike("Heavy Bike 3")
    };

    int choice;
    while (true) {
        std::cout << "\nCar and Bike Rental System\n";
        std::cout << "1. Display all vehicles\n";
        std::cout << "2. Rent a vehicle\n";
        std::cout << "3. Return a vehicle\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            displayVehicles(vehicles);
        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter the name of the vehicle to rent: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            bool found = false;
            for (size_t i = 0; i < vehicles.size(); ++i) {
                if (vehicles[i]->getName() == name) {
                    vehicles[i]->rent();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Vehicle not found." << std::endl;
            }
        } else if (choice == 3) {
            std::string name;
            std::cout << "Enter the name of the vehicle to return: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            bool found = false;
            for (size_t i = 0; i < vehicles.size(); ++i) {
                if (vehicles[i]->getName() == name) {
                    vehicles[i]->returnVehicle();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Vehicle not found." << std::endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    // Clean up
    for (size_t i = 0; i < vehicles.size(); ++i) {
        delete vehicles[i];
    }

    return 0;
}
