#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Skill
{
public:
    Skill();
    void skilledit(string name, string type, int dmg, int max);
    void display(int skillnum);
    void trycount();
    int gettry();
    int getmaxtry();
    int getdmg();
    string gettype();
    string getname();

protected:
    string skillname;
    string skilltype;
    int skilldmg;
    int maxtry;
    int lefttry;
};

class Pokemon
{
public:
    Pokemon(const string &name, const string &type, const int &hp);
    Pokemon();

    void setskill(int skillnum, string name, string type, int dmg, int max)
    {
        skills[skillnum].skilledit(name, type, dmg, max);
    }

    void showstats();

    int getHP();

    string getName();

    string getType();

    void reduceHp(int dmg);

    int skilldmg(int skillnum);

    string skilltype(int skillnum);

    Skill &getskill(int skillnum);

private:
    string name;
    string type;
    int maxhp;
    int hp;
    Skill skills[4];
};

Pokemon choosepokemon(int pokenum)
{
    if (pokenum == 0)
    {
        Pokemon pikachu("Pikachu", "Electric", 35);
        pikachu.setskill(0, "Tackle", "Normal", 4, 5);
        pikachu.setskill(1, "Grass Knot", "Grass", 8, 5);
        pikachu.setskill(2, "Thunderbolt", "Electric", 10, 5);
        pikachu.setskill(3, "Megabolt", "Electric", 15, 3);
        return pikachu;
    }
    else if (pokenum == 1)
    {
        Pokemon dratini("Dratini", "Water", 41);
        dratini.setskill(0, "Wrap", "Normal", 4, 10);
        dratini.setskill(1, "Aqua Tail", "Water", 3, 5);
        dratini.setskill(2, "Water Pulse", "Water", 13, 2);
        dratini.setskill(3, "Hyper Beam", "Normal", 20, 1);
        return dratini;
    }
    else if (pokenum == 2)
    {
        Pokemon charmander("Charmander", "Fire", 39);
        charmander.setskill(0, "Tackle", "Normal", 4, 5);
        charmander.setskill(1, "Flamethrower", "Fire", 11, 5);
        charmander.setskill(2, "Dig", "Ground", 7, 5);
        charmander.setskill(3, "Heat Wave", "Fire", 14, 5);
        return charmander;
    }
    else if (pokenum == 3)
    {
        Pokemon eevee("Eevee", "Normal", 55);
        eevee.setskill(0, "Tackle", "Normal", 4, 5);
        eevee.setskill(1, "Sand Attack", "Ground", 8, 3);
        eevee.setskill(2, "Bite", "Normal", 12, 3);
        eevee.setskill(3, "Rain Dance", "Water", 15, 1);
        return eevee;
    }
    else if (pokenum == 4)
    {
        Pokemon palkia("Palkia", "Water", 90);
        palkia.setskill(0, "Hydro Pump", "Water", 12, 10);
        palkia.setskill(1, "Earth Power", "Ground", 15, 10);
        palkia.setskill(2, "Surf", "Water", 13, 10);
        palkia.setskill(3, "Spatial Rend", "Normal", 30, 10);
        return palkia;
    }
}

int Effectiveness(const string &attackType, const string &defendType)
{
    // Super Effective (O): +5
    if ((attackType == "Ground" && defendType == "Electric") ||
        (attackType == "Ground" && defendType == "Fire") ||
        (attackType == "Water" && defendType == "Fire") ||
        (attackType == "Water" && defendType == "Ground") ||
        (attackType == "Grass" && defendType == "Water") ||
        (attackType == "Fire" && defendType == "Grass") ||
        (attackType == "Electric" && defendType == "Water"))
    {
        return 5; // Super effective
    }

    // Not Very Effective (X): -3
    if ((attackType == "Electric" && (defendType == "Ground" || defendType == "Electric" || defendType == "Grass")) ||
        (attackType == "Water" && (defendType == "Grass" || defendType == "Water")) ||
        (attackType == "Grass" && (defendType == "Fire" || defendType == "Ground" || defendType == "Grass")) ||
        (attackType == "Ground" && defendType == "Grass") ||
        (attackType == "Fire" && (defendType == "Fire" || defendType == "Water")))
    {
        return -3; // Not very effective
    }

    // Effective (-): 0
    return 0;
}

void Battle(Pokemon &p1, Pokemon &p2)
{
    bool p1turn = true;
    PrintBattlePage(p1, p2, p1turn);
    while (p1.getHP() > 0 && p2.getHP() > 0)
    {
        if (p1turn)
        {
            int skillnum, dmg, effect;
            cout << "“Choose a skill (0~3): ";
            cin >> skillnum;
            while (true)
            {
                if (p1.getskill(skillnum).gettry() > 0)
                    break;
                cout << "Pokémon-name failed to perform " << p1.getskill(skillnum).getname();
                cin >> skillnum;
            }
            if (p1.getskill(skillnum).gettry() > 0)
            {
                p1.getskill(skillnum).trycount();
                effect = Effectiveness(p1.skilltype(skillnum), p2.getType());
                dmg = p1.skilldmg(skillnum) + effect;
                if (effect == 5)
                {
                    cout << "It was super effective." << endl;
                }
                else if (effect == -3)
                {
                    cout << "It was not very effective." << endl;
                }
                else
                {
                    cout << "It was effective." << endl;
                }
                p2.reduceHp(dmg);
                if (p2.getHP() <= 0)
                    break;
            }
            p1turn = false;
        }
        if (!p1turn)
        {
            int skillnum, dmg, effect;
            cout << "“Choose a skill (0~3): ";
            cin >> skillnum;
            while (true)
            {
                if (p2.getskill(skillnum).gettry() > 0)
                    break;
                cout << "Pokémon-name failed to perform " << p2.getskill(skillnum).getname();
                cin >> skillnum;
            }
            if (p2.getskill(skillnum).gettry() > 0)
            {
                p2.getskill(skillnum).trycount();
                effect = Effectiveness(p2.skilltype(skillnum), p1.getType());
                dmg = p2.skilldmg(skillnum) + effect;
                if (effect == 5)
                {
                    cout << "It was super effective." << endl;
                }
                else if (effect == -3)
                {
                    cout << "It was not very effective." << endl;
                }
                else
                {
                    cout << "It was effective." << endl;
                }
                p1.reduceHp(dmg);
                if (p1.getHP() <= 0)
                    break;
            }
            p1turn = true;
        }
        PrintBattlePage(p1, p2, p1turn);
    }
}

