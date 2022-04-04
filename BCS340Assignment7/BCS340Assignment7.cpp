#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void bubbleSort(int arr[], int size);
void printArray(int A[], int size);
void menu();
void heapsort(int arr[], int numSize);
void maxHeapPercolateDown(int index, int heapArr[], int arrSize);


int main()
{
	int arr[] = { 0,34,56,75,23,1,93,32,46,48,94,200 };
	int size = sizeof(arr) / sizeof(arr[0]);


	int userChoice;
	string confirmChoice;
	//Display Menu
	do {
		printArray(arr, size);
		
		menu();
		cout << "Choose a number 1-7 from the Menu: ";
		cin >> userChoice;
		//Display Menu Option Buttons
		switch (userChoice)
		{
		case 1: 
			cout << "Selection Sort\n"; 
			break;
		case 2: 
			cout << "Insertion Sort\n"; 
			break;
		case 3: 
			cout << "Bubble Sort\n";
			bubbleSort(arr, size);
			printArray(arr, size);
			break;
		case 4: 
			cout << "Merge Sort\n"; 
			break;
		case 5: 
			cout << "Quick Sort\n"; 
			break;
		case 6: 
			cout << "Heap Sort\n";
			heapsort(arr, size);
			printArray(arr, size);
			break;
		case 7: 
			cout << "Re-Initialize Array\n"; 
			break;

		default: cout << "Wrong choice\n"; 
			break;
		}

		cout << "Press x or X to reset the menu: ";
		cin >> confirmChoice;
	} while (confirmChoice == "x" || confirmChoice == "X" );
	return 0;
}


void menu() {
    cout << "======================================================== \n";
    cout << "\t\t\tMENU\n";

    cout << "======================================================== \n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "6. Heap Sort\n";
    cout << "7. Re-Initialize Array to Random\n";
	cout << "======================================================== \n"
		"\t\t\tEND MENU\n\n";
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << ",";
	cout << endl;
}


void bubbleSort(int arr[], int size) {
	int outer, inner, temp;

	//Outer loop
	for (outer = size - 1; outer > 0; outer--) {

		//Inner Loop
		for (inner = 0; inner < outer; inner++) {

			//Swap two nums if needed
			if (arr[inner] > arr[inner + 1]) {
				temp = arr[inner];
				arr[inner] = arr[inner + 1];
				arr[inner + 1] = temp;
			}
		}
	}
}

/*
* HEAP SORT with  MAX PERCOLATE DOWN function
* Two functions to complete the sort. 
* 1. heapSort(int arr, int numSize)
* 2. maxHeapPercolateDown(int index, heapArr, arrSize)
*/

void heapsort(int arr[], int numSize) {
	//Heapify numbers Array
	for (int i = numSize / 2 - 1; i >= 0; i--) {
		maxHeapPercolateDown(i, arr, numSize);
	}

	for (int i = numSize - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		maxHeapPercolateDown(0, arr, i);
	}

}
void maxHeapPercolateDown(int index, int heapArr[], int arrSize) {
	int childIndex = 2 * index + 1;
	int value = heapArr[index];

	while (childIndex < arrSize) {
		//Find the max among the index and all the current nodes children
		int maxValue = value;
		int maxIndex = -1;
		for (int i = 0; i < 2 && i + childIndex < arrSize; i++) {
			if (heapArr[i + childIndex] > maxValue) {
				maxValue = heapArr[i + childIndex];
				maxIndex = i + childIndex;
			}
		}

		if (maxValue == value) {
			return;
		}

		else {
			std::swap(heapArr[index], heapArr[maxIndex]);
			index = maxIndex;
			childIndex = 2 * index + 1;
		}
	}
}





