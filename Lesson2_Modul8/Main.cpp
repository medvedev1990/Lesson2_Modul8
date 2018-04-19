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
		printf("����� �������: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.� �������� ������ �������� ������ ������ ������ ��������� �� ���� ��������. ����� ��� �������� ��������.*/
			char *alphavit = NULL;
			int chek = 0;
			alphavit = (char*)calloc(35, sizeof(char));
			alphavit = "�������������������������������";
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
			/*� �������� ������ ��������� ���������� ������ ��������, �������� � ��� ������*/
			char *str = NULL;
			int chek = 0;
			int simbols = 0;
			str = (char*)calloc(33, sizeof(char));
			str = "��������� ������ ������� �����";
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
				printf("\n���-�� ������ ������� = %d\n", count);
			}
			free(str);
		}
		break;
		case 4:
		{
			//"� �������� ������ ��������� ���������� ����, ���������� ������ �������� ������� �����. ������������� ���� ��������� �������.
			char *string = "� �������� ������ ��������� ���������� ���� ���������� ������ �������� ������� �����";
			printf("%s\n", string);
			int count = 0;
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) >= '�' && *(string + i) <= '�')
					if (*(string + i + 1) == ' ' || *(string + i + 1) == '\0')
						count++;
			}
			printf("%d\n", count);
		}
		break;
		case 5:
		{

			/*�� �������� ������ �������� ������ ����, �������� � ��� ������. ������������� ���� ��������� �������.*/
			char string[] = "�� �������� ������ �������� ������ ����,�������� � ��� ������";
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
			/*��� ������ ��������. ����������, ������� ��������� �������� ����������� � ���. ������� �� �� �����\n*/
			char *string = { "��� ������ ��������" };
			int count = 0;
			int check = 0;
			printf("���������� �������: ");
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
			printf("\n���-�� ���������� �������� = %d\n", count);
		}
		break;
		case 7:
		{

			/*��� ������ ��������. ���������� ����� ������� ������������������ ������ ������ ���� �.*/
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
			printf("����� ������� ������������������ 'a' = %d\n", max);
		}
		break;
		case 8:
		{

			/*��� ������ ��������, ����� ������� ���� ������������� � ������������� ������. ������� �� ����� ������� ��������, ������������� ������ ���� ������.*/
			char *string = "� ���� (�������� ������)";
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
			/*��� ������ ��������, ���������� �����. ���������� ���������� ��������� �������� � ��������� ���� � ������ ����� �������� � ���.*/
			char *string = "����� � ����� �������� ������� ����";
			printf("%s\n", string);
			int up = 0, down = 0, total = 0;
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) >= '�' && *(string + i) <= '�')
					down++;
				if (*(string + i) >= '�' && *(string + i) <= '�')
					up++;
				total++;
			}
			printf("\n�������� - %d (%2.2f%%)\n", down, (float)down * 100 / (float)total);
			printf("��������� - %d (%2.2f%%)\n", up, (float)up * 100 / (float)total);
			break;
		}
		case 10:
		{
			/*��� ������ ��������, ����� ������� ���� ���� ������������� � ���� ������������� ������. ������� �� ����� ��� �������, ������������� ������ ���� ������*/
			char *string = "������(���� ������� ��� ������ ��� ���)";
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
		default:printf("��� �������\n");
			break;
		}
		printf("���������� 1-��: ");
		scanf("%d", &quit);
	} while (quit == 1);
}