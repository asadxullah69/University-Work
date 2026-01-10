#include<iostream>
#include<fstream>
using namespace std;

//========Functions=======

void input(int** data, int rownum, int colnum[])
{
	ifstream read("data.txt");
	int dummy;   //Skip first line (Row number)
	read >> dummy;
	for (int i = 0; i < rownum; i++)
	{
		// skip first column value
		read >> dummy;

		for (int j = 0; j < colnum[i]; j++)
		{
			read >> data[i][j];
		}
	}

	read.close();
}

void findmax(int** data, int rownum, int colnum[])
{
	int* sum = new int[rownum];

	for (int i = 0; i < rownum; i++)
	{
		int temp = 0;

		for (int j = 0; j < colnum[i]; j++)
		{
			temp += data[i][j];
		}
		cout <<"Row sum is: "<< temp << endl;
		sum[i] = temp;
	}
	int max = sum[0];
	int callerid;
	for (int i = 1; i < rownum; i++)
	{
		if (sum[i] > max) {
			max = sum[i];
			callerid = i;
		}

	}

	cout <<callerid+1<<" caller has maximum number of calls: " << max<<" minutes" << endl;

	delete[] sum;
	sum = nullptr;
}


//=========Main==============

int main()
{
	ifstream read("data.txt");
	if (!read)
	{
		cout << "Can not find or open file" << endl;
		return 0;
	}

	int rownum;
	read >> rownum;

	int* colnum = new int[rownum];

	for (int i = 0; i < rownum; i++)
	{
		read >> colnum[i];

		int temp;
		while (read.peek() != '\n' && read >> temp) {}
	}
	read.close();

	int** data = new int* [rownum];
	for (int i = 0; i < rownum; i++)
	{
		data[i] = new int[colnum[i]];
	}

	input(data, rownum, colnum);
	findmax(data, rownum, colnum);

	// free memory
	for (int i = 0; i < rownum; i++)
		delete[] data[i];
	delete[] data;
	delete[] colnum;

	return 0;
}
