#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<algorithm>
#include<cstring>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
using namespace std;
struct password {
	int main()
	{
		bool is_upper = false;
		bool is_lower = false;
		bool is_number = false;
		bool is_special = false;
		string password1 = "";
		char pass[32];
		char pass2[32];
	START:
		int i = 0;
		char a;//a Temp char
		cout << "--> enter strong password which :\n";
		cout << "--> Is at least 12 characters long.\n";
		cout << "--> The longer your password is - the better.\n";
		cout << "--> Uses uppercase and lowercase letters, numbers and special symbols.\n";
		cout << "--> Passwords that consist of mixed characters are harder to crack.\n";
		cout << "--> Doesn't contain memorable keyboard paths.\n";
		cout << "--> Is not based on your personal information.\n";
		cout << "--> Password is unique for each account you have.\n\n";
		cout << "Enter your password : ";
		while (true)//infinite loop
		{
			a = _getch();//stores char typed in a
			if (a <= 126 && a >= 33)
			{
				pass[i] = a;//stores a in pass
				++i;
				cout << "*";
			}
			if (a == '\r')//if enter is pressed
			{
				pass[i] = '\0';//null means end of string.
				break;//break the loop
			}
		}
		//cout<<"\n\nYou entered : "<< pass << endl;
		regex special_char{ "[@!?;:#$%^&*-_=+/]+" };
		regex uppers{ "[A-Z]+" };
		regex lowers{ "[a-z]+" };
		regex numbers{ "[0-9]+" };

		is_upper = regex_search(pass, uppers); //save the result, if the expression was found.
		is_lower = regex_search(pass, lowers); //....
		is_number = regex_search(pass, numbers);
		is_special = regex_search(pass, special_char);

		if (!((i > 11) && is_upper && is_lower && is_number && is_special))
		{

			cout << "invalid password try again with right required conditions \n";
			_getch();//It was not pausing :p
			goto START;
		}

		for (size_t j = 0; j < i; j++)
		{
			password1 = password1 + pass[j];
		}

	START2:
		string password2 = "";
		i = 0;
		cout << "\n\nenter the password again : " << endl;
		while (true)//infinite loop
		{
			a = _getch();//stores char typed in a
			if (a <= 126 && a >= 33)
			{
				pass2[i] = a;//stores a in pass
				++i;
				cout << "*";
			}
			if (a == '\r')//if enter is pressed
			{
				pass2[i] = '\0';//null means end of string.
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

		cout << "valid password " << endl;
		fstream userdata;
		string line;
		line = password1;
		userdata.open("email.txt", ios::in | ios::out | ios::app);
		userdata << password1 << endl;


		return 0;
	}
};



bool valid_email(string email);
bool valid_id(string id);
bool valid_username(string Username);
bool valid_mobilenum(string mobile_num);
bool new_email(string str2, string& s);
bool new_id(string str2, string& s);
bool new_username(string str2, string& s);
bool new_mobile(string str2, string& s);
void check(string& id, string& pass);
void ChangePassword(string& id, string& pass, string& newpass, string& newpass2);
string id, pass, newpass, newpass2;
char email[50];
char Username[50];
char passwordnew[50];
char ID[50];
char mobileNum[50];
int main() {

	string str;
	string str2;
	fstream userdata;
	string email;
	string id;
	string Username;
	string mobile_num;
	string password1;
	string password2;
	string line;
	int n;
	userdata.open("email.txt", ios::in | ios::out | ios::app);

	/*
	if (userdata.fail())
		cout << "fail to open" << endl;
	else
		cout << "success" << endl;
		*/
START:
	int choose;
	int counter;
	cout << "Hallo in our program :) " << endl;
	cout << "Enter 1 ------------> Regestration" << endl;
	cout << "Enter 2 ------------> Login" << endl;
	cout << "Enter 3 ------------->Change password" << endl;
	cout << "Enter 4 -------------> Exit " << endl;
	cout << "Enter your choose: " << endl;
	cin >> choose;
	if (choose == 1) {
		cout << "Plese enter your email : ";
		cin >> email;

		// if file is empty and regex is true add to file else check search and regex 
		while (true) {
			if (valid_email(email)) {
				cout << "Valid email" << endl;
				//userdata << email << endl;
				break;
			}
			else {

				cout << "Invalid email or this email is oready exist" << endl;
				cout << "please enter another email :";
				cin >> email;
			}
		}


		// enter id
		cout << "please enter your id : ";
		cin >> id;
		while (true) {
			if (valid_id(id) == 1 ) {
				cout << "Valid id " << endl;
				break;
			}
			else {
				cout << "INvalid id or this id is exist before " << endl;
				cout << "please enter anothor id : ";
				cin >> id;
			}
		}
		// enter  username
		cout << "please enter your Username :";
		cin.ignore();
		getline(cin, Username);
		while (true) {
			if (valid_username(Username) == 1 ) {
				cout << "Valid username" << endl;
				break;
			}
			else {
				cout << "Invalid Username or this username is exist before" << endl;
				cout << "please Try to enter another username :";
				cin >> Username;
			}
		}
		// enter  mobile num
		cout << "please enter your mobile number : ";
		cin >> mobile_num;
		while (true) {
			if (valid_mobilenum(mobile_num) == 1 ) {
				cout << "valid mobile number" << endl;
				break;
			}
			else {
				cout << "invalid mobile number or this mobile number is exist before" << endl;
				cout << "please Try ro enter another phone number";
				cin >> mobile_num;
			}
		}
		// enter password and confirm it 
		password n;
		n.main();
		// check if all is vaild 
		if (valid_email(email) == 1 && valid_username(Username) == 1 && valid_id(id) == 1
			&& valid_mobilenum(mobile_num) == 1) {
			cout << "Successful Rregesrtation :) " << endl;
			userdata << email << endl;
			userdata << Username << endl;
			userdata << id << endl;
			userdata << mobile_num << endl;
			userdata << endl;
			/*
			string line = password1;
			for (int i = 0; i < line.size(); i++) {
				userdata << char(line[i] + 1);
			}*/
			userdata << endl;
		}
	}
	userdata.close();

	if (choose == 2) {
		check(id, pass);
		goto START;
	}
	if (choose == 3) {
		cout << "you must login first \n";

		check(id, pass);
		ChangePassword(id, pass, newpass, newpass2);
	}
	if (choose == 4) {
		return 0;
	}

}
// valid_email
bool valid_email(string str) {
	regex filter1("[A-Za-z0-9_#!%$‘&+*–/=?^`.{|}~-]+(.)[A-za-z0-9_#!%$‘&+*–/=?^`.{|}~-]*@[A-za-z0-9-+/]+.(com)");
	return regex_match(str, filter1);
}
// valid_id 
bool valid_id(string str) {
	regex filter2("[0-9]+");
	return regex_match(str, filter2);
}
// valid username 
bool valid_username(string str) {
	regex filter3("[a-zA-z-_ ]+");
	return regex_match(str, filter3);
}
// valid mobile_number 
bool valid_mobilenum(string str) {
	regex filter4("01(0|2|1|5)[0-9]{8}");
	return regex_match(str, filter4);
}

// add new email
/*
bool new_email(string str2, string& s) {
	fstream fin("email.txt", ios::in);
	while (!fin.eof()) {
		while (fin >> s) {
			if (s == str2)
			{
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}

// add new id 
bool new_id(string str2, string& s) {
	fstream fin("email.txt", ios::in);
	while (!fin.eof()) {
		while (fin >> s) {
			if (s == str2)
			{
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}
// add new username 
bool new_username(string str2, string& s) {
	fstream fin("email.txt", ios::in);
	while (!fin.eof()) {
		while (fin >> s) {
			if (s == str2)
			{
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}

// add new mobile 
bool new_mobile(string str2, string& s) {
	fstream fin("email.txt", ios::in);
	while (!fin.eof()) {
		while (fin >> s) {
			if (s == str2)
			{
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}

*/
// login
void check(string& id, string& pass) {
	int i = 0;
	int c = 0;

	while (i < 3) {
		cout << "Enter the ID :  ";
		cin >> id;
		cout << "Enter the Password : ";
		cin >> pass;


		fstream file;
		file.open("email.txt", ios::in);
		while (!file.eof())
		{
			file.getline(passwordnew, 50);
			file.getline(email, 50);
			file.getline(Username, 50);
			file.getline(ID, 50);
			file.getline(mobileNum, 50);
			if (id == ID && pass == passwordnew)
			{
				c++;
				cout << "successful login  welcome " << Username << endl;
				break;
			}
		}

		if (c == 0) { cout << "Failed login , Try again  \n"; }
		else if (c == 1)
		{
			break;
		}

		i++;

		if (i == 3) { cout << "you are denied access to the system"; }

	}
}
 


// Encryption password
/*
void encrypt_pass(string str) {
	fstream userdata;
	string line = str;
	for (int i = 0; i < line.size(); i++) {
		userdata << char(line[i] + 1);
	}
}

*/
// change password 
void ChangePassword(string& id, string& pass, string& newpass, string& newpass2) {
	int c = 0;

	//
	fstream file;
	fstream temp;
	file.open("email.txt", ios::in);
	temp.open("temp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(passwordnew, 50);
		file.getline(email, 50);
		file.getline(Username, 50);
		file.getline(ID, 50);
		file.getline(mobileNum, 50);


		cout << "  ";//
		if (passwordnew == pass) {
			c++;
			cout << "Enter the new password : ";//
			cin >> newpass;
			cout << "Enter the confirm password";

			cout << "  ";
			cin >> newpass2;

			if (newpass2 == newpass) {
				cout << "done";


				temp << email << "\n" << Username << "\n" << ID << "\n" << newpass2 << "\n" << mobileNum << "\n";


			}
			else {
				temp << email << "\n" << Username << "\n" << ID << "\n" << passwordnew << "\n" << mobileNum << "\n";
			}

		}
		else {
			temp << email << "\n" << Username << "\n" << ID << "\n" << passwordnew << "\n" << mobileNum << "\n";
			break;
		}
		if (c == 0) {
			cout << "the password is wrong ";
			break;

		}
	}


	file.close();
	temp.close();


	file.open("email.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (!temp.eof())
	{
		temp.getline(passwordnew, 50);
		temp.getline(email, 50);
		temp.getline(Username, 50);
		temp.getline(ID, 50);
		temp.getline(mobileNum, 50);
		file << email << "\n" << Username << "\n" << ID << "\n" << passwordnew<< "\n" << mobileNum << "\n";

	}
	file.close();
	temp.close();

	//remove("temp.txt");



}