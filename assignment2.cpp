// Brij Malhotra
// assignment2.cpp
// Purpose: This program implements a number of different mathematical
// functions that are all programmed to run in a recursive manner 

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

// Function prototypes
int menu();
int sumDigits(int);
float root5(int, float);
int egyptDivision(int, int);
void doubleInt(int &);
int halveInt(int, int);
float ramanujan(int, int);

int main(){

    cout << endl;

    // User input for the menu choice
    int choice = menu();

    while (choice != 5){
        
        int num;
        // Have to define the first guess otherwise it overlaps the
        // switch cases and does not compile
        float firstGuess = 1.0;
        
        switch (choice) {
            // Choice 1 is the sumDigits function
            case 1: 
            cout << "Please enter a number to sum its digits: " << endl;
            cin >> num;
            cout << "The sum of the digits of " << num << " is " << sumDigits(num);
            cout << endl << endl;
            break;

            // Choice 2 is the root5 function
            case 2:
            cout << "Please enter a number to calculate its fifth root: ";
            cin >> num;
            cout << "The fifth root of " << num << " is " << root5(num, firstGuess);
            cout << endl << endl;
            break;

            // Choice 3 is the egyptDivision function
            case 3: 
            int dividend, divisor;
            cout << "Egyptian division. Enter dividend and divisor: " << endl;
            cin >> dividend >> divisor;
            cout << "The quotient is " << egyptDivision(divisor, dividend);
            cout << endl << endl;
            break;

            // Choice 4 is the ramanujan function
            case 4: 
            cout << "Ramanujan. Enter integer depth: ";
            cin >> num;
            cout << "Result at depth " << num << ": " << ramanujan(num, 0) << endl;
            cout << "Result at infinite depth: 4" << endl << endl;
            break;

            // Choice 5 is exiting the menu
            case 5:
            break;
        }

        choice = menu();
    }

    cout << "Thank you for using this program to test recursion :D";
    cout << endl << endl;
}

// Function declaration

// This function displays the menu
int menu(){
    int num;
    cout << "Welcome to the recursion assignment. What would you like to test?" << endl;
    cout << "1. sumDigits" << endl;
    cout << "2. root5" << endl;
    cout << "3. egyptDivision" << endl;
    cout << "4. ramanujan" << endl;
    cout << "5. exit" << endl;
    cout << "Please enter your choice: ";
    cin >> num;
    cout << endl;
    return num;
}

// This function sums up the digits of the user input
int sumDigits(int num){
    // Base case
    if (num == 0){
        return 0;
    }

    // Recursive step, it takes the remainder when divided by 10 which is the last digit.
    // It continues until it goes through all digits in the input
    return (num % 10 + sumDigits(num/10));
}

// This function returns the fifth root of the number provided by the user
float root5(int num, float guess){
    // Base case
    if (abs(pow(guess,5) - num) < 0.00001){
        return guess;
    }

    // Recursive case that follows a derived formula from the problem given
    float betterGuess = (4 * guess + num/pow(guess, 4)) / 5;
    return root5(num, betterGuess);
}

// This function computes binary arithmetic that Egyptians used to make their
// own method of division, very straightforward due to the instructions
int egyptDivision(int b, int c){
    int a = 1;

    while (b < c){
        doubleInt(a);
        doubleInt(b);
    }

    int d = 0;

    while (a >= 1){
        if (b <= c){
            d = d + a;
            c = c - b;
        }

        a = halveInt(a, 0);
        b = halveInt(b, 0);
    }

    return d;
}

// This function simply doubles the number
void doubleInt(int & num){
    num = num + num;
}

// This function halves the number using recursion and a count variable
int halveInt(int num, int count){
    // Base case
    if (num == 0){
        return 0;
    }

    if (num == count){
        return num;
    }

    // The count variable is there so that each time we subtract 1 from the num
    // we add 1 to the count variable and we do this until num is equal to count
    return halveInt(num - 1, count + 1);
}

// This function carries out Ramanujan's equation using recursion
float ramanujan(int depth, int count){
    // Base case
    if (depth < 0){
        return 0;
    }

    // Recursive step, counter variable to keep track of depth iterations
    // when the depth goes below 0, it satisfies the base case and we retrieve
    // our final answer, this was quite weird to code up for me :/
    return sqrt((count + 6) + (count + 2) * ramanujan(depth - 1, count + 1));
}
 