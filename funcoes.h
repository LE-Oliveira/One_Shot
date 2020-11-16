#include "classes.h"
#include <time.h>
#include <math.h>

using namespace std;

creature create_wolf(){
    creature wolf;
    srand(time(NULL));
    wolf.hp = rand() % 8 + 2 +rand() % 8;
    wolf.atk = rand () % 4 + 2;
    wolf.def = rand () % 3 + 2;
    wolf.dex = rand () % 7 + 2;
    wolf.luck = rand () % 10 + 1;
    wolf.xp = wolf.hp + wolf.dex*5 + wolf.atk*4 + wolf.def*3 + ceil(wolf.luck/2);
    return wolf;
}

creature create_goblin(){
    creature goblin;
    goblin.hp = rand() % 6 + 1 + rand() % 6;
    goblin.atk = rand () % 3 + 1;
    goblin.def = rand () % 2 + 1;
    goblin.dex = rand () % 4 + 1;
    goblin.luck = rand () % 10 + 1;
    goblin.xp = goblin.hp + goblin.dex*5 + goblin.atk*4 + goblin.def*3 + ceil(goblin.luck/2);
    return goblin;
}

creature create_chitine(){
    creature chitine; 
    chitine.hp = rand() % 6 + 4 +rand() % 6 + rand() % 6 + rand() % 6;
    chitine.atk = rand () % 4 + 2;
    chitine.def = rand () % 3 + 2;
    chitine.dex = rand () % 7 + 2;
    chitine.luck = rand() % 5 + 1;
    chitine.xp = chitine.hp + chitine.dex*5 + chitine.atk*4 + chitine.def*3 + ceil(chitine.luck/2);
    return chitine;
}

weapon createLongBow(){
    weapon long_bow;
    long_bow.name = "Arco Longo";
    long_bow.bonus = 2;
    long_bow.price = 5000;
    long_bow.equiped = false;
    return long_bow;
}

weapon createShortSword(){
    weapon short_sword;
    short_sword.name = "Espada Curta";
    short_sword.bonus = 2;
    short_sword.price = 1000;
    short_sword.equiped = false;
    return short_sword;
}

weapon createSpear(){
    weapon spear;
    spear.name = "Lança";
    spear.bonus = 2;
    spear.price = 100;
    spear.equiped = false;
    return spear;
}

weapon createBattleAxe(){
    weapon battle_axe;
    battle_axe.name = "Machado de Batalha";
    battle_axe.bonus = 2;
    battle_axe.price = 3000;
    battle_axe.equiped = false;
    return battle_axe;
}

weapon createScythe(){
    weapon scythe;
    scythe.name = "Foice";
    scythe.bonus = 3;
    scythe.price = 5000;
    scythe.equiped = false;
    return scythe;
}

personagem inicia(personagem character){
    character.lvl = 1;
    character.weapons[0].name = "Short Bow";
    character.weapons[1].name = "Iron Dagger";
    character.weapons[0].price = 2500;
    character.weapons[1].price = 200;
    character.weapons[0].bonus = 0;
    character.weapons[1].bonus = 0;
    character.weapons[0].equiped = true;
    character.weapons[1].equiped = true;
    character.money = 0;
    character.upgrades = character.lvl*10;
    character.xp = 0;
    character.atk = 1;
    character.def = 1;
    character.dex = 1;
    character.luck = 1;
    character.vit = 1;
    return character;
}

