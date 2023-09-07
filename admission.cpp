#include "admission.h"

bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

bool getValidBoolInput(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;
        if (input == "true" || input == "false") {
            return input == "true";
        } else {
            std::cout << "Invalid input. Enter 'true' or 'false'." << std::endl;
        }
    }
}

int getValidIntInput(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        int value;
        std::cin >> value;

        if (std::cin.fail()) {
            // Handle invalid input (non-integer)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        } else if (value >= min && value <= max) {
            return value;
        } else {
            std::cout << "Invalid input. Enter an integer between " << min << " and " << max << "." << std::endl;
        }
    }
}


double getValidDoubleInput(const std::string& prompt, double min, double max) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;

        if (isNumeric(input)) {
            double value = std::stod(input);
            if (value >= min && value <= max) {
                return value;
            }
        }

        std::cout << "Invalid input. Enter a number between " << min << " and " << max << "." << std::endl;
    }
}

std::string getValidStringInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin.ignore();
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
        }
    }
}


