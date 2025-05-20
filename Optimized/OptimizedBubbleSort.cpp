#include <iostream>
using namespace std;

int smartBubbleSort(int intArray[], int intSize){
	int intTemp = 0;
	int intPassCounter = 0;
	bool flag = true;
	int start = 0;
	int end = intSize - 1;

	while (flag){
		flag = false;

		// Forward pass
		for (int i = start; i < end; i++){
			if (intArray[i] > intArray[i + 1]){
				intTemp = intArray[i];
				intArray[i] = intArray[i + 1];
				intArray[i + 1] = intTemp;
				flag = true;
			}
		}

		// If nothing moved, the array is sorted
		if (!flag)
			break;

		// Otherwise, prepare for the next backward pass
		flag = false;
		end--;
		intPassCounter++;

		// Backward pass
		for (int i = end; i > start; i--){
			if (intArray[i] < intArray[i - 1]){
				intTemp = intArray[i];
				intArray[i] = intArray[i - 1];
				intArray[i - 1] = intTemp;
				flag = true;
			}
		}
		start++;
		intPassCounter++;
	}

	return intPassCounter;
}

void printArray(int intArray[], int intSize){
	for (int i = 0; i < intSize; i++){
		cout << intArray[i] << " ";
	}
	cout << endl;
}

int main(){
	int intArray[] = {17, 48, 4, 24, 63, 19, 73};
	int intSize = sizeof(intArray) / sizeof(intArray[0]);

	// Prints unsorted array
	cout << "Unsorted Array: ";
	printArray(intArray, intSize);

	int intPasses = smartBubbleSort(intArray, intSize);

	// Prints sorted array
	cout << "Sorted Array: ";
	printArray(intArray, intSize);

	// Prints number of passes
	cout << "Number of Passes: " << intPasses << endl;

	return 0;
}

