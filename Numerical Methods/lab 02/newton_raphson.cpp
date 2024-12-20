#include  <iostream>
#include <cmath>
using namespace std;

float func(float x)
{
    return x-cos(x);
}

float deri(float x)
{
    return 1+sin(x);
}

int main()
{
    float x,x1;
    float error;
    cout<<"Enter starting guess: ";
    cin>>x;
    while(deri(x) == 0 )
    {
        cout<<"Enter valid guess: ";
        cin>>x;
    }

    do
    {
        x1 = x - func(x)/deri(x);
        error = abs(x1-x);
        x=x1;
    } while (error > 0.0001);
    
    cout<<"The root is: "<<x1;
    return 0;
    
}