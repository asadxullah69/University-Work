#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main() {
    const int maxstudents = 20;
    int studentids[maxstudents];
    int studentages[maxstudents];
    float studentgpa[maxstudents];
    int totalstudents = 0;

    int choice;
    do {
        cout << endl << "====== Student Records System ======" << endl;     //Menu
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Save to File" << endl;
        cout << "4. Load from File" << endl;
        cout << "5. Searh by id" << endl;
        cout << "6. Delete Student" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (Choose from numbers): ";
        cin >> choice;

        if (choice == 1) {
            if (totalstudents >= maxstudents) {
                cout << "Cannot add more students. Maximum limit reached." << endl;
            }
            else {
                int id, age;
                float gpa;

                cout << "Enter Student ID: ";
                cin >> id;

                cout << "Enter Age: ";
                cin >> age;

                cout << "Enter GPA: ";
                cin >> gpa;

                studentids[totalstudents] = id;     //storing data in arrays
                studentages[totalstudents] = age;
                studentgpa[totalstudents] = gpa;
                totalstudents++;

                cout << "Student added successfully." << endl;
            }
        }
        else if (choice == 2) {
            if (totalstudents == 0) {
                cout << "No students to display." << endl;
            }
            else {
                cout << endl << "Student Records:" << endl;
                cout << "-----------------" << endl;            //reads from file and prints it
                for (int i = 0; i < totalstudents; i++) {
                    cout << "Student " << i + 1 << ":" << endl;
                    cout << "ID: " << studentids[i] << endl;
                    cout << "Age: " << studentages[i] << endl;
                    cout << "GPA: " << studentgpa[i] << endl;
                    cout << "-----------------" << endl;
                }
            }
        }
        else if (choice == 3) {
            if (totalstudents == 0) {
                cout << endl << "No students to save." << endl;
            }
            else {
                ofstream fout("data.txt", ios::app);    //appends data in file. Does not overwrite
                if (!fout) {
                    cout << "File not found or cannot be opened" << endl;
                }
                else {

                    for (int i = 0; i < totalstudents; i++) {
                        fout << studentids[i] << " ";
                        fout << studentages[i] << " ";
                        fout << studentgpa[i] << endl;
                    }

                    cout << endl << "Data saved to file successfully" << endl;
                    fout.close();
                }
            }
        }
        else if (choice == 4) {
            ifstream read("data.txt");
            if (!read) {
                cout << "File not found or can not be opened" << endl;
            }
            else {
                totalstudents = 0;
                int i = 0;
                while (read >> studentids[totalstudents] >> studentages[totalstudents] >> studentgpa[totalstudents]) {
                    totalstudents++;
                    cout << endl << "ID: " << studentids[i] << endl;
                    cout << "Age: " << studentages[i] << endl;
                    cout << "GPA: " << studentgpa[i] << endl;
                    cout << "-----------------" << endl;
                    i++;
                    if (totalstudents >= maxstudents) break;    //breaks if students exceed max number
                }
                if (totalstudents == 0) {
                    cout << "No student record found" << endl;
                }
                else {
                    cout << "Data loaded successfully. Total " << totalstudents << " student(s) found" << endl;
                }
                read.close();
            }

        }
        else if (choice == 5) {         //searches the student by id
            int search, index = 0;
            bool found = false;
            cout << "Enter student id to search: ";
            cin >> search;
            for (int i = 0; i < totalstudents; i++) {
                if (search == studentids[i]) {
                    index = i;
                    found = true;
                    break;
                }

            }
            if (found) {
                cout << "-----------------" << endl;
                cout << "Student found successfully" << endl;
                cout << "ID: " << search << endl;
                cout << "Age: " << studentages[index] << endl;
                cout << "GPA: " << studentgpa[index] << endl;
                cout << "-----------------" << endl;
            }
            else {
                cout << "Id not found" << endl;
            }
        }
        else if (choice == 6) {
            int del;
            bool found = false;
            cout << "Enter the student id (Load student data first if you have not): ";  //giving warning as the ios out will clear the file and add new data
            cin >> del;

            for (int i = 0; i < totalstudents; i++) {
                if (del == studentids[i]) {
                    found = true;
                    for (int j = i; j < totalstudents - 1; j++) {   //will shift all values in array to left starting from the data to be removed
                        studentids[j] = studentids[j + 1];
                        studentages[j] = studentages[j + 1];
                        studentgpa[j] = studentgpa[j + 1];
                    }
                    totalstudents--;
                    break;
                }
            }

            if (found) {
                cout << "Student data deleted successfully."<<endl;

                ofstream fout("data.txt", ios::out); // overwrite file
                for (int i = 0; i < totalstudents; i++) {
                    fout << studentids[i] << " ";
                    fout << studentages[i] << " ";
                    fout << studentgpa[i] << endl;
                }
                fout.close();
                cout << "File updated successfully."<<endl;
            }
            else {
                cout << "No record found. Try adding or loading students first."<<endl;
            }
            }

        else if (choice == 7) {
            cout << "Exiting program. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
