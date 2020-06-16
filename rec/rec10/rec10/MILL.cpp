//
//  MILL.cpp
//  rec10
//
//  Created by liheng cao on 4/10/20.
//  Copyright © 2020 liheng cao. All rights reserved.
//

#include "MILL.hpp"
namespace Musical_Instruments{
    
    MILL::MILL(){}
    
    void MILL::receiveInstr(Musical_Instruments::Instrument &an_ins) {
        an_ins.makeSound();
        for (size_t i = 0; i < inventory.size(); ++i){
            if (inventory[i] == nullptr){
                inventory[i] = &an_ins;
                return;
            }
        }
        inventory.push_back(&an_ins);
    }
    
    void MILL::dailyTestPlay() const {
        for (size_t i = 0; i < inventory.size(); ++i){
            if (inventory[i]) inventory[i]->makeSound();
        }
    }
    
    Instrument* MILL::loanOut(){
        Instrument* loan;
        for (size_t i = 0; i < inventory.size(); ++i){
            if (inventory[i]){
                loan = inventory[i];
                inventory[i] = nullptr;
                return loan;
            }
        }
        return nullptr;
    }
    
    
}
