#include "character.hpp"
#include "func.hpp"

int main(){
    string name;
    bool went = true;
    int aux = 1;
    start();
    cin >> name;
    Beast wolf("wolf");
    Beast goblin("goblin");
    Beast chitine("chitine");
    Beast greatWolf("great wolf");
    Character character(name);
    character.setBeast(&wolf);
    character.setBeast(&goblin);
    character.setBeast(&chitine);
    character.setBeast(&greatWolf);
    system("clear");
    cout << "Now that you gave your character a name, you need to build it up" << endl;
    system("sleep 2");
    character.setStats("init");
    system("clear");
    character.showStats();
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
        fflush(stdin);
        cin >> aux;
        if(aux == 1){
            if(character.getHp() == 0){
                cout << "You have no remaining hp, rest&heal before fighting again" << endl;
                system("sleep 2");
            }
            else{
                character = battle(character);
                went = false;
            }
        }
        else if(aux == 2) character.upStat();
        else if(aux == 3){
            character.heal(went);
            went = true;
        }
        else if(aux == 4) character.inventory();
        else if(aux == 5) character.store();
        else break;
    }
    system("clear");
    cout << "Have a nice day" << endl;
    return 0;
}
