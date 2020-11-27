#include <iostream>
#include "Tank.h"
#include <vector>
#include <ctime>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

void team_point( vector<Tank> & defeat, vector<Tank> & win, int *counter) {

	for (int i = 0; i < defeat.size(); i++)
	{
			defeat[i % defeat.size()].defence_points--;
			if (defeat[i % defeat.size()].defence_points <= 0) {
				cout << "usuwamy czolg: ";
				defeat[i % defeat.size()].show();
				defeat.erase(defeat.begin() + (i % defeat.size()));
				counter--;
				team_point( defeat, win, counter);
			}
	}
	for (int i = 0; i < win.size(); i++)
	{

		win[i % win.size()].attack_points++;

	}
	
}	

int main() {
	const int n = 5;  //podaj
	srand(time(NULL));
	std::vector <Tank> red(n);
	std::vector <Tank> blue(n);
	char choice = 'T';
	bool animation_status = 1;
	cout << "Czy chcesz wyswietlic animacje walki?\nT - TAK \nN - NIE\n";
	cin >> choice;
	if(choice == 'N' || choice == 'n')
		animation_status = 0;

	REP(i, n)
	{
		//dodanie czolgow niebieskich
		blue[i] = Tank(animation_status , 2 * i + 1, "blue", rand() % 10 + 1, rand() % 10 + 1);
	}
	REP(i, n)
	{
		//dodanie czolgow czerwonych
		red[i] = Tank(animation_status , 2 * i + 2, "red", rand() % 10 + 1, rand() % 10 + 1);
	}

	int i = 0, j=0;
	while (blue.size() != 0 && red.size() != 0)
	{
		cout << "\n pozostale w grze czolgi : \n";
		for (int i = 0; i < blue.size(); i++)
		{
			if (i == 0)
				cout << "\n BLUE TEAM : \n";
			blue[i].show();
		}
		for (int i = 0; i < red.size(); i++)
		{
			if (i == 0)
				cout << "\n RED TEAM : \n";

			red[i].show();
		}


		blue[i % blue.size()].fight(&red[j % red.size()]);

		if (blue[i % blue.size()].defence_points <= 0) {
			cout << "usuwamy czolg: ";
			blue[i % blue.size()].show();
			blue.erase(blue.begin() + (i % blue.size()));
			
			i--;
			team_point( blue, red, &i);
			
		}

		if (red[j % red.size()].defence_points <= 0) {
			cout << "usuwamy czolg: ";
			red[j % red.size()].show();
			red.erase(red.begin() + (j % red.size()));
			j--;
			team_point( red, blue, &j);
			
		}
		i++;
		j++;

	}

	if (blue.size() == 0 && red.size()==0) {
		cout << "\nNikt nie wygral, czolgi zniszczyly sie wzajemnie w ostatniej walce \n";
		blue.clear();
		red.clear();
	}
	else {
		if (blue.size()) {
			cout << "\nBLUE WINS: \n";
			for (int i = 0; i < blue.size(); i++)
			{

				blue[i].show();
			}
			blue.clear();
		}
		if(red.size()) {
			cout << "\nRED WINS: \n";
			for (int i = 0; i < red.size(); i++)
			{

				red[i].show();
			}
			red.clear();
		}
	}

	return 0;
}