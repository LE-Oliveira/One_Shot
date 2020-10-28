#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    int aux;
    string opt;
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
    cout << "Welcome to this chaotic world, where villages are wiped out by monsters and heroes are lacking" << endl;
    getchar();
    system("clear");
    cout << "You'll start your adventure at Brengash Village" << endl;
    getchar();
    system("clear");
    cout << "Will you be able to change this world's destiny and defeat the Abysmal Lord?" << endl;
    system("sleep 2");
    system("clear");
    cout << "Before we start, what should your character be known as?" << endl;
    scanf("%s", perso.name);
    system("clear");
    cout << "Now that you gave your character a name, you need to build it up" << endl;
    getchar();
    while (perso.upgrades>0){
        system("clear");
        cout << "You still have " << perso.upgrades << " available" << endl;
        cout << "Please distribute them" << endl;
        cout << "1 - Constitution: " << perso.def << endl;
        cout << "2 - Strength: " << perso.atk << endl;
        cout << "3 - Dexterity: " << perso.dex << endl;
        cout << "4 - Luck: " << perso.luck << endl;
        cout << "5 - Vitality: " << perso.vit << endl;
        opt = getchar();
        if(opt == '1'){
            perso.def++;
            perso.upgrades--;
        }
        else if(opt == '2'){
            perso.atk++;
            perso.upgrades--;
        }
        else if(opt == '3'){
            perso.dex++;
            perso.upgrades--;
        }
        else if(opt == '4'){
            perso.luck++;
            perso.upgrades--;
        }
        else if(opt == '5'){
            perso.vit++;
            perso.upgrades--;
        }
        else{
            cout << "Valor inválido" << endl;
            system("sleep 2");
        }
    }
    perso.hp = 10 + 2*perso.vit;
    system("clear");
    cout << "Name: " << perso.name << endl;
    cout << "Constitution: " << perso.def << endl;
    cout << "Strength: " << perso.atk << endl;
    cout << "Dexterity: " << perso.dex << endl;
    cout << "Luck: " << perso.luck << endl;
    cout << "Vitality: " << perso.vit << endl;
    getchar();
    while((aux>0)&&(aux<5)){
        system("clear");
        cout << "Menu" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1 - Battle" << endl;
        cout << "2 - See points" << endl;
        if(perso.lvl==1){
            cout << "3 - Escape the game" << endl;
        }
        else if(perso.lvl==2){
            cout << "3 - Access inventory" << endl;
            cout << "4 - Escape the game" << endl;
        }
        else if(perso.lvl>2){
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
            system("clear");
            cout << "Have a nice day";
            break;
        }
        else if ((aux==3)&&(perso.lvl>1)){
            system("clear");
            inventory(perso);
            getchar();
        }
        else if ((aux==4)&&(perso.lvl==2)){
            system("clear");
            cout << "Have a nice day";
            break;
        }
        else if ((aux==4)&&(perso.lvl>2)){
            system("clear");
            perso = store(perso);
            getchar();
        }
        else if ((aux==5)&&(perso.lvl>2)){
            system("clear");
            cout << "Have a nice day";
            break;
        }
    }
    return 0;
}
