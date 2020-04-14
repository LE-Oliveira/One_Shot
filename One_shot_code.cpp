#include <cstdlib>
#include <iostream>
#include <string>
//#include "classes.cpp"
//#include "funcoes.cpp"
#include <time.h>
#include <math.h>

using namespace std;

class item{
    public:
        string name;
        int price, amount = 0;
};

class battle_item{
    public:
        string name;
        int bonus, price;
        bool equiped;
};

class personagem{
    public:
        int def, atk, dex, luck, vit, lvl, upgrades, xp, hp, money;
        battle_item sweapon, wweapon, armor;
        item items[50];
        char name[20];
};

class creature{
    public:
        int hp, atk, xp, dex, def;
};

personagem up_stat(personagem character){
    system("cls");
    int aux;
    string answer;
    cout << "Points Menu" <<endl;
    cout << "1 - See profile" << endl;
    cout << "2 - Upgrade stats" << endl;
    cout << "3 - Reset stats" << endl;
    cout << "4 - See experience" << endl;
    cout << "5 - Return to previous menu" << endl;
    cin >> aux;
    if (aux==1){
        system("cls");
        cout << "Level: " << character.lvl << endl;
        cout << "Name: " << character.name << endl;
        cout << "Money: " << character.money << endl;
        cout << "Constitution: " << character.def << endl;
        cout << "Strength: " << character.atk << endl;
        cout << "Dexterity: " << character.dex << endl;
        cout << "Luck: " << character.luck << endl;
        cout << "Vitality: " << character.vit << endl;

        system("pause");
    }
    else if (aux==2){
        if (character.upgrades>0){
            while (character.upgrades>0){
                system("cls");
                cout << "You still have " << character.upgrades << " available" << endl;
                cout << "Please distribute them" << endl;
                cout << "1 - Constitution: " << character.def << endl;
                cout << "2 - Strength: " << character.atk << endl;
                cout << "3 - Dexterity: " << character.dex << endl;
                cout << "4 - Luck: " << character.luck << endl;
                cout << "5 - Vitality: " << character.vit << endl;
                cin >> aux;
                switch (aux){
                    case 1:
                        character.def++;
                        character.upgrades--;
                    break;
                    case 2:
                        character.atk++;
                        character.upgrades--;
                    break;
                    case 3:
                        character.dex++;
                        character.upgrades--;
                    break;
                    case 4:
                        character.luck++;
                        character.upgrades--;
                    break;
                    case 5:
                        character.vit++;
                        character.hp = character.hp +2;
                        character.upgrades--;
                    break;
                }
            }
        }
        else{
            system("cls");
            cout << "You don't have any remaining points" << endl;
            system("pause");
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
                character.money = character.money - 100;
                system("cls");
                cout << "All stats were reset" <<endl;
                system("pause");
            }
            else{
                system("cls");
                cout << "You don't have enough money. Defeat more enemies to get more money" << endl;
            }
        }
    }
    else if (aux==4){
        system("cls");
        cout << "You have " << character.xp << " experience points" << endl;
        cout << "For the next lvl you need " << (character.lvl*10+pow(5,character.lvl))*10 << " experience points" << endl;
        system("pause");
    }
    return character;
}

