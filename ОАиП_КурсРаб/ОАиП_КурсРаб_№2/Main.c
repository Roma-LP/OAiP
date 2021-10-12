#include <stdio.h>
#include <Windows.h>
 /* Директива #define определяет идентификатор и последовательность символов, которые будут 
подставляться вместо идентификатора каждый раз, когда он встретится в исходном файле*/
#define COUNT_STUDENT 6
#define FILE_NAME "student.txt"

void PrintRatingMode(int stp);
void DoPrintRating();
void ReadFromFile();
void PrintFile();

char name[COUNT_STUDENT][10];
int mark[COUNT_STUDENT][5];
int ratinglist[COUNT_STUDENT][2];

int main()
{
	SetConsoleCP(1251);//настройка на ввод кириллицы (в числе прочего)
	SetConsoleOutputCP(1251);// на вывод

	ReadFromFile();
	PrintFile();

	DoPrintRating();

	PrintRatingMode(5);
	PrintRatingMode(4);
	PrintRatingMode(2);

	getch();
	return 0;
}

void PrintRatingMode(int stp)
{
	switch (stp)
	{
	case 5: {
		printf("Повышенная стипендия:\n");
		for (int i = 0; i < COUNT_STUDENT; i++)
		{
			if (ratinglist[i][1] == 5)
				printf("%20s %d %d %d %d %d\n", name[i], mark[i][0], mark[i][1], mark[i][2], mark[i][3], mark[i][4]);
		}
		break;
	}
	case 4: {
		printf("Обычная стипендия:\n");
		for (int i = 0; i < COUNT_STUDENT; i++)
		{
			if (ratinglist[i][1] == 4)
				printf("%20s %d %d %d %d %d\n", name[i], mark[i][0], mark[i][1], mark[i][2], mark[i][3], mark[i][4]);
		}
		break;
	}
	case 2: {
		printf("Не назначается стипендия:\n");
		for (int i = 0; i < COUNT_STUDENT; i++)
		{
			if (ratinglist[i][1] == 2)
				printf("%20s %d %d %d %d %d\n", name[i], mark[i][0], mark[i][1], mark[i][2], mark[i][3], mark[i][4]);
		}
		break;
	}
	default:
		printf("Ошибка вывода по стипендии(2,4,5) - %d\n",stp);
		break;
	}
}

void DoPrintRating()
{
	for (int i = 0; i < COUNT_STUDENT; i++)
	{
		ratinglist[i][0] = i;  // пронумеровываем студентов
		for (int j = 0; j < 5; j++) // т.к. 5 оценок
		{
			if (mark[i][j] == 5)
			{
				if (ratinglist[i][1] == 5 || ratinglist[i][1] == 0)
					ratinglist[i][1] = 5;
			}
			else
			{
				if (mark[i][j] >= 4)
				{
					if (ratinglist[i][1] >= 4 || ratinglist[i][1] == 0)
						ratinglist[i][1] = 4;
				}
				else
				{
					ratinglist[i][1] = 2;
					break;
				}
			}
		}
	}
	for (int i = 0; i < COUNT_STUDENT; i++)
	{
		printf("%d %d\n", ratinglist[i][0], ratinglist[i][1]);
	}
}

void ReadFromFile()
{
	FILE* fp;
	if ((fp = fopen(FILE_NAME, "r")) == NULL)
	{
		printf("Не удалось открыть файл %s", FILE_NAME);
	}

	for (int i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%s%d%d%d%d%d", &name[i], &mark[i][0], &mark[i][1], &mark[i][2], &mark[i][3], &mark[i][4]);
	}
	fclose(fp);
}

void PrintFile()
{
	for (int i = 0; i < COUNT_STUDENT; i++)
	{
		printf("%20s %d %d %d %d %d\n", name[i], mark[i][0], mark[i][1], mark[i][2], mark[i][3], mark[i][4]);
	}
}

