#include<iostream>
using namespace std;

void findminmax(int arr[], int size, int& min, int& max) {
	min = max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];


	}
}

int main() {
	const int size = 5;
	int arr[size] = { 2,3,5,6,7 };
	int min, max;
	findminmax(arr, size, min, max);
	cout << "Minimum is "<<min << endl;
	cout << "Maximum is "<<max << endl;
}