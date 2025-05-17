#include <iostream>
using namespace std;

//Original and unoptimized code for selection sort
void selectionSort(int array[], int arrLength){
    for(int i = 0; i < (arrLength - 1); i++){
        int min = i;
        for(int j = i + 1; j < arrLength; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }

        if(min != i){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void printArray(int array[], int arrLength){
    for(int i = 0; i < arrLength; i++){
        cout << array[i] << " ";
    }
}

int main(){
    int array[] = {25, 10, 2, 5, 12, 45, 60, 32, 56, 72, 88, 92};
    int arrLength = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted Array: "; printArray(array, arrLength);
    selectionSort(array, arrLength);
    cout << "\nSorted Array: "; printArray(array, arrLength);

    return 0;
}