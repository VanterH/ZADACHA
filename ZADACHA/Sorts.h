#pragma once

class Sorts
{
public:
    Sorts();
    ~Sorts();
    void bubbleSort();
    void insertSort();
    void selectionSort();
    void quickSort();
    void shellSort();
    void mergeSort();
    void natMeregeSort();
    int ExeTimeName();
    int ExeTimeTime();

private:
    int array_100[500];
    int array_5k[5000];
    int array_10k[10000];

    int arr_500[500];
    int arr_5k[5000];
    int arr_10k[10000];

    int arr_500s[500];
    int arr_5ks[5000];
    int arr_10ks[10000];

    int arr_500r[500];
    int arr_5kr[5000];
    int arr_10kr[10000];

    int arr_500rev[500];
    int arr_5krev[5000];
    int arr_10krev[10000];
    //void readFile();
    void reverse();
    void random();
    void sorted();
    int bSort(int* array, int size);
    int iSort(int* array, int size);
    int sSort(int* array, int size);
    void qSort(int* array, int low, int high);
    int shSort(int* array, int size);
    double check(int* array, int size);
    int mSort(int* array, int size);
    int nmSort(int* arr, int n);
    void merge(int* arr, int l, int mid, int r);
    
};

