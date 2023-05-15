#include <iostream> 
#include <time.h> 
#include <cstdlib>
#include <iomanip> 
#include <Windows.h>
#include <chrono>
#include <fstream>
#include "sorts.h"
using namespace std;

int exetime[2] = { 0,MAXINT };

int Sorts::ExeTimeName()
{
    int k = exetime[0];
    return k;
}

int Sorts::ExeTimeTime()
{
    int t = exetime[1];
    return t;
}


Sorts::Sorts()
{
    ifstream in("500_rand.txt");
    int a, i = 0;
    while (in >> a)
    {
        arr_500r[i] = a;
        i++;
    }
    i = 0;
    in.close();

    ifstream gin("5k_rand.txt");
    a = 0;
    while (gin >> a)
    {
        arr_5kr[i] = a;
        i++;
    }
    i = 0;
    gin.close(); 
    
    ifstream qin("10k_rand.txt");
    a = 0;
    while (qin >> a)
    {
        arr_10kr[i] = a;
        i++;
    }
    i = 0;
    qin.close();

    ifstream fin("arr_500_sorted.txt");
    a = 0;
    while (fin >> a)
    {
        arr_500s[i] = a;
        i++;
    }
    i = 0;
    fin.close(); 
    
    ifstream lin("arr_5k_sorted.txt");
    a = 0;
    while (lin >> a)
    {
        arr_5ks[i] = a;
        i++;
    }
    i = 0;
    lin.close();

    ifstream ein("arr_10k_sorted.txt");
    a = 0;
    while (ein >> a)
    {
        arr_10ks[i] = a;
        i++;
    }
    i = 0;
    ein.close();

    ifstream tin("arr_500_reverse.txt");
    a = 0;
    while (tin >> a)
    {
        arr_500rev[i] = a;
        i++;
    }
    i = 0;
    tin.close(); 

    ifstream yin("arr_5k_reverse.txt");
    a = 0;
    while (yin >> a)
    {
        arr_5krev[i] = a;
        i++;
    }
    i = 0;
    yin.close();

    ifstream oin("arr_10k_reverse.txt");
    a = 0;
    while (oin >> a)
    {
        arr_10krev[i] = a;
        i++;
    }
    oin.close();
}

Sorts::~Sorts()
{
}

void Sorts::bubbleSort()
{
    cout << "................................................\n";
    int cnt = 0, time = MAXINT;
    cout << setprecision(4) << fixed << "Bubble sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    while (cnt < 3)
    {
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        if (time >= bSort(array_100, n)) { time = bSort(array_100, n); }
        cout << "\t" << bSort(array_100, n) << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        if (time >= bSort(array_5k, n)) { time = bSort(array_5k, n); }
        cout << bSort(array_5k, n) << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        if (time >= bSort(array_10k, n)) { time = bSort(array_10k, n); }
        cout << bSort(array_10k, n) << "\n\n";

        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time){exetime[0] = 1;exetime[1] = time;}
}

int Sorts::bSort(int* array, int size)
{
    int temp = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}

void Sorts::insertSort()
{
    cout << "................................................\n";
    cout << "\nInsertion sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    int cnt = 0, time = MAXINT;
    while (cnt < 3)
    {
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        if (time >= iSort(array_100, n)) { time = iSort(array_100, n); }
        cout << "\t" << iSort(array_100, n) << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        if (time >= iSort(array_5k, n)) { time = iSort(array_5k, n); }
        cout << iSort(array_5k, n) << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        if (time >= iSort(array_10k, n)) { time = iSort(array_10k, n); }
        cout << iSort(array_10k, n) << "\n\n";
        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time) { exetime[0] = 2; exetime[1] = time; }
}

int Sorts::iSort(int* array, int size)
{
    int key, j;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}

