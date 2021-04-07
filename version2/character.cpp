#include "character.hpp"
#include "func.hpp"
#include "beast.hpp"
#include "weapon.hpp"
#include "armor.hpp"
#include <time.h>
#include <math.h>

Character::Character(string name){
    c_def=c_atk=c_dex=c_luck=c_vit=c_lvl=1;
    c_upgrades = 10*c_lvl;
    c_xp = 0;
    c_hp = 10+2*c_vit;
    c_money = 50;
    c_name = name;
    Weapon melee("Iron Dagger");
    c_weapons.push_back(melee);
    Weapon range("Short Bow");
    c_weapons.push_back(range);
}

void Character::setLoot(Loot i){
    int j=0;
    string aux = i.getName();
    for(j=0; j<c_inventory.size(); j++){
        if(aux==c_inventory.at(j).getName()){
            c_inventory.at(j)+(i.getAmount());
            break;
        }
    }
    if(j==0||j==c_inventory.size()-1) c_inventory.push_back(i); 
}

void Character::setWeapons(Weapon w){
    int i = 0;
    string aux = w.getName();
    for(i=0; i<c_weapons.size(); i++){
        if(aux==c_weapons.at(i).getName()){
            cout << "You already have this weapon on your arsenal, are you sure you wanna do this?" << endl;
            cin >> aux;
            if(aux == "S"|| aux == "s"){
                c_money-=w.getPrice();
                c_weapons.at(i)+1;
                cout << "You acquired another " << w.getName() << ". You can change your weapons in the inventory" << endl;
            }
            else break;
        }
    }
    if(i == c_weapons.size()||i == 0){
        w.setOwned(true);
        c_weapons.push_back(w); 
        c_money-=w.getPrice();
        cout << "You acquired " << w.getName() << ". You can change your weapons in the inventory" << endl;
    }
    system("sleep 2");
}

void Character::setArmors(Armor a){
    int i = 0;
    string aux = a.getName();
    for(i=0; i<c_armors.size(); i++){
        if(aux==c_armors.at(i).getName()){
            cout << "You already have this armor on your arsenal, are you sure you wanna do this?" << endl;
            cin >> aux;
            if(aux == "S"|| aux == "s"){
                c_money-=a.getPrice();
                c_armors.at(i)+(1);
                cout << "You acquired another " << a.getName() << ". You can change your armors in the inventory" << endl;
            }
            else break;
        }
    }
    if(i == c_armors.size()||i == 0){
        a.setOwned(true);
        c_armors.push_back(a);
        c_money-=a.getPrice();
        cout << "You acquired " << a.getName() << ". You can change your armors in the inventory" << endl;
    }
    system("sleep 2");
}

void Character::setStats(string aux){
    char opt;
    while(c_upgrades>0){
        system("clear");
        cout << "You still have " << c_upgrades << " available" << endl;
        cout << "Please distribute them" << endl;
        cout << "1 - Constitution: " << c_def << endl;
        cout << "2 - Strength: " << c_atk << endl;
        cout << "3 - Dexterity: " << c_dex << endl;
        cout << "4 - Luck: " << c_luck << endl;
        cout << "5 - Vitality: " << c_vit << endl;
        if(aux=="up") cout << "6 - I've changed my mind. Don't wanna spend my points now" << endl;
        fflush(stdin);
        cin >> opt;
        if(opt == '1'){
            c_def++;
            c_upgrades--;
        }
        else if(opt == '2'){
            c_atk++;
            c_upgrades--;
        }
        else if(opt == '3'){
            c_dex++;
            c_upgrades--;
        }
        else if(opt == '4'){
            c_luck++;
            c_upgrades--;
        }
        else if(opt == '5'){
            c_vit++;
            c_upgrades--;
            c_hp+=2;
        }
        else if(aux == "up" && opt == '6') break;
    }
}

