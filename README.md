# Merge Sort Algorithm

This code implements the merge sort algorithm to sort an array of numbers. The merge sort algorithm is a divide-and-conquer algorithm that recursively divides the array into smaller sub-arrays, sorts them individually, and then merges them back together to obtain a sorted array.

## Code Overview

The code consists of the following components:

1. An array of numbers to be sorted: The code provides examples of different arrays, each commented out. Uncomment one of the arrays or create your own to test the sorting algorithm.

2. The `sort_numbers` function: This is a recursive function that performs the merge sort algorithm. It takes in the current state of whether to sort numbers into the `nrs` array or the temporary `tmp` array, as well as the lower and higher indices of the sub-array to be sorted. The function divides the array into smaller sub-arrays, recursively sorts them, and then merges them back together.

3. The `main` function: This is the entry point of the program. It initializes variables, prints the array before sorting, calls the `sort_numbers` function, stores the sorted array back into the original array, and finally prints the sorted array.

## Getting Started

To run the code and test the merge sort algorithm:

1. Choose an array of numbers to sort. Uncomment one of the arrays provided or create your own.

2. Compile and run the code using a C compiler.

3. The program will print the array before sorting and then the sorted array after the sorting process is completed.

4. You can modify the code to use your own arrays and experiment with different inputs.

Feel free to explore and understand the code to gain insights into how the merge sort algorithm works.
