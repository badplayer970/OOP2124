//  Liheng Cao lc4241 OOP Sec D

#include "Protector.hpp"
#include "Noble.hpp"

using namespace std;
using namespace WarriorCraft;

namespace WarriorCraft{
    ostream& operator<<(ostream &os, const Protector &a_warrior){
//        output operator that works for all derived
        a_warrior.display_info(os);
        return os;
    }

//    Protector
    Protector::Protector(const string &a_name, float a_strength)
        : p_name(a_name), strength(a_strength){}

    float Protector::get_p_strength() const {
        // return Protector strength
        return strength;
    }

    void Protector::multiply_strength(float ratio){
        // change protector's strength by ratio
        strength *= ratio;
    }

    string Protector::get_name() const {
        // get protector name
        return p_name;
    }

    bool Protector::is_hired() const {
        // see if protector is hired
        return employer != nullptr;
    }

    void Protector::set_employment(Lord* Lptr){
        // change the protector employment
        employer = Lptr;
    }

    bool Protector::runaway(){
        // the protector quits
        if (!employer){
            cout << "Not employed!";
            return false;
        }
        cout << p_name << " flees in terror, abandoning his lord, " <<
        employer->get_name() << endl;
        employer->remove_protector(*this);
        return true;
    }
    
    void Protector::display_info(std::ostream &os) const {
//        used for output operator
        os << employer->get_name();
    }
    
    
//    Wizard: Protector
    void Wizard::display_info(std::ostream &os) const {
//        used for output operator
        if (Protector::get_p_strength() != 0){
            os << "POOF\n";
        }
    }
    
    Wizard::Wizard(const std::string &a_name, float a_strength)
        : Protector(a_name, a_strength){}
    
    
//    Warrior: Protector
    void Warrior::display_info(std::ostream &os) const {
//        used for output operator
        if (Protector::get_p_strength() != 0){
            os << " says: Take that in the name of my lord, ";
            Protector::display_info(os);
            os << endl;
        }
    }
    
    Warrior::Warrior(const std::string &a_name, float a_strength)
        : Protector(a_name, a_strength){}
    
    
//    Archer: Warrior
    void Archer::display_info(std::ostream &os) const {
//        used for output operator
        if (Protector::get_p_strength() != 0){
            os << "Twang! " << Protector::get_name();
            Warrior::display_info(os);
        }
    }
    
    Archer::Archer(const std::string &a_name, float a_strength)
        : Warrior(a_name, a_strength){}
    
    
//    Swordsmen: Warrior
    void Swordsman::display_info(std::ostream &os) const {
//        used for output operator
        if (Protector::get_p_strength() != 0){
            os << "Clang! " << Protector::get_name();
            Warrior::display_info(os);
        }
    }
    
    Swordsman::Swordsman(const std::string &a_name, float a_strength)
        : Warrior(a_name, a_strength){}
    
}
