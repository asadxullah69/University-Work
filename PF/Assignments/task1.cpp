#include<iostream>
using namespace std;

void findmax(int* a, int* b) {
	if (a > b) {
		cout << *a;
	}
	else {
		cout << *b;
	}
}



int main()
{
	int num1 = 15, num2 = 20;
	findmax(&num1, &num2);
}