#include <iostream>
#include <string>
using namespace std;
class Skill
{
public:
    Skill();
    void skilledit(string name, string type, int dmg, int max);
    void display(int skillnum);

protected:
    string skillname;
    string skilltype;
    int skilldmg;
    int maxtry;
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

private:
    string name;
    string type;
    int maxhp;
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

int Effectiveness(const string& attackType, const string& defendType) {
    // Super Effective (O): +5
    if (attackType == "Ground" && defendType == "Electric") return 5;
    if (attackType == "Ground" && defendType == "Fire") return 5;
    if (attackType == "Water" && defendType == "Fire") return 5;
    if (attackType == "Water" && defendType == "Ground") return 5;
    if (attackType == "Grass" && defendType == "Water") return 5;
    if (attackType == "Fire" && defendType == "Grass") return 5;
    if (attackType == "Electric" && defendType == "Water") return 5;

    // Not Very Effective (X): -3
    if (attackType == "Electric" && defendType == "Ground") return -3;
    if (attackType == "Electric" && defendType == "Electric") return -3;
    if (attackType == "Electric" && defendType == "Grass") return -3;
    if (attackType == "Water" && defendType == "Grass") return -3;
    if (attackType == "Water" && defendType == "Water") return -3;
    if (attackType == "Grass" && defendType == "Fire") return -3;
    if (attackType == "Grass" && defendType == "Ground") return -3;
    if (attackType == "Grass" && defendType == "Grass") return -3;
    if (attackType == "Ground" && defendType == "Grass") return -3;
    if (attackType == "Fire" && defendType == "Fire") return -3;
    if (attackType == "Fire" && defendType == "Water") return -3;

    // Effective (-): 0
    return 0;
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
}

Skill::Skill() : skillname("None"), skilltype("None"), skilldmg(0), maxtry(0) {}
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
}

Pokemon::Pokemon() : name("None"), type("None"), maxhp(0) {}

Pokemon::Pokemon(const string &name, const string &type, const int &hp) : name(name), type(type), maxhp(hp) {}

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