void Sorts::selectionSort()
{
    cout << "................................................\n";
    cout << "\nSelection sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    int cnt = 0, time = MAXINT;
    while (cnt < 3)
    {
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        if (time >= sSort(array_100, n)) { time = sSort(array_100, n); }
        cout << "\t" << sSort(array_100, n) << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        if (time >= sSort(array_5k, n)) { time = sSort(array_5k, n); }
        cout << sSort(array_5k, n) << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        if (time >= sSort(array_10k, n)) { time = sSort(array_10k, n); }
        cout << sSort(array_10k, n) << "\n\n";

        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time) { exetime[0] = 3; exetime[1] = time; }
}

int Sorts::sSort(int* array, int size)
{
    int j = 0;
    int temp = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        j = i;
        for (int k = i; k < size; k++)
        {
            if (array[j] > array[k])
            {
                j = k;
            }
        }
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}

void Sorts::quickSort()
{
    cout << "................................................\n";
    cout << "\nQuick sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    int cnt = 0;
    int time2, time1 = MAXINT;
    while (cnt < 3)
    {
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        auto start = chrono::high_resolution_clock::now();
        qSort(array_100, 0, n);
        auto stop = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::microseconds>(stop - start);
        time2 = time.count();
        if (time1 >= time2) { time1 = time2; }
        cout << "\t" << time.count() << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        start = chrono::high_resolution_clock::now();
        qSort(array_5k, 0, n);
        stop = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::microseconds>(stop - start);
        time2 = time.count();
        if (time1 >= time2) { time1 = time2; }
        cout << time.count() << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        start = chrono::high_resolution_clock::now();
        qSort(array_10k, 0, n);
        stop = chrono::high_resolution_clock::now();
        time = chrono::duration_cast<chrono::microseconds>(stop - start);
        time2 = time.count();
        if (time1 >= time2) { time1 = time2; }
        cout << time.count() << "\n\n";

        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time2) { exetime[0] = 4; exetime[1] = time2; }
}

void Sorts::shellSort()
{
    cout << "................................................\n";
    cout << "\nShell sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    int cnt = 0, time = MAXINT;
    while (cnt < 3)
    {
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        if (time >= shSort(array_100, n)) { time = shSort(array_100, n); }
        cout << "\t" << shSort(array_100, n) << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        if (time >= shSort(array_5k, n)) { time = shSort(array_5k, n); }
        cout << shSort(array_5k, n) << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        if (time >= shSort(array_10k, n)) { time = shSort(array_10k, n); }
        cout << shSort(array_10k, n) << "\n\n";

        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time) { exetime[0] = 5; exetime[1] = time; }
}

void Sorts::qSort(int* array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;
    //clock_t time_begin = clock();
    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        qSort(array, low, j);
    if (i < high)
        qSort(array, i, high);
    //clock_t time_end = clock();
    //double time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    //return time_spent;
}

int Sorts::shSort(int* arr, int size)
{
    auto start = chrono::high_resolution_clock::now();
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}

double Sorts::check(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return -1.0;
        }
    }
    return 0.0;
}

void Sorts::mergeSort()
{
    cout << "................................................\n";
    cout << "\nMerge sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    int cnt = 0, time = MAXINT;
    while (cnt < 3)
    {
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        if (time >= mSort(array_100, n)) { time = mSort(array_100, n); }
        cout << "\t" << mSort(array_100, n) << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        if (time >= mSort(array_5k, n)) { time = mSort(array_5k, n); }
        cout << mSort(array_5k, n) << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        if (time >= mSort(array_10k, n)) { time = mSort(array_10k, n); }
        cout << mSort(array_10k, n) << "\n\n";

        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time) { exetime[0] = 6; exetime[1] = time; }
}