personagem battle(personagem character){
    system("cls");
    bool turn = false;
    int being, attack, damage, hit, qtd, i;
    string aux;
    srand(time(NULL));
    being = rand() % (character.lvl + 1) + 1;
    if (being==1){
        cout << "You find a wolf" << endl;
        system("pause");
        creature wolf;
        wolf.hp=7;
        wolf.atk=4;
        wolf.xp=50;
        wolf.dex=5;
        wolf.def=2;
        if (character.dex>wolf.dex){
            turn = true;
        }
        while ((wolf.hp>0)&&(character.hp>0)){
            if(turn){
                system("cls");
                cout << "It is your turn" << endl;
                cout << "What you want to do?" <<endl;
                cout << "1 - Hit him with a knife" << endl;
                cout << "2 - Throw an arrow on him" << endl;
                cout << "3 - Run away" << endl;
                damage = character.atk - wolf.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                system("cls");
                hit = rand() % 20 +1;
                if (attack==1){
                    turn = false;
                    srand(time(NULL));
                    if ((hit+character.wweapon.bonus/5)>=20){
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
                    hit = rand() % 20 +1;
                    if (hit==20){
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
                    character.hp = 10 + 2*character.vit;
                    break;
                }
            }
            else{
                cout << "It is the wolf's turn" << endl;
                system("pause");
                system("cls");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = wolf.atk - character.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 +1;
                if (attack==1){
                    turn = true;
                    if (hit==20){
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
                    if (hit==20){
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
            system("pause");
            system("cls");
        }
        if (wolf.hp<=0){
            cout << "Congratulations, you just defeated a wolf" << endl;
            srand(time(NULL));
            if ((rand() % 5 + ceil(1+character.luck/10) >= 5)){
                srand(time(NULL));
                qtd = rand() % 4 + ceil(1 + character.luck/10);
                cout << "It's your lucky day, you found " << qtd << " Wolf's Claws" << endl;
                cout << "You sold them to the store and got " << 50*qtd << " coins" << endl;
                character.money = character.money + 50*qtd;
            }
            if ((rand() % 10 + ceil(1+character.luck/10)) >= 10){
                srand(time(NULL));
                qtd = rand() % 10 + ceil(1 + character.luck/10);
                cout << "It's your lucky day, you found " << qtd << " packs of Wolf's fur" << endl;
                cout << "You sold them to the store and got " << 10*qtd << " coins"<< endl;
                character.money = character.money + 10*qtd;
            }
            character.xp = character.xp+wolf.xp;
        }
        else if (character.hp<=0){
            cout << "Oh, the wolf was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("pause");
    }
    else if (being==2){
        cout << "You find a goblin" << endl;
        system("pause");
        creature goblin;
        goblin.hp=5;
        goblin.atk=3;
        goblin.xp=25;
        goblin.dex=2;
        goblin.def=0;
        if (character.dex>goblin.dex){
            turn = true;
        }
        while ((goblin.hp>0)&&(character.hp>0)){
            if(turn){
                system("cls");
                cout << "It is your turn" << endl;
                cout << "What you want to do?" <<endl;
                cout << "1 - Hit him with a knife" << endl;
                cout << "2 - Throw an arrow on him" << endl;
                cout << "3 - Run away" << endl;
                damage = character.atk - goblin.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                system("cls");
                hit = rand() % 20 +1;
                if (attack==1){
                    turn = false;
                    srand(time(NULL));
                    if (hit==20){
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
                    hit = rand() % 20 +1;
                    if (hit==20){
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
                system("pause");
                system("cls");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = goblin.atk - character.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 +1;
                if (attack==1){
                    turn = true;
                    if (hit==20){
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
                    if (hit==20){
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
            system("pause");
            system("cls");
        }
        if (goblin.hp<=0){
            cout << "Congratulations, you just defeated the goblin" << endl;
            srand(time(NULL));
            qtd = (rand() % 10 + 1)*10 + character.luck*(rand() % 5);
            cout << "It's your lucky day, you found " << qtd << " coins with the goblin" << endl;
            character.xp = character.xp+goblin.xp;
            character.money = character.money + qtd;
        }
        else if (character.hp<=0){
            cout << "Oh, the goblin was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("pause");
    }
    else if (being ==3){
        cout << "You find a chitine" << endl;
        system("pause");
        creature chitine;
        chitine.hp=15;
        chitine.atk=4;
        chitine.xp=150;
        chitine.dex=3;
        chitine.def=1;
        if (character.dex>chitine.dex){
            turn = true;
        }
         while ((chitine.hp>0)&&(character.hp>0)){
            if(turn){
                system("cls");
                cout << "It is your turn" << endl;
                cout << "What you want to do?" <<endl;
                cout << "1 - Hit him with a knife" << endl;
                cout << "2 - Throw an arrow on him" << endl;
                cout << "3 - Run away" << endl;
                damage = character.atk - chitine.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                system("cls");
                hit = rand() % 20 +1;
                if (attack==1){
                    turn = false;
                    srand(time(NULL));
                    if (hit==20){
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
                    if (hit==20){
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
                system("pause");
                system("cls");
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
                    if (hit==20){
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
                        if (hit==20){
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
            system("pause");
            system("cls");
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
            character.money = character.money + qtd;
        }
        else if (character.hp<=0){
            cout << "Oh, the chitine was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }

        system("pause");

    }
    character.hp = 10 + 2*character.vit;
    if (character.xp >= (character.lvl*10+pow(5,character.lvl))*10){
        character.lvl++;
        character.upgrades = character.upgrades + 10;
        system("cls");
        cout << "Congrats, " << character.name << " upgraded its level to " << character.lvl << endl;
        system ("pause");
    }
    return character;
}

personagem inventory(personagem character){
    int aux;
    system("cls");
    cout << "Inventory Menu" << endl;
    cout << "1 - See Battle Items" << endl;
    cout << "2 - See Other Items" << endl;
    cout << "3 - Go back to previous Menu" << endl;
    system("pause");
    cin >> aux;
    if (aux == 1){
        if (character.sweapon.equiped){
            cout << "Your strong weapon is " << character.sweapon.name << " which gives + " << character.sweapon.bonus << " in the attacks" << endl;
        }
        else{
            cout << "You have no equiped strong weapon" << endl;
        }
        if (character.wweapon.equiped){
            cout << "Your weak weapon is " << character.wweapon.name << " which gives + " << character.wweapon.bonus << " in the attacks" << endl;
        }
        else{
            cout << "You have no equiped weak weapon" << endl;
        }
        if (character.armor.equiped){
            cout << "You are wearing the " << character.armor.name << "which gives + " << character.armor.bonus << " in the defense" << endl;
        }
        else{
            cout << "You have no equiped armor" << endl;
        }
        
    }
    else if (aux==2){
        for (aux=0;aux<50;aux++){
            if (character.item[i].amount > 0){
                cout << "You have " << character.item[i].amount << " units of " << character.item[i].name << endl;
            }
        }
    }
    return character;
}

personagem store(personagem character){

    return character;
}

int main(){
    int aux, aux1;
    personagem perso;
    item basic_dagger, basic_bow;
    perso.sweapon.name = "Short Bow";
    perso.wweapon.name = "Iron Dagger";
    perso.sweapon.price = 2500;
    perso.wweapon.price = 200;
    perso.sweapon.bonus = 0;
    perso.wweapon.bonus = 0;
    perso.money = 0;
    perso.upgrades = 10;
    perso.xp = 0;
    perso.atk = 1;
    perso.def = 1;
    perso.dex = 1;
    perso.luck = 1;
    perso.vit = 1;
    perso.lvl = 1;
    perso.hp = 10 + 2*perso.vit;
    cout << "Welcome to this chaotic world, where villages are wiped out by monsters and heroes are lacking" << endl;
    system("pause");
    system("cls");
    cout << "You'll start your adventure at Brengash Village" << endl;
    system("pause");
    system("cls");
    cout << "Will you be able to change this world's destiny and defeat the Abysmal Lord?" << endl;
    system("pause");
    system("cls");
    cout << "Before we start, what should your character be known as?" << endl;
    cin >> perso.name;
    system("cls");
    cout << "Now that you gave your character a name, you need to build him up" << endl;
    system("pause");
    while (perso.upgrades>0){
        system("cls");
        cout << "You still have " << perso.upgrades << " available" << endl;
        cout << "Please distribute them" << endl;
        cout << "1 - Constitution: " << perso.def << endl;
        cout << "2 - Strength: " << perso.atk << endl;
        cout << "3 - Dexterity: " << perso.dex << endl;
        cout << "4 - Luck: " << perso.luck << endl;
        cout << "5 - Vitality: " << perso.vit << endl;
        cin >> aux;
        switch (aux){
            case 1:
                perso.def++;
                perso.upgrades--;
            break;
            case 2:
                perso.atk++;
                perso.upgrades--;
            break;
            case 3:
                perso.dex++;
                perso.upgrades--;
            break;
            case 4:
                perso.luck++;
                perso.upgrades--;
            break;
            case 5:
                perso.vit++;
                perso.hp = perso.hp +2;
                perso.upgrades--;
            break;
        }
    }
    system("cls");
    cout << "Name: " << perso.name << endl;
    cout << "Constitution: " << perso.def << endl;
    cout << "Strength: " << perso.atk << endl;
    cout << "Dexterity: " << perso.dex << endl;
    cout << "Luck: " << perso.luck << endl;
    cout << "Vitality: " << perso.vit << endl;
    system("pause");
    aux1 = 0;
    while (aux1==0){
        system("cls");
        cout << "Menu" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1 - Battle" << endl;
        cout << "2 - See points" << endl;
        if  ( perso.lvl==1){
            cout << "3 - Escape the game" << endl;
        }
        else if (perso.lvl==2){
            cout << "3 - Access inventory" << endl;
            cout << "4 - Escape the game" << endl;
        }
        else if (perso.lvl>2){
            cout << "3 - Access inventory" << endl;
            cout << "4 - Go to the store" << endl;
            cout << "5 - Escape the game" << endl;
        }
        cin >> aux;
        if (aux==1){
            perso = battle(perso);
        }
        else if (aux==2){
            perso = up_stat(perso);
        }
        else if ((aux==3)&&(perso.lvl==1)){
            system("cls");
            cout << "Have a nice day";
            break;
        }
        else if ((aux==3)&&(perso.lvl>1)){
            system("cls");
            cout << "Sorry, this is still in development" << endl;
            system("pause");
        }
        else if ((aux==4)&&(perso.lvl==2)){
            system("cls");
            cout << "Have a nice day";
            break;
        }
        else if ((aux==4)&&(perso.lvl>2)){
            system("cls");
            cout << "Sorry, this is still in development" << endl;
            system("pause");
        }
        else if ((aux==5)&&(perso.lvl>2)){
            system("cls");
            cout << "Have a nice day";
            break;
        }
    }
    return 0;
}
