#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float func(float x)
{
    return x - cos(x);
}

int main()
{
    float x, x1, x2;
    float error;

    cout << "Enter two guesses: ";
    cin >> x >> x1;

    while (func(x) - func(x1) == 0)
    {
        cout << "Enter valid guesses: ";
        cin >> x >> x1;
    }

    // Set precision and format output
    cout << fixed << setprecision(6);
    cout << "\nIter    "
         << setw(12) << "x"
         << setw(15) << "x1"
         << setw(15) << "x2"
         << setw(15) << "func(x)"
         << setw(15) << "func(x1)"
         << setw(15) << "Error" << "\n";


    int iteration = 1;
    do
    {
        x2 = (x * func(x1) - x1 * func(x)) / (func(x1) - func(x));
        error = abs(x1 - x2);

        // Print values in tabulated form
        cout << setw(4) << iteration++ << "    "
             << setw(12) << x
             << setw(15) << x1
             << setw(15) << x2
             << setw(15) << func(x)
             << setw(15) << func(x1)
             << setw(15) << error << "\n";

        x = x1;
        x1 = x2;

    } while (error > 0.000001);

    cout << "\nThe root is : " << x2 << endl;

    return 0;
}
