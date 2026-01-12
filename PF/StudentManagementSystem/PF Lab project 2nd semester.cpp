#include<iostream>
#include<fstream>
using namespace std;

//------------Functions----------------


//-------------------Add student----------------------

void addstudent(int studentids[],char **name, int col,int studentages[], float studentgpa[], int index) {
    cout << "Enter Student ID: ";
    cin >> studentids[index];
    cin.ignore();
    cout << "Enter Student's name: ";
    cin.getline(name[index], col);

    cout << "Enter Age: ";
    cin >> studentages[index];

    cout << "Enter GPA: ";
    cin >> studentgpa[index];

    cout << "Student added successfully." << endl;
}
//-----------------Grow array----------------------------

void grow(int*& studentid, char**&name,int &rows,int col,float*& studentgpa, int*& studentage, int& size) {
    int newSize = size + 1;
    int newrows = rows + 1;

    int* tempid = new int[newSize];
    float* tempgpa = new float[newSize];
    int* tempage = new int[newSize];
    char** tempname = new char* [newrows];
    for (int i = 0; i < newrows; i++) {
        tempname[i] = new char[col];
    }
    for (int i = 0; i < size; i++) {
        tempid[i] = studentid[i];
        tempgpa[i] = studentgpa[i];
        tempage[i] = studentage[i];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            tempname[i][j] = name[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] name[i];
    }
    delete[] name;
    delete[] studentid;
    delete[] studentgpa;
    delete[] studentage;

    studentid = tempid;
    studentgpa = tempgpa;
    studentage = tempage;
    name = tempname;

    size = newSize;
    rows = newrows;
}

//------------delete student or shrink array--------------

void deletestudent(int*& studentid, char**& name, int& rows, int col, float*& studentgpa, int*& studentage, int& size) {
    int newSize = size - 1;
    int newrows = rows - 1;

    int* tempid = new int[newSize];
    float* tempgpa = new float[newSize];
    int* tempage = new int[newSize];
    char** tempname = new char* [newrows];
    for (int i = 0; i < newrows; i++) {
        tempname[i] = new char[col];
    }
    for (int i = 0; i < newSize; i++) {
        tempid[i] = studentid[i];
        tempgpa[i] = studentgpa[i];
        tempage[i] = studentage[i];
    }
    for (int i = 0; i < newrows; i++) {
        for (int j = 0; j < col; j++) {
            tempname[i][j] = name[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] name[i];
    }
    delete[] name;
    delete[] studentid;
    delete[] studentgpa;
    delete[] studentage;

    studentid = tempid;
    studentgpa = tempgpa;
    studentage = tempage;
    name = tempname;

    size = newSize;
    rows = newrows;
    cout << "Last student deleted Successfully" << endl;

}

//========create coloums for 2d dunamic array============

void createcol(char** arr, int rows, int col) {
    for (int i = 0; i < rows; i++) {
        arr[i] = new char[col];
    }
}

//==========display student======================

void displaystudent(int studentids[], char** name, int col, int studentages[], float studentgpa[], int size) {
    cout << endl << "Student Records:" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "ID: " << studentids[i] << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Age: " << studentages[i] << endl;
        cout << "GPA: " << studentgpa[i] << endl;
        cout << "-----------------" << endl;
    }
}

//==============save to file=====================

void savefile(int studentid[], char** name, int studentage[], float studentgpa[], int size) {
    if (size == 0) {
        cout << endl << "No students to save." << endl;
    }
    else {
        ofstream fout("output.txt");
        if (!fout) {
            cout << "File not found or cannot be opened" << endl;
        }
        else {
            for (int i = 0; i < size; i++) {

                fout << studentid[i] << " ";
                fout << studentage[i] << " ";
                fout << studentgpa[i] << " ";
                fout << name[i] << " ";
                fout << endl;
            }

            cout << endl << "Data saved to file successfully" << endl;
            fout.close();
        }
    }
}

//==============load from file===================

void loadfile(int*& studentid, char**& name, int& rows, int col,
    int*& studentage, float*& studentgpa, int& size)
{
    size = 0;
    int id, age;
    float gpa;
    ifstream read("output.txt");

    if (!read) {
        cout << "File not found or cannot be opened" << endl;
    }
    else {
        int i = 0;
        while (read>>id >> age >> gpa) {
   
            grow(studentid, name, rows, col, studentgpa, studentage, size);
            read.get(name[i], col);
            studentid[size - 1] = id;
            studentage[size - 1] = age;
            studentgpa[size - 1] = gpa;
            i++;
        }

        if (size == 0) {
            cout << "No student record found" << endl;
        }
        else {
            cout << "Data loaded successfully. Total "
                << size << " student(s) found" << endl;
        }

        read.close();
    }
}

//==================search student===============

void search(int studentid[], char** name, int studentage[], float studentgpa[], int size) {
    if (size == 0) {
        cout << "No students in the system to search." << endl;
        return;
    }

    int searchid;
    cout << "Enter student id to search: ";
    cin >> searchid;

    bool found = false;

    for (int i = 0; i < size; i++) {
        if (searchid == studentid[i]) {
            cout << "-----------------" << endl;

            cout << "Student found" << endl;
            cout << "Displaying Student Record......." << endl;
            cout << "ID: " << studentid[i] << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Age: " << studentage[i] << endl;
            cout << "GPA: " << studentgpa[i] << endl;
            cout << "-----------------" << endl;
            found = true;
            break;  // stop once found
        }
    }

    if (!found) {
        cout << "Student not found" << endl;
    }
}


//==================Main body====================

int main() {
    int size = 0;

    int* studentid = nullptr;
    float* studentgpa = nullptr;
    int* studentage = nullptr;
    int rows = 1;
    int col = 15;
    char** name = new char* [rows];
    createcol(name, rows, col);
    int choice;

    do {
        cout << "====== Student Records System ======" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Save to file" << endl;
        cout << "4. Load from file" << endl;
        cout << "5. Search Student from ID" << endl;
        cout << "6. Delete Last Saved Student" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            grow(studentid,name,rows,col, studentgpa, studentage, size);

            addstudent(studentid, name,col,studentage, studentgpa, size-1);
        }
        else if (choice == 2) {
            if (size == 0) {
                cout << "No students to display." << endl;
            }
            else {
                displaystudent(studentid, name, col, studentage, studentgpa, size);
            }
        }
        else if (choice == 3) {
            savefile(studentid, name, studentage, studentgpa, size);
        }
        else if (choice == 4) {
            loadfile(studentid, name, rows, col, studentage, studentgpa, size);

        }
        else if (choice == 5) {
            search(studentid,name,studentage,studentgpa, size);
        }
        else if (choice == 6) {
            if (size == 0) {
                cout << "No data to delete" << endl;
            }
            else {
                deletestudent(studentid,name,rows,col, studentgpa, studentage, size);
            }
        }

    } while (choice != 7);

    delete[] studentid;
    delete[] studentgpa;
    delete[] studentage;

    return 0;
}

