#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size);
void printArray(int A[], int size);

void selectionSort(int a[], int size);

void insertionSort(int a[], int size);

void fillRandomNum(int a[], int size);

int main()
{
	/*	Create array of 10,000 numbers	*/
	cout << "Before testArray\n";

	const int TEST_SIZE = 1000;
	int* testArr = new int[TEST_SIZE];

	fillRandomNum(testArr, TEST_SIZE);

	printArray(testArr, TEST_SIZE);




	cout << "After testArray\n";



	/* BubbleSort - Kyle G. */

	int arr[] = { 2, 5, 6, 2, 1, 5, 6, 7, 1, 2 };
	int size = (sizeof(arr) / sizeof(arr[0]));

	cout << "Print Array: \n";
	printArray(arr, size);
	cout << "\n";

	BubbleSort(arr, size);
	cout << "\nArray after BubbleSort\n" << endl;

	cout << "Print Array: \n";
	printArray(arr, size);
	cout << "\n";


	/*	selectionSort - Vincent C. 	*/

	int selectionarr[] = { 77, 44, 22, 88, 99, 11, 33, 55, 66, 0 };
	int selectionsize = (sizeof(selectionarr) / sizeof(selectionarr[0]));


	cout << "print selectionarr[]: ";					// Print original array
	printArray(selectionarr, selectionsize);

	selectionSort(selectionarr, selectionsize);			// selectionSort by ascending order, passing arr and size into function

	cout << "\nselectionArr[] after selectionsort: ";	// Print sorted array
	printArray(selectionarr, selectionsize);
	cout << "\n\n";

	/*	insertionSort - Vincent C.	*/

	int insertionArr[] = { 340, 220, 150, 490, 580, 900, 830, 760, 640, 0 };	// Initialize array
	int insertionSize = (sizeof(insertionArr) / sizeof(insertionArr[0]));		// Initialize insertionSize

	cout << "Print insertionArr[]: ";
	printArray(insertionArr, insertionSize);			// Print original insertionArr[]

	insertionSort(insertionArr, insertionSize);

	cout << "\ninsertionArr[] after insertionSort: ";
	printArray(insertionArr, insertionSize);
	cout << "\n\n";


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
void fillRandomNum(int a[], int size) {
	cout << "Initialize array elements with 1000 random num\n";
	for (int i = 0; i < size; i++) {
		a[i] = rand() % size + 1;
	}
}


void insertionSort(int a[], int size) {
	int i = 0;
	int j = 0;
	int temp = 0;  // Temporary variable for swap

	for (i = 1; i < size; ++i) {
		j = i;
		// Insert numbers[i] into sorted part
		// stopping once numbers[i] in correct position
		while (j > 0 && a[j] < a[j - 1]) {

			/*	Swap numbers[j] and numbers[j - 1]	*/
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			--j;							// Decrement index of inserted element
		}
	}
}


void selectionSort(int a[], int size) {
	int outer, inner, min;

	for (outer = 0; outer < size - 1; outer++) {
		min = outer;

		for (inner = outer + 1; inner < size; inner++) {
			if (a[inner] < a[min]) {
				min = inner;
			}
		}

		int temp = a[outer];
		a[outer] = a[min];
		a[min] = temp;
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