void PrintBattlePage(Pokemon &p1, Pokemon &p2, bool p1Turn)
{
    const int columnWidth = 30;

    cout << "+------------------------------+------------------------------+" << endl;
    cout << "| " << left << setw(columnWidth - 2)
         << (p1Turn ? p1.getName() + " (*)" : p1.getName())
         << "| " << left << setw(columnWidth - 2)
         << (!p1Turn ? p2.getName() + " (*)" : p2.getName())
         << "|" << endl;

    cout << "| Type: " << setw(columnWidth - 9) << p1.getType()
         << "| Type: " << setw(columnWidth - 9) << p2.getType()
         << "|" << endl;
    cout << "| HP: " << setw(columnWidth - 6) << p1.getHP()
         << "| HP: " << setw(columnWidth - 6) << p2.getHP()
         << "|" << endl;
    cout << "+------------------------------+------------------------------+" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "| (" << i << ") " << setw(columnWidth - 6) << p1.getskill(i).getname()
             << "| (" << i << ") " << setw(columnWidth - 6) << p2.getskill(i).getname()
             << "|" << endl;
        cout << "|     - Type: " << setw(columnWidth - 13) << p1.getskill(i).gettype()
             << "|     - Type: " << setw(columnWidth - 13) << p2.getskill(i).gettype()
             << "|" << endl;
        cout << "|     - Damage: " << setw(columnWidth - 15) << p1.getskill(i).getdmg()
             << "|     - Damage: " << setw(columnWidth - 15) << p2.getskill(i).getdmg()
             << "|" << endl;
        cout << "|     - Count: " << setw(columnWidth - 14)
             << to_string(p1.getskill(i).gettry()) + "(" + to_string(p1.getskill(i).getmaxtry()) + ")"
             << "|     - Count: " << setw(columnWidth - 14)
             << to_string(p2.getskill(i).gettry()) + "(" + to_string(p2.getskill(i).getmaxtry()) + ")"
             << "|" << endl;
    }
    cout << "+------------------------------+------------------------------+" << endl;
}

int main()
{
    int pokenum[2];
    Pokemon pokemon[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Choose a Pokemon(0~4): ";
        cin >> pokenum[i];
    }
    while (pokenum[1] == pokenum[0])
    {
        cout << "You have to choose Pokemons different from each other.";
        cin >> pokenum[1];
    }
    for (int i = 0; i < 2; i++)
    {
        pokemon[i] = choosepokemon(pokenum[i]);
    }
    Battle(pokemon[0], pokemon[1]);
}

Skill::Skill() : skillname("None"), skilltype("None"), skilldmg(0), maxtry(0), lefttry(0) {}
void Skill::display(int skillnum)
{
    cout << "-Skill " << skillnum << ':' << endl;
    cout << "\t-Name: " << skillname << endl;
    cout << "\t-Skill Type: " << skilltype << endl;
    cout << "\t-Damage: " << skilldmg << endl;
    cout << "\t-MaxTry: " << maxtry << endl;
}

void Skill::skilledit(string name, string type, int dmg, int max)
{
    skillname = name;
    skilltype = type;
    skilldmg = dmg;
    maxtry = max;
    lefttry = max;
}

void Skill::trycount()
{
    lefttry -= 1;
}

int Skill::getdmg()
{
    return skilldmg;
}

int Skill::gettry()
{
    return lefttry;
}

int Skill::getmaxtry()
{
    return maxtry;
}

string Skill::gettype()
{
    return skilltype;
}

string Skill::getname()
{
    return skillname;
}

Pokemon::Pokemon() : name("None"), type("None"), maxhp(0), hp(0) {}

Pokemon::Pokemon(const string &name, const string &type, const int &hp) : name(name), type(type), maxhp(hp), hp(hp) {}

void Pokemon::showstats()
{
    cout << "Pokemon name: " << name << endl;
    cout << "Pokemon type: " << type << endl;
    cout << "Max HP: " << maxhp << endl;
    for (int i = 0; i < 4; i++)
    {
        skills[i].display(i);
    }
}

int Pokemon::getHP()
{
    return hp;
}

string Pokemon::getName()
{
    return name;
}

string Pokemon::getType()
{
    return type;
}
void Pokemon::reduceHp(int dmg)
{
    hp -= dmg;
    if (hp < 0)
        hp = 0;
}

int Pokemon::skilldmg(int skillnum)
{
    return skills[skillnum].getdmg();
}

string Pokemon::skilltype(int skillnum)
{
    return skills[skillnum].gettype();
}

Skill &Pokemon::getskill(int skillnum)
{
    return skills[skillnum];
}