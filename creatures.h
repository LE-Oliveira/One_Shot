#include <string>
#include <iostream>
#include <math.h>
#include "classes.h"
#include <math.h>
#include <time.h>

creature wolf;
srand(time(NULL));
wolf.hp = rand() % 8 + 2 +rand() % 8;
wolf.atk = rand () % 4 + 2;
wolf.def = rand () % 3 + 2;
wolf.dex = rand () % 7 + 2;
wolf.xp = wolf.hp + wolf.dex*5 + wolf.atk*4 + wolf.def*3;

creature goblin;
goblin.hp = rand() % 6 + 1 + rand() % 6;
goblin.atk = rand () % 3 + 1;
goblin.def = rand () % 2 + 1;
goblin.dex = rand () % 4 + 1;
goblin.xp = goblin.hp + goblin.dex*5 + goblin.atk*4 + goblin.def*3;

creature chitine; 
chitine.hp = rand() % 6 + 4 +rand() % 6 + rand() % 6 + rand() % 6;
chitine.atk = rand () % 4 + 2;
chitine.def = rand () % 3 + 2;
chitine.dex = rand () % 7 + 2;
chitine.xp = chitine.hp + chitine.dex*5 + chitine.atk*4 + chitine.def*3;
