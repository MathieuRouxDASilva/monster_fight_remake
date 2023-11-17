#pragma once
#include "Monster.h"
//all extern variables
#pragma region extern
extern int Choice;
extern int action;
extern bool ParryOncePlayer;
extern bool ParryOnceEnemy;
#pragma endregion

//function to show stats
void ShowStats(Monster& monster);

//function to see what the player want to do 
void Actions();

//function to realise action
void Turn(Monster& monster, Monster& ennemy);

//function to realise enemy action
void EnemyTurn(Monster& enemy, Monster& monster);

//function to calculate if next move is a crit or not
bool IsCrit();

//function that decide based on luck what enemy do
void EnnemyChoice();

//function to reset def
int ResetDef(Monster& player, Monster& enemy);