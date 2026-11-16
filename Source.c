#include <stdio.h>
#include <locale.h>
#include <math.h>

#define SYMBOL '*'

float area(float a);
void definition();
void draw(int a);

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;
    int a;

    printf("Введите длину стороны треугольника: ");
    scanf("%d", &a);

    if (a <= 0)
    {
        printf("Ошибка! Длина стороны должна быть положительной.\n");
        return 1;
    }

    do
    {
        printf("\nМЕНЮ\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выход\n");

        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Площадь треугольника: %.2f\n", area(a));
            break;

        case 2:
            definition();
            break;

        case 3:
            draw(a);
            break;

        case 0:
            printf("Завершение программы.\n");
            break;

        default:
            printf("Неверный пункт меню!\n");
        }

    } while (choice != 0);

    return 0;
}

float area(float a)
{
    return (a * a * sqrt(3)) / 4;
}

void definition()
{
    printf("\nРавносторонний треугольник — это треугольник,\n");
    printf("у которого все три стороны равны,\n");
    printf("а все три угла составляют 60 градусов.\n");
}

void draw(int a)
{
    int i, j;

    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= a - i; j++)
        {
            printf(" ");
        }

        for (j = 1; j <= 2 * i - 1; j++)
        {
            if (i == a || j == 1 || j == 2 * i - 1)
            {
                printf("%c", SYMBOL);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}