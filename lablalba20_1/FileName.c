#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

double func(double x);
float Average(const char* filename);

int main() {
    setlocale(LC_ALL, "RUS");
    FILE* file;
    char filename[] = "func.txt";
    double start, end, step;
    do
    {
        printf("������� ������ ��������� (2-4): ");
        scanf("%lf", &start);
    } while (start < 2 || start >= 4);
    do
    {
        printf("������� ����� ��������� (2-4): ");
        scanf("%lf", &end);
    } while (end <= 2 || end > 4 || end <= start);
    do
    {
        printf("������� ��� ���������: ");
        scanf("%lf", &step);
    } while (step <= 0);
    int choice;
    double average;
    do
    {
        printf("�������� ��������\n");
        printf("1 - ������ � ����� ����\n");
        printf("2 - �������� � ������������ ����\n");
        printf("3 - ������� ��������������\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            file = fopen(filename, "w");
            fprintf(file, "x\t\t y\n");
            for (double x = start; x <= end; x += step)
            {
                double y = func(x);
                fprintf(file, "%.4lf\t%.4lf\n", x, y);
            }
            fclose(file);
            printf("���������� �������� � ���� %s\n", filename);
            break;
        case 2:
            file = fopen(filename, "a");
            fprintf(file, "x\t\t y\n");
            for (double x = start; x <= end; x += step)
            {
                double y = func(x);
                fprintf(file, "%.4lf\t%.4lf\n", x, y);
            }
            fclose(file);
            printf("���������� �������� � ���� %s\n", filename);
            break;
        case 3:
            average = Average("func.txt");
            printf("������� ��������������: %f", average);
            return 0;
            break;
        default:
            printf("�������� �����");
            break;
        }
    } while (choice != 4);
}

double func(double x)
{
    return pow(x, 3) + 3 * pow(x, 2) - 3;
}

float Average(const char* filename)
{
    double a, sum = 0;
    int n = 0;
    filename = fopen(filename, "r");
    if (filename == NULL)
    {
        printf("������ ��������\n");
        return 0;
    }
    while (fscanf(filename, "%d", &a) == 1)
    {
        sum += a;
        n++;
    }
    fclose(filename);
    return sum / n;
}