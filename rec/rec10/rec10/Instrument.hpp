//
//  Instrument.hpp
//  rec10
//
//  Created by liheng cao on 4/10/20.
//  Copyright © 2020 liheng cao. All rights reserved.
//

#ifndef Instrument_hpp
#define Instrument_hpp

#include <stdio.h>

namespace Musical_Instruments{
    
    // base Instrument
    class Instrument{
    public:
        Instrument();
    public:
        virtual void makeSound() const = 0;
        virtual void playInstrument() const = 0;
    };

    
    // base Brass
    class Brass: public Instrument{
    public:
        Brass(unsigned s);
        virtual void makeSound() const;
    private:
        unsigned mouthpiece_size;
    };
    
    class Trombone: public Brass{
    public:
        Trombone(unsigned s);
//        virtual void makeSound() const ;
        virtual void playInstrument() const ;
    };
    
    class Trumpet: public Brass{
    public:
        Trumpet(unsigned s);
//        virtual void makeSound() const ;
        virtual void playInstrument() const ;
    };
    
    
    // base String
    class String: public Instrument{
    public:
        String(unsigned p);
        virtual void makeSound() const;
    private:
        unsigned pitch;
    };
    
    class Cello: public String{
    public:
        Cello(unsigned p);
//        virtual void makeSound() const ;
        virtual void playInstrument() const ;
    };
    
    class Violin: public String{
    public:
        Violin(unsigned p);
//        virtual void makeSound() const ;
        virtual void playInstrument() const ;
    };
    
    // base Percussion
    class Percussion: public Instrument{
    public:
        Percussion();
        virtual void makeSound() const;
    };
    
    class Drum: public Percussion{
    public:
        Drum();
//        virtual void makeSound() const ;
        virtual void playInstrument() const ;
    };
    
    class Cymbal: public Percussion{
    public:
        Cymbal();
//        virtual void makeSound() const ;
        virtual void playInstrument() const ;
    };
};
#endif /* Instrument_hpp */
