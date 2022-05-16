#include "CS112-203-2nd-s15,16-20210162-20210254-20211014-A4-TextEditorFunc.h"
text::text() {

}
text::~text() {

}
void text::check(string str)
{
    fstream fcheck;
    fcheck.open(str);
    if (fcheck.is_open())
        cout << "file is exist \n";
    else {
        cout << "file does not exist \nI created it for you\n";
        fcheck.open(str, ios::app);
    }
    fcheck.close();
}

void text::filter_1(string str)
{
    string addsen;
    fstream fin(str, ios::app);
    fstream fout(str, ios::app);

    cout << "enter the sentence you want to append : ";
    cin.ignore();
    getline(cin, addsen);
    cin.ignore(0);
    fout << addsen << endl;
}

void text::filter_2(string str)
{
        string line;
        fstream fin(str, ios::in);
        while (getline(fin, line)) {
            cout << line << endl;
        }
}

void text::filter_3(string str)
{
    fstream fin(str, ios::out | ios::trunc);
}

void text::filter_4(string str)
{
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::out | ios::in);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(line[i] + 1);
            }
        }
    }
}

void text::filter_5(string str)
{
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::in | ios::out);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(line[i] - 1);
            }
        }
    }
}

void text::filter_6(string str1)
{
    string file2;
    fstream fout(str1, ios::app);
    cout << "enter srcond file : \n";
    cin >> file2;
    check(file2);
    fstream fin(file2, ios::in);
    char str[100];
    fout << '\n';
    while (fin.getline(str, 100, '\n'))
    {
        fout << str << endl;
    }
    cout << "Done \n\n";
}

void text::filter_7(string str1, int& i, string& s)
{
    fstream fin(str1, ios::in);
    while (fin >> s) {
        i++;
    }
    cout << "the number of words = " << i << endl << endl;
}

void text::filter_8(string str1, int& i, string& s)
{
    fstream fin(str1, ios::in);
    while (fin >> s) {
        i = i + s.length();
    }
    cout << "the number of characters = " << i << endl << endl;
}

void text::filter_9(string str1, int& i)
{
    fstream fin(str1, ios::in);
    char line[100];
    while (fin.getline(line, 100, '\n')) {
        i++;
    }
    cout << "the number of lines = " << i << endl << endl;
}

void text::filter_10(string str1, string& s)
{
    string word;
    bool check = false;
    cout << "enter the word to search : ";
    cin >> word;
    fstream fin(str1, ios::in);
    while (fin >> s) {
        if (s == word)
        {
            check = true;
        }
    }
    check == false ? cout << "Word was not found in the file \n\n" : cout << "Word was found in the file \n \n";
}

void text::filter_11(string str)
{
    int counter=0;
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

void text::filter_12(string str)
{
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::in | ios::out);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(toupper(line[i]));
            }
        }
    }
}

void text::filter_13(string str)
{
    string line;
    fstream fin(str, ios::in | ios::out);
    fstream fout(str, ios::in | ios::out);
    while (!fin.eof()) {
        while (getline(fin, line)) {
            for (int i = 0; i < line.size(); i++) {
                fout << char(tolower(line[i]));
            }
        }
    }
}

void text::filter_14(string str1, string& s)
{
    fstream datafile(str1, ios::in | ios::out);
    fstream secondfile(str1, ios::in | ios::out);
    char line[100];
    //while (datafile.getline(line, 100, '\n')) {
    while (datafile >> s) {
        secondfile << char(toupper(s[0]));
        for (size_t i = 1; i < s.length(); i++)
        {
            secondfile << char(tolower(s[i]));
        }
        secondfile << " \n";
    }
}

void text::filter_15(string str)
{
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

                }
            }
        }
    }
}


void text::choose_menu()
{
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
    cout << "Enter 11-------------> Count the number of times a word exists in the file" << endl;
    cout << "Enter 12-------------> Turn the file content to upper case" << endl;
    cout << "Enter 13-------------> Turn the file content to lower case" << endl;
    cout << "Enter 14-------------> Turn file content to 1st caps" << endl;
    cout << "Enter 15-------------> save" << endl;
    cout << "Enter 16-------------> Exit" << endl;
    cout << "enter the number of choice : ";
}
