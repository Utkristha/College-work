#include <iostream>
#include <cstring>
using namespace std;
#define maxsize 20

class stack_
{
    int tos = -1;
    char arr[maxsize];
    public:
    
    bool isEmpty()
    {
        return (tos == -1);
    }

    bool isFull()
    {
        return(tos == maxsize-1);
    }

    void push(char element)
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
    char peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return '\0';
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

int checkPrecedency(char element)
{
    char test[] = {'+','-','*','/','$','^'};
    int testNumber[] = {1,1,2,2,3,3};
    int j=0;
    for(int i=0;element != test[i];i++)
    {
        j++;
    }

    return testNumber[j];
}

int main()
{
    stack_ s1;
    int l,j=0;;
    char infix[maxsize],postfix[maxsize];

    cout<<"Enter infix expression: "<<endl;
    cin>>infix;

    l = strlen(infix);

    for(int i=0;i<l;i++)
    {
        if(isOperator(infix[i]))
        {
            if(s1.isEmpty() || s1.peek() == '(')
            {
                s1.push(infix[i]);
            }
            else
            {
                if(checkPrecedency(infix[i]) > checkPrecedency(s1.peek()))
                {
                    s1.push(infix[i]);
                }
                else if(checkPrecedency(infix[i]) < checkPrecedency(s1.peek()))
                {
                    while((checkPrecedency(infix[i]) < checkPrecedency(s1.peek())) && s1.peek() !='(' )
                    {
                        postfix[j] = s1.peek();
                        s1.pop();
                        j++;
                    }
                    s1.push(infix[i]);
                }
                else
                {
                    if(checkPrecedency(infix[i]) == 2 || checkPrecedency(infix[i]) == 1)
                    {
                            postfix[j] = s1.peek();
                            s1.pop();
                            j++;
                            s1.push(infix[i]);
                    }
                    else 
                    {
                        s1.push(infix[i]);
                    }
                    
                }
            }
        }
        else
        {
            if(infix[i] == '(')
            {
                s1.push(infix[i]);
            }
            else if(infix[i] == ')')
            {
                while(s1.peek() != '(')
                {
                    postfix[j] = s1.peek();
                    s1.pop();
                    j++;
                }
                s1.pop();
            }
            else
            {
                postfix[j] = infix[i];
                j++;
            }
        }
    }

    postfix[j] = '\0';

    cout<<postfix<<endl;
    return 0;
}