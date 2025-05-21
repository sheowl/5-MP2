# Implementation and Optimization of Brute-Force Algorithms

## Team Members
**Group 5 of BSCS 2-5**
- Co, Kyle Desmond
- Babasa, Maria Hanna 
- Borondia, Kurt 
- Castillo, Julianna Leila 
- Gueco, Jasper King 
- Nadonga, Solomon 
- Rivera, Geuel John 
- Tagura, Red Gabriel 
- Satorre, Ken Calvin

---

## About

This activity explores a collection of brute force algorithms, which represent the most straightforward approach to solving computational problems—by exhaustively checking all possible solutions or options. While not always the most efficient, brute force algorithms are essential building blocks in computer science and problem solving. Understanding them provides a foundation for learning more advanced algorithms and optimization techniques.

This repository includes the following brute force techniques:
1. Bubble Sort – A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. It's often used for educational purposes due to its simplicity.
2. Selection Sort – Another basic sorting algorithm that divides the array into a sorted and unsorted region and repeatedly selects the minimum element from the unsorted region.
3. Linear Search – A straightforward search method that checks each element in a list one by one until the target value is found or the end is reached.
4. Traveling Salesman Problem (TSP) – An NP-hard problem where the goal is to find the shortest possible route that visits each city exactly once and returns to the origin. The brute force approach checks all permutations of cities.
5. Knapsack Problem – A classic optimization problem in which you determine the most valuable combination of items to include in a knapsack with a fixed capacity. The brute force solution examines all possible combinations of items.

While these methods may be inefficient for large datasets, investigating and understanding them builds a solid foundation for understanding computational complexity, especially their worst-case scenarios.

### Directory Structure:
```bash
5-MP2/
│
├── README.md                        
├── .gitignore                       
│
├── Optimized/                       # Optimized versions of algorithms
│   ├── OptimizedTSP.cpp
│   ├── OptimizedBubbleSort.cpp
│   ├── OptimizedKnapsackProblem.cpp
│   └── OptimizedSelectionSort.cpp
│
├── Original/                        # Original brute force algorithm implementations
│   ├── TSP.cpp
│   ├── BubbleSort.cpp
│   ├── KnapsackProblem.cpp
│   └── SelectionSort.cpp
│
└── linear-search-menu/             # Variants of linear search algorithms and menu interface
    ├── BidirectionalLS.cpp
    ├── TraditionalLS.cpp
    ├── TransposeLS.cpp
    └── LinearSearchMenu.cpp
```
## Developer Setup Guide

### Initial Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/sheowl/5-MP2.git
   cd 5-MP2
   ```

2. **Compile and run the Code**
    ```bash
    g++ -o bubble_sort Original/BubbleSort.cpp
    ./bubble_sort
    ```

*For submission of Machine Problem 2 in Design and Analysis of Algorithms*
