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
