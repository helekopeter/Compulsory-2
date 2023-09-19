#include <iostream>
#include "Comp2.h"
using namespace std;

void MultiplyPoly() {
    int DegreeA, DegreeB;

    cout << "Enter the degree of the first polynomial\n";
    cin >> DegreeA;
    CinCheck();
    DegreeA++; //add one to acount for constant

    //make polynom array A
    int* A = new int[DegreeA];
    cout << "Enter the coefficients of the first polynomial\n";
    //define each coefficiant in polynom array A
    for (int i = 0; i < DegreeA; i++)
    {
        cin >> A[i];
        CinCheck();
    }

    cout << "Enter the degree of the second polynomial\n";
    cin >> DegreeB;
    CinCheck();
    DegreeB++;

    //make polynom array B
    int* B = new int[DegreeB];
    cout << "Enter the coefficients of the second polynomial\n";
    //define each coefficiant in polynom array B
    for (int i = 0; i < DegreeB; i++)
    {
        cin >> B[i];
        CinCheck();
    }

    cout << "First polynomial is ";
    printPoly(A, DegreeA);
    cout << "\n" << "Second polynomial is ";
    printPoly(B, DegreeB);

    //does the multiplication
    int* prod = multiplyPolyArray(A, B, DegreeA, DegreeB);

    cout << "\n" << "Product polynomial is ";
    printPoly(prod, DegreeA + DegreeB - 1);

    //delete the stuff we are done with
    delete[] A;
    delete[] B;
    delete[] prod;
}

void AddPoly() {
    int DegreeA, DegreeB;

    cout << "Enter the degree of the first polynomial\n";
    cin >> DegreeA;
    CinCheck();
    DegreeA++;

    int* A = new int[DegreeA];
    cout << "Enter the coefficients of the first polynomial\n";
    for (int i = 0; i < DegreeA; i++)
    {
        cin >> A[i];
        CinCheck();
    }

    cout << "Enter the degree of the second polynomial\n";
    cin >> DegreeB;
    CinCheck();
    DegreeB++;

    int* B = new int[DegreeB];
    cout << "Enter the coefficients of the second polynomial\n";
    for (int i = 0; i < DegreeB; i++)
    {
        cin >> B[i];
        CinCheck();
    }

    cout << "First polynomial is ";
    printPoly(A, DegreeA);
    cout << endl << "Second polynomial is ";
    printPoly(B, DegreeB);

    //does the addition
    int* sum = addPolyArray(A, B, DegreeA, DegreeB);

    cout << endl << "If you add them it's ";
    printPoly(sum, (DegreeA > DegreeB) ? DegreeA : DegreeB);

    //delete the stuff we are done with
    delete[] A;
    delete[] B;
    //delete[] sum;    //This casued an error. Don't know why it works in "MultiplyPoly" and not here.
                       //But i think it should be fine without.
}

void SubtractPoly() {
    int DegreeA, DegreeB;

    cout << "Enter the degree of the first polynomial\n";
    cin >> DegreeA;
    CinCheck();
    DegreeA++;

    int* A = new int[DegreeA];
    cout << "Enter the coefficients of the first polynomial\n";
    for (int i = 0; i < DegreeA; i++)
    {
        cin >> A[i];
        CinCheck();
    }

    cout << "Enter the degree of the second polynomial\n";
    cin >> DegreeB;
    CinCheck();
    DegreeB++;

    int* B = new int[DegreeB];
    cout << "Enter the coefficients of the second polynomial\n";
    for (int i = 0; i < DegreeB; i++)
    {
        cin >> B[i];
        CinCheck();
    }

    cout << "First polynomial is ";
    printPoly(A, DegreeA);
    cout << endl << "Second polynomial is ";
    printPoly(B, DegreeB);

    //does the subtraction
    int* sum = subPolyArray(A, B, DegreeA, DegreeB);

    cout << endl << "If you subtract them it's  ";
    printPoly(sum, (DegreeA > DegreeB) ? DegreeA : DegreeB);

    //delete the stuff we are done with
    delete[] A;
    delete[] B;
    //delete[] sum;    //This casued an error. Don't know why it works in "MultiplyPoly" and not here.
                       //But i think it should be fine without.
}

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
    cout << "\n1. Multiply two Polynomials\n";
    cout << "2. Add two polynomials\n";
    cout << "3. Subtract two polynomials\n";
    int Option;
    cin >> Option;
    switch (Option) {
    case 1:
        MultiplyPoly();
        break;
    case 2:
        AddPoly();
        break;
    case 3:
        SubtractPoly();
        break;
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