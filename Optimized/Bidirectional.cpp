#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 23, 45, 67, 89, 12, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target number: ";
    cin >> target;

    bool found = false;

    for (int i = 0; i <= size / 2; ++i) {
        if (arr[i] == target) {
            cout << "Target [" << target << "] found at index " << i << endl;
            found = true;
            break;
        } 
        else if (arr[size - 1 - i] == target) {
            cout << "Target [" << target << "] found at index " << (size - 1 - i) << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Target [" << target << "] not found in array." << endl;
    }

    return 0;
}
