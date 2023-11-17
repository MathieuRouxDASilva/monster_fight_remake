#include "Function_Game.h"
#include <iostream>
#include "Monster.h"
#pragma region variables
int Choice;
int action;
bool ParryOncePlayer = false;
bool ParryOnceEnemy = false;
#pragma endregion

//place where functions are define(to see what they do look Function_Game.h)

bool IsCrit()
{
	srand(time(NULL));

	int CritChance = rand() % 5;

	if (CritChance == 0)
	{
		return true;
	}
	return false;
}

void ShowStats(Monster& monster)
{
	monster.Display();
	std::cout << "-------------\n";
}

void Actions()
{

	std::cout << "what action do you want to do ?\n";
	std::cout << "[0] to attack (can crit), [1] to heal (5 hp), [2] to parry (raise def)\n";
	std::cin >> action;

}

void Turn(Monster& monster, Monster& ennemy)
{
	switch (action)
	{
	case 0:
		if (IsCrit())
		{
			std::cout << "Your monster infflict crit dmg : \n";
			monster.InfflictCritDmg(ennemy);
		}
		else
		{
			std::cout << "Your monster attack : \n";
			monster.InfflictDmg(ennemy);
		}
		break;
	case 1:
		if (monster.GetHp() >= 10)
		{
			std::cout << "can't heal, you are full life\n";
		}
		else
		{
			std::cout << "Your monster heal : \n";
			monster.Heal();
		}
		break;
	case 2:
		std::cout << "Your monster parry : \n";
		monster.Parry();
		ParryOncePlayer = true;
		break;
	default:
		std::cout << "don?t know what to do sry\n";

	}
}

void EnnemyChoice()
{
	srand(time(NULL));

	Choice = rand() % 3;

}

void EnemyTurn(Monster& enemy, Monster& monster)
{
	EnnemyChoice();
	switch (Choice)
	{
	case 0:
		if (IsCrit())
		{
			std::cout << "Ennemy monster infflict crit dmg : \n";
			enemy.InfflictCritDmg(monster);
		}
		else
		{
			std::cout << "Ennemy monster attack : \n";
			enemy.InfflictDmg(monster);
		}
		break;
	case 1:
		if (enemy.GetHp() >= 10)
		{
			std::cout << "your enemy can't heal, he is full life\n";
		}
		else
		{
			std::cout << "Enemy monster heal : \n";
			enemy.Heal();
		}
		break;
	case 2:
		std::cout << "Ennemy monster parry : \n";
		enemy.Parry();
		ParryOnceEnemy = true;
		break;
	default:
		std::cout << "don?t know what to do sry\n";

	}
}

int ResetDef(Monster& player, Monster& enemy)
{
	if (ParryOncePlayer)
	{
		ParryOncePlayer = false;
		return player.resetDef();
	}
	if (ParryOnceEnemy)
	{
		ParryOnceEnemy = false;
		return enemy.resetDef();
	}

	return 0;
}