#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define maxsize 20

class stack_
{
    int tos = -1;
    float arr[maxsize];
    public:
    
    bool isEmpty()
    {
        return (tos == -1);
    }

    bool isFull()
    {
        return(tos == maxsize-1);
    }

    void push(float element)
    {
        if(isFull())
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            tos++;
            arr[tos] = element;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            tos--;
        }
    }
    float peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[tos];
    }
        
};

bool isOperator(char element)
{
    char test[] = {'+','-','*','/','^','$'};
    for(int i=0;i<6;i++)
    {
        if(element == test[i])
        {
            return true;
        }
    }
    return false;
}


int main()
{
    stack_ s1;
    float result;
    char postfix[50] = "3 5 + 2 7 * - 4 ^ 6 2 / + 8 3 - $";


    int l =strlen(postfix);

    for(int i=0;i<l;i++)
    {
        if(!isOperator(postfix[i]))
        {
            if(postfix[i] != ' ')
            {
                if(isdigit(postfix[i]))
                {
                    float num = 0;
                    while(i < l && isdigit(postfix[i]))
                    {
                        num = num * 10 + (postfix[i] - '0');
                        i++;
                    }
                    s1.push(num);
                }
            }
        }
        else
        {
            float x = s1.peek();
            s1.pop();
            float y = s1.peek();
            s1.pop();

            switch(postfix[i])
            {
                case '+':
                result = y + x; 
                break;
                case '-':
                result = y - x;
                break;
                case '*':
                result = y * x;
                break;
                case '/':
                result = y / x;
                break;
                case '^':
                result = pow(y,x);
                break;
                case '$':
                result = pow(y,x);
                break;
                default:
                cout<<"No valid operator"<<endl;
                break;
            }
            s1.push(result);
        }
    }

    cout<<s1.peek()<<endl;
    s1.pop();
    return 0;

}