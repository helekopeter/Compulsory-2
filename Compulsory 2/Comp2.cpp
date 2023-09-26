#include <iostream>
#include "Comp2.h"
using namespace std;

void doSimpleMath() {
    char symbol;
    float num1, num2;

    cout << "\nPick operator: +, -, *, /\n";
    cin >> symbol;

    cout << "Enter two inputs\n";
    cin >> num1;
    cin >> num2;

    switch (symbol) {

    case '+':
        cout << "\n" << num1 << " + " << num2 << " = " << num1 + num2;
        break;

    case '-':
        cout << "\n" << num1 << " - " << num2 << " = " << num1 - num2;
        break;

    case '*':
        cout << "\n" << num1 << " * " << num2 << " = " << num1 * num2;
        break;

    case '/':
        cout << "\n" << num1 << " / " << num2 << " = " << num1 / num2;
        break;

    default:
        cout << "Not a valid operator";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        doSimpleMath();
        break;
    }
    cout << "\n";
}

void doFactorial() {
    cout << "Pick a positive number (Max 20)\n";
    int number;
    cin >> number;
    if (number >= 20)
        number = 20;
    cout << number << "! = " << factorial(number) << "\n";
}

void polySubmenu() {

    //Menu for what to do with the polynomials

    cout << "\n1. Multiply two polynomials\n";
    cout << "2. Add two polynomials\n";
    cout << "3. Subtract two polynomials\n";
    int Option;
    cin >> Option;

    //Define the fist polynomial

    int DegreeA, DegreeB;
    
    cout << "Enter the degree of the first polynomial (Max 8)\n";
    cin >> DegreeA;
    CinCheck();
    if (DegreeA > 8)DegreeA = 8; //Set it to max 8 (I set a max for it so you cant write something very high and have to restart)
    DegreeA++;                   //add one to acount for constant

    int* A = new int[DegreeA];
    cout << "Enter the coefficients of the first polynomial (from constant to last degree)\n";
    for (int i = 0; i < DegreeA; i++)
    {
        cin >> A[i];
        CinCheck();
    }

    //Define the second polynomial

    cout << "Enter the degree of the second polynomial (Max 8)\n";
    cin >> DegreeB;
    CinCheck();
    if (DegreeB > 8)DegreeB = 8;
    DegreeB++;

    int* B = new int[DegreeB];
    cout << "Enter the coefficients of the second polynomial (from constant to last degree)\n";
    for (int i = 0; i < DegreeB; i++)
    {
        cin >> B[i];
        CinCheck();
    }

    //Print the polynomials

    cout << "First polynomial is ";
    printPoly(A, DegreeA);
    cout << "\n" << "Second polynomial is ";
    printPoly(B, DegreeB);

    //Do and print the opperation

    switch (Option) {
    case 1:     //Multiply
    {
        int* prod = multiplyPolyArray(A, B, DegreeA, DegreeB);
        cout << "\n" << "Product polynomial is ";
        printPoly(prod, DegreeA + DegreeB - 1);
        break; 
    }
    case 2:     //Add
    {
        int* sum = addPolyArray(A, B, DegreeA, DegreeB);
        cout << endl << "If you add them it's ";
        printPoly(sum, (DegreeA > DegreeB) ? DegreeA : DegreeB);
        break;
    }
    case 3:     //subtract
    {
        int* sum = subPolyArray(A, B, DegreeA, DegreeB);

        cout << endl << "If you subtract them it's  ";
        printPoly(sum, (DegreeA > DegreeB) ? DegreeA : DegreeB);
        break;
    }
    //Delete stuff we are done with
    delete[] A;
    delete[] B;

    return;
    }
}

void Menu() {
    cout << "\n1. Factorial\n";
    cout << "2. Solve Polynomial Equation\n";
    cout << "3. Simple math\n";
    cout << "4. Exit\n";
    int Option;
    cin >> Option;
    switch (Option) {
    case 1:
        doFactorial();
        Menu();
        break;
    case 2:
        polySubmenu();
        Menu();
        break;
    case 3:
        doSimpleMath();
        Menu();
        break;
    case 4:
        return;
    default:
        //failsafe if answer is invalid
        cout << "Not a valid answer\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Menu();
        return;
    }
}

int main(){
	Menu();
    return 0;
}