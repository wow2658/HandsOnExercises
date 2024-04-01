#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map <string, int> player;
	//map <string, int> player; // key name 알파벳순으로 sort

	//insert
	player["luffy"] = 65;
	player["zoro"] = 97;
	player["sanji"] = 99;
	player["nami"] = 256;
	player.insert({ "usopp",77 });

	//update
	player["luffy"] = (1 + 0.1) * player["luffy"];

	//delete
	player.erase("usopp");

	//search
	string temp;
	cin >> temp;
	cout << endl;

	if (0 == player.count(temp))
	{
		cout << temp << " is not player" << endl;
	}
	else
	{
		cout << temp << " is playable" << endl;
	}
	cout << endl;

	auto it2 = player.find(temp);
	if (it2 == player.end()) 
	{
		cout << temp << " is not player2" << endl;
	}
	else {
		cout << temp << " is playable2" << endl<<endl;
	}
	


	//print
	for (pair<string,int> it : player)
	{
		cout << it.first << " Lv_" << it.second << endl;
	}
	cout << endl;

	for (auto it = player.begin(); it != player.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << endl;
	}
	cout << endl;

	cout << boolalpha <<player.empty() << " " << player.size() << endl;
	player.clear();
	cout << noboolalpha <<player.empty() << " " << player.size() << endl;

	
	return 0;
}
