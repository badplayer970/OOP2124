//
//  MILL.hpp
//  rec10
//
//  Created by liheng cao on 4/10/20.
//  Copyright © 2020 liheng cao. All rights reserved.
//

#ifndef MILL_hpp
#define MILL_hpp

#include <stdio.h>
#include "Instrument.hpp"
#include <vector>

using namespace std;

namespace Musical_Instruments{
    class MILL{
    public:
        MILL();
        void receiveInstr(Instrument& an_ins);
        void dailyTestPlay() const ;
        Instrument* loanOut();
    private:
        vector<Instrument*> inventory;
    };
}

#endif /* MILL_hpp */
