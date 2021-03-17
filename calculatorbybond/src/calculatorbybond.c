/*
 ============================================================================
 Name        : calculatorbybond.c
 Author      : Nikita Bondarev
 ============================================================================
 */
#include <stdio.h>
#include <math.h>

int main()
{

    float x,y,z;  // Используемые переменные.
    char m,n;
    long int p=1;

     do {printf("Enter the first number:\n");  // Запрос на введение первого числа.
        scanf("%f",&x);

    printf("What operation do you want to use?\n");
    printf("Possible operations: +,-,*,/,!,^\n"); // Виды возможных операций, предоставленных пользователю.
    scanf("%s",&m);

    if(m=='+'||m=='-'||m=='*'||m=='/')
    { printf("Enter the second number:\n");  // Запрос на введение второго числа.
      scanf("%f",&y);}
      else if(m=='^')
      { printf("Enter the degree:\n");
      scanf("%f",&y);}


       switch(m){
        case '+':
        z=x+y;
        printf("%.3f\n",z);
        break;
        case '-':
        z=x-y;
        printf("%.3f\n",z);                         // Основной блок программы в котором происходит выполнение
        break;                                      // выбранной пользователем операции.
        case '*':
        z=x*y;
        printf("%.3f\n",z);
        break;
        case '/':
        if(y==0)
        printf("Cannot be divided by 0\n");
        else{
        z=x/y;
        printf("%.5f\n",z);}
        break;
        case '!':
           if(x<0)
           printf("You entered a negative number.\n");
           else if (x==0)                            // Вывод информации об некоректном запросе пользователя
           printf("1\n");
           else if (x==1)
           printf("1\n");
           else if(x-(int)x!=0)
           printf("Fractional number used\n");
           else {
           for(float i=1; i<=x; i++)
           {p=p*i;}
           printf("%li\n",p);}
        break;
        case '^':
        if(y==0){
            printf("1\n");
        }
        else{
        printf("%0.5f\n",pow(x,y));}
        break;
    }

    printf("Do you want to continue? (y or n) \n");   // Вывод информации с возможностью продолжить или завершить
    scanf("%s",&n);                                // процесс программы


     while ((n != 'y') && (n !='n')){
        printf("Do you want to continue? (y or n)\n");
        scanf("%s",&n);}
     }
    while(n=='y');


    return 0;
}
