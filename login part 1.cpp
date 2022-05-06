#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<vector>
using namespace std;
bool valid_email(string email);
bool valid_id(string id);
bool valid_username(string Username);
bool valid_mobilenum(string mobile_num);
int main() {
	string str;
	fstream userdata;
	string email;
	string id;
	string Username;
	string mobile_num;
	string password;
	string confirm_password;
	userdata.open("main.txt", ios::in | ios::out | ios::app);
	/*
	if (userdata.fail())
		cout << "fail to open" << endl;
	else
		cout << "success" << endl;
		*/
		// enter  emaill
	cout << "Plese enter your email : ";
	cin >> email;

	
	if (valid_email(email) == 1) {
		cout << "Valid email" << endl;
		userdata << email << endl;
	}
	else {
		//cout << "Invalid email or this email is oready exist" << endl;
		cout << "Try again please :) " << endl;
	}


	// enter id
	cout << "please enter your id : ";
	cin >> id;
	if (valid_id(id) == 1) {
		cout << "Valid id " << endl;
		userdata << id << endl;
	}
	else
		cout << "INvalid id ";

	// enter  username
	cout << "please enter your Username :";
	cin.ignore();
	getline(cin, Username);
	if (valid_username(Username) == 1) {
		cout << "Valid username" << endl;
		userdata << Username << endl;
	}
	else {
		cout << "Invalid Username" << endl;
		cout << "please Try again" << endl;
	}
	// enter  mobile num
	cout << "please enter your mobile number : ";
	cin >> mobile_num;
	if (valid_mobilenum(mobile_num) == 1) {
		cout << "valid mobile number" << endl;
		userdata << mobile_num << endl;
	}
	else {
		cout << "invalid mobile number " << endl;
		cout << "please Try again" << endl;
	}
	// enter password and confirm it 
	cout << "please enter password :";
	cin >> password;
	cout << "please confirm password :";
	cin >> confirm_password;
	if (password == confirm_password ) {
		cout << "valid password";
		userdata << password << endl;

	}
	else {
		cout << "two passwords are not idental" << endl;
		cout << "please try again";
	}

	userdata.close();



}

// valid_email
bool valid_email(string str) {
	regex filter1("[A-Za-z0-9_#!%$‘&+*–/=?^`.{|}~-]*(.)[A-za-z0-9_#!%$‘&+*–/=?^`.{|}~-]*@[A-za-z0-9-+/]+.(com)");
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



