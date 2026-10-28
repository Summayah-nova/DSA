#include <iostream>
using namespace std;

class myCarStack {
private:
    int cars[8];
    int topIndex;

public:
    myCarStack() {
        topIndex = -1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == 7;
    }

    int totalCars() const {
        return topIndex + 1;
    }

    void push(int carNumber) {
        if (isFull()) {
            cout << "Parking lot is full!\n";
            return;
        }

        if (search(carNumber)) {
            cout << "This car is already parked!\n";
            return;
        }

        cars[++topIndex] = carNumber;
        cout << "Car parked successfully.\n";
    }

    int pop() {
        if (isEmpty())
            return -1;

        return cars[topIndex--];
    }

    bool search(int carNumber) const {
        for (int i = 0; i <= topIndex; i++) {
            if (cars[i] == carNumber)
                return true;
        }
        return false;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No cars are parked.\n";
            return;
        }

        cout << "Cars (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << cars[i] << " ";
        }
        cout << endl;
    }

    void removeCar(int carNumber) {
        if (!search(carNumber)) {
            cout << "Car not found!\n";
            return;
        }

        myCarStack temp;
        int currentCar;

        while (cars[topIndex] != carNumber) {
            temp.push(pop());
        }

        pop();  // Remove the requested car
        cout << "Car " << carNumber << " removed.\n";

        while (!temp.isEmpty()) {
            currentCar = temp.pop();
            push(currentCar);
        }
    }
};

int main() {
    myCarStack parking;
    int choice, carNumber;

    do {
        cout << "\n--- PARKING LOT MENU ---\n";
        cout << "1. Park a new car\n";
        cout << "2. Remove a car\n";
        cout << "3. View parked cars\n";
        cout << "4. Total cars parked\n";
        cout << "5. Search for a car\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> carNumber;
            parking.push(carNumber);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNumber;
            parking.removeCar(carNumber);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars parked: "
                << parking.totalCars() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNumber;

            if (parking.search(carNumber))
                cout << "Car is present in the parking lot.\n";
            else
                cout << "Car is not present.\n";
            break;

        case 6:
            cout << "Parking system closed.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}