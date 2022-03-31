#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size);
void printArray(int A[], int size);

int main()
{
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
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << ",";
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

