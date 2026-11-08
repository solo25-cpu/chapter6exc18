#include <iostream>
#include <iomanip>

// Function that calculates and returns the projected new size of the population after one year
double calculateNewPopulation(double currentPopulation, double birthRate, double deathRate) {
    return currentPopulation * (1.0 + birthRate) * (1.0 - deathRate);
}

int main() {
    double startingPopulation = 0;
    double birthRate = 0.0;
    double deathRate = 0.0;
    int years = 0;

    std::cout << "=========================================\n";
    std::cout << "      POPULATION PROJECTION SYSTEM       \n";
    std::cout << "=========================================\n\n";

    // Input Validation: Starting size of population (minimum 2)
    std::cout << "Enter the starting size of the population (minimum 2): ";
    std::cin >> startingPopulation;
    while (startingPopulation < 2) {
        std::cout << "Invalid input. Population must be at least 2. Please re-enter: ";
        std::cin >> startingPopulation;
    }

    // Input Validation: Annual birth rate (must be non-negative)
    std::cout << "Enter the annual birth rate (as a decimal, e.g., 0.032): ";
    std::cin >> birthRate;
    while (birthRate < 0) {
        std::cout << "Invalid input. Birth rate cannot be negative. Please re-enter: ";
        std::cin >> birthRate;
    }

    // Input Validation: Annual death rate (must be non-negative)
    std::cout << "Enter the annual death rate (as a decimal, e.g., 0.026): ";
    std::cin >> deathRate;
    while (deathRate < 0) {
        std::cout << "Invalid input. Death rate cannot be negative. Please re-enter: ";
        std::cin >> deathRate;
    }

    // Input Validation: Number of years to display (minimum 1)
    std::cout << "Enter the number of years to display (minimum 1): ";
    std::cin >> years;
    while (years < 1) {
        std::cout << "Invalid input. Years must be at least 1. Please re-enter: ";
        std::cin >> years;
    }

    // Display Table Headings
    std::cout << "\n-----------------------------------------\n";
    std::cout << std::left << std::setw(10) << "Year" << " | " << "Projected Population" << std::endl;
    std::cout << "-----------------------------------------\n";

    // Display Starting State (Year 0)
    std::cout << std::fixed << std::setprecision(0);
    std::cout << std::left << std::setw(10) << "Starting" << " | " << startingPopulation << std::endl;

    // Loop through each year to compute and show calculations
    double currentPopulation = startingPopulation;
    for (int i = 1; i <= years; ++i) {
        currentPopulation = calculateNewPopulation(currentPopulation, birthRate, deathRate);
        std::cout << std::left << std::setw(10) << i << " | " << currentPopulation << std::endl;
    }

    std::cout << "-----------------------------------------\n";

    return 0;
}
