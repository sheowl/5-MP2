#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 23, 45, 67, 89, 12, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target number: ";
    cin >> target;

    int left = 0;
    int right = size - 1;
    bool found = false;

    while (left < right) {
        if (arr[left] == target || arr[right] == target) {
            found = true;
            break;
        }
        ++left;
        --right;
    }

    // If pointers met in the middle and not checked yet
    if (!found && left == right && arr[left] == target) {
        found = true;
    }

    if (found) {
        cout << "Target " << target << " found!" << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }

    return 0;
}