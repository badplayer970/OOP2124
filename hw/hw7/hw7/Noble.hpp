//  Liheng Cao lc4241 OOP Sec D

#ifndef Noble_hpp
#define Noble_hpp

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft{
    class Protector;
    
//    Noble
    class Noble{
        friend std::ostream& operator<<
            (std::ostream &os, const Noble &a_noble);
    public:
        Noble(const std::string& a_name, float a_strength = 0);
        virtual void battle(Noble &other_noble);
        std::string get_name() const;
        virtual void display_info(std::ostream &os) const = 0;
    protected:
        virtual bool is_dead() const;
        virtual void add_to_strength(float s);
        virtual void battle_messages() const=0;
        virtual void battle_status_messages(const Noble &other_noble) const;
        virtual void multiply_warrior_strengths(float ratio);
    private:
        std::string n_name;
        float strength;
        bool dead = false;
    };
    
//    Lord, aka Lords of the Land
    class Lord: public Noble{
    public:
        Lord(const std::string& a_name);
        virtual bool hires(Protector &a_warrior);
        virtual bool fire(Protector &a_warrior);
        virtual void remove_protector(Protector &a_warrior, size_t iter = 0);
        virtual void display_info(std::ostream &os) const override;
    protected:
        virtual void battle_messages() const override;
        virtual void multiply_warrior_strengths(float ratio) override;
    private:
        std::vector<Protector*> army;
    };
    
    
//    PersonWithStregthToFight
    class PersonWithStrengthToFight: public Noble{
    public:
        PersonWithStrengthToFight(const std::string &a_name, float a_strength);
        virtual void display_info(std::ostream &os) const override;
    protected:
        virtual void battle_messages() const override;
    };
}
#endif
