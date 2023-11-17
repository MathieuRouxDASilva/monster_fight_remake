#pragma once
#include <string>
#include <vector>
//monster class
class Monster
{
	int Atk;
	int Def;
	int Hp;
	int Speed;
	std::string Name;

public:
	//constructor
	Monster(int  atk, int def, int hp, int speed, std::string name) : Atk(atk), Def(def), Hp(hp), Speed(speed), Name(name) {};

	//all methods to affect you/enemy
	int InfflictDmg(Monster& ennemy);
	int InfflictCritDmg(Monster& ennemy);
	int Heal();
	int Parry();
	int resetDef();

	//methods to use in main
	void Display();
	int GetHp();
	int GetSpeed();
};
