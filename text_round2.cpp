#include <iostream>
#include <fstream> //file stream
#include <string>
using namespace std ;

void check (string str);
void filter_6(string str1);
void filter_7(string str1, int& i, string & s);
void filter_8(string str1 , int & i , string& s);
void filter_9(string str1 , int & i);
void filter_10(string str1 , string& s);
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

    goto START;

}

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
    cout << "Enter 16-------------> Exit" << endl;
    cout << "enter the number of choice : "; 
  
}

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

void filter_7 (string str1 , int & i , string& s){
    fstream fin(str1 , ios:: in);
    while(fin >> s){
        i++ ;
    }
    cout << "the number of words = " << i << endl << endl;
}

void filter_8 (string str1 , int & i , string& s){
    fstream fin(str1 , ios:: in);
    while(fin >> s){
        i = i + s.length() ;
    }
    cout << "the number of characters = " << i << endl << endl ;
}

void filter_9 (string str1 , int & i){
    fstream fin(str1 , ios:: in);
    char line[100];
    while (fin.getline(line , 100 , '\n')){
        i++ ;
    }
    cout << "the number of lines = " << i << endl << endl ;
}

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
