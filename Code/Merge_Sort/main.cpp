//
//  main.cpp
//  Merge_Sort
//
//  Created by Олег Джинганин on 10/12/2019.
//  Copyright © 2019 Олег Джинганин. All rights reserved.
//

#include <iostream>
using namespace std;

class MergeSorting {
private:
    struct ch{
        int a;
        int b;
        double x;
    };
    ch* arr;
    int ArrSize;
public:
    void SetArray(int size){
        arr = new ch[size];
        this->ArrSize=size;
        cout << "Исходный массив: " << endl;
        for (int i = 0; i < size; ++i) {
            arr[i].a = rand() % size + 1;
            arr[i].b = rand() % size + 1;
            arr[i].x = arr[i].a*1.0 / arr[i].b;
            cout << arr[i].a << "/" << arr[i].b<<"\t";
        }
    }
    void MergItems(int arr[], int begin, int end)
    {
        int i = begin,
            t = 0,
            mid = begin + (end - begin) / 2,
            j = mid + 1,
            d[nmax];
           
        while (i <= mid && j <= end){

            if (arr[i] <= arr[j]) {
                d[t] = arr[i]; i++;
            }
            else {
                d[t] = arr[j]; j++;
            }
            t++;
        }

        while (i <= mid){
            d[t] = arr[i]; i++; t++;
        }

        while (j <= end){
            d[t] = arr[j]; j++; t++;
        }

        for (i = 0; i < t; i++)
            arr[begin + i] = d[i];
    }

    void MergSort(int *arr, int left, int right)
    {
        int  temp;
        if (left<right)
        {
            if (right - left == 1)
            {
                if (arr[right]<arr[left])
                {
                    temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                }
            }
            else
            {
                MergSort(arr, left, left + (right - left) / 2);
                MergSort(arr, left + (right - left) / 2 + 1, right);
                MergItems(arr, left, right);
            }
        }
    }
};


int main()
{
    setlocale(0, "");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    MergeSorting obj;
    obj.SetArray(n);
    system("pause");
    return 0;
}

