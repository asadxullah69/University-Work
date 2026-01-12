#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


//----------------Functions----------------

void checkvalid1(char op[]) {            //Version 1
    ifstream read("data.txt");
    ofstream fout("output.txt", ios::app);
    while (read.getline(op, 50)) {

        bool valid = true;

        // Rule 1: must start with '0'
        if (op[0] != '0') {
            valid = false;
        }

        // Rule 2: must have '-' at position 4 (index 4) and total numbers should be 11
        int len = strlen(op);
        if ( len!= 12 || op[4] != '-') {
            valid = false;
        }
        if (valid)
            fout << op << "  Valid"<<endl;
        else
            fout << op << "  Invalid" << endl;
    }
}

//-----------------------------Version 2-------------------------


void checkvalid2(char *op) {
    ifstream read("data.txt");
    ofstream fout("output.txt",ios::app);
    fout << "\nRunning pointer version\n" << endl;
    while (read.getline(op, 50)) {

        bool valid = true;

        // Rule 1: must start with '0'
        if (*(op) != '0') {
            valid = false;
        }

        // Rule 2: must have '-' at position 4 and total numbers should be 11 (index 4)
        int len = strlen(op);
        if (len != 12 || *(op+4) != '-') {
            valid = false;
        }
        
        
        if (valid)
            fout << op << "  Valid" << endl;
        else
            fout << op << "  Invalid" << endl;
    }
}


//----------------Main-----------------------

int main() {
	char op[20];
    checkvalid1(op);
    cout << "Data analyzed successfully and saved in file" << endl;
    checkvalid2(op);
}
