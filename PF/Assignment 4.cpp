//Task 1

#include<iostream>
using namespace std;

//========Functions==========

void checkComm(int matrix[][5],int rownum,int colnum) {
	int row[5];
	int col[5];
	int commcount = 0;
	for (int i = 0; i < 5; i++) {
		row[i] = matrix[rownum][i];
		col[i] = matrix[i][colnum];
	}
	cout << "Selected Row " << rownum + 1 << " is:";
	for (int i = 0; i < 5; i++) {
		cout << row[i] << " ";
	}
	cout << endl;
	cout << "Selected coloum " << colnum + 1 << " is: ";
	for (int i = 0; i < 5; i++) {
		cout << col[i] << " ";
	}
	cout << endl;
	cout << "Common numbers in row and coloum are: ";
	for (int i = 0; i < 5; i++) {
		if (row[i] == col[i]) {
			cout << row[i] << " ";
			commcount++;
		}
	}
	if (commcount == 0) {
		cout << commcount;
	}

}
void print(int matrix[][5], int rowsize, int colsize) {
	cout << "Whole matrix is: ";
	for (int i = 0; i < rowsize; i++) {
		cout << endl;
		for (int j = 0; j < colsize; j++) {
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
}

//==========Main Function=============

int main() {
	int rownum, colnum, rowsize = 5, colsize = 5;
	int matrix[5][5] = { 1,2,3,4,5,6,2,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	cout << "Enter the row number: ";
	cin >> rownum;
	cout << "Enter the coloum number: ";
	cin >> colnum;
	colnum--;
	rownum--;
	print(matrix, rowsize, colsize);
	checkComm(matrix, rownum, colnum);



}