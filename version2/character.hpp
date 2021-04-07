#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <vector>
#include "item.hpp"
#include "armor.hpp"
#include "weapon.hpp"

using namespace std;

class Character{
    private:
        int c_def, c_atk, c_dex, c_luck, c_vit, c_lvl, c_upgrades, c_xp, c_hp, c_money;
        vector <Weapon> c_weapons;
        vector <Armor> c_armors;
        vector <Loot> c_inventory;
        vector <Beast*> c_enemies;
        string c_name;
    public:
        Character();
        Character(string name);

        //Set
        void setLvl(){c_lvl++;};
        void setUpgrade(){c_upgrades+=10;};
        void setAtk(int plus){c_atk+=plus;};
        void setVit(int plus){c_vit+=plus;};
        void setDef(int plus){c_def+=plus;};
        void setLuck(int plus){c_luck+=plus;};
        void setDex(int plus){c_dex+=plus;};
        void setMoney(int money){c_money+=money;};
        void setXp(int xp){c_xp+=xp;};
        void setWeapons(Weapon w);
        void setLoot(Loot i);
        void setArmors(Armor a);
        void setBeast(Beast* enemy){c_enemies.push_back(enemy);};

        //Get
        string getName(){return c_name;};
        int getRanged();
        int getMelee();
        int getArmor();
        int getDef(){return c_def;};
        int getAtk(){return c_atk;};
        int getDex(){return c_dex;};
        int getLuck(){return c_luck;};
        int getHp(){return c_hp;};
        int getLvl(){return c_lvl;};
        int getMoney(){return c_money;};
        int getXp(){return c_xp;};
        vector<Beast*> getBeasts(){return c_enemies;};
        vector<Weapon> getWeapons(){return c_weapons;};
        vector<Armor> getArmors(){return c_armors;};
        vector<Loot> getLoot(){return c_inventory;};

        //Funcions
        void setStats(string aux);
        void showStats();
        void showCharacter();
        void upStat();
        void heal(bool went);
        void inventory();
        void store();

        //Operators
        void operator + (Loot loot){c_inventory.push_back(loot);};
        void operator + (int money){setMoney(money);};
        void operator * (int xp){setXp(xp);};
        void operator - (int damage){c_hp-=damage;};

        //Destructor
        ~Character(){};
};

#endif //CHARACTER_HPP