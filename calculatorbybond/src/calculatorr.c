#include <stdio.h>
#include <stdlib.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    float *onevector,*twovector;
    int size;
    float a, b, res, stepen;
    int vbor;
    float result = 0.0;
    char operation;
    char next;
    printf("My operation: + - * ^ ! \n");
    do {
        printf("What will you work with with numbers or vectors (0-numbers, 1-vectors)\n"); // выбор с чем работать с числами или с векторами
        scanf("%i",&vbor);
        if(vbor == 1){
            printf("Enter the size of the vector:\n");
            scanf("%i",&size);
            onevector = malloc(size*sizeof(int));
            twovector = malloc(size*sizeof(int));
            printf(" :\n");
            for(int i = 0; i < size ;i++){scanf("%f",&onevector[i]);} // заполняем первый вектор

            printf("Enter vector two:\n");
            for(int i = 0; i < size ;i++){scanf("%f",&twovector[i]);} // заполняем второй вектор

            printf("Enter an operation on vectors(+ - *):\n");

            scanf(" %c", &operation);
            switch(operation){      // операции с векторами
            case('+'):
                for(int i = 0; i < size ;i++)printf("%f ",onevector[i] + twovector[i]);
                break;
            case('-'):
                for(int i = 0; i < size ;i++)printf("%f ",onevector[i] - twovector[i] );
                break;
            case('*'):
                for(int i = 0; i < size ;i++){
                    result += onevector[i] * twovector[i];
                }
                printf("%f \n",result);
                result = 0;
                break;
            default:
                    printf("Error\n");
            }
            free(onevector);
            free(twovector);
            printf("Continue (y/n)? \n");
            scanf(" %c", &next);
        }else{

            scanf("%f %c", &a, &operation);
            if (operation != '!') {                      // тут необходимое условие тк для факториала нужно только ввести число и операцию
                scanf("%f", &b);
                switch (operation) {                     //тут происходит выбор операции над числом или числами
                case ('+'):
                    printf("%f %c %f = %f\n", a, operation, b, a + b);
                    break;
                case ('-'):
                    printf("%f %c %f = %f\n", a, operation, b, a - b);
                    break;
                case ('/'):
                    printf("%f %c %f = %f\n", a, operation, b, a / b);
                    break;
                case ('*'):
                    printf("%f %c %f = %f\n", a, operation, b, a * b);
                    break;
                case ('^'):                              // помимо простых действий над число ( + - * /),
                    stepen = 1;                          //где нужно ничего особенно пиcать для реализации
                    if (b >= 0) {                        // в отличие от возведения в степень,где для реализации нужен цикл for
                        for (int i = 1; i <= b; i++) {
                            stepen *= a;
                        }
                        printf("%f %c %f = %f\n", a, operation, b, stepen);
                    } else if (b < 0) {
                        for (int i = 0; i > b; i--) {
                            stepen *= a;
                        }
                        printf("%f %c %f = %f\n", a, operation, b, 1 / stepen);
                    }
                    break;
                default:                                 // если операция не определена то будет ошибка
                    printf("Error\n");
                }
            } else {
                res = 1;
                if (a >= 0 && (a * 3 < (int)a)) {
                    for (int i = 1; i <= a; i++) {       // факториал реализован через цикл for
                        res *= i;
                    }
                    printf("%f %c = %f\n", a, operation, res);
                } else {                                 // обработка ошибки
                    printf("Error\n");
                }
            }
            printf("Continue (y/n)? \n");                // y - yes , n - not
            scanf(" %c", &next);
        }
    } while (next == 'y');                           // цикл для того чтобы пользователь продолжил считать либо закончил работу
    return 0;
