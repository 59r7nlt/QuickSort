/*
Name: Ritika Lama
Course: CS 310
Professor: Dr. Nazmul Shahadat
Purpose: The purpose of this program is to implement quicksort
         to sort the given unsorted array.
*/
#include <iostream>
#include <vector>
using namespace std;

/**
 * Partitions the array around a pivot.
 * 
 * @param arr The array to be partitioned.
 * @param low The lower index of the array.
 * @param high The higher index of the array.
 * @return The index of the pivot element.
 */
int partition(vector<int>& arr, int low, int high) {
    // the last element as pivot
    int pivot = arr[high];
    int firstTemp; 
    int i = low - 1; // Index of smaller element

    // Move elements smaller than or equal to pivot to the left
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int secondTemp;
            //swap arr[i] and arr[j]
            secondTemp = arr[i];
            arr[i] = arr[j];
            arr[j] = secondTemp;
        }
    }

    //swap a[i+1] and pivot
    firstTemp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = firstTemp;

    // Return the index of the pivot element
    return i + 1;
}

/**
 * Recursively sorts the array using the Quicksort algorithm.
 * 
 * @param arr The array to be sorted.
 * @param low The starting index of the portion to be sorted.
 * @param high The ending index of the portion to be sorted.
 */
void quicksort(vector<int>& arr, int low, int high) {
    // Check if there are elements to sort
    if (low < high) {
        //get the pivot index
        int q = partition(arr, low, high);
        // Recursively sort the left partition
        quicksort(arr, low, q - 1);
        // Recursively sort the right partition
        quicksort(arr, q + 1, high);
    }
}

// main function
int main() {
    int sizeOfarr;
    cout << "Enter the number of elements to be sorted: " << endl;
    cin >> sizeOfarr;

    // Create a vector of the entered size
    vector<int> arr(sizeOfarr);

    // Taking input from the user
    if (sizeOfarr > 0) {
        cout << "Enter the elements (separated by spaces): ";
        for (int i = 0; i < sizeOfarr; i++) {
            cin >> arr[i];
        }

        // raneg based loop to display the unsorted array
        cout << "Unsorted array: " << endl;
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

        // Sort the array using quicksort
        quicksort(arr, 0, arr.size() - 1);

        //  range based loop to display the sorted array
        cout << "Sorted array: " << endl;
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        // display if the array is empty
        cout << "No array to be sorted." << endl;
    }
    return 0;
}
