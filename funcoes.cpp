#include <cstdlib>
#include <iostream>
#include <string>
//#include "classes.cpp"
#include <time.h>
#include <math.h>

using namespace std;

void up_stat(personagem perso){
    int points = perso.upgrades, aux;
    while (points>0){
        cout << "You still have " << points << "available" << endl;
        cout << "Please distribute them (use the first 3 letters to select'em)" << endl;
        cout << "1 - Defense: " << perso.def << endl;
        cout << "2 - Attack: " << perso.atk << endl;
        cout << "3 - Dexterity: " << perso.dex << endl;
        cout << "4 - Luck: " << perso.luck << endl;
        cout << "5 - Vitality: " << perso.vit << endl;
        cin >> aux;
        switch (aux){
            case 1:
                perso.def++;
                points--;
            break;
            case 2:
                perso.atk++;
                points--;
            break;
            case 3:
                perso.dex++;
                points--;
            break;
            case 4:
                perso.luck++;
                points--;
            break;
            case 5:
                perso.vit++;
                points--;
            break;
        }
    }
}

int menu(personagem perso){
    int aux;
    cout << "Menu";
    cout << "What do you want to do?";
    cout << "1 - Battle";
    cout << "2 - See points";
    cout << "3 - Escape the game";
    cin >> aux;
    if (aux==1){
        cout << "Not ready yet";
        //battle(perso);
        return 0;
    }
    if (aux==2){
        up_stat(perso);
        return 0;
    }
    else{
        return 1;
    }
}

int reset_points(personagem perso){
    int points = perso.lvl*10;
    return points;
};

int battle(personagem perso){
    bool turn = false;
    int being, attack, damage;
    srand(time(NULL));
    if (perso.lvl==1){
        being = rand() % 1;//2;
    }
    if (being==1){
        cout << "You find a wolf";
        creature wolf;
        wolf.hp=7;
        wolf.atk=4;
        wolf.xp=50;
        wolf.dex=5;
        wolf.def=2;
        while ((wolf.hp!=0)||(perso.hp!=0)){
            if (perso.dex>wolf.dex){
                turn = true;
            }
            if(turn){
                cout << "It is your turn" << endl;
                cout << "What you want to do?" <<endl;
                cout << "1 - Hit him with a knife" << endl;
                cout << "2 - Throw an arrow on him" << endl;
                cout << "3 - Run away" << endl;
                damage = perso.atk - wolf.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                if (attack==1){
                    if ((rand() % 20)==20){
                        wolf.hp = wolf.hp - 2*damage;
                    }
                    else if((rand() % 20)>10){
                        wolf.hp = wolf.hp - damage;
                    }
                    else if((rand() % 20)==1){
                        cout << "Auch, you hurt yourself" << endl;
                        perso.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                if (attack==2){
                    if ((rand() % 20)==20){
                        wolf.hp = wolf.hp - 3*damage;
                    }
                    else if((rand() % 20)>15){
                        wolf.hp = wolf.hp - ceil(1.5*damage);
                    }
                    else if((rand() % 20)==1){
                        cout << "Auch, you hurt yourself" << endl;
                        perso.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
            }
            else{
                cout << "It is the wolf's turn" << endl;
                attack = rand() % 2;
                damage = wolf.atk - perso.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                if (attack==1){
                    if ((rand() % 20)==20){
                        perso.hp = perso.hp - 2*damage;
                    }
                    else if((rand() % 20)>ceil(10-wolf.dex/5)){
                        perso.hp = perso.hp - damage;
                    }
                    else if((rand() % 20)==1){
                        cout << "How clumsy, the wolf hurt itself" << endl;
                        wolf.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                if (attack==2){
                    if ((rand() % 20)==20){
                        perso.hp = perso.hp - 3*damage;
                    }
                    else if((rand() % 20)>(ceil(15-wolf.dex/5))){
                        perso.hp = perso.hp - 1.5*damage;
                    }
                    else if((rand() % 20)==1){
                        cout << "How clumsy, the wolf hurt itself" << endl;
                        wolf.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << perso.name <<"'s hp: " << perso.hp << endl;
            cout << "Wolf's hp: " << wolf.hp << endl;
        }
        if (wolf.hp==0){
            cout << "Congratulations, you just defeated a wolf" << endl;
            perso.xp = perso.xp+wolf.xp;
        }
        else{
            cout << "Oh, the wolf was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
    }
    if (being==2){
        cout << "You find a goblin";
        creature goblin;
        goblin.hp=5;;
        goblin.atk=3;;
        goblin.xp=25;
        goblin.dex=2;
        goblin.def=0;
        while ((goblin.hp!=0)||(perso.hp!=0)){
            if (perso.dex>goblin.dex){
                turn = true;
            }
            if(turn){
                cout << "It is your turn" << endl;
                cout << "What you want to do?" <<endl;
                cout << "1 - Hit him with a knife" << endl;
                cout << "2 - Throw an arrow on him" << endl;
                cout << "3 - Run away" << endl;
                damage = perso.atk - goblin.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                cin >> attack;
                if (attack==1){
                    if ((rand() % 20)==20){
                        goblin.hp = goblin.hp - 2*damage;
                    }
                    else if((rand() % 20)>10){
                        goblin.hp = goblin.hp - damage;
                    }
                    else if((rand() % 20)==1){
                        cout << "Auch, you hurt yourself" << endl;
                        perso.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                if (attack==2){
                    if ((rand() % 20)==20){
                        goblin.hp = goblin.hp - 3*damage;
                    }
                    else if((rand() % 20)>15){
                        goblin.hp = goblin.hp - ceil(1.5*damage);
                    }
                    else if((rand() % 20)==1){
                        cout << "Auch, you hurt yourself" << endl;
                        perso.hp--;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
            }
            else{
                cout << "It is the goblin's turn" << endl;
                attack = rand() % 2;
                damage = goblin.atk - perso.def;
                if ((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if (damage<-9){
                    damage = 0;
                }
                if (attack==1){
                    if ((rand() % 20)==20){
                        perso.hp = perso.hp - 2*damage;
                    }
                    else if((rand() % 20)>ceil(10-goblin.dex/5)){
                        perso.hp = perso.hp - damage;
                    }
                    else if((rand() % 20)==1){
                        cout << "How clumsy, the goblin hurt itself" << endl;
                        goblin.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                if (attack==2){
                    if ((rand() % 20)==20){
                        perso.hp = perso.hp - 3*damage;
                    }
                    else if((rand() % 20)>(ceil(15-goblin.dex/5))){
                        perso.hp = perso.hp - 1.5*damage;
                    }
                    else if((rand() % 20)==1){
                        cout << "How clumsy, the goblin hurt itself" << endl;
                        goblin.hp--;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << perso.name <<"'s hp: " << perso.hp << endl;
            cout << "Wolf's hp: " << goblin.hp << endl;
        }
        if (goblin.hp==0){
            cout << "Congratulations, you just defeated a goblin" << endl;
            perso.xp = perso.xp+goblin.xp;
        }
        else{
            cout << "Oh, the goblin was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
    }
    return 0;
}

