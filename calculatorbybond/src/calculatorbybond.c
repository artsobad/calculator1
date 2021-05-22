/*
 ============================================================================
 Name        : calculatorbybond.c
 Author      : Nikita Bondarev
 ============================================================================
 */
#include <stdio.h>  
#include <stdlib.h> 

int main() 
{
    setvbuf(stdout, NULL, _IONBF, 0); 
    setvbuf(stderr, NULL, _IONBF, 0); 

    float a, b, *c, *d, res, g;
    char y, x, z, t;
    int res1, i, j;
    do
    {
        printf("Do you want to use algebra or vector calculator? (a/v):\n "); // выборка для пользователя между числами и векторами
        scanf(" %c", &x);                                                    
        switch (x)
        {
        case 'a':      // первый блок работы с числами

            printf("Enter the first number:\n");  // Запрос на введение первого числа.
            scanf("%f", &a);
            printf("Enter operation (- + / * ^ !):\n");  // Виды возможных операций, предоставленных пользователю.
            scanf(" %c", &z);

            if (z == '!') 
            {
                if (a < 0) 
                {
                    printf("Error \n");
                }
                else if (a == 0)
                {
                    printf("Result:  \n"); 
                }
                else if (a - (int)a != 0) 
                {
                    printf("You can't use factorial of this number \n");
                }
                else if (a != 0) //
                {
                    res1 = 1;
                    for (int r = 1; r <= a; r++)
                    {
                        res1 *= r;
                    }
                    printf("Result: %i \n", res1);
                }
            }
            else
            {
                printf("Enter second number: \n");  // Запрос на введение второго числа.
                scanf("%f", &b);
                switch (z)                          
                {
                case '+':
                    printf("Result %f: \n", a + b);
                    break;
                case '-':
                    printf("Result %f: \n", a - b);
                    break;
                case '/':
                    printf("Result %f: \n", a / b);
                    break;
                case '*':
                    printf("Result %f: \n", a * b);
                    break;
                case '^':
                    g = 1;
                    if (b < 0)
                    {
                        for (int i = 0; i > b; i--)
                        {
                            g = g * a;
                        }
                        res = 1 / g;
                    }
                    else if (b == 0)
                    {
                        res = 1;
                    }
                    else if (b - (int)b != 0)
                    {
                        printf("Error \n");
                    }
                    else
                    {
                        for (int i = 1; i <= b; i++)
                        {
                            g = g * a;
                        }
                        res = g;
                    }
                    printf("Result: %f \n", res);
                    break;
                default:
                    printf("Error \n");
                }
            }
            break;

        case 'v':  // Второй основной блок программы для работы с векторами
        {
            printf("Enter size of vectors: \n");
            scanf("%i", &i);
            c=malloc((i-1) * sizeof(float));    
            d=malloc((i-1) * sizeof(float));    
            printf("Enter first vector: \n ");  
            for (j = 0; j <= (i-1); j++)
            {
                scanf("%f", &c[j]);
            }
            printf("Enter operation (-+*): \n");
            scanf(" %c", &t);
            printf("Enter second vector: \n ");
            for (j = 0; j <= (i-1); j++)       
            {
                scanf("%f", &d[j]);
            }
            switch (t)
            {
            case '-':
                printf("Result: \n");
                for (j = 0; j < i; j++)        
                {
                    printf("%f ", c[j]-d[j]);
                }
                break;
            case '+':
                printf("Result: \n");           
                for (j = 0; j < i; j++)
                {
                    printf("%f ", c[j]+d[j]);
                }
                break;
            case '*':                           
                printf("Result: \n");
                for (j = 0; j < i; j++)
                {
                    printf("%f ", c[j]*d[j]);
                }
                break;
            default:
                printf("Wrong operation");      
            }
        }
        }
        printf("Do you want to continue? (y/n) \n");
        scanf(" %c", &y);
    } while (y == 'y');
    free(c);
    free(d);
    return 0;
}
