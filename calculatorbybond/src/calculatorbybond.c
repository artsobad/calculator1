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
  	char y, x, z, t, input[50], output[50], yy;
  	int res1, i, j;

                FILE *in, *out; 
		in = fopen(input, "r"); 
		out = fopen(output, "w"); 
do {
		printf("Input input file name: \n");
		scanf(" %s", &input);
		printf("Input output file name: \n");
		scanf(" %s", &output);    
 do
    {
        printf("Do you want to use algebra or vector calculator? (a/v):\n "); // выборка для пользователя между числами и векторами
        fscanf(" %c", &x);                                                    
        switch (x)
        {
        case 'a': 

				printf("Input first number:\n"); 
				fscanf(in, "%f", &a);
				printf("Input operation (-+/*^!):\n"); 
				fscanf(in, " %c", &z);

				if (z == '!')
						{
					if (a < 0) 
							{
						fprintf(out, "Error \n");
					} else if (a == 0) {
						fprintf(out, "1! = 1 \n"); 
					} else if (a - (int) a != 0) 
							{
						fprintf(out,
								"You can't use factorial of this number \n");
					} else if (a != 0) //
							{
						res1 = 1;
						for (int r = 1; r <= a; r++) {
							res1 *= r;
						}
						fprintf(out, "%f ! = ", a);
						fprintf(out, "%i \n", res1);
					}
				} else {
					printf("Input second number: \n"); 
					fscanf(in, "%f", &b);
					switch (z) 					
					{
					case '+':
						fprintf(out, "%f + ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a + b);
						break;
					case '-':
						fprintf(out, "%f - ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a - b);
						break;
					case '/':
						fprintf(out, "%f / ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a / b);
						break;
					case '*':
						fprintf(out, "%f * ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a * b);
						break;
					case '^':
						g = 1;
						if (b < 0) {
							for (int i = 0; i > b; i--) {
								g = g * a;
							}
							res = 1 / g;
						} else if (b == 0) {
							res = 1;
						} else if (b - (int) b != 0) {
							fprintf(out, "Error \n");
						} else {
							for (int i = 1; i <= b; i++) {
								g = g * a;
							}
							res = g;
						}
						fprintf(out, "%f ^ ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", res);
						break;
					default:
						fprintf(out, "Error \n");
					}
				}
				break;

			case 'v': 
			{
				printf("Input size of vectors: \n");
				fscanf(in, "%i", &i);
				c = malloc(i * sizeof(float)); 
				d = malloc(i * sizeof(float)); 
				printf("Input first vector: \n ");	

				for (j = 0; j < i; j++) {
					fscanf(in, "%f", &c[j]);
				}
				printf("Input operation (-+*): \n");
				fscanf(in, " %c", &t);
				printf("Input second vector: \n ");
				for (j = 0; j < i; j++)		
						{
					fscanf(in, "%f", &d[j]);
				}
				switch (t) {
				case '-': 								
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ", c[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, " %c ", '-');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ",  d[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, " %c ", '=');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
							{
						fprintf(out, "%f ", c[j] - d[j]);
					}
					fprintf(out, "%c", ')');
					break;
				case '+':
					fprintf(out, "%c", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ", c[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, "%c", '+');
					fprintf(out, "%c", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ",  d[j]);
					}
					fprintf(out, "%c", '=');
					fprintf(out, "%c", '(');
					for (j = 0; j < i; j++) {
						fprintf(out, "%f ", c[j] + d[j]);
					}
					fprintf(out, "%c", ')');
					break;
				case '*':				//цикл вывода скалярного произведения
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ", c[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, " %c ", '*');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ",  d[j]);
					}
					fprintf(out, "%c ", ')');
					fprintf(out, "%c ", '=');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++) {
						fprintf(out, "%f ", c[j] * d[j]);
					}
					fprintf(out, "%c", ')');
					break;
				default:
					fprintf(out, "WRONG OPERATION");	//стоило бы сделать так, чтобы это выводилось сразу после вывода операции, которой нет в перечисленном списке
				}
				free(c);
				free(d);
				fclose(in);
				fclose(out);
			}
			}
			printf("Do you want to continue? (y/n) \n");
			fscanf(in, " %c", &y);
		} while (y == 'y');
		printf("Do you want to continue? (y/n) \n");
		scanf(" %c", &yy);
	} while (yy == 'y');
	return 0;
}
