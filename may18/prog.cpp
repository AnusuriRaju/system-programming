// program to display the user name
#include <cstring>
#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include <sstream>

using namespace std; 
 class user 
{
	string userName;
	string userID;

	public:
	string name;
	string userid;

	User(string userName,string userID)
	{
	this->userName = name;
	this->userID = id;
	}
	int readFileinfo()
	{
		ifstream input;
		input.open("data.txt");
		if(!input.is_open())
		{
			cout << "Unable to open input file" << endl;
