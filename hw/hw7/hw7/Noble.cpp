//  Liheng Cao lc4241 OOP Sec D

#include "Noble.hpp"
#include "Protector.hpp"

using namespace std;
using namespace WarriorCraft;

namespace WarriorCraft{
    ostream& operator<<(ostream &os, const Noble &a_noble){
//        output opeator that works for all derived
        a_noble.display_info(os);
        return os;
	}
    
//        Noble
	Noble::Noble(const string& a_name, float a_strength)
    : n_name(a_name), strength(a_strength){}
	
	void Noble::battle(Noble &other_noble){
//        console the messages and then adjust the strength
		battle_status_messages(other_noble);
		if (!dead || !other_noble.dead) {
			if (strength < other_noble.strength){
				other_noble.multiply_warrior_strengths
				(1-strength/other_noble.strength);
				multiply_warrior_strengths(0);
			}
			else{
				multiply_warrior_strengths
				(1-other_noble.strength/strength);
				other_noble.multiply_warrior_strengths(0);
			}
		}
	}
	
	string Noble::get_name() const {
		return n_name;
	}
    
    bool Noble::is_dead() const {
        return dead;
    }
    
    void Noble::display_info(std::ostream &os) const {
//        used for output operator
        os << get_name();
    }
	
	void Noble::battle_status_messages(const Noble &other_noble) const {
//         announce who is battling and display type dependent messages
		cout << n_name << " battles " << other_noble.n_name << endl;
        battle_messages();
        other_noble.battle_messages();
		float s1 = strength;
		float s2 = other_noble.strength;
		// each respective Noble's strengths
		if (dead){
			if (other_noble.dead){
				//prints if both Nobles start off dead
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
			}
			else{
				//prints if only the first Noble is dead
				cout << "He's dead, " << other_noble.n_name
					 << endl;
			}
		}
		else if (other_noble.dead){
			// prints if only the second Noble is dead
			cout << "He's dead, " << n_name << endl;
		}
		else if (s1 == s2){
			// the Nobles have equal non-zero strength
			cout << "Mutual Annihilation: " << n_name << " and "
				 << other_noble.n_name << " die at each other's hands" << endl;
		}
		else if (s1 > s2){
			// current Noble is stronger
			cout << n_name << " defeats " << other_noble.n_name << endl;
		}
		else{
			// other Noble is stronger
			cout << other_noble.n_name << " defeats " << n_name << endl;
		}
	}
	
	void Noble::multiply_warrior_strengths(float ratio){
		strength *= ratio;
		if (strength == 0){
//            make the Noble dead if the health drops to 0
			dead = true;
		}
    }
    
    void Noble::add_to_strength(float s) {
        strength += s;
    }
    
    
//    Lord: Noble
    Lord::Lord(const std::string &a_name): Noble(a_name){}
    
    bool Lord::hires(WarriorCraft::Protector &a_warrior) {
        if (is_dead() || a_warrior.is_hired()){ return false;}
//        don't hire if either protector or noble are dead
        army.push_back(&a_warrior);
        Noble::add_to_strength(a_warrior.get_p_strength());
        a_warrior.set_employment(this);
        return true;
    }
    
    bool Lord::fire(WarriorCraft::Protector &a_warrior) {
        size_t iter = 0;
        while (true){ // find Warrior to delete
            if (army[iter] == &a_warrior) break;
            iter += 1;
        }
        if (iter==army.size()){ // return false if warrior not in army
            cout << a_warrior.get_name() << " is not in " << Noble::get_name()
            <<  "\'s" <<" army" << endl;
            return false;
        }
        cout << "You don't work for me anymore " << a_warrior.get_name()
        << "! -- " << Lord::get_name() << ".\n";
        a_warrior.set_employment(nullptr);
        Lord::remove_protector(a_warrior, iter);
        Noble::add_to_strength(-1* a_warrior.get_p_strength());
        army.pop_back();
        return true;
    }
    
    void Lord::remove_protector
            (WarriorCraft::Protector &a_warrior, size_t iter) {
        // warrior guarenteed to be in army
        Noble::add_to_strength(-1* a_warrior.get_p_strength());
        while (true){ // find Warrior to delete
            if (army[iter] == &a_warrior) break;
            iter += 1;
        }
        while (iter < army.size() - 1 ){
            // shift elements 1 index forward, delete via overwrite
            // order preserved
            army[iter] = army[iter+1];
            iter += 1;
        }
        army.pop_back();
    }
    
    void Lord::battle_messages() const {
//        used for output operator
        for (size_t i = 0; i < army.size(); ++i){
            cout << *army[i];
        }
    }
    
    void Lord::multiply_warrior_strengths(float ratio) {
//        change strength of the Lord and of its protectors
        Noble::multiply_warrior_strengths(ratio);
        for (size_t iter = 0; iter < army.size(); iter++){
            if (!army[iter]){ break; }
            army[iter]->multiply_strength(ratio);
        }
    }
    
    void Lord::display_info(std::ostream &os) const {
        Noble::display_info(os);
        os  << " has an army of " << army.size();
        for (const Protector* a_warrior : army){
            if (a_warrior){
                os << endl << "\t" << *a_warrior;
            }
        }
    }
    
    
//    PersonWithStrengthToFight: Noble
    PersonWithStrengthToFight::PersonWithStrengthToFight
    (const std::string &a_name, float a_strength): Noble(a_name, a_strength){}
    
    void PersonWithStrengthToFight::battle_messages() const {
        if (!is_dead()){
//            no message if dead
            cout << "Ugh!!!\n";
        }
    }
    
    void PersonWithStrengthToFight::display_info(std::ostream &os) const {
        os << Noble::get_name();
    }
    
}
