#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
#define numCities 4 // total num of cities

int travelingSalesmanProblem(int costMatrix[][numCities], int startCity) {
    vector<int> cityList;
    for (int i = 0; i < numCities; i++) {
        if (i != startCity) {
            cityList.push_back(i);      // initialize excluding the start
        }
    }
    
    int minDistance = INT_MAX; // infinity  
    vector<vector<int>> bestRoute;
    
    do {
        int currentDistance = 0;
        int currentCity = startCity;       // at startCity
        
        for (int i = 0; i < cityList.size(); i++) {
            currentDistance += costMatrix[currentCity][cityList[i]];    // add costs
            currentCity = cityList[i];
        }
        
        currentDistance += costMatrix[currentCity][startCity];      // return to start
        
        // printing of results
        cout << "Route: " << startCity;
        for (int i = 0; i < cityList.size(); i++) {
            cout << " -> " << cityList[i];
        }
        cout << " -> " << startCity << " | Total Distance: " << currentDistance << endl;
        
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute.clear();
            bestRoute.push_back(cityList);
        } else if (currentDistance == minDistance){
            bestRoute.push_back(cityList);
        }
    } while (next_permutation(cityList.begin(), cityList.end()));
    
    cout << endl << "The shortest route(s) is/are: " << endl;
    for (size_t i = 0; i < bestRoute.size(); i++) {
        cout << startCity;
        for (size_t j = 0; j < bestRoute[i].size(); j++) {
            cout << " -> " << bestRoute[i][j];
        }
        cout << " -> " << startCity << endl;
    }
    
    return minDistance;
}

int main() {
    int costMatrix[][numCities] = {
        {0, 5, 4, 6},   // city 0/a
        {5, 0, 8, 7},   // city 1/b
        {4, 8, 0, 2},   // city 2/c
        {6, 7, 2, 0}    // city 3/d
    };
    int startCity = 0;
    
    int minimumDistance = travelingSalesmanProblem(costMatrix, startCity);
    cout << endl << "Minimum Distance: " << minimumDistance;
    return 0;
}