#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int arr[], int size);
void printArray(int A[], int size);
void menu();

int main()
{
	
	int userChoice;
	string confirmChoice;
	//Display Menu
	do {
		menu();
		cout << "Choose a number 1-7 from the Menu: ";
		cin >> userChoice;
		//Display Menu Option Buttons
		switch (userChoice)
		{
		case 1: cout << "Selection Sort\n"; break;
		case 2: cout << "Insertion Sort\n"; break;
		case 3: cout << "Bubble Sort\n"; break;
		case 4: cout << "Merge Sort\n"; break;
		case 5: cout << "Quick Sort\n"; break;
		case 6: cout << "Heap Sort\n"; break;
		case 7: cout << "Re-Initialize Array\n"; break;
		default: cout << "Wrong choice\n"; break;
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


