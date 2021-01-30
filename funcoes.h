#ifndef _funcoes_
#define _funcoes_

#include "classes.h"

creature createWolf();
creature createGoblin();
creature createChitine();
weapon createShortBow();
weapon createIronDagger();
weapon createLongBow();
weapon createShortSword();
weapon createSpear();
weapon createBattleAxe();
weapon createScythe();
personagem inicia();
personagem upStat(personagem character);
void battleMenu();
personagem battle(personagem character);
void inventory(personagem character);
personagem store(personagem character);
personagem heal(personagem character, bool went);

#endif