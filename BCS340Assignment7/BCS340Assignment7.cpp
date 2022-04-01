// BCS340Assignment7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << ",";
    cout << endl;
}



void insertionSort(int arr[], int size)
{
    int curr, prev, temp;
    for (curr = 1; curr < size; curr++) {
        temp = arr[curr];
        prev = curr - 1;

        while (prev >= 0 && arr[prev] > temp) {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
        arr[prev + 1] = temp;
    }

}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    //mergeSort(arr, 0, arr_size - 1); 
    insertionSort(arr, arr_size);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
