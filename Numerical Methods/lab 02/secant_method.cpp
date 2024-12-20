#include <iostream>
#include <cmath>
using namespace std;

float func(float x)
{
    return x - cos(x);
}

int main()
{
    float x, x1, x2;
    float error;
    
    cout<<"Enter two guesses: ";
    cin>>x>>x1;

    do
    {
        x2 = (x*func(x1) - x1*func(x))/(func(x1)-func(x));
        x = x1;
        x1 = x2;
        error = abs(x1 - x);
    } while (error > 0.0001);

    cout<<"The root is :"<<x1;
    return 0;
}