#include<iostream>
using namespace std;

int add(int x, int y) {
    return (x + y);
}

int subtract(int x, int y) {
    return (x - y);
}

int multiply(int x, int y) {
    return (x * y);
}

int divide(int x, int y) {
    if (y == 0) {
        cout << "Division by zero is not allowed!" << endl;
        return 0; 
    }
    return (x / y);
}
void display()
{
    cout << " 1. Add" << endl << " 2. Subtract" << endl << " 3. Multiply" << endl << " 4. Divide" << endl << " 5. Exit" << endl;
        cout << "Enter the number beside the operation: ";
}

int main() {
    int num1, num2, input = 0, result;
    while (input != 5) {
        display();
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter two numbers you want to add: ";
                cin >> num1 >> num2;
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Enter two numbers you want to subtract: ";
                cin >> num1 >> num2;
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Enter two numbers you want to multiply: ";
                cin >> num1 >> num2;
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Enter two numbers you want to divide: ";
                cin >> num1 >> num2;
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            
        }
    }

    return 0;
}
