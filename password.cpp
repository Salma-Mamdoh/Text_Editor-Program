#include <iostream>
#include <string>
#include <regex>
#include <conio.h>
#include <stdlib.h>

using namespace std; //needed for cout and etc

int main()
{   
    bool is_upper = false ; 
    bool is_lower = false ; 
    bool is_number = false ; 
    bool is_special = false ;
    string password1 = "" ; 
    char pass[32] ;
    char pass2[32] ;
    START:
    int i = 0 ;
    char a;//a Temp char
    cout << "--> enter strong password which :\n";
	cout << "--> Is at least 12 characters long.\n";
	cout << "--> The longer your password is - the better.\n";
	cout << "--> Uses uppercase and lowercase letters, numbers and special symbols.\n";
	cout << "--> Passwords that consist of mixed characters are harder to crack.\n";
	cout << "--> Doesn't contain memorable keyboard paths.\n";
	cout << "--> Is not based on your personal information.\n";
	cout << "--> Password is unique for each account you have.\n\n";
    while(true)//infinite loop
    {
        a=getch();//stores char typed in a
        if(a <= 126 && a >= 33)
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    //cout<<"\n\nYou entered : "<< pass << endl;
    regex special_char{ "[@!?;:#$%^&*-_=+/]+"};
    regex uppers {"[A-Z]+"}; 
    regex lowers {"[a-z]+"}; 
    regex numbers {"[0-9]+"}; 

    is_upper = regex_search(pass, uppers); //save the result, if the expression was found.
    is_lower = regex_search(pass, lowers); //....
    is_number = regex_search(pass, numbers);
    is_special = regex_search(pass, special_char);

    if(!((i > 11) && is_upper && is_lower && is_number && is_special))
    {

        cout<<"invalid password try again with right required conditions \n";
        getch();//It was not pausing :p
        goto START;
    }

    for (size_t j = 0; j < i; j++)
    {
        password1 = password1 + pass[j];
    }
    
    START2:
    string password2 = "" ;
    i = 0 ;
    cout << "\n\nenter the password again : \n\n";
    while(true)//infinite loop
    {
        a=getch();//stores char typed in a
        if(a <= 126 && a >= 33)
        {
            pass2[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\r')//if enter is pressed
        {
            pass2[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    for (size_t j = 0; j < i; j++)
    {
        password2 = password2 + pass2[j];
    }

    if (password1 != password2)
    {
        goto START2;
    }
    
    cout << "valid password \n";
    return 0;
    }   
