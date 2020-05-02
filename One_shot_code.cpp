#include <cstdlib>
#include <iostream>
#include <string>
#include "classes.h"
#include "funcoes.h"
#include <time.h>
#include <math.h>

using namespace std;

int main(){
    int aux, aux1;
    personagem perso;
    item basic_dagger, basic_bow;
    perso.lvl = 3;
    perso.weapons[0].name = "Short Bow";
    perso.weapons[1].name = "Iron Dagger";
    perso.weapons[0].price = 2500;
    perso.weapons[1].price = 200;
    perso.weapons[0].bonus = 0;
    perso.weapons[1].bonus = 0;
    perso.weapons[0].equiped = true;
    perso.weapons[1].equiped = true;
    perso.money = 0;
    perso.upgrades = perso.lvl*10;
    perso.xp = 0;
    perso.atk = 1;
    perso.def = 1;
    perso.dex = 1;
    perso.luck = 1;
    perso.vit = 1;
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
    cout << "Now that you gave your character a name, you need to build it up" << endl;
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
            inventory(perso);
            system("pause");
        }
        else if ((aux==4)&&(perso.lvl==2)){
            system("cls");
            cout << "Have a nice day";
            break;
        }
        else if ((aux==4)&&(perso.lvl>2)){
            system("cls");
            perso = store(perso);
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
