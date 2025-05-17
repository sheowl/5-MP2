#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // return the index
        }
    }
    return -1; // not found
}

int main() {
    int intArrSize;

    cout << "Enter array size: ";
    cin >> intArrSize;

    int* arrContainer = new int[intArrSize];

    cout << "Enter " << intArrSize << " integers:\n";
    for (int i = 0; i < intArrSize; ++i) {
        cout << "[" << i + 1 << "]: ";
        cin >> arrContainer[i];
    }

    int intTarget;
    cout << "Enter target number: ";
    cin >> intTarget;

    int result = linearSearch(arrContainer, intArrSize, intTarget);

    if (result != -1)
        cout << "Present at index " << result << endl;
    else
        cout << "Target not present" << endl;

    delete[] arrContainer;
    return 0;
}
