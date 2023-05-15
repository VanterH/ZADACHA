#include <iostream> 
#include <time.h> 
#include <cstdlib>
#include <iomanip> 
#include <Windows.h>
#include "Sorts.h"
//#include "Interface.h"
using namespace std;

void defineSort(int k, int t) {
    switch (k)
    {
    case 1:
        cout << "Best is bubble sort, it time is" << t;
    case 2:
        cout << "Best is insert sort, it time is" << t;
    case 3:
        cout << "Best is selection sort, it time is" << t;
    case 4:
        cout << "Best is quick sort, it time is" << t;
    case 5:
        cout << "Best is shell sort, it time is" << t;
    case 6:
        cout << "Best is merege sort, it time is" << t;
    case 7:
        cout << "Best is natural merege sort, it time is" << t;
    }

}

int main()
{
    Sorts smth;
link:
    int key, n = 0;
    system("cls");
    cout << "1.Bubble Sort.\n2.Insertion Sort.\n3.Selection Sort.\n4.Quick Sort.\n5.Shell Sort.\n6.Merege Sort.\n7.Natural Merege Sort.\n8.Best of them all.";
    cin >> key;
    switch (key)
    {
    case 1:
        system("cls");
        smth.bubbleSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 2:
        system("cls");
        smth.insertSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 3:
        system("cls");
        smth.selectionSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 4:
        system("cls");
        smth.quickSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 5:
        system("cls");
        smth.shellSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 6:
        system("cls");
        smth.mergeSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 7:
        system("cls");
        smth.natMeregeSort();
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    case 8:
        system("cls");
        smth.bubbleSort();
        smth.insertSort();
        smth.selectionSort();
        smth.quickSort();
        smth.shellSort();
        smth.mergeSort();
        //smth.natMeregeSort();
        defineSort(smth.ExeTimeName(), smth.ExeTimeTime());
        cout << "To exit the menu press 9\n";
        while (n != 9) cin >> n;
        goto link;
        break;
    }

    //smth.natMeregeSort();
    //system("cls");

}


/*
1.qSort() ошибка из-за рекурсивности ф-ии+
2.общий инетрфейс
3.Ввод вывод файла+
4.Разобраться с подсётом времени+
5.Переделать массивы в динамический массив -?
6.Переписать ф-ии: random(), revrse(), запуска сортровки; для работы с динамическим массивом -?
7.Разобраться с подключаемыми файлами+
8.Дописать оставшиеся сортировки+

шелла+
вставка список+
пузырь+
бытсрая+
пр выыбор+
слиягие+
ест слияние+

*/