personagem up_stat(personagem character){
    system("clear");
    int aux;
    string answer, opt;
    cout << "Points Menu" <<endl;
    cout << "1 - See profile" << endl;
    cout << "2 - Upgrade stats" << endl;
    cout << "3 - Reset stats" << endl;
    cout << "4 - See experience" << endl;
    cout << "5 - Return to previous menu" << endl;
    cin >> aux;
    if (aux==1){
        system("clear");
        cout << "Level: " << character.lvl << endl;
        cout << "Name: " << character.name << endl;
        cout << "Money: " << character.money << endl;
        cout << "Constitution: " << character.def << endl;
        cout << "Strength: " << character.atk << endl;
        cout << "Dexterity: " << character.dex << endl;
        cout << "Luck: " << character.luck << endl;
        cout << "Vitality: " << character.vit << endl;
        system("sleep 6");
    }
    else if (aux==2){
        if (character.upgrades>0){
            while (character.upgrades>0){
                system("clear");
                cout << "You still have " << character.upgrades << " available" << endl;
                cout << "Please distribute them" << endl;
                cout << "1 - Constitution: " << character.def << endl;
                cout << "2 - Strength: " << character.atk << endl;
                cout << "3 - Dexterity: " << character.dex << endl;
                cout << "4 - Luck: " << character.luck << endl;
                cout << "5 - Vitality: " << character.vit << endl;
                opt = getchar();
                if(opt == "1"){
                    character.def++;
                    character.upgrades--;
                }
                else if(opt == "2"){
                    character.atk++;
                    character.upgrades--;
                }
                else if(opt == "3"){
                    character.dex++;
                    character.upgrades--;
                }
                else if(opt == "4"){
                    character.luck++;
                    character.upgrades--;
                }
                else if(opt == "5"){
                    character.vit++;
                    character.upgrades--;
                }
                else{
                    cout << "Valor inválido" << endl;
                    system("sleep 2");
                }
            }
        }
        else{
            system("clear");
            cout << "You don't have any remaining points" << endl;
            system("sleep 2");
        }
    }
    else if (aux==3){
        cout << "Reseting the stats will cost you 100 coins and this action can't be undone. Are you sure? [Y/N]" << endl;
        cin >> answer;
        if (answer == "Y"){
            if (character.money >= 100){
                character.upgrades = character.upgrades + character.def + character.atk + character.dex + character.luck + character.vit - 5;
                character.def = 1;
                character.atk = 1;
                character.dex = 1;
                character.luck = 1;
                character.vit = 1;
                character.hp = 12;
                character.money = character.money - 100;
                system("clear");
                cout << "All stats were reset" <<endl;
                system("sleep 2");
            }
            else{
                system("clear");
                cout << "You don't have enough money. Defeat more enemies to get more money" << endl;
                system("sleep 2");
            }
        }
    }
    else if (aux==4){
        system("clear");
        cout << "You have " << character.xp << " experience points" << endl;
        cout << "For the next lvl you need " << (character.lvl*10+pow(5,character.lvl))*10 << " experience points" << endl;
        system("sleep 3");
    }
    return character;
}

void battle_menu(){
    cout << "It is your turn" << endl;
    cout << "What you want to do?" <<endl;
    cout << "1 - Hit him with a knife" << endl;
    cout << "2 - Throw an arrow on him" << endl;
    cout << "3 - Run away" << endl;
}

