#include <iostream>
#include <string>
using namespace std;
class Skill{
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
class Pokemon{
    public:
    Pokemon(const string& name, const string& type, const int& hp);
    Pokemon();

    void setskill(int skillnum, string name, string type, int dmg, int max){
        skills[skillnum].skilledit(name, type, dmg, max);
    }

    void showstats();

    private:
    string name;
    string type;
    int maxhp;
    Skill skills[4];
};
Skill::Skill(): skillname("None"), skilltype("None"), skilldmg(0), maxtry(0) {}
