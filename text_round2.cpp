#include <iostream>
#include <fstream> //file stream
#include <string>
#include<cstring>
using namespace std ;

void check (string str);
void filter_1(string str);
void filter_2(string str);
void filter_3(string str);
void filter_4(string str);
void filter_5(string str);
void filter_6(string str1);
void filter_7(string str1, int& i, string & s);
void filter_8(string str1 , int & i , string& s);
void filter_9(string str1 , int & i);
void filter_10(string str1 , string& s);
void filter_11(string str);
void filter_12(string str);
void filter_13(string str);
void filter_14(string str1 , string& s);
void filter_15(string str);
void choose_menu() ;

int main(){
    string file , str ;
    cout << "Hallo in our Text editor programm :)" << endl;
    cout << "enter file name : \n";
    cin >> file ;
    check(file);
    START:
    int choose ,counter = 0;
    choose_menu();
    cin >> choose ;

    if (choose == 16){
        return 0 ;
    }
    else if (choose == 1) {
        filter_1(file);
    }
    else if (choose == 2) {
        filter_2(file);
    }
    else if (choose == 3) {
        filter_3(file);
    }
    else if (choose == 4) {
        filter_4(file);
    }
    else if (choose == 5) {
        filter_5(file);
    }

    else if (choose == 6){
        filter_6(file);
    }

    else if (choose == 7){
        filter_7 (file , counter , str);
    }

    else if (choose == 8){
        filter_8(file , counter , str);
    }

    else if (choose == 9){
        filter_9 (file , counter);
    }

    else if (choose == 10){
        filter_10 (file, str);
    }
    else if (choose == 11) {
        filter_11(file);
    }
    else if (choose == 12) {
        filter_12(file);
    }
    else if (choose == 13) {
        filter_13(file);
    }
    else if (choose == 14){
        filter_14 (file, str);
    }
    else if (choose == 15) {
        filter_15(file);
    }

    goto START;
}
// check file if it is exist before or create new file
void check(string str){
    fstream fcheck ;
    fcheck.open(str);
    if (fcheck.is_open())
        cout << "file is exist \n";
    else{
        cout << "file does not exist \nI created it for you\n";
        fcheck.open(str , ios :: app);
    }
    fcheck.close();
}

void choose_menu() {

    cout << "Enter 1--------------> Add new text to the end of the file" << endl;
    cout << "Enter 2--------------> Display the content of the file" << endl;
    cout << "Enter 3--------------> Empty the file" << endl;
    cout << "Enter 4--------------> Encrypt the file content" << endl;
    cout << "Enter 5--------------> Decrypt the file content" << endl;
    cout << "Enter 6--------------> Merge another file" << endl;
    cout << "Enter 7--------------> Count the number of words in the file" << endl;
    cout << "Enter 8--------------> Count the number of characters in the file" << endl;
    cout << "Enter 9--------------> Count the number of lines in the file" << endl;
    cout << "Enter 10-------------> Search for a word in the file" << endl;
    cout<<  "Enter 11-------------> Count the number of times a word exists in the file"<<endl;
    cout << "Enter 12-------------> Turn the file content to upper case" << endl;
    cout << "Enter 13-------------> Turn the file content to lower case" << endl;
    cout << "Enter 14-------------> Turn file content to 1st caps" << endl;
    cout << "Enter 15-------------> save" << endl;
    cout << "Enter 16-------------> Exit" << endl;
    cout << "enter the number of choice : ";

}
// append sentence to file.
void filter_1(string str) {
    string addsen;
    fstream fin(str, ios::app);
    fstream fout(str, ios::app);

    cout << "enter the sentence you want to append : ";
    cin.ignore();
    getline(cin ,addsen);
    cin.ignore(0);
    fout<< addsen << endl;
}
// display the content of file
void filter_2(string str) {
    string line;
    fstream fin(str, ios::in);
    while (getline(fin, line)) {
        cout << line << endl;
    }}
// delete the content of the file
void filter_3(string str) {
    fstream fin(str, ios::out | ios::trunc);
}
// encrypt all content of file by shifiting every character for 1
void filter_4(string str) {
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::out | ios::in);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(line[i] + 1);
            }}}}
// decrypt all the content of file
void filter_5(string str) {
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::in | ios::out);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(line[i] - 1);
            }}}}
// merge the content of 2 different files
void filter_6 (string str1){
    string file2 ;
    fstream fout(str1 , ios:: app);
    cout << "enter srcond file : \n";
    cin >> file2 ;
    check(file2);
    fstream fin(file2 , ios::in);
    char str[100] ;
    fout << '\n';
    while (fin.getline(str , 100 , '\n'))
    {
        fout << str << endl;
    }
    cout << "Done \n\n";
}
//Count the number of words in the file
void filter_7 (string str1 , int & i , string& s){
    fstream fin(str1 , ios:: in);
    while(fin >> s){
        i++ ;
    }
    cout << "the number of words = " << i << endl << endl;
}
//Count the number of characters in the file

void filter_8 (string str1 , int & i , string& s){
    fstream fin(str1 , ios:: in);
    while(fin >> s){
        i = i + s.length() ;
    }
    cout << "the number of characters = " << i << endl << endl ;
}
//Count the number of lines  in the file
void filter_9 (string str1 , int & i){
    fstream fin(str1 , ios:: in);
    char line[100];
    while (fin.getline(line , 100 , '\n')){
        i++ ;
    }
    cout << "the number of lines = " << i << endl << endl ;
}
// Search for a word in the file
void filter_10 (string str1, string & s){
    string word ;
    bool check = false ;
    cout << "enter the word to search : ";
    cin >> word ;
    fstream fin(str1 , ios:: in);
    while(fin >> s){
        if (s == word)
        {
            check = true ;
        }
    }
    check == false ? cout << "Word was not found in the file \n\n" : cout << "Word was found in the file \n \n";
}
// Count the number of times a word exists in the file
void filter_11(string str ) {
    int counter;
    fstream fin(str, ios::in);
    string word;
    cout << "what the word do you wont : ";
    cin >> word;
    while (fin >> str) {
        if (word == str) {
            counter++;
        }
}
    cout << "the number of word (" << word << ") = " << counter << endl;
}
//Turn the file content to upper case
void filter_12(string str) {
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::in | ios::out);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(toupper(line[i]));
            }}}}
//Turn the file content to lower case
void filter_13(string str) {
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::in | ios::out);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(tolower(line[i]));
            }}}}
//Turn file content to 1st caps
void filter_14 (string str1, string & s){
    fstream datafile (str1, ios::in | ios::out);
    fstream secondfile(str1, ios::in | ios::out);
    char line[100] ;
    //while (datafile.getline(line, 100, '\n')) {
    while (datafile >> s) {
        secondfile << char(toupper(s[0]));
        for (size_t i = 1; i < s.length(); i++)
        {
            secondfile << char(tolower(s[i]));
        }
           secondfile << " \n";
       }}
// save in the same file or in a new file.
void filter_15(string str) {
    int n;
    cout << "if you want to save in the same file enter 1 " << endl;
    cout << "if you want to save in another file enter 2" << endl;
    cin >> n;
    if (n == 1) {
        cout << "Done" << endl;
        choose_menu();
        cin >> n;
    }
    else if (n == 2) {
        string filename2;
        string line;
        cout << "enter the name of file";
        cin >> filename2;
        fstream fin(str, ios::in | ios::out);
        fstream fout(filename2, ios::in | ios::out | ios::app);
        while (!fin.eof()) {
            while (getline(fin, line)) {
                for (int i = 0; i < line.size(); i++) {
                    fout << line[i];

                }}}}}
