#include <iostream>
#include <fstream> //file stream
#include <string>
using namespace std ;

void check (string str);
void filter_6(string str1);
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
    if (choose == 6){
        string file2 ;
        fstream fout(file , ios:: app);
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
        goto START;
        }

    else if (choose == 7){
        fstream fin(file , ios:: in);
        while(fin >> str){
            counter++ ;
        }
        cout << "the number of words = " << counter << endl << endl;
        goto START;
    }

    else if (choose == 8){
        fstream fin(file , ios:: in);
        while(fin >> str){
            counter = counter + str.length() ;
            
        }
        cout << "the number of characters = " << counter << endl << endl ;
        goto START;
    }
    else if (choose == 9){
        fstream fin(file , ios:: in);
        char line[100];
        while (fin.getline(line , 100 , '\n')){
            counter++ ;
        }
        cout << "the number of lines = " << counter << endl << endl ;
        goto START;
    }
    else if (choose == 10){
        string word ;
        cout << "enter the word to search : ";
        cin >> word ;

        fstream fin(file , ios:: in);

        while(fin >> str){

            if (str == word)
            {
                cout << "Word was found in the file \n \n"; 
                goto START;
            }
        }

        cout << "Word was not found in the file \n\n"; 
        goto START;
    }

    else if (choose == 16){
        return 0 ;
    }

}

void check(string str){
    fstream fcheck ;
    fcheck.open(str);
    if (fcheck.is_open())
        cout << "file is exist \n";
    else{
        cout << "file does not exist \nI created it for you";
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
    cout << "Enter 6------------->  Merge another file" << endl;
    cout << "Enter 7--------------> Count the number of words in the file" << endl;
    cout << "Enter 8--------------> Count the number of characters in the file" << endl;
    cout << "Enter 9--------------> Count the number of lines in the file" << endl;
    cout << "Enter 10--------------> Search for a word in the file" << endl;
    cout << "Enter 16-------------> Exit" << endl;
    cout << "enter the number of choice : "; 
  
}