personagem battle(personagem character){
    system("clear");
    bool turn = false;
    int being, attack, damage, hit, qtd, i, chance;
    string aux;
    srand(time(NULL));
    being = rand() % (character.lvl + 1) + 1;
    if (being==1){
        cout << "You find a wolf" << endl;
        system("sleep 1");
        creature wolf = create_wolf();
        if (character.dex>wolf.dex){
            turn = true;
        }
        while ((wolf.hp>0)&&(character.hp>0)){
            if(turn){
                system("clear");
                battle_menu();
                damage = character.atk - wolf.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                system("clear");
                hit = rand() % 20 + 1 + floor(character.luck/5) - floor(wolf.luck/5);
                if (attack==1){
                    turn = false;
                    srand(time(NULL));
                    if ((hit+character.weapons[1].bonus/5)>=20){
                        damage = 2*damage;
                        wolf.hp = wolf.hp - damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit>floor(10-character.dex/5)){
                        wolf.hp = wolf.hp - damage;
                        cout << "You cut him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if (attack==2){
                    turn = false;
                    if (hit>=20){
                        damage = 3*damage;
                        wolf.hp = wolf.hp - damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit>floor(15 - character.dex/5)){
                        damage = ceil(1.5*damage);
                        wolf.hp = wolf.hp - damage;
                        cout << "Your arrow pierced him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if (attack==3){
                    cout << "You ran away" << endl;
                    break;
                }
            }
            else{
                cout << "It is the wolf's turn" << endl;
                system("sleep 1");
                system("clear");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = wolf.atk - character.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 + 1 + floor(wolf.luck/5) - floor(character.luck/5);
                if (attack==1){
                    turn = true;
                    if (hit>=20){
                        damage = 2*damage;
                        character.hp = character.hp - damage;
                        cout << "Ouch, he dealt you a serious scratch" << endl;
                    }
                    else if(hit>ceil(10-wolf.dex/5)){
                        character.hp = character.hp - damage;
                        cout << "He scratched you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the wolf hurt itself" << endl;
                        wolf.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                else if (attack==2){
                    turn = true;
                    if (hit>=20){
                        damage = 3*damage;
                        character.hp = character.hp - damage;
                        cout << "Ouch, he dealt you a serious bite" << endl;
                    }
                    else if(hit>ceil(15-wolf.dex/5)){
                        character.hp = character.hp - floor(1.5*damage);
                        cout << "He bit you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the wolf hurt itself" << endl;
                        wolf.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << character.name <<"'s hp: " << character.hp << endl;
            cout << "Wolf's hp: " << wolf.hp << endl;
            system("sleep 2");
            system("clear");
        }
        if (wolf.hp<=0){
            cout << "Congratulations, you just defeated a wolf" << endl;
            srand(time(NULL));
            if ((rand() % 5 + ceil(1+character.luck/10) >= 5)){
                srand(time(NULL));
                qtd = rand() % 4 + ceil(1 + character.luck/10);
                cout << "It's your lucky day, you found " << qtd << " Wolf's Claws" << endl;
                cout << "With this claws you can earn some money on the store" << endl;
            }
            if ((rand() % 10 + ceil(1+character.luck/10)) >= 10){
                srand(time(NULL));
                qtd = rand() % 10 + ceil(1 + character.luck/10);
                cout << "It's your lucky day, you found " << qtd << " packs of Wolf's fur" << endl;
                cout << "You can sell those packs on the store" << endl;
            }
            character.xp = character.xp+wolf.xp;
        }
        else if (character.hp<=0){
            cout << "Oh, the wolf was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("sleep 2");
    }
    else if (being==2){
        cout << "You find a goblin" << endl;
        system("sleep 1");
        creature goblin = create_goblin();
        if (character.dex>goblin.dex){
            turn = true;
        }
        while ((goblin.hp>0)&&(character.hp>0)){
            if(turn){
                system("clear");
                battle_menu();
                damage = character.atk - goblin.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                system("clear");
                hit = rand() % 20 + 1 + floor(character.luck/5) - floor(goblin.luck/5);
                if (attack==1){
                    turn = false;
                    srand(time(NULL));
                    if (hit>=20){
                        damage = 2*damage;
                        goblin.hp = goblin.hp - damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit>floor(10-character.dex/5)){
                        goblin.hp = goblin.hp - damage;
                        cout << "You cut him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if (attack==2){
                    turn = false;
                    if (hit>=20){
                        damage = 3*damage;
                        goblin.hp = goblin.hp - damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit>floor(15-character.dex/5)){
                        damage = ceil(1.5*damage);
                        goblin.hp = goblin.hp - damage;
                        cout << "Your arrow pierced him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if (attack==3){
                    cout << "You ran away" << endl;
                    character.hp = 10 + 2*character.vit;
                    break;
                }
            }
            else{
                cout << "It is the goblin's turn" << endl;
                system("sleep 1");
                system("clear");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = goblin.atk - character.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 + 1 + floor(goblin.luck/5) - floor(character.luck/5);
                if (attack==1){
                    turn = true;
                    if (hit>=20){
                        damage = 2*damage;
                        character.hp = character.hp - damage;
                        cout << "Ouch, he dealt you a serious slash" << endl;
                    }
                    else if(hit>ceil(10-goblin.dex/5)){
                        character.hp = character.hp - damage;
                        cout << "He cut you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the goblin hurt itself" << endl;
                        goblin.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                else if (attack==2){
                    turn = true;
                    if (hit>=20){
                        damage = 3*damage;
                        character.hp = character.hp - damage;
                        cout << "Ouch, he dealt you a serious concussion" << endl;
                    }
                    else if(hit>ceil(15-goblin.dex/5)){
                        character.hp = character.hp - floor(1.5*damage);
                        cout << "He threw a stone on you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the goblin hurt itself" << endl;
                        goblin.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << character.name <<"'s hp: " << character.hp << endl;
            cout << "Goblin's hp: " << goblin.hp << endl;
            system("sleep 2");
            system("clear");
        }
        if (goblin.hp<=0){
            cout << "Congratulations, you just defeated the goblin" << endl;
            srand(time(NULL));
            chance = rand() % 20 + floor(character.luck/5);
            if (chance > 10){
                qtd = (rand() % 10 + 1) * (rand() % 5 + 1) + character.luck*(rand() % 5);
                cout << "It's your lucky day, you found " << qtd << " coins with the goblin" << endl;
                character.money = character.money + qtd;
            }
            character.xp = character.xp+goblin.xp;
        }
        else if (character.hp<=0){
            cout << "Oh, the goblin was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("sleep 2");
    }
    else if (being ==3){
        cout << "You find a chitine" << endl;
        system("sleep 1");
        creature chitine = create_chitine();
        if (character.dex>chitine.dex){
            turn = true;
        }
        while ((chitine.hp>0)&&(character.hp>0)){
            if(turn){
                system("clear");
                battle_menu();
                damage = character.atk - chitine.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                system("clear");
                srand(time(NULL));
                hit = rand() % 20 + 1 + floor(character.luck/5);
                if (attack==1){
                    turn = false;
                    srand(time(NULL));
                    if (hit>=20){
                        damage = 2*damage;
                        chitine.hp = chitine.hp - damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit>floor(10-character.dex/5)){
                        chitine.hp = chitine.hp - damage;
                        cout << "You cut him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if (attack==2){
                    turn = false;
                    hit = rand() % 20 +1;
                    if (hit>=20){
                        damage = 3*damage;
                        chitine.hp = chitine.hp - damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit>floor(15-character.dex/5)){
                        damage = ceil(1.5*damage);
                        chitine.hp = chitine.hp - damage;
                        cout << "Your arrow pierced him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if (attack==3){
                    cout << "You ran away" << endl;
                    character.hp = 10 + 2*character.vit;
                    break;
                }
            }
            else{
                cout << "It is the chitine's turn" << endl;
                system("sleep 1");
                system("clear");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = chitine.atk - character.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                srand(time(NULL));
                if (attack==1){
                    hit = rand() % 20 +1;
                    turn = true;
                    if (hit>=20){
                        damage = 2*damage;
                        character.hp = character.hp - damage;
                        cout << "Ouch, he dealt you a serious slash" << endl;
                    }
                    else if(hit>ceil(10-chitine.dex/5)){
                        character.hp = character.hp - damage;
                        cout << "He cut you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the chitine hurt itself" << endl;
                        chitine.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                else if (attack==2){
                    turn = true;
                    for (i=0; i<2; i++){
                        hit = rand() % 20 +1;
                        if (hit>=20){
                            damage = 2*damage;
                            character.hp = character.hp - damage;
                            cout << "Ouch, it dealt you a serious slash" << endl;
                        }
                        else if(hit>ceil(15-chitine.dex/5)){
                            character.hp = character.hp - damage;
                            cout << "It cut you" << endl;
                        }
                        else if(hit==1){
                            cout << "How clumsy, the chitine hurt itself" << endl;
                            chitine.hp--;
                        }
                        else{
                            cout << "Hooray, you dodged the attack" << endl;
                        }
                    }
                }
            }
            cout << character.name <<"'s hp: " << character.hp << endl;
            cout << "Chitine's hp: " << chitine.hp << endl;
            system("sleep 2");
            system("clear");
        }
        if (chitine.hp<=0){
            cout << "Congratulations, you just defeated the chitine" << endl;
            srand(time(NULL));
            qtd = 1 + character.luck/5;
            i = rand() % 5 + 1;
            if (i==1){
                aux = "strength";
                character.atk = character.atk + qtd;
            }
            else if (i==2){
                aux = "constitution";
                character.vit = character.vit + qtd;
            }
            else if (i==3){
                aux = "defense";
                character.def = character.def + qtd;
            }
            else if (i==4){
                aux = "luck";
                character.luck = character.luck + qtd;
            }
            else{
                aux = "vitality";
                character.vit = character.vit + qtd;
            }
            cout << "Thanks to this fight with a tough foe, your " << aux << " became higher" << endl;
            character.xp = character.xp+chitine.xp;
        }
        else if (character.hp<=0){
            cout << "Oh, the chitine was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("sleep 2");

    }
    if (character.xp >= (character.lvl*10+pow(5,character.lvl))*10){
        character.lvl++;
        character.upgrades = character.upgrades + 10;
        system("clear");
        cout << "Congrats, " << character.name << " upgraded its level to " << character.lvl << endl;
        system("sleep 2");
    }
    return character;
}

void inventory(personagem character){
    int aux, i = 0;
    system("clear");
    cout << "Inventory Menu" << endl;
    cout << "1 - See Battle Items" << endl;
    cout << "2 - See Other Items" << endl;
    cout << "3 - Go back to previous Menu" << endl;
    cin >> aux;
    system("clear");
    if (aux == 1){
        if (character.weapons[0].equiped){
            cout << "Your strong weapon is " << character.weapons[0].name << " which gives + " << character.weapons[0].bonus << " in the attacks" << endl;
        }
        else{
            cout << "You have no equiped strong weapon" << endl;
        }
        if (character.weapons[1].equiped){
            cout << "Your weak weapon is " << character.weapons[1].name << " which gives + " << character.weapons[1].bonus << " in the attacks" << endl;
        }
        else{
            cout << "You have no equiped weak weapon" << endl;
        }
        if (character.armors[0].equiped){
            cout << "You are wearing the " << character.armors[0].name << "which gives + " << character.armors[0].bonus << " in the defense" << endl;
        }
        else{
            cout << "You have no equiped armor" << endl;
        }
        system("sleep 5");
    }
    else if (aux==2){
        for (aux=0;aux<50;aux++){
            if (character.items[aux].amount > 0){
                cout << "You have " << character.items[aux].amount << " units of " << character.items[aux].name << endl;
                i++;
            }
        }
        if (i==0){
            cout << "You have no other items. Battle to find items" << endl;
            system("sleep 2");
        }
        else system("sleep 5");
    }
}

personagem store(personagem character){
    system("clear");
    int i, id, qtd, aux1 = 0; int aux2 = 0; int aux3 = 0;
    char opt;
    cout << "Seja bem-vinde a loja" << endl;
    cout << "1 - Vender Itens" << endl;
    cout << "2 - Comprar Itens" << endl;
    cout << "3 - Voltar ao Menu Principal" <<endl;
    cin >> opt;
    system("clear");
    if(opt == '1'){
        for (int k=0;k<10;k++){
            if ((character.weapons[k].amount>0)&&(character.weapons[k].equiped = false)){
                aux1++;
            }
        }
        for (int k=0;k<5;k++){
            if ((character.armors[k].amount>0)&&(character.armors[k].equiped = false)){
                aux2++;
            }
        }
        for (int k=0;k<50;k++){
            if (character.items[k].amount>0){
                aux3++;
            }
        }
        cout << "Deseja vender itens[I] ou armas[W] ou armaduras[A]?" << endl;
        cin >> opt;
        system("clear");
        if ((opt == 'I')||(opt == 'i')){
            if (aux3 == 0){
                cout << "You have now items yet. Battle to acquire some more" << endl;
                system("sleep 2");
                return character;
            }
            while(aux3 > 0){  
                aux3 = 0;
                system("clear");
                cout << "Id |  Iten's name  |  Iten's price  |  Owned" << endl;
                for (i=0;i<50;i++){
                /*if (character.items[i].amount>0){
                    cout << character.items[i].name << ": " << character.items[i].price << endl;
                    cout << "Voce deseja vender todos[T], alguns[A] ou nenhum[N]?" << endl;
                    opt = getchar();
                    system("clear");
                    if ((opt == 't')||(opt == 'T')){
                        character.items[i].amount = 0;
                        character.money = character.money + character.items[i].price*character.items[i].amount;
                    }
                    else if ((opt == 65)||(opt == 97)){
                        cout << "Quantos?" << endl;
                        opt = getchar();
                        while (opt>character.items[i].amount){
                            system("clear");
                            cout << "Por favor, insira um valor válido" << endl;
                            opt = getchar();
                        }
                        character.items[i].amount = character.items[i].amount - opt;
                        character.money = character.money + character.items[i].amount*character.items[i].price;
                    }
                    system("clear");
                }
*/
                    if(character.items[i].amount>0){
                        cout << i << "  |  " << character.items[i].name << "  |  " << character.items[i].price << "  |  " << character.items[i].amount << endl;
                        aux3++;
                    }
                }
                if (aux3 == 0){
                    system("clear");
                    cout << "It seems you have run out of sellable merchandise, but don't worry, you can acquire others by battling" << endl;
                    system("sleep 2");
                    return character;
                }
                cout << endl;
                cout << "Which item would you like to sell? Please insert the respective Id. If you wanna quit, insert the number 200" << endl;
                cin >> id;
                if (id == 200){
                    cout << "Okay dokay, see ya" << endl;
                    system("sleep 2");
                    return character;
                } 
                if (character.items[id].amount>1){
                    cout << "How many you wanna sell?" << endl;
                    cin >> qtd;
                    if (qtd>character.items[id].amount||qtd<0){
                        cout << "Well, if you are gonna lie, our business for now is done" << endl;
                        break;
                    }
                    else if(qtd == 0){
                        cout << "Oh, I see. You've changed your mind. It happens..." << endl; 
                    }
                    else{
                        character.money = character.money + qtd*character.items[id].price;
                        character.items[id].amount = character.items[id].amount - qtd;
                    }   
                }
                else if(character.items[id].amount == 1){
                    cout << "Alright, here's you money" << endl;
                    cout << "You got " << character.items[id].price << endl;
                    character.money = character.money + character.items[id].price;
                    character.items[id].amount = character.items[id].amount - 1;
                    system("sleep 2");
                }
            }
        }
        else if((opt == 'w')||(opt == 'W')){
            for (i=0;i<10;i++){
                if ((!character.weapons[i].equiped)&&(character.weapons[i].owned)){
                    cout << "Voce nao esta usando " << character.weapons[i].name << endl;
                    cout << "Nos podemos lhe pagar " << ceil(character.weapons[i].price*0.9) << endl;
                    cout << "Deseja vender[S/N]?" << endl;
                    opt = getchar();
                    if ((opt == 83)||(opt == 115)){
                        character.money = character.money + ceil(character.weapons[i].price*0.9);
                        character.weapons[i].amount = 0;
                    }
                    system("clear");
                }
            }
        }
        else if((opt == 'a')||(opt == 'A')){
            for (i=0;i<10;i++){
                if ((!character.armors[i].equiped)&&(character.armors[i].owned)){
                    cout << "Voce nao esta usando " << character.armors[i].name << endl;
                    cout << "Nos podemos lhe pagar " << ceil(character.armors[i].price*0.9) << endl;
                    cout << "Deseja vender[S/N]?" << endl;
                    opt = getchar();
                    if ((opt == 83)||(opt == 115)){
                        character.money = character.money + ceil(character.armors[i].price*0.9);
                        character.armors[i].amount = 0;
                    }
                    system("clear");
                }
            }
        }
    }
    else if(opt == '2'){
        cout << "Estamos com o estoque esgotado. Volte novamente mais tarde" << endl;
    }
    /*
    else if(opt == '2'){
        cout << "We have several options ready for you" << endl;
        cout << "Would you like to see armours[A] or weapons[W]?" << endl;
        cin >> opt;
    }
    */
    else if(opt == 3){
        return character;
    }
    system("sleep 2");
    return character;
}

personagem heal(personagem character, bool went){
    char aux;
    int opt, menor, chance;
    system("clear");
    if (character.hp < 10 + 2*character.vit){
        cout << character.name << "'s hp: " << character.hp << "/" << 10+2*character.vit << endl;
        cout << endl;
        cout << "It seems that you are hurt" << endl;
        cout << "We have the best and confiest bedroom over the region" << endl;
        cout << "Do you wish to rest for a bit in the Sweet Dreams Inn? [Y/N]" << endl;
        cin >> aux;
        if (aux=='Y'||aux=='y'){
            system("clear");
            cout << character.name << "'s hp: " << character.hp << "/" << 10 + 2 * character.vit << endl;
            cout << endl;
            cout << "Money: " << character.money;
            cout << endl;
            cout << "We have 3 options of services" << endl;
            cout << "1 - Standard: costs 5 coins and heals 25% of life" << endl;
            cout << "2 - Advanced: costs 9 coins and heals 50% of life" << endl;
            cout << "3 - Complete: costs 17 coins and heals 100% of life" << endl;
            cout << "4 - Never mind. I've changed my mind" << endl;
            cin >> opt;
            if(went) chance = 0;
            else{
                srand(time(NULL));
                chance = rand() % (20) + 1 + character.luck;
            }
            if(opt == 1){
                system("clear");
                if(chance>19){
                    cout << "You know what? Take a free trial. No fees for ya" << endl;
                    for(int time = 0; time < menor; time++){
                        system("clear");
                        character.hp++;
                        cout << character.name << "'s hp: " << character.hp << "/" << 10 + 2 * character.vit << endl;
                        cout << "Resting" << endl;
                        system("sleep 0.05");
                    }
                    cout << "After a rest in a bed you feel a bit better" << endl;
                }
                else{
                    if(character.money >= 5){
                        if (character.hp + ceil(0.25 * (10 + 2 * character.vit)) > 10 + 2 * character.vit){
                            menor = 10 + 2 * character.vit - character.hp;
                        }
                        else menor = ceil(0.25 * (10 + 2 * character.vit));
                        for(int time = 0; time < menor; time++){
                            system("clear");
                            character.hp++;
                            cout << character.name << "'s hp: " << character.hp << "/" << 10 + 2 * character.vit << endl;
                            cout << "Resting" << endl;
                            system("sleep 0.05");
                        }
                        cout << "After a rest in a bed you feel a bit better" << endl;
                        character.money = character.money - 5;
                    }
                    else cout << "You don't have enough money. Sorry, we can do nothing for you" << endl;
                    system("sleep 2");
                }
            }
            else if(opt == 2){
                if(chance>19){
                    cout << "You know what? Take a free trial. No fees for ya" << endl;
                    for(int time = 0; time < menor; time++){
                        system("clear");
                        character.hp++;
                        cout << character.name << "'s hp: " << character.hp << "/" << menor << endl;
                        cout << "Resting" << endl;
                        system("sleep 0.05");
                    }
                    cout << "After a rest in a bed you feel a bit better" << endl;
                }
                else{
                    if(character.money >= 9){
                        if (character.hp + ceil(0.5 * (10 + 2 * character.vit)) > 10 + 2 * character.vit){
                            menor = 10 + 2 * character.vit - character.hp;
                        }
                        else menor = ceil(0.5 * (10 + 2 * character.vit));
                        for(int time = 0; time < menor; time++){
                            system("clear");
                            character.hp++;
                            cout << character.name << "'s hp: " << character.hp << "/" << 10 + 2 * character.vit << endl;
                            cout << "Resting" << endl;
                            system("sleep 0.05");
                        }
                        cout << "After a rest in a confy bed you feel better" << endl;
                        character.money = character.money - 9;
                        character.hp = character.hp + ceil(0.5*(10 + 2*character.vit));
                    }
                }
            }
            else if(opt == 3){
                if(chance>19){
                    cout << "You know what? Take a free trial. No fees for ya" << endl;
                    for(int time = 0; time < (10+2*character.vit); time++){
                        system("clear");
                        character.hp++;
                        cout << character.name << "'s hp: " << character.hp << "/" << 10 + 2 * character.vit << endl;
                        cout << "Resting" << endl;
                        system("sleep 0.05");
                    }
                    cout << "After a rest in a bed you feel a bit better" << endl;
                }
                else{
                    if(character.money >= 17){
                        menor = 10 + 2 * character.vit - character.hp;
                        for(int time = 0; time < menor; time++){
                            system("clear");
                            character.hp++;
                            cout << character.name << "'s hp: " << character.hp << "/" << 10 + 2 * character.vit << endl;
                            cout << "Resting" << endl;
                            system("sleep 0.05");
                        }
                        cout << "After a rest in a superbly confy bed you feel revigorated" << endl;
                        character.money = character.money - 9;
                        character.hp = 10 + 2*character.vit;
                    }
                    else cout << "You don't have enough money. Sorry, we can do nothing for you" << endl;
                    system("sleep 2");
                }
            }
            else if(opt == 4){
                system("clear");
                cout << "Okay, good luck out there" << endl;
            }
        }
        else{
            cout << "Okay, good luck out there" << endl;
        }
    }
    else{
        cout << "Oh, your health is perfect!! Came back when you have injuries" << endl;
    }
    system("sleep 2");
    system("clear");
    return character;
}