void Character::showStats(){
    cout << "Name: " << c_name << endl;
    cout << "Constitution: " << c_def << endl;
    cout << "Strength: " << c_atk << endl;
    cout << "Dexterity: " << c_dex << endl;
    cout << "Luck: " << c_luck << endl;
    cout << "Vitality: " << c_vit << endl;
}

void Character::showCharacter(){
    cout << "Name: " << c_name << endl;
    cout << "Level: " << c_lvl << endl;
    cout << "Money: " << c_money << endl;
    cout << "Constitution: " << c_def << endl;
    cout << "Strength: " << c_atk << endl;
    cout << "Dexterity: " << c_dex << endl;
    cout << "Luck: " << c_luck << endl;
    cout << "Vitality: " << c_vit << endl;
    cout << "HP: " << c_hp << "/" << (10+2*c_vit) << endl;
    system("sleep 6");
}

void Character::upStat(){
    system("clear");
    int aux;
    string answer, opt;
    cout << "Points Menu" <<endl;
    cout << "1 - See profile" << endl;
    cout << "2 - Upgrade stats" << endl;
    cout << "3 - Reset stats" << endl;
    cout << "4 - See experience" << endl;
    cout << "5 - Return to previous menu" << endl;
    fflush(stdin);
    cin >> aux;
    if (aux==1){
        system("clear");
        showCharacter();
    }
    else if (aux==2){
        if (c_upgrades>0) setStats("up");
        else{
            system("clear");
            cout << "You don't have any remaining points" << endl;
            system("sleep 2");
        }
    }
    else if (aux==3){
        cout << "Reseting the stats will cost you 100 coins and this action can't be undone. Are you sure? [Y/N]" << endl;
        fflush(stdin);
        cin >> answer;
        if (answer == "Y"){
            if (c_money >= 100){
                c_upgrades = c_upgrades + c_def + c_atk + c_dex + c_luck + c_vit - 5;
                c_def = 1;
                c_atk = 1;
                c_dex = 1;
                c_luck = 1;
                c_vit = 1;
                c_hp = 12;
                c_money = c_money - 100;
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
        cout << "You have " << c_xp << " experience points" << endl;
        cout << "For the next lvl you need " << (c_lvl*10+pow(5,c_lvl))*10 << " experience points" << endl;
        system("sleep 3");
    }
}

void Character::heal(bool went){
    char aux;
    int opt, menor, chance;
    system("clear");
    if (c_hp < 10 + 2*c_vit){
        cout << c_name << "'s hp: " << c_hp << "/" << 10+2*c_vit << endl << endl;
        cout << "It seems that you are hurt" << endl;
        cout << "We have the best and confiest bedroom over the region" << endl;
        cout << "Do you wish to rest for a bit in the Sweet Dreams Inn? [Y/N]" << endl;
        fflush(stdin);
        cin >> aux;
        if (aux=='Y'||aux=='y'){
            system("clear");
            cout << c_name << "'s hp: " << c_hp << "/" << 10 + 2 * c_vit << endl << endl;
            cout << "Money: " << c_money << endl;
            cout << "We have 3 options of services" << endl;
            cout << "1 - Standard: costs 5 coins and heals 25% of life" << endl;
            cout << "2 - Advanced: costs 9 coins and heals 50% of life" << endl;
            cout << "3 - Complete: costs 17 coins and heals 100% of life" << endl;
            cout << "4 - Never mind. I've changed my mind" << endl;
            fflush(stdin);
            cin >> opt;
            if(went) chance = 0;
            else{
                srand(time(NULL));
                chance = rand() % (20) + 1 + c_luck;
            }
            if(opt == 1){
                if (c_hp + ceil(0.25 * (10 + 2 * c_vit)) > 10 + 2 * c_vit){
                    menor = 10 + 2 * c_vit - c_hp;
                }
                else menor = ceil(0.25 * (10 + 2 * c_vit));
                system("clear");
                if(chance>19){
                    cout << "You know what? Take a free trial. No fees for ya" << endl;
                    for(int time = 0; time < menor; time++){
                        system("clear");
                        c_hp++;
                        cout << c_name << "'s hp: " << c_hp << "/" << 10 + 2 * c_vit << endl;
                        cout << "Resting" << endl;
                        system("sleep 0.05");
                    }
                    cout << "After a rest in a bed you feel a bit better" << endl;
                }
                else{
                    if(c_money >= 5){
                        for(int time = 0; time < menor; time++){
                            system("clear");
                            c_hp++;
                            cout << c_name << "'s hp: " << c_hp << "/" << 10 + 2 * c_vit << endl;
                            cout << "Resting" << endl;
                            system("sleep 0.05");
                        }
                        cout << "After a rest in a bed you feel a bit better" << endl;
                        c_money = c_money - 5;
                    }
                    else cout << "You don't have enough money. Sorry, we can do nothing for you" << endl;
                    system("sleep 2");
                }
            }
            else if(opt == 2){
                if (c_hp + ceil(0.5 * (10 + 2 * c_vit)) > 10 + 2 * c_vit){
                    menor = 10 + 2 * c_vit - c_hp;
                }
                else menor = ceil(0.5 * (10 + 2 * c_vit));
                if(chance>19){
                    cout << "You know what? Take a free trial. No fees for ya" << endl;
                    for(int time = 0; time < menor; time++){
                        system("clear");
                        c_hp++;
                        cout << c_name << "'s hp: " << c_hp << "/" << menor << endl;
                        cout << "Resting" << endl;
                        system("sleep 0.05");
                    }
                    cout << "After a rest in a bed you feel a bit better" << endl;
                }
                else{
                    if(c_money >= 9){
                        for(int time = 0; time < menor; time++){
                            system("clear");
                            c_hp++;
                            cout << c_name << "'s hp: " << c_hp << "/" << 10 + 2 * c_vit << endl;
                            cout << "Resting" << endl;
                            system("sleep 0.05");
                        }
                        cout << "After a rest in a confy bed you feel better" << endl;
                        c_money = c_money - 9;
                        c_hp = c_hp + ceil(0.5*(10 + 2*c_vit));
                    }
                }
            }
            else if(opt == 3){
                menor = 10 + 2 * c_vit - c_hp;
                if(chance>19){
                    cout << "You know what? Take a free trial. No fees for ya" << endl;
                    for(int time = 0; time < menor; time++){
                        system("clear");
                        c_hp++;
                        cout << c_name << "'s hp: " << c_hp << "/" << 10 + 2 * c_vit << endl;
                        cout << "Resting" << endl;
                        system("sleep 0.05");
                    }
                    cout << "After a rest in a bed you feel a bit better" << endl;
                }
                else{
                    if(c_money >= 17){
                        menor = 10 + 2 * c_vit - c_hp;
                        for(int time = 0; time < menor; time++){
                            system("clear");
                            c_hp++;
                            cout << c_name << "'s hp: " << c_hp << "/" << 10 + 2 * c_vit << endl;
                            cout << "Resting" << endl;
                            system("sleep 0.05");
                        }
                        cout << "After a rest in a superbly confy bed you feel revigorated" << endl;
                        c_money = c_money - 17;
                        c_hp = 10 + 2*c_vit;
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
            system("clear");
            cout << "Okay, good luck out there" << endl;
        }
    }
    else{
        cout << "Oh, your health is perfect!! Came back when you have injuries" << endl;
    }
    system("sleep 2");
    system("clear");
}

void Character::inventory(){
    int aux, auxSec, a = 0, Mequipped = -1, Requipped = -1, Aequipped = -1;
    bool item = false;
    system("clear");
    cout << "Inventory Menu" << endl;
    cout << "1 - See Battle Items" << endl;
    cout << "2 - See Other Items" << endl;
    cout << "3 - Change Equipment" << endl;
    cout << "4 - Go back to previous Menu" << endl;
    fflush(stdin);
    cin >> aux;
    system("clear");
    if (aux == 1){
        bool range = false, melee = false, armor = false;
        vector<Weapon> weapons = getWeapons();
        vector<Armor> armors = getArmors();
        for(int j=0; j<weapons.size(); j++){
            if(weapons.at(j).getEquiped()){
                if(weapons.at(j).getMelee()){
                    cout << "Your melee weapon is " << weapons.at(j).getName() << " which gives you + " << weapons.at(j).getBonus() << " in your melee attacks" << endl;
                    melee = true;
                }
                else if(weapons.at(j).getRanged()){
                    cout << "Your ranged weapon is " << weapons.at(j).getName() << " which gives you + " << weapons.at(j).getBonus() << " in your ranged attacks" << endl;
                    range = true;
                }
            }
        }
        for(int j=0; j<armors.size(); j++){
            if(armors.at(j).getEquiped()){
                cout << "You have a " << armors.at(j).getName() << " which gives you + " << armors.at(j).getBonus() << " in defense" << endl;
                armor = true;
            }
        }
        if(!melee) cout << "You have no equiped melee weapon" << endl;
        if(!range) cout << "You have no equiped ranged weapon" << endl;
        if(!armor) cout << "You have no equiped armor" << endl;
        system("sleep 5");
    }
    else if (aux==2){
        vector <Loot> loot = getLoot();
        for (int j = 0; j < loot.size(); j++){
            if (loot.at(j).getAmount() == 1){
                cout << "You have " << loot.at(j).getAmount() << " unit of " << loot.at(j).getName() << " dropped by " << loot.at(j).getBeast()->getName() << endl;
                item = true;
            }
            else if (loot.at(j).getAmount() > 1){
                cout << "You have " << loot.at(j).getAmount() << " units of " << loot.at(j).getName() << " dropped by " << loot.at(j).getBeast()->getName() << endl;
                item = true;
            }
        }
        if (!item){
            cout << "You have no other items. Battle to find items" << endl;
            system("sleep 2");
        }
        else system("sleep 5");
    }
    else if (aux == 3){
        system("clear");
        cout << "Welcome to your armory" << endl;
        cout << "Would you to change something?" << endl;
        cout << "1 - Armor" << endl;
        cout << "2 - Weapon" << endl;
        cout << "3 - Never mind, I've changed my mind" << endl;
        fflush(stdin);
        cin >> aux;
        if (aux == 1){
            system("clear");
            for(int j=0; j<c_armors.size(); j++){
                if(c_armors.at(j).getOwned()){
                    if(a == 0) cout << "You have the following armors in your arsenal" << endl;
                    a++;
                    cout << j+1 << " - "<< c_armors.at(j).getName() << ":     " << c_armors.at(j).getBonus() << endl;
                }
                if(c_armors.at(j).getEquiped()) Aequipped = j;
            }
            if(a != 0){
                cout << endl;
                cout << "Which you wanna use now? Insert the ID of the respective armor (Insert 200 for cancelling)" << endl;
                fflush(stdin);
                cin >> aux;
                if(aux < 1) cout << "I'll take that as a 'I don't wanna change it anymore'..." << endl;
                else if(Aequipped != -1){ if (aux - 1 == Aequipped) cout << "This armor is already in use" << endl;}
                else{
                    if(Aequipped != -1) c_armors.at(Aequipped).setEquiped(false);
                    c_armors.at(aux-1).setEquiped(true);
                    cout << "Armors successfully swapped" << endl;
                }
            }
            else cout << "You have no armor. Go to the store to aquire some gear" << endl;
            system("sleep 2");
        }
        else if(aux == 2){
            system("clear");
            for(int j=0; j<c_weapons.size(); j++){
                if(c_weapons.at(j).getOwned()){
                    if(a == 0) cout << "You have the following weapons in your arsenal" << endl;
                    a++;
                    cout << j+1 << " - "<< c_weapons.at(j).getName() << ":     " << c_weapons.at(j).getBonus() << endl;
                }
                if(c_weapons.at(j).getEquiped() && c_weapons.at(j).getMelee()) Mequipped = j;
                if(c_weapons.at(j).getEquiped() && c_weapons.at(j).getRanged()) Requipped = j;
            }
            if(a !=0 ){
                cout << endl;
                cout << "Which you wanna use now? Insert the ID of the respective weapon (Insert 200 for cancelling)" << endl;
                fflush(stdin);
                cin >> aux;
                if(aux==200) return;
                if (aux - 1 == Mequipped || aux - 1 == Requipped) cout << "This weapon is already in use" << endl;
                else{  
                    if(c_weapons.at(aux-1).getMelee()){
                        c_weapons.at(aux-1).setEquiped(true);
                        c_weapons.at(Mequipped).setEquiped(false);
                        cout << "Weapons successfully swapped" << endl;
                    }
                    else if(c_weapons.at(aux-1).getRanged()){
                        c_weapons.at(aux-1).setEquiped(true);
                        c_weapons.at(Requipped).setEquiped(false);
                        cout << "Weapons successfully swapped" << endl;
                    }
                }
            }
            else cout << "You have no weapon. Go to the store to aquire some gear" << endl;
            system("sleep 2");
        }
    }
}

void Character::store(){
    system("clear");
    int i, id, qtd, aux1 = 0; int aux2 = 0; int aux3 = 0;
    char opt;
    cout << "Welcomte to the shop" << endl;
    cout << "1 - Sell Items" << endl;
    cout << "2 - Buy Items" << endl;
    cout << "3 - Back to main menu" <<endl;
    fflush(stdin);
    cin >> opt;
    system("clear");
    if(opt == '1'){
        for (int k=0;k<c_weapons.size();k++){
            if ((c_weapons.at(k).getAmount()>0)&&(!c_weapons.at(k).getEquiped())){
                aux1++;
            }
        }
        for (int k=0;k<c_armors.size();k++){
            if ((c_armors.at(k).getAmount()>0)&&(!c_armors.at(k).getEquiped())){
                aux2++;
            }
        }
        for (int k=0;k<c_inventory.size();k++){
            if (c_inventory.at(k).getAmount()>0){
                aux3++;
            }
        }
        cout << "Do you want to sell items[I], weapons [W] or armors[A]?" << endl;
        fflush(stdin);
        cin >> opt;
        system("clear");
        if ((opt == 'I')||(opt == 'i')){
            if (aux3 == 0){
                cout << "You have no items yet. Battle to acquire some more" << endl;
                system("sleep 2");
            }
            while(aux3 > 0){  
                aux3 = 0;
                system("clear");
                cout << "Id |  Iten's name  |  Iten's price  |  Owned" << endl;
                for (i=0;i<c_inventory.size();i++){
                    if(c_inventory.at(i).getAmount()>0){
                        if(c_inventory.at(i).getPrice()<10){
                            cout << i << "  |  " << c_inventory.at(i).getName() << "   |       " << c_inventory.at(i).getPrice() << "        |  " << c_inventory.at(i).getAmount() << endl;
                        }
                        else if(c_inventory.at(i).getPrice()<100){
                            cout << i << "  |  " << c_inventory.at(i).getName() << " |       " << c_inventory.at(i).getPrice() << "       |  " << c_inventory.at(i).getAmount() << endl;
                        }
                        else if(c_inventory.at(i).getPrice()<1000){
                            cout << i << "  |  " << c_inventory.at(i).getName() << "  |       " << c_inventory.at(i).getPrice() << "      |  " << c_inventory.at(i).getAmount() << endl;
                        }
                    }
                }
                if (aux3 == 0){
                    system("clear");
                    cout << "It seems you have run out of sellable merchandise, but don't worry, you can acquire others by battling" << endl;
                    system("sleep 3");
                    return;
                }
                cout << endl;
                cout << "Which item would you like to sell? Please insert the respective Id. If you wanna quit, insert the number 200" << endl;
                fflush(stdin);
                cin >> id;
                if (id == 200){
                    cout << "Okay dokay, see ya" << endl;
                    system("sleep 2");
                } 
                if (c_inventory.at(id).getAmount()>1){
                    cout << "How many you wanna sell?" << endl;
                    fflush(stdin);
                    cin >> qtd;
                    if (qtd>c_inventory.at(id).getAmount()||qtd<0){
                        cout << "Well, if you are gonna lie, our business for now is done" << endl;
                        break;
                    }
                    else if(qtd == 0){
                        cout << "Oh, I see. You've changed your mind. It happens..." << endl; 
                    }
                    else{
                        +(qtd*c_inventory.at(id).getPrice());
                        c_inventory.at(id).setAmount(c_inventory.at(id).getAmount() - qtd);
                    }   
                }
                else if(c_inventory[id].getAmount() == 1){
                    system("clear");
                    cout << "Alright, here's you money" << endl;
                    cout << "You got " << c_inventory.at(id).getPrice() << endl;
                    +(c_inventory[id].getPrice());
                    c_inventory.at(id).setAmount(c_inventory[id].getAmount() - 1);
                    system("sleep 2");
                }
            }
        }
        else if((opt == 'w')||(opt == 'W')){
            for (i=0;i<c_weapons.size();i++){
                if ((!c_weapons.at(i).getEquiped())&&(c_weapons.at(i).getOwned())){
                    cout << "You are not using " << c_weapons.at(i).getName() << endl;
                    cout << "We can give you " << ceil(c_weapons.at(i).getPrice()*0.9) << " for it" << endl;
                    cout << "Wanna sell it[Y/N]?" << endl;
                    fflush(stdin);
                    cin >> opt;
                    if ((opt == 'Y')||(opt == 'y')){
                        setMoney(ceil(c_weapons.at(i).getPrice()*0.9));
                        c_weapons.at(i) + -1;
                        cout << c_weapons.at(i).getName() << " was sold" << endl;
                        if(c_weapons.at(i).getAmount() == 0){
                            c_weapons.erase(c_weapons.begin() + i);
                        }
                        cout << c_weapons.size() << endl;
                    }
                }
            }
        }
        else if((opt == 'a')||(opt == 'A')){
            for (i=0;i<c_armors.size();i++){
                if ((!c_armors.at(i).getEquiped())&&(c_armors.at(i).getOwned())){
                    cout << "You are not using " << c_armors.at(i).getName() << endl;
                    cout << "We can give you " << ceil(c_armors.at(i).getPrice()*0.9) << " for it" << endl;
                    cout << "Wanna sell it[Y/N]?" << endl;
                    fflush(stdin);
                    cin >> opt;
                    if ((opt == 'Y')||(opt == 'y')){
                        setMoney(ceil(c_armors.at(i).getPrice()*0.9));
                        c_armors.at(i) + -1;
                        cout << c_armors.at(i).getName() << " was sold" << endl;
                        if(c_armors.at(i).getAmount() == 0){
                            c_armors.erase(c_armors.begin() + i);
                        }
                    }
                }
            }
        }
    }
    else if(opt == '2'){
        cout << "We have several options ready for you" << endl;
        cout << "Would you like to see armours[A] or weapons[W]?" << endl;
        fflush(stdin);
        cin >> opt;
        system("clear");
        if(opt == 'A' || opt == 'a'){
            cout << "We have the following armors available" << endl;
            cout << endl;
            cout << "ID |      Name      | Price | Bonus" << endl;
            cout << "1  | Padded Leather |  100  |   1  " << endl;
            cout << "2  |   Ring Mail    |  600  |   2  " << endl;
            cout << "3  |   Half Plate   | 4000  |   3  " << endl;
            cout << "4  |   Chain Mail   | 6000  |   4  " << endl << endl;
            if (getLvl()>3) cout << "5  |  Spiked Armor  | 3500  |   2  " << endl;
            cout << "Let me know if any of them caught your eye. Take this hint: just give me the ID and I'll get it for ya" << endl;
            fflush(stdin);
            cin >> opt;
            if (opt == '1'){
                if (getMoney()>=100){
                    system("clear");
                    Armor armor("Padded Leather");
                    setArmors(armor);
                }
                else cout << "You don't have enough money" << endl;
            }
            else if (opt == '2'){
                if (getMoney()>=600){
                    system("clear");
                    Armor armor("Ring Mail");
                    setArmors(armor);
                }
                else cout << "You don't have enough money" << endl;
            }
            else if (opt == '3'){
                if (getMoney()>=4000){
                    system("clear");
                    Armor armor("Half Plate");
                    setArmors(armor);
                }
                else cout << "You don't have enough money" << endl;
            }
            else if (opt == '4'){
                if (getMoney()>=6000){
                    system("clear");
                    Armor armor("Chain Mail");
                    setArmors(armor);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
            else if (opt == '5' && getLvl()>=3){
                if (getMoney()>=3500){
                    system("clear");
                    Armor armor("Spiked Armor");
                    setArmors(armor);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
        }
        else if (opt == 'W' || opt == 'w'){
            cout << "We have the following weapons available" << endl;
            cout << endl;
            cout << "ID |    Name     | Price | Bonus" << endl;
            cout << "1  |    Spear    | 1000  |   2  " << endl;
            cout << "2  | Short Sword | 1000  |   2  " << endl;
            cout << "3  | Battle Axe  | 2500  |   3  " << endl;
            cout << "4  |   Long Bow  | 3750  |   2  " << endl;
            cout << endl;
            if (getLvl()>3) cout << "5  |    Scythe   | 5000  |   5  " << endl;
            cout << "Let me know if any of them caught your eye. Take this hint: just give me the ID and I'll get it for ya" << endl;
            fflush(stdin);
            cin >> opt;
            if (opt == '1'){
                if (getMoney()>=100){
                    system("clear");
                    Weapon weapon("Spear");
                    setWeapons(weapon);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
            else if (opt == '2'){
                if (getMoney()>=1000){
                    system("clear");
                    Weapon weapon("Short Sword");
                    setWeapons(weapon);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
            else if (opt == '3'){
                if (getMoney()>=2500){
                    system("clear");
                    Weapon weapon("Battle Axe");
                    setWeapons(weapon);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
            else if (opt == '4'){
                if (getMoney()>=3750){
                    system("clear");
                    Weapon weapon("Long Bow");
                    setWeapons(weapon);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
            else if (getLvl() > 4 && opt == '5'){
                if (getMoney()>=5000){
                    system("clear");
                    Weapon weapon("Scythe");
                    setWeapons(weapon);
                }
                else{
                    cout << "You don't have enough money" << endl;
                }
            }
            else {
                cout << "I got it. You lost interest on buying din'cha?" << endl;
            }
        }
    }
    system("sleep 2");
    system("clear");
}

int Character::getRanged(){
    for(int i=0; i<c_weapons.size(); i++){
        if(c_weapons.at(i).getEquiped()&&c_weapons.at(i).getRanged()) return c_weapons.at(i).getBonus();
    }
    return 0;
}

int Character::getMelee(){
    for(int i=0; i<c_weapons.size(); i++){
        if(c_weapons.at(i).getEquiped()&&c_weapons.at(i).getMelee()) return c_weapons.at(i).getBonus();
    }
    return 0;
}

int Character::getArmor(){
    for(int i=0; i<c_armors.size(); i++){
        if(c_armors.at(i).getEquiped()) return c_armors.at(i).getBonus();
    }
    return 0;
}
