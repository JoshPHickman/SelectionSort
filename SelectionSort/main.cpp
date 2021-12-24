/********************************************************************************
\file		main.cpp
\author		Josh Hickman
\date		2021-12-23
\brief		practice exercise for an insertion sort
\description:
	The insertion sort works by sepearting a given array into 2 seperate logical
	subarrays (sorted & unsorted). This is done by nesting for loops, the first
	of which sets the minimum value to the current indexed value of the first 
	loop. The second loop updates this min value, comparing the element at the 
	indexed pos to all OTHER data in the array, effectively creating 2 arrays.
*********************************************************************************/
#include <iostream>
using namespace std;

//swaps two params when invoked
void swap(int& x, int& y);

//compares values within the array, invoking swap when necessary
void selectionSwap(int arr[], int maxLength);

//prints out the elements of an array when invoked
void printArr(int arr[], int maxLength);

int main() {
	int arr[] = { 2, 5, 1, 3, 4, 5, 6, 9, 8 };
	//divide the size of the whole array by size of an element to get number of elements in array (allowing dynamic array sizes rather than const)
	int max = sizeof(arr) / sizeof(arr[0]);	

	cout << "The unsorted array" << endl;
	printArr(arr, max);

	cout << "The sorted array" << endl;
	selectionSwap(arr, max);
	printArr(arr, max);

	return 0;
}

void swap(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void selectionSwap(int arr[], int maxLength) {
	//increment the boundary of unsorted subarray
	for (int i = 0; i < (maxLength - 1); i++) {
		int minIndex = i;
		//compare element at minIndex to all other elements in the array
		for (int j = i + 1; j < maxLength; j++) {
			if (arr[j] < arr[minIndex]) {
				//update the new number being compared as it was smaller than the previous
				minIndex = j;
			}
		}
		//swap the new min elem with the original elem iff it is different
		if (arr[minIndex] != arr[i]) {
			swap(arr[minIndex], arr[i]);
		}
	}
}

void printArr(int arr[], int maxLength) {
	for (int i = 0; i < maxLength; i++) {
		cout << arr[i] << endl;
	}
}
