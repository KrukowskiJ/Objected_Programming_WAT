#include "Tank.h"
#include <iostream>
#include <windows.h>


using namespace std;


void Tank::fight(Tank* enemy)
{
	

	cout << "\n\nStatystyki czolgu " << this->tank_type <<"  "<< this->color << " atak: " << this->attack_points << " obrona : " << this->defence_points << "\n";
	cout << "Statystyki czolgu " << enemy->tank_type << "  " << enemy->color << " atak: " << enemy->attack_points << " obrona : " << enemy->defence_points << "\n\n\n";

	if(this->animation_status)
	this->Tank::animation();
	

	if (enemy->defence_points > this->attack_points)
		enemy->defence_points -= this->attack_points;
	else {
		enemy->defence_points = 0;
	}
	/*if (this->defence_points > enemy->attack_points)
		this->defence_points -= enemy->attack_points;
	else {
		this->defence_points = 0;
	}
	*/
}

void Tank::animation(){

	cout << "\n     _||======\n";
	cout << "   _|   |__\n";
	cout << "  / oooooo /\n";
	for (int i = 0; i < 20; i++) {
		cout << "-";
		Sleep(75);
	}
	cout << "\n";
}
void Tank::show() {
	cout << "id: " << this->color<<"_"<< this->id << "  ";
	cout << "  atak: " << this->attack_points << "  ";
	cout << "obrona: " << this->defence_points << "  ";
	cout << "type: " << this->tank_type << "  ";
	cout << "weight: " << this->tank_weight << "  ";
	cout << "max_speed: " << this->tank_speed << "  \n";
}
