// Code Example:
// Here's a classic example of a recursive algorithm: Merge Sort.


#include <iostream>
using namespace std;
#include <vector>

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arrSize = arr.size();

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}




// Part 1: Understanding Recursion
// Here's a simple example of a recursive function that calculates the factorial of a number.
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Part 2: Understanding Binary Search
// Here's a simple example of a binary search-like function that finds the middle index of an array.
int findMiddleIndex(const std::vector<int>& arr) {
    return arr.size() / 2;
}

// Part 3: Understanding Sorting Check
// Here's a simple example of a function that checks if the first element of an array is less than the second.
bool isFirstElementLess(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        return true;
    } else {
        return arr[0] < arr[1];
    }
}

// Part 4: Understanding Random Number Generation
// Here's a simple example of a function that generates a single random integer.
int generateRandomInteger() {
    return rand() % 100;
}


int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        if (arr[mid] == target)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, high, target);
    }

    // We reach here when element is not present in array
    return -1;
}

