#pragma once

unsigned long long int factorial(int num) {
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}

int* multiplyPolyArray(int A[], int B[], int DegreeA, int DegreeB)
{
    int* prod = new int[DegreeA + DegreeB - 1];

    //for each degree in both polynomial minus one
    for (int i = 0; i < DegreeA + DegreeB - 1; i++)
        //initialize product array
        prod[i] = 0;
    //for every term of first polynomial
    for (int i = 0; i < DegreeA; i++)
    {
        // multiply the current term of first polynomial with every term of second polynomial.
        for (int j = 0; j < DegreeB; j++)
            prod[i + j] += A[i] * B[j];
    }

    return prod;
}

int* addPolyArray(int A[], int B[], int DegreeA, int DegreeB)
{
    // find the maximum degree
    int maxDegree = (DegreeA > DegreeB) ? DegreeA : DegreeB;

    //define the array
    int* sum = new int[maxDegree];

    for (int i = 0; i <= maxDegree; i++)
    {
        // initialize the variable in the array by making it 0
        sum[i] = 0;
        //add A for degree
        if (i <= DegreeA-1)
            sum[i] += A[i];
        //add B for degree
        if (i <= DegreeB-1)
            sum[i] += B[i];
    }

    return sum;
}

int* subPolyArray(int A[], int B[], int DegreeA, int DegreeB)
{
    // find the maximum degree
    int maxDegree = (DegreeA > DegreeB) ? DegreeA : DegreeB;

    //define the array
    int* sum = new int[maxDegree];

    for (int i = 0; i <= maxDegree; i++)
    {
        // initialize the variable in the array by making it 0
        sum[i] = 0;
        //add A for degree
        if (i <= DegreeA - 1)
            sum[i] += A[i];
        //subtract B for degree
        if (i <= DegreeB - 1)
            sum[i] -= B[i];
    }
    return sum;
}

void printPoly(int poly[], int Degree){
    //for each degree
    for (int i = 0; i < Degree; i++)
    {
        std::cout << poly[i];        //print number
        if (i != 0)                  //if not zero degree
            std::cout << "x^" << i;  //print x^degree
        if (i != Degree - 1)         //if you're not the last thing 
            std::cout << " + ";      //add a + between
    }
}

void CinCheck() {
    if (std::cin.fail())
    {
        std::cout << "Invalid input" << "\n";
        std::cin.clear();
        std::cin.ignore();
        return;
    }
}