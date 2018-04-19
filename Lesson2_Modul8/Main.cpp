#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include"Header.h"
#include<string.h>

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int n, quit;
	do
	{
		printf("номер задания: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.В заданной строке заменить каждый символ строки следующим по коду символом. Букву «я» заменить пробелом.*/
			char *alphavit = NULL;
			int chek = 0;
			alphavit = (char*)calloc(35, sizeof(char));
			alphavit = "абвгдеёжзийклмнопртуфхцчшщбыьэюя";
			if (alphavit != NULL)
			{
				int i;
				for (int i = 0; i < strlen(alphavit); i++)
				{
					printf("%c", *(alphavit + i) + 1);
				}
				printf("\n");
			}
			else
				printf("no memmory");
			free(alphavit);
		}
		break;
		case 2:
		{
			/*В заданной строке посчитать количество разных символов, входящих в эту строку*/
			char *str = NULL;
			int chek = 0;
			int simbols = 0;
			str = (char*)calloc(33, sizeof(char));
			str = "маленькой елочке холодно зимой";
			if (str != NULL)
			{
				int count = 0;
				for (int i = 0; i < strlen(str); i++)
				{
					for (int j = 0; j < strlen(str); j++)
					{
						if ((*(str + i) == *(str + j)) && (i != j))
						{
							i++;
							break;
						}
					}
					count++;
				}
				printf("\nКол-во разных сиволов = %d\n", count);
			}
			free(str);
		}
		break;
		case 4:
		{
			//"В заданной строке посчитать количество слов, содержащих только строчные русские буквы. Разделителями слов считаются пробелы.
			char *string = "В заданной строке посчитать количество слов содержащих только строчные русские буквы";
			printf("%s\n", string);
			int count = 0;
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) >= 'а' && *(string + i) <= 'я')
					if (*(string + i + 1) == ' ' || *(string + i + 1) == '\0')
						count++;
			}
			printf("%d\n", count);
		}
		break;
		case 5:
		{

			/*По заданной строке получить массив слов, входящих в эту строку. Разделителями слов считаются пробелы.*/
			char string[] = "По заданной строке получить массив слов,входящих в эту строку";
			printf("%s\n", string);
			char *pt = strtok(string, " ,");
			while (pt != NULL)
			{
				printf("%s\n", pt);
				pt = strtok(NULL, " ,");
			}
		}
		break;
		case 6:
		{
			/*Дан массив символов. Подсчитать, сколько различных символов встречается в нем. Вывести их на экран\n*/
			char *string = { "Дан массив символов" };
			int count = 0;
			int check = 0;
			printf("Уникальные символы: ");
			for (int i = 0; i < strlen(string); i++)
			{
				check = 0;
				for (int j = 0; j < strlen(string); j++)
				{
					if ((*(string + i) == *(string + j)) && i != j)
						check++;
				}
				if (check == 0)
				{
					count++;
					printf("[%c]", *(string + i));
				}
			}
			printf("\nКол-во уникальных символов = %d\n", count);
		}
		break;
		case 7:
		{

			/*Дан массив символов. Подсчитать самую длинную последовательность подряд идущих букв а.*/
			char *string = { "aaaadsjdlkfjaaaskddlaa" };
			printf("%s\n", string);
			int len = 0;
			int max = len;
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) == 'a')
					len++;
				else
				{
					if (len > max)
						max = len;
					len = 0;
				}
			}
			printf("Самая длинная последовательность 'a' = %d\n", max);
		}
		break;
		case 8:
		{

			/*Дан массив символов, среди которых есть открывающиеся и закрывающиеся скобки. Вывести на экран массивы символов, расположенные внутри этих скобок.*/
			char *string = "В лесу (родилась елочка)";
			char *copystring = NULL;
			copystring = (char*)calloc(strlen(string), sizeof(char));
			printf("%s\n", string);
			int k = 0;
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i - 1) == '(')
					do
					{
						*(copystring + k) = *(string + i);
						i++;
						k++;
					} while (*(string + i) != ')');
			}
			char *pt = strtok(copystring, " ,");
			while (pt != NULL)
			{
				printf("%s\n", pt);
				pt = strtok(NULL, " ,");
			}
			printf("\n");
			free(copystring);
		}
		break;
		case 9:
		{
			/*Дан массив символов, содержащий текст. Определить процентное отношение строчных и прописных букв к общему числу символов в нем.*/
			char *string = "Зимой и летом Стройная зеЛеная была";
			printf("%s\n", string);
			int up = 0, down = 0, total = 0;
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) >= 'а' && *(string + i) <= 'я')
					down++;
				if (*(string + i) >= 'А' && *(string + i) <= 'Я')
					up++;
				total++;
			}
			printf("\nСтрочных - %d (%2.2f%%)\n", down, (float)down * 100 / (float)total);
			printf("Прописных - %d (%2.2f%%)\n", up, (float)up * 100 / (float)total);
			break;
		}
		case 10:
		{
			/*Дан массив символов, среди которых есть одна открывающаяся и одна закрывающаяся скобка. Вывести на экран все символы, расположенные внутри этих скобок*/
			char *string = "Метели(Пели песенку спи елечка баю бай)";
			printf("%s\n", string);
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i - 1) == '(')
					do
					{
						printf("%c", *(string + i));
						i++;
					} while (*(string + i) != ')');
			}
			printf("\n");
		}
		break;
		default:printf("нет задания\n");
			break;
		}
		printf("продолжить 1-Да: ");
		scanf("%d", &quit);
	} while (quit == 1);
}