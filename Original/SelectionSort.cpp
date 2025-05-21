#include <iostream>
using namespace std;

//Original and unoptimized code for selection sort
int selectionSort(int arrNumbers[], int intArrLength){
    int intPassCount = 0;

    //Iterates through the array and selects the minimum value in the unsorted portion
    for(int i = 0; i < (intArrLength - 1); i++){ 
        int min = i;
        for(int j = i + 1; j < intArrLength; j++){
            if(arrNumbers[j] < arrNumbers[min]){
                min = j; 
            }
        }

        //Swaps the current element with the found minimum value
        if(min != i){
            int temp = arrNumbers[i];
            arrNumbers[i] = arrNumbers[min];
            arrNumbers[min] = temp;
        }

        intPassCount++;
    }
    return intPassCount;
}

//Printing arrNumbers function
void printArray(int arrNumbers[], int intArrLength){
    for(int i = 0; i < intArrLength; i++){
        cout << arrNumbers[i] << " ";
    }
}

//main function
int main(){
    int arrNumbers[] = {19, 42, 12, 71, 201, 9, 14, 56, 2, 2941, 0, 19};
    int intArrLength = sizeof(arrNumbers) / sizeof(arrNumbers[0]);

    cout << "Unsorted Array: "; printArray(arrNumbers, intArrLength);
    int intPasses = selectionSort(arrNumbers, intArrLength);
    cout << "\nSorted Array: "; printArray(arrNumbers, intArrLength);
    cout << "\nNumber of Passes: " << intPasses;

    return 0;
}