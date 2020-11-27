#include <iostream>
#include "Tank.h"
#include <vector>
#include <ctime>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

void order(Tank * me, Tank * enemy) {
	me->fight(enemy);

}

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
	const int n = 8;  //podaj
	srand(time(NULL));
	std::vector <Tank> all_tanks;
	std::vector <Tank> red(n);
	std::vector <Tank> blue(n);
	char choice = 'T';
	bool animation_status = 1;
	cout << "Czy chcesz wyswietlic animacje walki?\nT - TAK \nN - NIE\n";
	cin >> choice;
	if(choice == 'N' || choice == 'n')
		animation_status = 0;

	REP(i, 2*n)
	{
		//dodanie czolgow niebieskich
		PR nowy(animation_status, (i + 0)%n +1, rand() % 10 + 1, rand() % 10 + 1);
		all_tanks.push_back(nowy);
		TO nowy1(animation_status, (i + 1) % n +1, rand() % 25 + 1, rand() % 10 + 1);
		all_tanks.push_back(nowy1);
		SW nowy2(animation_status, (i + 2) % n +1, rand() % 10 + 1, rand() % 20 + 1);
		all_tanks.push_back(nowy2);
		BWP nowy3(animation_status, (i + 3) % n +1, rand() % 10 + 1, rand() % 10 + 1);
		all_tanks.push_back(nowy3);
		CZ nowy4(animation_status, (i + 4) % n +1, rand() % 20 + 1, rand() % 10 + 1);
		all_tanks.push_back(nowy4);
		SZP nowy5 (animation_status, (i + 5) % n +1, rand() % 30 + 1, rand() % 10 + 1);
		all_tanks.push_back(nowy5);
		DS nowy6 (animation_status, (i + 6) % n +1, rand() % 10 + 1, rand() % 30 + 1);
		all_tanks.push_back(nowy6);
		SA nowy7 (animation_status, (i + 7) % n +1, rand() % 10 + 1, rand() % 20 + 1);
		all_tanks.push_back(nowy7);
		i += n-1;
	}
	for (int i = 0; i < all_tanks.size(); i++)
	{
		if (i < n) {
			blue[i % n] = all_tanks[i];
			blue[i % n].color_change("blue");
		}
		else {
			red[i % n] = all_tanks[i];
			red[i % n].color_change("red");
		}
	}

	all_tanks.clear();


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

		if (blue.size())
		if (blue[i % blue.size()].zwroc()) {
			int x = rand() % blue.size();
			cout <<"\n"<< blue[i % blue.size()].zwroc_typ() << " blue (R) -> ";
			cout << blue[x].zwroc_typ() << " blue (A) -> ";
			cout << red[i % red.size()].zwroc_typ() << " red";
			order(&blue[x], &red[i % red.size()]);
		}
		else {
			if (blue.size()) {
				cout << "\n" << blue[i % blue.size()].zwroc_typ() << " blue (A) -> ";
				cout << red[i % red.size()].zwroc_typ() << " red";
				blue[i % blue.size()].fight(&red[j % red.size()]);
				if (!red[j % red.size()].defence_points) {
					cout << "usuwamy czolg : ";
					red[j % red.size()].show();
					red.erase(red.begin() + (j % red.size()));
				}
			}
		}



		if (red.size())
		if (red[i % red.size()].zwroc()) {
			int x = rand() % red.size();
			cout << red[i % red.size()].zwroc_typ()<<" red (R) -> ";
			cout << red[x % red.size()].zwroc_typ()<<" red (A) -> ";
			cout << blue[i % blue.size()].zwroc_typ() << " blue";
			order(&red[x % red.size()], &blue[i % blue.size()]);
		}
		else {
			if (red.size()) {
				cout << red[i % red.size()].zwroc_typ() << " red (A) -> ";
				cout << blue[i % blue.size()].zwroc_typ() << " blue";
				red[i % red.size()].fight(&blue[j % blue.size()]);
				if (!blue[j % blue.size()].defence_points) {
					cout << "usuwamy czolg : ";
					blue[j % blue.size()].show();
					blue.erase(blue.begin() + (j % blue.size()));
				}
			}
		}


	if(blue.size())
		if (blue[i % blue.size()].defence_points <= 0) {
			cout << "usuwamy czolg: ";
			blue[i % blue.size()].show();
			blue.erase(blue.begin() + (i % blue.size()));
			i--;
			team_point( blue, red, &i);
		}
	if(red.size())
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

	red.clear();
	blue.clear();
	

	return 0;
}