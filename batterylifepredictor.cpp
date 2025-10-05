#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Function to calculate estimated battery life (in hours)
double calculateBatteryLife(double capacity_mAh, double current_mA, double efficiency) {
    return (capacity_mAh * efficiency) / current_mA;
}

// Function to calculate total stored energy (in watt-hours)
double calculateEnergy(double voltage, double capacity_mAh) {
    return (voltage * capacity_mAh) / 1000.0; // convert mAh → Ah
}

// Function to display a time breakdown in hours & minutes
void displayTime(double hours) {
    int hrs = static_cast<int>(hours);
    int mins = static_cast<int>((hours - hrs) * 60);
    cout << "Estimated runtime: " << fixed << setprecision(2) << hours
         << " hours (≈ " << hrs << "h " << mins << "m)" << endl;
}

// Function to log results to a text file
void logResults(double voltage, double capacity_mAh, double current_mA,
                double efficiency, double lifeHours, double energyWh) {
    ofstream file("battery_log.txt", ios::app); // append mode
    if (file.is_open()) {
        file << fixed << setprecision(2);
        file << "Voltage: " << voltage << " V, "
             << "Capacity: " << capacity_mAh << " mAh, "
             << "Load: " << current_mA << " mA, "
             << "Efficiency: " << efficiency << ", "
             << "Life: " << lifeHours << " h, "
             << "Energy: " << energyWh << " Wh" << endl;
        file.close();
    } else {
        cout << "⚠️ Could not open log file.\n";
    }
}

// Main Program
int main() {
    cout << "=========================================\n";
    cout << "        🔋 Battery Life Predictor 🔋      \n";
    cout << "=========================================\n\n";

    double voltage, capacity_mAh, current_mA, efficiency;

    // Input section
    cout << "Enter battery voltage (V): ";
    cin >> voltage;

    cout << "Enter battery capacity (mAh): ";
    cin >> capacity_mAh;

    cout << "Enter device current draw (mA): ";
    cin >> current_mA;

    cout << "Enter efficiency (0-1): ";
    cin >> efficiency;

    // Input Validation
    if (voltage <= 0 || capacity_mAh <= 0 || current_mA <= 0 ||
        efficiency <= 0 || efficiency > 1) {
        cout << "\n❌ Invalid input! Please enter positive values "
                "and efficiency between 0 and 1.\n";
        return 1;
    }

    // Calculations
    double lifeHours = calculateBatteryLife(capacity_mAh, current_mA, efficiency);
    double energyWh = calculateEnergy(voltage, capacity_mAh);

    cout << "\n-----------------------------------------\n";
    cout << "🔧 Results:\n";
    cout << "-----------------------------------------\n";
    displayTime(lifeHours);
    cout << "Battery energy: " << fixed << setprecision(2) << energyWh << " Wh\n";

    // Status message based on runtime
    if (lifeHours < 1)
        cout << "⚠️  Warning: Device may drain the battery very quickly.\n";
    else if (lifeHours < 5)
        cout << "⏳ Moderate runtime.\n";
    else
        cout << "✅ Good endurance for low-power device.\n";

    // Log to file
    logResults(voltage, capacity_mAh, current_mA, efficiency, lifeHours, energyWh);

    cout << "\n📁 Results saved to 'battery_log.txt'.\n";
    cout << "-----------------------------------------\n";

    return 0;
}
