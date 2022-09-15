#include <iostream>
#include <fstream> //file stream
#include <string>
#include<cstring>
using namespace std;
#pragma once
class text
{
public:
	string str;
	int choose;
	int counter=0;
	string file;
	void check(string str);
	void filter_1(string str);
	void filter_2(string str);
	void filter_3(string str);
	void filter_4(string str);
	void filter_5(string str);
	void filter_6(string str1);
	void filter_7(string str1, int& i, string& s);
	void filter_8(string str1, int& i, string& s);
	void filter_9(string str1, int& i);
	void filter_10(string str1, string& s);
	void filter_11(string str);
	void filter_12(string str);
	void filter_13(string str);
	void filter_14(string str1, string& s);
	void filter_15(string str);
	void choose_menu();
	text();
	~text();
};

