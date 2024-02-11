#include <iostream>
#include <cstdlib> // for abs()

// Recursive function to populate array
void populateArray(int* arr, int size, int index = 0) {
    if(index == size) {
        return;
    }
    std::cout << "Enter value for index " << index << ": ";
    std::cin >> arr[index];
    populateArray(arr, size, index + 1);
}

void printArray(int* arr, int size, int index = 0) {
    if(index == size) {
        return;
    }
    std::cout << "Value at index " << index << ": ";
    std::cout << arr[index] << std::endl;
    printArray(arr, size, index + 1);
}

// Recursive function to find closest value
int findClosest(int* arr, int size, int num, int index = 0, int closest = 0) {
    if(index == size) {
        return closest;
    }
    if(index == 0 || abs(num - arr[index]) < abs(num - closest)) {
        closest = arr[index];
    }
    return findClosest(arr, size, num, index + 1, closest);
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size]; // dynamic array

    populateArray(arr, size);
    printArray(arr, size);

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int closest = findClosest(arr, size, num);
    std::cout << "The closest value to " << num << " in the array is " << closest << std::endl;

    delete[] arr; // don't forget to delete dynamic array

    return 0;
}