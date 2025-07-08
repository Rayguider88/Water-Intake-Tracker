#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string DATA_FILE = "water_log.txt";

int loadWaterIntake() {
    ifstream file(DATA_FILE);
    int total = 0;
    if (file.is_open()) {
        file >> total;
        file.close();
    }
    return total;
}

void saveWaterIntake(int total) {
    ofstream file(DATA_FILE);
    if (file.is_open()) {
        file << total;
        file.close();
    }
}

void showMenu() {
    cout << "\n====== Water Intake Tracker ======" << endl;
    cout << "1. Add Water Intake (ml)" << endl;
    cout << "2. View Total Intake Today" << endl;
    cout << "3. Reset Today's Intake" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    int waterIntake = loadWaterIntake();
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int amount;
                cout << "Enter amount of water (ml): ";
                cin >> amount;
                if (amount > 0) {
                    waterIntake += amount;
                    saveWaterIntake(waterIntake);
                    cout << "Water added! Current total: " << waterIntake << " ml" << endl;
                } else {
                    cout << "Invalid amount!" << endl;
                }
                break;
            }
            case 2:
                cout << "Total water intake today: " << waterIntake << " ml" << endl;
                break;
            case 3:
                waterIntake = 0;
                saveWaterIntake(waterIntake);
                cout << "Daily intake reset to 0 ml." << endl;
                break;
            case 4:
                cout << "Exiting... Stay hydrated!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
