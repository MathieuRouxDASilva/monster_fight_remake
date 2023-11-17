#include <iostream>
#include "Monster.h"
#include "Function_Game.h"

int main()
{
#pragma region Variables
	//variables + Monster vector
	std::vector<Monster> Playable_Monster
	{
	Monster {5, 4, 10, 5, "Orc"},
	Monster {8, 3, 10, 2, "Troll"},
	Monster {5, 2, 10, 10, "Reptile"},
		Monster {6, 0, 20, 0, "secret feature"},
	};
	bool Alive = true;
	int PlayerChoice;
	int MonsterChoice;
	int Round = 1;
#pragma endregion

	//choices of monster (do not fight same monster it doesn't work -> stats does not change at all)
	std::cout << "who is the first fighter ?\n\n";
	std::cout << "type in [0] for the orc, [1] for the troll, [2] for the reptile ?\n\n";
	std::cin >> PlayerChoice;
	std::cout << "who is the secound fighter ?\n\n";
	std::cout << "type in [0] for the orc, [1] for the troll, [2] for the reptile ?\n\n";
	std::cin >> MonsterChoice;

	//setupp your monster
	Monster Enemy = Playable_Monster.at(MonsterChoice);
	Monster Player = Playable_Monster.at(PlayerChoice);

	system("cls");

	//show stat player monster
	std::cout << "your monster has : \n" << "-------------\n";
	ShowStats(Player);

	//show stat enemy monster
	std::cout << "the enemy monster has : \n" << "-------------\n";
	ShowStats(Enemy);

	do
	{
		//setup round number
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t [Round :" << Round << "]\n";

		//action player
		Actions();

		//speed decide who attack first
		if (Player.GetSpeed() > Enemy.GetSpeed())
		{
			//action player
			Turn(Player, Enemy);

			// action ennemy
			EnemyTurn(Enemy, Player);
		}
		else if (Enemy.GetSpeed() > Player.GetSpeed())
		{
			//action enemy
			EnemyTurn(Enemy, Player);

			// action player
			Turn(Player, Enemy);
		}

		//show stats
		std::cout << "your monster has : \n" << "-------------\n";
		ShowStats(Player);
		std::cout << "the enemy monster has : \n" << "-------------\n";
		ShowStats(Enemy);

		//reset def stat in case parry so it is usefull only one turn
		ResetDef(Player, Enemy);

		//setupp win/lose
		if (Player.GetHp() <= 0)
		{
			std::cout << "you lose\n";
			Alive = false;
		}
		else if (Enemy.GetHp() <= 0)
		{
			std::cout << "you win\n";
			Alive = false;
		}
		Round++;
	} while (Alive == true);
}
