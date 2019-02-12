//programmer name:RAHEEL
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
void dec_to_bin(int);
void bin_to_dec(int);
int main()
{
    int x,ch;
    while(1)
    {
    cout<<"\nEnter Your choice"<<endl;
    cout<<"\n1: Decimal to Binary";
    cout<<"\n2: Binary to Decimal";
    cout<<"\n3: Exit"<<endl<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"\nEnter a Decimal Number\t";
               cin>>x;
               cout<<"The binary equivalent of "<<x<<" is "<<endl;
               dec_to_bin(x);
               break;
        case 2:cout<<"\nEnter a Binary Number\t";
                cin>>x;
                cout<<"\nDecimal Equivalent of "<<x<<" is "<<endl;
                bin_to_dec(x);
                break;
        case 3:cout<<"\nExit";
                return 0;
        default: cout<<"\nEnter a Proper Choice";
    }
    }
    return 0;
}

void dec_to_bin(int x)
{
    int bin;
    stack<int>a;
    while(x>0)
    {
        bin=x%2;
        a.push(bin);
        x=x/2;
    }
    while(!a.empty())
    {
        cout<<a.top();
        a.pop();
    }
}

void bin_to_dec(int x)
{
    int rem,result,i;
    i=0;
    while(x>0)
    {
        rem=x%10;
        result=result+rem*(pow(2,i));
        i=i+1;
        x=x/10;
    }
    cout<<result;
}
