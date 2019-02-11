#pragma once
#include<iostream>
#include<string>
#include "pch.h"
//#include<cstring>
#include<fstream>
using namespace std;

class CricketTeam
{
private:
	string * membernames;
	int no_of_members;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
	string filepath;
	int trackofMembers;
public:
	CricketTeam();
	CricketTeam(string teamName, int no_of_members);
	CricketTeam(string filepath);
	int getRank(int Rank)const;
	char getteamName(int teamName)const;
	string getcaptian(string captain)const;
	int getno_of_members(int no_of_members)const;
	void setRank(int&Rank);
	void setteamName(char*&teamName);
	void setno_of_members(int &no_of_members);
	void setcaptian(string &captian);
	void inputTeamMember(string name);
	void inputScore(int score);
	int AverageScore(int Scoreinlast10matches[10]);
	bool compare(CricketTeam otherTeam);
	void printPerformance(int Scoreinlast10matches[10], string * membernames, string captain, int trackofMembers);
	void TeamInfo();
};

