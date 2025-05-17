#include <iostream>
using namespace std;

int bubbleSort(int array[], int size){
	int temp = 0;
	int passCounter = 0;
	
	for(int i = 0; i < size - 1; i++){
		passCounter++; // Increments for each pass done by the algorithm
		for(int j = 0; j < size - i - 1; j++){
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	} return passCounter;
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array[] = {63, 48, 73, 24, 17, 19};
    int size = sizeof(array) / sizeof(array[0]);
    int passes = bubbleSort(array, size);

	// Prints unsorted array
    cout << "Unsorted Array: ";
    printArray(array, size);

	// Prints sorted array
    cout << "Sorted Array: ";
    printArray(array, size);

	// Prints number of passes
    cout << "Number of Passes: " << passes << endl;

    return 0;
}
