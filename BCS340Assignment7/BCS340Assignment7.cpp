#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size);
void printArray(int A[], int size);

void selectionSort(int selectionSortArr[], int size);

void fillRandomNum(int fillRandomArr[], int size);

void displaySortedArray(int a[], int size);

void quickSort(int quickSortArr[], int lowIndex, int highIndex);
int partition(int a[], int lowIndex, int highIndex);

int main()
{
	/*	Create array of 1,000 numbers	*/
	cout << "Before filling testArray\n";

	const int TEST_SIZE = 1000;
	int* testArr = new int[TEST_SIZE];

	fillRandomNum(testArr, TEST_SIZE);

	printArray(testArr, TEST_SIZE);

	cout << "After filling testArray with random numbers\n\n";



	/* BubbleSort - Kyle G. */

	/*int arr[] = { 2, 5, 6, 2, 1, 5, 6, 7, 1, 2 };
	int size = (sizeof(arr) / sizeof(arr[0]));

	cout << "Print Array: \n";
	printArray(arr, size);
	cout << "\n";

	BubbleSort(arr, size);
	cout << "\nArray after BubbleSort\n" << endl;

	cout << "Print Array: \n";
	printArray(arr, size);
	cout << "\n";*/


	/*	selectionSort - Vincent C. 	*/

	int selectionarr[] = { 77, 44, 22, 88, 99, 11, 33, 55, 66, 0 };
	int selectionsize = (sizeof(selectionarr) / sizeof(selectionarr[0]));


	cout << "print selectionarr[]: \n";					// Print original array
	printArray(selectionarr, selectionsize);

	selectionSort(selectionarr, selectionsize);			// selectionSort by ascending order, passing arr and size into function

	cout << "\nselectionArr[] after selectionsort: \n";	// Print sorted array
	printArray(selectionarr, selectionsize);
	cout << "\n\n";


	/*   QuickSort - Vincent C.	*/

	int quickSortArr[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
	const int QS_SIZE = 8;
	

	cout << "print quickSortArr[]: \n";
	for (int i = 0; i < QS_SIZE; ++i) {
		cout << quickSortArr[i] << " ";
	}
	cout << "\n\n";

	// Initial call to quicksort
	quickSort(quickSortArr, 0, QS_SIZE - 1);

	cout << "sorted quickSortArr[]: \n";
	for (int i = 0; i < QS_SIZE; ++i) {
		cout << quickSortArr[i] << " ";
	}
	cout << "\n\n";
}


void quickSort(int quickSortArr[], int lowIndex, int highIndex) {
	if (lowIndex >= highIndex) { return; }	// Base case: If partition size is 1 or 0 elements, then partition is already sorted

	int lowEndIndex = partition(quickSortArr, lowIndex, highIndex);	// Partition data within array. lowEndIndex is the index of the low partition's last element

	quickSort(quickSortArr, lowIndex, lowEndIndex);		// Recursively sort low partition (lowIndex to lowEndIndex) 
	quickSort(quickSortArr, lowEndIndex + 1, highIndex);	// and high partition (lowEndIndex + 1 to highIndex)
}


int partition(int a[], int lowIndex, int highIndex) {
	
	int midpoint = lowIndex + (highIndex - lowIndex) / 2;	// Pick middle element as pivot
	int pivot = a[midpoint];
	bool done = false;

	while (!done) {

		while (a[lowIndex] < pivot) {	// Increment lowIndex while numbers[lowIndex] < pivot
			lowIndex += 1;
		}

		while (pivot < a[highIndex]) {	// Decrement highIndex while pivot < numbers[highIndex]
			highIndex -= 1;
		}

		if (lowIndex >= highIndex) {	// If zero or one elements remain, then all numbers are 
			done = true;				// partitioned. Return highIndex.
		}
		else {
			/* Swap numbers[lowIndex] and numbers[highIndex]  */
			int temp = a[lowIndex];
			a[lowIndex] = a[highIndex];
			a[highIndex] = temp;

			/* Update lowIndexand highIndex */
			lowIndex += 1;
			highIndex -= 1;
			}
		}
	return highIndex;
}


/* Display first 50 elements */
void displaySortedArray(int a[], int size) {
	cout << "First fifty elements after sort\n";
	for (int i = 0; i < 50; i++) {
		cout << "arr[" << i << "]: " << a[i] << "\n";
	}
	cout << endl;
}


/* Fill with random numbers based on size of array passed in */
void fillRandomNum(int fillRandomArr[], int size) {
	cout << "Initialize array elements with 1000 random num\n";
	for (int i = 0; i < size; i++) {
		fillRandomArr[i] = rand() % size + 1;
	}
}



void selectionSort(int selectionSortArr[], int size) {
	int outer, inner, min;

	for (outer = 0; outer < size - 1; outer++) {
		min = outer;

		for (inner = outer + 1; inner < size; inner++) {
			if (selectionSortArr[inner] < selectionSortArr[min]) {
				min = inner;
			}
		}

		int temp = selectionSortArr[outer];
		selectionSortArr[outer] = selectionSortArr[min];
		selectionSortArr[min] = temp;
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << "arr[" << i << "]: " << A[i] << "\n";
	}
	cout << endl;
}

void BubbleSort(int arr[], int size) {
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



