#include <iostream>
using namespace std;

int bubbleSort(int intArray[], int intSize){
	int intTemp = 0;
	int intPassCounter = 0;
	
	for(int i = 0; i < intSize - 1; i++){
		intPassCounter++; // Increments for each pass done by the algorithm
		for(int j = 0; j < intSize - i - 1; j++){
			if(intArray[j] > intArray[j + 1]){
				intTemp = intArray[j];
				intArray[j] = intArray[j + 1];
				intArray[j + 1] = intTemp;
			}
		}
	} return intPassCounter;
}

void printArray(int intArray[], int intSize){
    for(int i = 0; i < intSize; i++){
        cout << intArray[i] << " ";
    }
    cout << endl;
}

int main(){
    int intArray[] = {63, 48, 73, 24, 17, 19};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int intPasses = bubbleSort(intArray, intSize);

	// Prints unsorted array
    cout << "Unsorted Array: ";
    printArray(intArray, intSize);

	// Prints sorted array
    cout << "Sorted Array: ";
    printArray(intArray, intSize);

	// Prints number of passes
    cout << "Number of Passes: " << intPasses << endl;

    return 0;
}
