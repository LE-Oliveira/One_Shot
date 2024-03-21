#include "beast.hpp"

Beast::Beast(string name){
    srand(time(NULL));
    b_name = name;
    if(name == "wolf"){
        b_hp = rand() % 8 + 2 +rand() % 8;
        b_atk = rand () % 4 + 2;
        b_def = rand () % 3 + 2;
        b_dex = rand () % 7 + 2;
        b_luck = rand () % 10 + 1;
        b_xp = b_hp + b_dex*5 + b_atk*4 + b_def*3 + ceil(b_luck/2);
    }
    else if(name == "goblin"){
        b_hp = rand() % 6 + 1 + rand() % 6;
        b_atk = rand () % 3 + 1;
        b_def = rand () % 2 + 1;
        b_dex = rand () % 4 + 1;
        b_luck = rand () % 10 + 1;
        b_xp = b_hp + b_dex*5 + b_atk*4 + b_def*3 + ceil(b_luck/2);
    }
    else if(name == "chitine"){
        b_hp = rand() % 6 + 4 + rand() % 6 + rand() % 6 + rand() % 6;
        b_atk = rand () % 4 + 2;
        b_def = rand () % 3 + 2;
        b_dex = rand () % 7 + 2;
        b_luck = rand() % 5 + 1;
        b_xp = b_hp + b_dex*5 + b_atk*4 + b_def*3 + ceil(b_luck/2);
    }
    else if(name == "great wolf"){
        b_hp = rand() % 10 + 15 + rand() % 10 + rand() % 10 + rand() % 10 + rand() % 10;
        b_atk = rand() % 4 + rand() % 4 + 10;
        b_def = rand () % 3 + 6;
        b_dex = rand () % 7 + 11;
        b_luck = rand() % 5 + 7;
        b_xp = b_hp + b_dex*5 + b_atk*4 + b_def*3 + ceil(b_luck/2);
    }
}