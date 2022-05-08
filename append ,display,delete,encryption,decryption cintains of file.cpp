#include<fstream>
#include<string>
#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void choose_menu();

int main()
{
    string appsentence;
    string line;
    int n;
    fstream datafile;
    fstream secondfile;
    string filename;
    cout << "Hallo in our Text editor programm :)" << endl;
    cout << "please enter the name of file with txt extension :";
    cin >> filename;
    datafile.open(filename, ios::out | ios::_Nocreate);
    if (datafile.fail()) {
        datafile.open(filename, ios::out);
        cout << "we made this file for you  " << endl;
        datafile.close();
    }
    else {
        cout << "this file is already exist" << endl;
        datafile.close();
    }
    choose_menu();
    cin >> n;
    // append to the file 
    if (n == 1) {
        datafile.open(filename, ios::app);
        cout << "enter the sentence you want to append : ";
        cin.ignore();
        getline(cin, appsentence);
        datafile << appsentence << endl;
        choose_menu();
        // "enter another option you want to do on the file : ";
        cin >> n;
        datafile.close();
    }
    // display the content of the file 
    if (n == 2) {
        datafile.open(filename, ios::in);
        while (getline(datafile, line)) {
            cout << line << endl;
        }
        choose_menu();
        // "enter another option you want to do on the file : ";
        cin >> n;
        datafile.close();
    }
    // empty the file 
    if (n == 3) {
        datafile.open(filename, ios::out | ios::trunc);
        choose_menu();
        // "enter another option you want to do on the file : ";
        cin >> n;
        datafile.close();
    }
    // encrypt the file 
    if (n == 4) {
        datafile.open(filename, ios::in | ios::out );
        secondfile.open(filename, ios::out | ios::in );
        /*
        if (secondfile.fail()) {
            cout << " fail to open";
        }
        else {
            cout << "success to open";
        }
        */
        while (!datafile.eof()) {
            while (getline(datafile, line)) {
                for (int i = 0; i < line.size(); i++) {
                    secondfile << char(line[i] + 1);
                }
            }
        }
        choose_menu();
        //"enter another option you want to do on the file : ";
        cin >> n;
        datafile.close();
        secondfile.close();
    }
    // decryt text 
    if (n == 5) {
        datafile.open(filename, ios::in | ios::out);
        secondfile.open(filename, ios::in | ios::out);
        while (!datafile.eof()) {
            while (getline(datafile, line)) {
                for (int i = 0; i < line.size(); i++) {
                    secondfile << char(line[i] - 1);
                }
            }
        }
        choose_menu();
        // "enter another option you want to do on the file : ";
        cin >> n;
        datafile.close();
        secondfile.close();
    }


    
    // exit the programm
    if (n == 16) {
        exit(0);
    }

}

void choose_menu() {
   
    cout << "Enter 1--------------> Add new text to the end of the file" << endl;
    cout << "Enter 2--------------> Display the content of the file" << endl;
    cout << "Enter 3--------------> Empty the file" << endl;
    cout << "Enter 4--------------> Encrypt the file content" << endl;
    cout << "Enter 5--------------> Decrypt the file content" << endl;
    cout << "Enter 16-------------> Exit" << endl;
    cout << "enter the number of choice : "; 
  
}