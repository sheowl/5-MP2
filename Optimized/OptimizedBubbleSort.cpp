#include <iostream>
using namespace std;

int cocktailSort(int intArray[], int intSize) {
    int intTemp = 0;
    int start = 0;
    int end = intSize - 1;
    int intPassCounter = 0;
    bool flag = true;
    
    while (flag) {
        flag = false;

        // Forward pass
        for (int i = start; i < end; i++) {
            if (intArray[i] > intArray[i + 1]) {
                intTemp = intArray[i];
                intArray[i] = intArray[i + 1];
                intArray[i + 1] = intTemp;
                flag = true;
            }
        }

        intPassCounter++;

        if (!flag)
            break;

        flag = false;
        end--;

        // Backward pass
        for (int i = end; i > start; i--) {
            if (intArray[i] < intArray[i - 1]) {
                intTemp = intArray[i];
                intArray[i] = intArray[i - 1];
                intArray[i - 1] = intTemp;
                flag = true;
            }
        }

        intPassCounter++;
        start++;
    }

    return intPassCounter;
}

void printArray(int intArray[], int intSize) {
    for (int i = 0; i < intSize; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArray[] = {17, 48, 4, 24, 63, 19, 73};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    // Print unsorted array
    cout << "Unsorted Array: ";
    printArray(intArray, intSize);

    int intPasses = cocktailSort(intArray, intSize);

    // Print sorted array
    cout << "Sorted Array: ";
    printArray(intArray, intSize);

    // Print number of passes
    cout << "Number of Passes: " << intPasses << endl;

    return 0;
}

