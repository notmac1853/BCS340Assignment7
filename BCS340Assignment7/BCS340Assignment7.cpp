// BCS340Assignment7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h> 
#include <stdio.h>
#include <vector>
using namespace std;

void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << ",";
    cout << endl;
}



void insertionSort(int arr[], int size){
    //setting variables for the current, previous positions, and a variable for the temporay value
    //that will be copied into a certain position
    int curr, prev, temp;
    //for loop to iterate over the array
    for (curr = 1; curr < size; curr++) {
        //assign the value at current to temp
        temp = arr[curr];
        //the previous array element is curr - 1
        prev = curr - 1;

        //shift elements greater than the temp one position ahead
        while (prev >= 0 && arr[prev] > temp) {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
        arr[prev + 1] = temp;
    }

}

void merge(int arr[], int leftIndex, int mid, int rightIndex){
    //initialize iterators. i for the the first index of subarray1
    //j is the first index of subarray2
    //k is the first index of the merged subarray
    int i, j, k;
    int size1 = mid - leftIndex + 1;
    int size2 = rightIndex - mid;

    //initializing temporary arrays of variable size
    int* temp1 = new int[size1];
    int* temp2 = new int[size2];


    //copying the data to the temporary arrays
    for (i = 0; i < size1; i++) {
        temp1[i] = arr[leftIndex + i];
    }
    for (j = 0; j < size2; j++) {
        temp2[j] = arr[mid + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = leftIndex; 


    //merge the temporary arrays back
    while (i < size1 && j < size2){
        if (temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
        }
        else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    //copy remaining elements of temp1
    while (i < size1){
        arr[k] = temp1[i];
        i++;
        k++;
    }

    //copy remaining elements of temp2
    while (j < size2){
        arr[k] = temp2[j];
        j++;
        k++;
    }

    //calling array delete on the two temporary arrays
    delete[] temp1;
    delete[] temp2;
}

void mergeSort(int arr[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        //get the midpoint
        int mid = leftIndex + (rightIndex - leftIndex) / 2;

        //we call mergesort recursively to sort halves 1 and 2
        mergeSort(arr, leftIndex, mid);
        mergeSort(arr, mid + 1, rightIndex);

        merge(arr, leftIndex, mid, rightIndex);
    }
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1); 
    //insertionSort(arr, arr_size);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}


