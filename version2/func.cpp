#include "func.hpp"
#include "character.hpp"

void start(){
    cout << "Welcome to this chaotic world, where villages are wiped out by monsters and heroes are lacking" << endl;
    Sleep(2000);
    system("cls");
    cout << "You'll start your adventure at Brengash Village" << endl;
    Sleep(2000);
    system("cls");
    cout << "Will you be able to change this world's destiny and defeat the Abysmal Lord?" << endl;
    Sleep(2000);
    system("cls");
    cout << "Before we start, what should your character be known as?" << endl;
}

void battleMenu(Character perso){
    cout << "It is your turn" << endl;
    cout << "What you want to do?" <<endl;
    cout << "1 - " << perso.getMeleeWeapon().getSentence() << endl;
    cout << "2 - " << perso.getRangedWeapon().getSentence() << endl;
    cout << "3 - Run away" << endl;
}

void cutScene(Character perso){
    system("cls");
    cout << " 'OH NO!! Something must be wrong! The ground wasn't supossed to be shaking, neither the clouds should be funneling like a-- OH S**T!! THAT'S A MOTHERDUCKING MAGICAL STORM!! HANG OOONNN!!!!' " << endl;
    Sleep(4000);
    system("cls");
    Sleep(5000);
    cout << "It seems you've got stronger, but so do the hostile creatures" << endl;
    perso.setUpgrade(5);
}

