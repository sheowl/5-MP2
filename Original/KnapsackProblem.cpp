#include <iostream>
using namespace std;

int main() {
    int item[4][2] = {{1, 1}, {2, 6}, {3, 10}, {2, 7}};
    int n = 4;
    int mask, i;
    int totalWeight, totalValue;
    int maxWeight = 5, highestValue = 0;
    for(mask = 0; mask < (1 << n); mask++){ 
        totalWeight = 0; 
        totalValue = 0; 
        cout << "\nSubset: "; 
        for(i = 0; i < n; i++){ 
            if(mask & (1 << i)){ 
                totalWeight += item[i][0]; 
                totalValue += item[i][1]; 
                cout << i + 1 << " "; 
            } 
        }
        if(totalWeight <= maxWeight){
            if(highestValue < totalValue){ 
                highestValue = totalValue; 
            }
        }
        else{ 
            cout << "\nExceeds Max Weight!\n"; 
        }
        cout << endl << "Total Weight: " << totalWeight << endl << "Total Value: " << totalValue << endl; 
    }
    cout << "Highest value with total with 5kg restriction: " << highestValue; 

 
    return 0;
}
