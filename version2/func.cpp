#include "func.hpp"
#include "character.hpp"
#include <time.h>
#include <math.h>

void start(){
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
}

void battleMenu(){
    cout << "It is your turn" << endl;
    cout << "What you want to do?" <<endl;
    cout << "1 - Attack him with a melee weapon" << endl;
    cout << "2 - Attack him with a ranged weapon" << endl;
    cout << "3 - Run away" << endl;
}

Character battle(Character character){
    system("clear");
    bool turn = false;
    int being, attack, damage, hit, qtd, i, chance;
    string aux;
    srand(time(NULL));
    being = rand() % (character.getLvl() + 1) + 1;
    if(being==1){
        cout << "You find a wolf" << endl;
        system("sleep 1");
        Beast wolf("wolf");
        if(character.getDex()>wolf.getDex()){
            turn = true;
        }
        while ((wolf.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("clear");
                battleMenu();
                fflush(stdin);
                cin >> attack;
                system("clear");
                hit = rand() % 20 + 1 + floor(character.getLuck()/5) - floor(wolf.getLuck()/5);
                damage = character.getAtk() - wolf.getDef();
                if((damage<1)&&(damage>-10)) damage = 1;
                else if(damage<-9) damage = 0;
                if(attack==1){
                    damage+=character.getMelee();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        wolf-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMelee()>floor(10-character.getDex()/5)){
                        wolf-damage;
                        cout << "You cut him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character-1;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if(attack==2){
                    turn = false;
                    damage+=character.getRanged();
                    if(hit>=20){
                        damage = 3*damage;
                        wolf-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRanged()>floor(15 - character.getDex()/5)){
                        damage = ceil(1.5*damage);
                        wolf-damage;
                        cout << "Your arrow pierced him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character-1;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if(attack==3){
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
                damage = wolf.getAtk() - character.getDef() - character.getArmor();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 + 1 + floor(wolf.getLuck()/5) - floor(character.getLuck()/5);
                if(attack==1){
                    turn = true;
                    if(hit>=20){
                        character-2*damage;
                        cout << "Ouch, he dealt you a serious scratch" << endl;
                    }
                    else if(hit>ceil(10-wolf.getDex()/5) - character.getArmor()){
                        character-damage;
                        cout << "He scratched you" << endl;
                    }
                    else if(hit+character.getArmor()==1){
                        cout << "How clumsy, the wolf hurt itself" << endl;
                        wolf-1;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                else if(attack==2){
                    turn = true;
                    if(hit>=20){
                        character-3*damage;
                        cout << "Ouch, he dealt you a serious bite" << endl;
                    }
                    else if(hit>ceil(15-wolf.getDex()/5) - character.getArmor()){
                        character-1.5*damage;
                        cout << "He bit you" << endl;
                    }
                    else if(hit+character.getArmor()==1){
                        cout << "How clumsy, the wolf hurt itself" << endl;
                        wolf-1;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << character.getName() <<"'s hp: " << character.getHp() << endl;
            cout << "Wolf's hp: " << wolf.getHp() << endl;
            system("sleep 1");
            system("clear");
        }
        if(wolf.getHp()<=0){
            cout << "Congratulations, you just defeated a wolf" << endl;
            srand(time(NULL));
            if((rand() % 5 + ceil(1+character.getLuck()/10) >= 5)){
                srand(time(NULL));
                qtd = rand() % 4 + ceil(1 + character.getLuck()/10);
                cout << "It's your lucky day, you found " << qtd << " Wolf's Claws" << endl;
                cout << "With this claws you can earn some money on the store" << endl;
                Loot claws("Wolf's Claws", 10, qtd, character.getBeasts().at(0));
                character.setLoot(claws); 
            }
            if((rand() % 10 + ceil(1+character.getLuck()/10)) >= 10){
                srand(time(NULL));
                qtd = rand() % 10 + ceil(1 + character.getLuck()/10);
                cout << "It's your lucky day, you found " << qtd << " packs of Wolf's fur" << endl;
                cout << "You can sell those packs on the store" << endl;
                Loot fur("Wolf's Fur", 2, qtd, character.getBeasts().at(0));
                character.setLoot(fur); 
            }
            character*(wolf.getXp());
        }
        else if(character.getHp()<=0){
            cout << "Oh, the wolf was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("sleep 2");
    }
    else if(being==2){
        cout << "You find a goblin" << endl;
        system("sleep 1");
        Beast goblin("goblin");
        if(character.getDex()>goblin.getDex()){
            turn = true;
        }
        while ((goblin.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("clear");
                battleMenu();
                damage = character.getAtk() - goblin.getDef();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                fflush(stdin);
                cin >> attack;
                system("clear");
                hit = rand() % 20 + 1 + floor(character.getLuck()/5) - floor(goblin.getLuck()/5);
                if(attack==1){
                    damage+=character.getMelee();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        goblin-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMelee()>floor(10-character.getDex()/5)){
                        goblin-damage;
                        cout << "You cut him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character-1;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if(attack==2){
                    turn = false;
                    damage+=character.getRanged();
                    if(hit>=20){
                        damage = 3*damage;
                        goblin-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRanged()>floor(15-character.getDex()/5)){
                        damage = ceil(1.5*damage);
                        goblin-damage;
                        cout << "Your arrow pierced him" << endl;
                    }
                    else if(hit==1+character.getRanged()){
                        cout << "Ouch, you hurt yourself" << endl;
                        character-1;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if(attack==3){
                    cout << "You ran away" << endl;
                    break;
                }
            }
            else{
                cout << "It is the goblin's turn" << endl;
                system("sleep 1");
                system("clear");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = goblin.getAtk() - character.getDef() - character.getArmor();;
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 + 1 + floor(goblin.getLuck()/5) - floor(character.getLuck()/5);
                if(attack==1){
                    turn = true;
                    if(hit>=20){
                        damage = 2*damage;
                        character-1;
                        cout << "Ouch, he dealt you a serious slash" << endl;
                    }
                    else if(hit>ceil(10-goblin.getDex()/5)+character.getArmor()){
                        character-1;
                        cout << "He cut you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the goblin hurt itself" << endl;
                        goblin-1;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                else if(attack==2){
                    turn = true;
                    if(hit>=20){
                        damage = 3*damage;
                        character-1;
                        cout << "Ouch, he dealt you a serious concussion" << endl;
                    }
                    else if(hit>ceil(15-goblin.getDex()/5)+character.getArmor()){
                        character-1;
                        cout << "He threw a stone on you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the goblin hurt itself" << endl;
                        goblin-1;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << character.getName() <<"'s hp: " << character.getHp() << endl;
            cout << "Goblin's hp: " << goblin.getHp() << endl;
            system("sleep 2");
            system("clear");
        }
        if(goblin.getHp()<=0){
            cout << "Congratulations, you just defeated the goblin" << endl;
            srand(time(NULL));
            chance = rand() % 20 + floor(character.getLuck()/5);
            if(chance > 10){
                qtd = (rand() % 10 + 1) * (rand() % 5 + 1) + character.getLuck()*(rand() % 5);
                cout << "It's your lucky day, you found " << qtd << " coins with the goblin" << endl;
                character+(qtd);
            }
            character*(goblin.getXp());
        }
        else if(character.getHp()<=0){
            cout << "Oh, the goblin was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("sleep 2");
    }
    else if(being ==3){
        cout << "You find a chitine" << endl;
        system("sleep 1");
        Beast chitine("chitine");
        if(character.getDex()>chitine.getDex()){
            turn = true;
        }
        while ((chitine.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("clear");
                battleMenu();
                damage = character.getAtk() - chitine.getDef();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                fflush(stdin);
                cin >> attack;
                system("clear");
                srand(time(NULL));
                hit = rand() % 20 + 1 + floor(character.getLuck()/5);
                if(attack==1){
                    damage+=character.getMelee();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        chitine-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMelee()>floor(10-character.getDex()/5)){
                        chitine-damage;
                        cout << "You cut him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character-1;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if(attack==2){
                    turn = false;
                    damage+=character.getRanged();
                    if(hit>=20){
                        damage = 3*damage;
                        chitine-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRanged()>floor(15-character.getDex()/5)){
                        damage = ceil(1.5*damage);
                        chitine-damage;
                        cout << "Your arrow pierced him" << endl;
                    }
                    else if(hit==1){
                        cout << "Ouch, you hurt yourself" << endl;
                        character-1;
                    }
                    else{
                        cout << "Oh, you missed the attack" << endl;
                    }
                }
                else if(attack==3){
                    cout << "You ran away" << endl;
                    break;
                }
            }
            else{
                cout << "It is the chitine's turn" << endl;
                system("sleep 1");
                system("clear");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = chitine.getAtk() - character.getDef() - character.getArmor();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                srand(time(NULL));
                if(attack==1){
                    hit = rand() % 20 + 1 + floor(chitine.getLuck()/5);
                    turn = true;
                    if(hit>=20){
                        character-2*damage;
                        cout << "Ouch, he dealt you a serious slash" << endl;
                    }
                    else if(hit - character.getArmor()>ceil(10-chitine.getDex()/5)){
                        character-damage;
                        cout << "He cut you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the chitine hurt itself" << endl;
                        chitine-1;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
                else if(attack==2){
                    turn = true;
                    for (i=0; i<2; i++){
                        hit = rand() % 20 + 1 + floor(chitine.getLuck()/5);
                        if(hit>=20){
                            character-2*damage;
                            cout << "Ouch, it dealt you a serious slash" << endl;
                        }
                        else if(hit - character.getArmor()>ceil(15-chitine.getDex()/5)){
                            character-damage;
                            cout << "It cut you" << endl;
                        }
                        else if(hit==1){
                            cout << "How clumsy, the chitine hurt itself" << endl;
                            chitine-1;
                        }
                        else cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << character.getName() <<"'s hp: " << character.getHp() << endl;
            cout << "Chitine's hp: " << chitine.getHp() << endl;
            system("sleep 2");
            system("clear");
        }
        if(chitine.getHp()<=0){
            cout << "Congratulations, you just defeated the chitine" << endl;
            srand(time(NULL));
            int chance = rand() % 10 + 1;
            if(chance>=9){
                qtd = 1 + character.getLuck()/5;
                i = rand() % 5 + 1;
                if(i==1){
                    aux = "strength";
                    character.setAtk(qtd);
                }
                else if(i==2){
                    aux = "dexterity";
                    character.setDex(qtd);
                }
                else if(i==3){
                    aux = "defense";
                    character.setDef(qtd);
                }
                else if(i==4){
                    aux = "luck";
                    character.setLuck(qtd);
                }
                else{
                    aux = "vitality";
                    character.setVit(qtd);
                }
                cout << "Thanks to this fight with a tough foe, your " << aux << " became higher" << endl;
            }
            character*(chitine.getXp());
        }
        else if(character.getHp()<=0){
            cout << "Oh, the chitine was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        system("sleep 2");

    }
    if(character.getXp() >= (character.getLvl()*10+pow(5,character.getLvl()))*10){
        character.setLvl();
        character.setUpgrade();
        system("clear");
        cout << "Congrats, " << character.getName() << " upgraded its level to " << character.getLvl() << endl;
        system("sleep 2");
    }
    return character;
}
