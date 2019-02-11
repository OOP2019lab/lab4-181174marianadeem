// q1_1811874.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"CricketTeam.h"
#include<string>

CricketTeam::CricketTeam()
{
	int no_of_members = -1;
	string * membernames;
	membernames = new string[no_of_members];
	char *teamName;
	teamName = new char;
	teamName = nullptr;
	int Scoreinlast10matches[10];
	for (int i = 0;i < 10;i++)
	{
		Scoreinlast10matches[i] = -1;
	}
	int Rank = -1;
	string captain="";
	string filepath="";
	int trackofMembers=-1;
}
CricketTeam::CricketTeam(string teamName, int no_of_members)
{
	for (int i = 0;i < no_of_members;i++)
	{
		Scoreinlast10matches[i] = -1;
	}
	int Rank = -1;
	string captain = "";
	string filepath = "";
	int trackofMembers = -1;
	int trackofMembers = -1;
}
CricketTeam::CricketTeam(string filepath)
{
	ifstream fin;
	fin.open(filepath);
	while (!fin.eof())
	{
		string temp="o";
		while (temp != ":")
		{
			fin >> temp;
		}
		fin >> *teamName;
		temp = "o";
		while (temp != ":")
		{
			fin >> temp;
		}
		fin >> no_of_members;
		for (int i = 0;i < 11;i++)
		{
			string s1,s2,s3;
			fin >> s1;
			s2 = " ";
			fin >> s3;
			membernames[i]=s1+s2+s3;
		}
		temp = "o";
		while (temp != ":")
		{
			fin >> temp;
		}
		fin >> Rank;
		temp = "o";
		while (temp != ":")
		{
			fin >> temp;
		}
		string s1,s2,s3;
		fin >> s1;
		fin >> s2;
		fin >> s3;
		captain=s1+s2+s3;
		temp = "o";
		while (temp != ":")
		{
			fin >> temp;
		}
		for (int i = 0;i < 10;i++)
		{
			string str;
			int score;
			getline(fin, str, ',');
			//stoi(str, Scoreinlast10matches[i]);///error :(
		}
	}
	fin.close;
}
int CricketTeam:: getRank(int Rank)const
{
	return Rank;
}
char CricketTeam::getteamName(int teamName)const
{
	return teamName;
}
string CricketTeam::getcaptian(string captain)const
{
	return captain;
}
int CricketTeam::getno_of_members(int no_of_members)const
{
	return no_of_members;
}
void CricketTeam::setRank(int&rank)
{
	Rank = rank;
}
void CricketTeam::setteamName(char*&TeamTitle)
{
	*teamName = *TeamTitle;  
}
void CricketTeam::setno_of_members(int &numofMembers)
{
	//void CricketTeam::setno_of_members(int &numofMembers)
		no_of_members = numofMembers;
}
void CricketTeam::setcaptian(string &Captian)
{
	captain = Captian;
}
void CricketTeam::inputTeamMember(string name)
{
	for (int i = 0;i < no_of_members;i++)
	{
		//cout << "enter the player's name";
		membernames[i]=name;
		trackofMembers++;
		if (trackofMembers == 10)
		{
			cout<<"team is full";
			return;
		}
	}
}
void CricketTeam::inputScore(int score)
{
	for (int i = 0;i < 10;i++)
	{
		if (Scoreinlast10matches[i] == -1)
		{
			Scoreinlast10matches[i] = score;
		}
	}
	for (int i=0;i > 1;i--)
	{
		Scoreinlast10matches[i - 1] = Scoreinlast10matches[i];
	}
	Scoreinlast10matches[9] = score;
}
int CricketTeam::AverageScore(int Scoreinlast10matches[10])
{
	int average;
	for (int i = 0;i < 10;i++)
	{
		average += Scoreinlast10matches[i];
	}
	average = average / 10;
	return average;
}
bool CricketTeam::compare(CricketTeam otherTeam)
{
	int average;
	for (int i = 0;i < 10;i++)
	{
		average += Scoreinlast10matches[i];
	}
	average = average / 10;
	int averageforotherTeam = otherTeam.AverageScore(otherTeam.Scoreinlast10matches);
	if (average < averageforotherTeam)
		return true;
	if (average > averageforotherTeam)
		return false;
	if (average = averageforotherTeam)
		return false;
}
void CricketTeam::printPerformance(int Scoreinlast10matches[10], string * membernames, string captain, int trackofMembers)
{
	cout << "Name of the Captian is:" <<captain<< endl;
	cout << "score in last 10 matches is:";
	for (int i = 0;i < 10;i++)
	{
		cout << Scoreinlast10matches[i] << ",";
	}cout << endl;
	cout << "names of players of the teams are:";
	for (int i = 0;i < trackofMembers;i++)
	{
		cout << membernames[i] << endl;
	}
}
void CricketTeam::TeamInfo()
{
	cout << "Name of the Captian is:" << captain << endl;
	cout << "score in last 10 matches is:";
	for (int i = 0;i < 10;i++)
	{
		cout << Scoreinlast10matches[i] << ",";
	}cout << endl;
	cout << "names of players of the teams are:";
	for (int i = 0;i < trackofMembers;i++)
	{
		cout << membernames[i] << endl;
	}
	cout << "Rank of the team is" << Rank<<endl;
	cout << "number of players of the team" << no_of_members<<endl;
	cout << "number of more players needed in the team" << no_of_members - trackofMembers << endl;
}
CricketTeam::~CricketTeam()
{
	cout << "destructor of the object is invoke" << endl;
	/*for (int i = 0;i < no_of_members;i++)///error :(
	{
		delete []membernames[i];
	}*/
	delete[]membernames;
	delete membernames;
	delete teamName;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
