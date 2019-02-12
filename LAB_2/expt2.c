#include<stdio.h>
#include<string.h>
int stack[30],top=-1;
int pop();
void push(int);
int todecimal(int);
void tobinary(int,int);
void main()
{
    int choice,number,remainder,digit,i=0,t=0;
    char hexa[20];
    do
    {
        printf("1: hexadecimal to binary\n2: octal to binary\n");
        printf("3: binary to hecxdecimalL\n4: binary to octal\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("\nEnter a hexa decimal number: ");
                    scanf("%s",&hexa);
                    printf("BINARY NUMBER IS: ");
                    for(i=0;i<strlen(hexa);i++)
                    {
                        digit=hexa[i];
                        switch(digit)
                        {
                            case 'A': tobinary(4,10);
                                        break;
                            case 'B': tobinary(4,11);
                                        break;
                            case 'C': tobinary(4,12);
                                        break;
                            case 'D': tobinary(4,13);
                                        break;
                            case 'E': tobinary(4,14);
                                        break;
                            case 'F': tobinary(4,15);
                                        break;
                            default: tobinary(4,digit-'0');
                        }

                    }
                    break;
            case 2:
                    printf("\nEnter a octal number: ");
                    scanf("%d",&number);
                    printf("BINARY NUMBER IS: ");
                    while(number)
                    {
                        digit=number%10;
                        t=t*10+digit;
                        number=number/10;
                    }
                    while(t!=0)
                    {
                        digit=t%10;
                        tobinary(3,digit);
                        t=t/10;
                    }
                    break;
            case 3:
                    printf("\nENTER A BINARY NUMBER: ");
                    scanf("%d",&number);
                    while(number)
                    {
                        remainder=number%10000;
                        switch(remainder)
                        {
                            case 1010: push('A');
                                        break;
                            case 1011: push('B');
                                        break;
                            case 1100: push('C');
                                        break;
                            case 1101: push('D');
                                        break;
                            case 1110: push('E');
                                        break;
                            case 1111: push('F');
                                        break;
                            default: push(todecimal(remainder));
                        }
                        number=number/10000;
                    }
                    printf(" HEXADECIMAL NUMBER IS:");
                    while(top!=-1)
                    {
                        digit=pop();
                        switch(digit)
                        {
                            case 65: printf("%c",digit);
                                        break;
                            case 66: printf("%c",digit);
                                        break;
                            case 67: printf("%c",digit);
                                        break;
                            case 68: printf("%c",digit);
                                        break;
                            case 69: printf("%c",digit);
                                        break;
                            case 70: printf("%c",digit);
                                        break;
                            default: printf("%d",digit);
                        }
                    }
                    break;
            case 4: printf("\nEnter a binary number: ");
                    scanf("%d",&number);
                    while(number)
                    {
                        remainder=number%1000;
                        push(remainder);
                        number=number/1000;
                    }
                    printf("OCTAL NUMBER IS:");
                    while(top!=-1)
                    {
                        digit=pop();
                        digit=todecimal(digit);
                        printf("%d",digit);
                    }
                    break;
        }
        printf("\n\n");
    }   while(choice);
}

int todecimal(int number)
{
    int sum=0,p=0;
    while(number)
    {
        sum=sum+(number%10)*pow(2,p);
        number=number/10;
        p++;
    }
    return sum;
}

void push(int n)
{
    stack[++top]=n;
}

int pop()
{
    return(stack[top--]);
}

void tobinary(int bit,int n)
{
    while(n>0)
    {
        push(n%2);
        n=n/2;
    }
    for(n=top+1;n<bit;n++)
    {
        printf("0");
    }
    while(top!=-1)
        printf("%d",pop());

    printf(" ");
}
