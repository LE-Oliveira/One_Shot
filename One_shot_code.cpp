//#include "funcoes.h"
#include "funcoes.cpp"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    int aux = 1;
    bool went = true;
    char opt;
    personagem perso = inicia();
    item basic_dagger, basic_bow;
    cout << "Welcome to this chaotic world, where villages are wiped out by monsters and heroes are lacking" << endl;
    system("sleep 2");
    system("clear");
    cout << "You'll start your adventure at Brengash Village" << endl;
    system("sleep 2");
    system("clear");
    cout << "Will you be able to change this world's destiny and defeat the Abysmal Lord?" << endl;
    system("sleep 2");
    system("clear");
    cout << "Before we start, what should your character be known as?" << endl;
    scanf("%s", perso.name);
    system("clear");
    cout << "Now that you gave your character a name, you need to build it up" << endl;
    system("sleep 2");
    while (perso.upgrades>0){
        system("clear");
        cout << "You still have " << perso.upgrades << " available" << endl;
        cout << "Please distribute them" << endl;
        cout << "1 - Constitution: " << perso.def << endl;
        cout << "2 - Strength: " << perso.atk << endl;
        cout << "3 - Dexterity: " << perso.dex << endl;
        cout << "4 - Luck: " << perso.luck << endl;
        cout << "5 - Vitality: " << perso.vit << endl;
        scanf("%c", &opt);
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
    }
    perso.hp = 10 + 2*perso.vit;
    system("clear");
    cout << "Name: " << perso.name << endl;
    cout << "Constitution: " << perso.def << endl;
    cout << "Strength: " << perso.atk << endl;
    cout << "Dexterity: " << perso.dex << endl;
    cout << "Luck: " << perso.luck << endl;
    cout << "Vitality: " << perso.vit << endl;
    system("sleep 2");
    while((aux>0)&&(aux<7)){
        system("clear");
        cout << "Menu" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1 - Battle" << endl;
        cout << "2 - See points" << endl;
        cout << "3 - Rest and heal" << endl;
        cout << "4 - Access inventory" << endl;
        cout << "5 - Go to the store" << endl;
        cout << "6 - Escape the game" << endl;
        cin >> aux;
        if (aux==1){
            perso = battle(perso);
            went = false;
        }
        else if (aux==2){
            perso = upStat(perso);
        }
        else if (aux==3){
            perso = heal(perso, went);
            went = true;
        }
        else if (aux==4){
            inventory(perso);
        }
        else if (aux==5){
            perso = store(perso);
        }
        else if (aux==6){
            system("clear");
            cout << "Have a nice day\n";
            break;
        }
    }
    return 0;
}
