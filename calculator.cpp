#include <iostream>
#include <limits>

using namespace std;

// Function prototypes
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    float num1, num2, result;
    char operation;
    bool keepRunning = true;

    // Display welcome message
    cout << "Welcome to the Basic Calculator!\n";

    while (keepRunning) {
        // Display menu and get operation choice
        displayMenu();
        cin >> operation;

        // Validate operation input
        while (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != 'q') {
            cout << "Invalid operation. Please choose a valid operation (+, -, *, /) or 'q' to quit: ";
            cin >> operation;
        }

        if (operation == 'q') {
            keepRunning = false;
            continue;
        }

        // Prompt user for input numbers
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Perform the chosen operation
        switch (operation) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                if (num2 != 0) {
                    result = divide(num1, num2);
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                    continue;
                }
                break;
        }

        // Display result
        cout << "Result: " << result << endl;
    }

    cout << "Thank you for using the Basic Calculator! Goodbye.\n";
    return 0;
}

void displayMenu() {
    cout << "\nChoose an operation to perform:\n";
    cout << "+ : Addition\n";
    cout << "- : Subtraction\n";
    cout << "* : Multiplication\n";
    cout << "/ : Division\n";
    cout << "q : Quit\n";
    cout << "Enter your choice: ";
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}
