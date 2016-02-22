#include <iostream>
#include <vector>

using namespace std;

namespace rws2016_vsantos
{

	class Player
	{
	      public:

		Player(string name)
		{
			this->name = name;	//to avoid shadowing
			cout << name << endl;
		}

		string name;

		string getTeamName()
		{
			return team;
		}

		int setTeamName(int team_index = 1)	//1 by default
		{
			if(team_index == 0)
				setTeamName("red");
			else if(team_index == 1)
				setTeamName("green");
			else if(team_index == 2)
				setTeamName("blue");
		}

		//Set team name, if given a correct team name (accessor)
		int setTeamName(string team)	//can not have a default since it would be ambiguous
		{
			if(team == "red" || team == "green" || team == "blue")
			{
				this->team = team;
				return 1;
			}
			else
			{
				cout << "cannot set team name to " << team <<
					endl;
				return 0;
			}
		}


	      private:
		string team;
	};


	class MyPlayer:public Player
	{

	      public:
	      MyPlayer(string name, string team = "red"):Player(name)
		{
			setTeamName(team);

		}
		int varexample;
	};

	class Team
	{
	      public:

		Team(vector < string > player_names)
		{
			for(size_t i = 0; i < player_names.size(); ++i)
			{
				Player player_temp(player_names[i]);
				  players.push_back(player_temp);
			}
		}

		void printTeamInfo(void)
		{
			cout << "Team has the following players:" << endl;
			for(size_t i = 0; i < players.size(); i++)
				cout << players[i].name << endl;
		}

		vector < Player > players;
	};

}				//end of my namespace



int main()
{
	//std::vector < int >as;
	//int myint = 5;
	//as.push_back(myint);


	//as[1];
	//for(size_t i = 0; i < as.size(); ++i)
	//{
	//cout << "as[" << i << "]=" << as[i] << endl;
	//}


	//cout << "Hello" << endl;
	//MyPlayer player("vsantos", "blue");
	//rws2016_vsantos::MyPlayer player("vsantos");
	//Player player("vsantos");
	//player.setTeamName("red");
	//player.setTeamName(2);
	//player.setTeamName(); //use the default
	//cout << "Player name =" << player.name << endl;
	//cout << "Player team =" << player.team << endl;  //fails
	//cout << "Player team =" << player.getTeamName() << endl;      //fails


	std::vector < string > names;
	names.push_back("moliveira");
	names.push_back("vsantos");
	names.push_back("pdias");

	rws2016_vsantos::Team team(names);
	team.printTeamInfo();

	return 1;
}