Character battle(Character character){
    system("cls");
    bool turn = false;
    int being, attack, damage, hit, qtd, i, chance;
    string aux;
    srand(time(NULL));
    being = rand() % (character.getLvl() + 1) + 1;
    if(being==1){
        cout << "You find a wolf" << endl;
        Sleep(2000);
        Beast wolf("wolf");
        if(character.getDex()>wolf.getDex()){
            turn = true;
        }
        while ((wolf.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("cls");
                battleMenu(character);
                fflush(stdin);
                cin >> attack;
                system("cls");
                hit = rand() % 20 + 1 + floor(character.getLuck()/5) - floor(wolf.getLuck()/5);
                damage = character.getAtk() - wolf.getDef();
                if((damage<1)&&(damage>-10)) damage = 1;
                else if(damage<-9) damage = 0;
                if(attack==1){
                    damage+=character.getMeleeWeapon().getBonus();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        wolf-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMeleeWeapon().getBonus()>floor(10-character.getDex()/5)){
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
                    damage+=character.getRangedWeapon().getBonus();
                    if(hit>=20){
                        damage = 3*damage;
                        wolf-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRangedWeapon().getBonus()>floor(15 - character.getDex()/5)){
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
                Sleep(2000);
                system("cls");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = wolf.getAtk() - character.getDef() - character.getArmor().getBonus();
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
                    else if(hit>ceil(10-wolf.getDex()/5) - character.getArmor().getBonus()){
                        character-damage;
                        cout << "He scratched you" << endl;
                    }
                    else if(hit==1){
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
                    else if(hit>ceil(15-wolf.getDex()/5) - character.getArmor().getBonus()){
                        character-1.5*damage;
                        cout << "He bit you" << endl;
                    }
                    else if(hit==1){
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
            Sleep(2000);
            system("cls");
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
        Sleep(2000);
    }
    else if(being==2){
        cout << "You find a goblin" << endl;
        Sleep(2000);
        Beast goblin("goblin");
        if(character.getDex()>goblin.getDex()){
            turn = true;
        }
        while ((goblin.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("cls");
                battleMenu(character);
                damage = character.getAtk() - goblin.getDef();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                fflush(stdin);
                cin >> attack;
                system("cls");
                hit = rand() % 20 + 1 + floor(character.getLuck()/5) - floor(goblin.getLuck()/5);
                if(attack==1){
                    damage+=character.getMeleeWeapon().getBonus();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        goblin-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMeleeWeapon().getBonus()>floor(10-character.getDex()/5)){
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
                    damage+=character.getRangedWeapon().getBonus();
                    if(hit>=20){
                        damage = 3*damage;
                        goblin-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRangedWeapon().getBonus()>floor(15-character.getDex()/5)){
                        damage = ceil(1.5*damage);
                        goblin-damage;
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
                cout << "It is the goblin's turn" << endl;
                Sleep(2000);
                system("cls");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = goblin.getAtk() - character.getDef() - character.getArmor().getBonus();
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
                    else if(hit>ceil(10-goblin.getDex()/5)+character.getArmor().getBonus()){
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
                    else if(hit>ceil(15-goblin.getDex()/5)+character.getArmor().getBonus()){
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
            Sleep(2000);
            system("cls");
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
        Sleep(2000);
    }
    else if(being ==3){
        cout << "You find a chitine" << endl;
        Sleep(2000);
        Beast chitine("chitine");
        if(character.getDex()>chitine.getDex()){
            turn = true;
        }
        while ((chitine.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("cls");
                battleMenu(character);
                damage = character.getAtk() - chitine.getDef();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                fflush(stdin);
                cin >> attack;
                system("cls");
                srand(time(NULL));
                hit = rand() % 20 + 1 + floor(character.getLuck()/5);
                if(attack==1){
                    damage+=character.getMeleeWeapon().getBonus();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        chitine-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMeleeWeapon().getBonus()>floor(10-character.getDex()/5)){
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
                    damage+=character.getRangedWeapon().getBonus();
                    if(hit>=20){
                        damage = 3*damage;
                        chitine-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRangedWeapon().getBonus()>floor(15-character.getDex()/5)){
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
                Sleep(2000);
                system("cls");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = chitine.getAtk() - character.getDef() - character.getArmor().getBonus();
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
                    else if(hit - character.getArmor().getBonus()>ceil(10-chitine.getDex()/5)){
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
                        else if(hit - character.getArmor().getBonus()>ceil(15-chitine.getDex()/5)){
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
            Sleep(2000);
            system("cls");
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
        Sleep(2000);

    }
    else if(being==4){
        cout << "You find a great wolf, beware" << endl;
        Sleep(2000);
        Beast greatWolf("great wolf");
        if(character.getDex()>greatWolf.getDex()){
            turn = true;
        }
        while ((greatWolf.getHp()>0)&&(character.getHp()>0)){
            if(turn){
                system("cls");
                battleMenu(character);
                fflush(stdin);
                cin >> attack;
                system("cls");
                hit = rand() % 20 + 1 + floor(character.getLuck()/5) - floor(greatWolf.getLuck()/5);
                damage = character.getAtk() - greatWolf.getDef();
                if((damage<1)&&(damage>-10)) damage = 1;
                else if(damage<-9) damage = 0;
                if(attack==1){
                    damage+=character.getMeleeWeapon().getBonus();
                    turn = false;
                    srand(time(NULL));
                    if(hit>=20){
                        damage = 2*damage;
                        greatWolf-damage;
                        cout << "Congrats, critical slash" << endl;
                    }
                    else if(hit+character.getMeleeWeapon().getBonus()>floor(10-character.getDex()/5)){
                        greatWolf-damage;
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
                    damage+=character.getRangedWeapon().getBonus();
                    if(hit>=20){
                        damage = 3*damage;
                        greatWolf-damage;
                        cout << "Congrats, critical pierce" << endl;
                    }
                    else if(hit+character.getRangedWeapon().getBonus()>floor(15 - character.getDex()/5)){
                        damage = ceil(1.5*damage);
                        greatWolf-damage;
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
                cout << "It is the great wolf's turn" << endl;
                Sleep(2000);
                system("cls");
                srand(time(NULL));
                attack = rand() % 2 +1;
                damage = greatWolf.getAtk() - character.getDef() - character.getArmor().getBonus();
                if((damage<1)&&(damage>-10)){
                    damage = 1;
                }
                else if(damage<-9){
                    damage = 0;
                }
                hit = rand() % 20 + 1 + floor(greatWolf.getLuck()/5) - floor(character.getLuck()/5);
                if(attack==1){
                    turn = true;
                    if(hit>=20){
                        character-2*damage;
                        cout << "Ouch, he dealt you a serious scratch" << endl;
                    }
                    else if(hit>ceil(10-greatWolf.getDex()/5) - character.getArmor().getBonus()){
                        character-damage;
                        cout << "He scratched you" << endl;
                    }
                    else if(hit+character.getArmor().getBonus()==1){
                        cout << "How clumsy, the great wolf hurt itself" << endl;
                        greatWolf-1;
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
                    else if(hit>ceil(15-greatWolf.getDex()/5) - character.getArmor().getBonus()){
                        character-1.5*damage;
                        cout << "He bit you" << endl;
                    }
                    else if(hit==1){
                        cout << "How clumsy, the great wolf hurt itself" << endl;
                        greatWolf-1;
                    }
                    else{
                        cout << "Hooray, you dodged the attack" << endl;
                    }
                }
            }
            cout << character.getName() <<"'s hp: " << character.getHp() << endl;
            cout << "great wolf's hp: " << greatWolf.getHp() << endl;
            Sleep(2000);
            system("cls");
        }
        if(greatWolf.getHp()<=0){
            cout << "Congratulations, you just defeated a great wolf" << endl;
            srand(time(NULL));
            if((rand() % 5 + ceil(1+character.getLuck()/10) >= 5)){
                srand(time(NULL));
                qtd = rand() % 4 + ceil(1 + character.getLuck()/10);
                cout << "It's your lucky day, you found " << qtd << " Great Wolf's Claws" << endl;
                cout << "With this claws you can earn some money on the store" << endl;
                Loot gClaws("Great Wolf's Claws", 10, qtd, character.getBeasts().at(0));
                character.setLoot(gClaws); 
            }
            if((rand() % 10 + ceil(1+character.getLuck()/10)) >= 10){
                srand(time(NULL));
                qtd = rand() % 10 + ceil(1 + character.getLuck()/10);
                cout << "It's your lucky day, you found " << qtd << " packs of Great Wolf's Fur" << endl;
                cout << "You can sell those packs on the store" << endl;
                Loot gFur("Great Wolf's Fur", 2, qtd, character.getBeasts().at(0));
                character.setLoot(gFur); 
            }
            character*(greatWolf.getXp());
        }
        else if(character.getHp()<=0){
            cout << "Oh, the great wolf was too strong for you" << endl;
            cout << "Better luck next time" << endl;
        }
        Sleep(2000);
    }
  
    if(character.getXp() >= (character.getLvl()*10+pow(5,character.getLvl()))*10){
        character.setLvl();
        character.setUpgrade(10);
        system("cls");
        cout << "Congrats, " << character.getName() << " upgraded its level to " << character.getLvl() << endl;
        Sleep(2000);
        if(character.getLvl() == 5) cutScene(character);
    }
    return character;
}