int Sorts::mSort(int* array, int size)
{
    auto start = chrono::high_resolution_clock::now();
    int mid = size / 2;
    if (size % 2 == 1)
        mid++;
    int h = 1;
    int* c = (int*)malloc(size * sizeof(int));
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            {
                if (array[i] < array[j])
                {
                    c[k] = array[i];
                    i++; k++;
                }
                else {
                    c[k] = array[j];
                    j++; k++;
                }
            }
            while (i < step)
            {
                c[k] = array[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            {
                c[k] = array[j];
                j++; k++;
            }
            step = step + h;
        }
        h = h * 2;

        for (i = 0; i < size; i++)
            array[i] = c[i];
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}


void Sorts::reverse()
{
    for (int i = 0; i < sizeof(array_100) / sizeof(array_100[0]); i++)
    {
        array_100[i] = arr_500rev[i];
    }
    for (int i = 0; i < sizeof(array_5k) / sizeof(array_5k[0]); i++)
    {
        array_5k[i] = arr_5krev[i];
    }
    for (int i = 0; i < sizeof(array_10k) / sizeof(array_10k[0]); i++)
    {
        array_10k[i] = arr_10krev[i];
    }
}

void Sorts::random()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < sizeof(array_100) / sizeof(array_100[0]); i++)
    {
        array_100[i] = arr_500r[i];
    }
    for (int i = 0; i < sizeof(array_5k) / sizeof(array_5k[0]); i++)
    {
        array_5k[i] = arr_5kr[i];
    }
    for (int i = 0; i < sizeof(array_10k) / sizeof(array_10k[0]); i++)
    {
        array_10k[i] = arr_10kr[i];
    }
}

void Sorts::sorted()
{
    for (int i = 0; i < sizeof(array_100) / sizeof(array_100[0]); i++)
    {
        array_100[i] = arr_500s[i];
    }
    for (int i = 0; i < sizeof(array_5k) / sizeof(array_5k[0]); i++)
    {
        array_5k[i] = arr_5ks[i];
    }
    for (int i = 0; i < sizeof(array_10k) / sizeof(array_10k[0]); i++)
    {
        array_10k[i] = arr_10ks[i];
    }
    
}

void Sorts::merge(int* arr, int l, int mid, int r)
{

    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

int Sorts::nmSort(int* arr, int n)
{
    auto start = chrono::high_resolution_clock::now();
    int left, mid, right;
    bool flag = true;
    while (flag) {
        left = 0, mid = 0, right = 0;
        flag = false;
        while (right < n) {

            if (right == n - 1 || arr[right] > arr[right + 1]) {
                if (mid < right) {
                    if (!flag) flag = true;
                    merge(arr, left, mid, right);
                }
                left = right + 1;
                mid = left;
            }
            else if (!flag && arr[left] > arr[right]) {
                mid = right;
            }
            right++;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}



void Sorts::natMeregeSort()
{
    cout << "................................................\n";
    cout << "\nNatural merege sort:\n";
    cout << " \t\t\t500\t5000\t10000\n\n";
    int cnt = 0, time = MAXINT;
    while (cnt < 3)
    {
        
        if (cnt == 1) { reverse(); cout << " Back sorted array:"; }
        else if (cnt == 2) { random(); cout << " Random array:\t"; }
        else { sorted(); cout << " Sorted array:\t"; }

        int n = sizeof(array_100) / sizeof(array_100[0]);
        if (time >= nmSort(array_100, n)) { time = nmSort(array_100, n); }
        cout << "\t" << nmSort(array_100, n) << "\t";

        n = sizeof(array_5k) / sizeof(array_5k[0]);
        if (time >= nmSort(array_5k, n)) { time = nmSort(array_5k, n); }
        cout << nmSort(array_5k, n) << "\t";

        n = sizeof(array_10k) / sizeof(array_10k[0]);
        if (time >= nmSort(array_10k, n)) { time = nmSort(array_10k, n); }
        cout << nmSort(array_10k, n) << "\n\n";

        cnt++;
    }
    cout << "Best time is " << time << "\n\n";
    if (exetime[1] > time) { exetime[0] = 7; exetime[1] = time; }
}


