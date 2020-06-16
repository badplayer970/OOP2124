//  Liheng Cao lc4241 OOP Sec D

#ifndef Protector_hpp
#define Protector_hpp

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft{
    class Lord;
    
//    Protector
    class Protector{
        friend std::ostream& operator<<(std::ostream &os, const Protector &a_warrior);
    public:
        Protector(const std::string &a_name, float a_strength);
		virtual float get_p_strength() const;
		virtual bool is_hired() const;
        virtual std::string get_name() const;
        virtual void multiply_strength(float ratio);
        virtual void set_employment(Lord* Lptr);
        virtual bool runaway();
        virtual void display_info(std::ostream &os) const = 0;
    private:
        std::string p_name;
        float strength;
		Lord* employer = nullptr;
    };
    
    class Wizard: public Protector{
    public:
        Wizard(const std::string &a_name, float a_strength);
        virtual void display_info(std::ostream &os) const;
    };
    
    class Warrior:public Protector{
    public:
        Warrior(const std::string &a_name, float a_strength);
        virtual void display_info(std::ostream &os) const = 0;
    };
    
    class Archer: public Warrior{
    public:
        Archer(const std::string &a_name, float a_strength);
        virtual void display_info(std::ostream &os) const;
    };
    
    class Swordsman: public Warrior{
    public:
        Swordsman(const std::string &a_name, float a_strength);
        virtual void display_info(std::ostream &os) const;
    };
}
#endif
