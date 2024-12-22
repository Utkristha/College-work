#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float func(float x)
{
    return x - cos(x);
}

float deri(float x)
{
    return 1 + sin(x);
}

int main()
{
    float x, x1;
    float error;

    cout << "Enter starting guess: ";
    cin >> x;

    while (deri(x) == 0)
    {
        cout << "Enter valid guess: ";
        cin >> x;
    }

    // Set up the table headers
    cout << fixed << setprecision(6);
    cout << "\nIter    "
         << setw(12) << "x"
         << setw(15) << "func(x)"
         << setw(15) << "deri(x)"
         << setw(15) << "Error" << "\n";

    int iteration = 1;
    do
    {
        x1 = x - func(x) / deri(x);
        error = abs(x1 - x);

        // Print the values for each iteration
        cout << setw(4) << iteration++ << "    "
             << setw(12) << x
             << setw(15) << func(x)
             << setw(15) << deri(x)
             << setw(15) << error << "\n";

        x = x1;

    } while (error > 0.0001);

    cout << "\nThe root is: " << x1 << endl;

    return 0;
}
