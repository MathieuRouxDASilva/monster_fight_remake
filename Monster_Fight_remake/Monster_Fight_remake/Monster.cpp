#include "Monster.h"
#include <iostream>

//method to inflict dmg to your opponent
int Monster::InfflictDmg(Monster& ennemy)
{
	int Damage = Atk - ennemy.Def;

	if (Damage < 0)
	{
		std::cout << "too much def\n";
		return Hp;
	}
	return ennemy.Hp -= Damage;
}

//method to inflict crit dmg(throught def stat) to your opponent
int Monster::InfflictCritDmg(Monster& ennemy)
{
	return ennemy.Hp -= Atk;
}

//method to recover 5 hp
int Monster::Heal()
{
	return Hp += 5;
}

//method to raise def stat for 1 turn
int Monster::Parry()
{
	return Def += 2;
}

//method to show all stats
void Monster::Display()
{

	std::cout << "Atk : " << Atk << "\n";
	std::cout << "Def : " << Def << "\n";
	std::cout << "Hp : " << Hp << "\n";
	std::cout << "Speed : " << Speed << "\n";
	std::cout << "name : " << Name << "\n";

}

//method to get hp stat (main)
int Monster::GetHp()
{
	return Hp;
}

//method to get speed stat (main)
int Monster::GetSpeed()
{
	return Speed;
}

//method to make def normal again
int Monster::resetDef()
{
	return Def -= 2;
}