/*
Задание 1. Написать программу, которая содержит функцию Action, 
принимающую в качестве аргумента, указатели на два массива (А и В) 
и размеры массивов, а такжеуказатель на функцию.
Пользователю отображается меню, в котором он
может выбрать max, min, avg. Если выбран max — 
передается указатель на функцию, которая ищет максимум,
если выбран min — передается указатель на функцию,
которая ищет минимум, если выбран avg — передается
указатель на функцию, которая ищет среднее.
Возвращаемое значение функции Action результат
выбора пользователя max, min, avg.
*/

#include <iostream>

using namespace std;

void printMassiv(int const* massiv, int const& size);
double action(int const* massiv, int const massivSize, double(*pAction) (int const* massiv, int const& size));
double searchMin(int const* massiv, int const& size);
double searchMax(int const* massiv, int const& size);
double searchAverage(int const* massiv, int const& size);

enum UserChoice
{
    Exit = 0,
    Min = 1,
    Max = 2,
    Average = 3
};

int main()
{
    //указатель на функцию action
    double(*pAction) (int const* massiv, int const& size);
    
    //для выбора пользователя
    int intUserChoice;
    enum UserChoice userChoice;
    //заданные массивы
    int const massivSize = 10;
    int const massiv1[massivSize] = { 1, 2, 3, 4, 5, 0, 8, 12, 5, 15 };
    int const massiv2[massivSize] = { 4, 6, 9, 2, 88, 9, 44, 2, 5, 73 };
    //вывод исходных массивов
    cout << "Massiv 1: ";
    printMassiv(massiv1, massivSize);
    cout << "Massiv 2: ";
    printMassiv(massiv2, massivSize);
    //вывод меню
    cout << "Your choice: " << endl <<
        "0 = exit" << endl <<
        "1 = search min" << endl <<
        "2 = search max" << endl <<
        "3 = search average" << endl;
    cin >> intUserChoice;
    userChoice = (enum UserChoice)intUserChoice;
    //выбор действия
    switch (userChoice)
    {
    case Exit:
        cout << "You want to quit" << endl;
        break;
    case Min:
        pAction = searchMin;
        break;
    case Max:
        pAction = searchMax;
        break;
    case Average:
        pAction = searchAverage;
        break;
    default:
        cout << "Invalid value" << endl;
        return 1;
    }
    cout << "Massiv1 = " << action(massiv1, massivSize,pAction) << endl;
    cout << "Massiv2 = " << action(massiv2, massivSize,pAction) << endl;
}

void printMassiv(int const* massiv, int const& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(massiv + i) << " ";
    }
    cout << endl;
}

double action(int const* massiv, int massivSize, double(*pAction) (int const* massiv, int const& size))
{
    return (*pAction)(massiv, massivSize);
}

double searchMin(int const* massiv, int const& size)
{
    int min = massiv[0];

    for (int i = 0; i < size; i++)
    {
        if (massiv[i] < min)
        {
            min = massiv[i];
        }
    }
    cout << "Min ";
    return min;
}

double searchMax(int const* massiv, int const& size)
{
    int max = massiv[0];

    for (int i = 0; i < size; i++)
    {
        if (massiv[i] > max)
        {
            max = massiv[i];
        }
    }
    cout << "Max ";
    return max;
}

double searchAverage(int const* massiv, int const& size)
{

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += massiv[i];
    }
    double average = (double)sum / size;
    cout << "Average ";
    return average;
}
