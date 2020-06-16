//
//  Instrument.cpp
//  rec10
//
//  Created by liheng cao on 4/10/20.
//  Copyright © 2020 liheng cao. All rights reserved.
//

#include<iostream>
#include "Instrument.hpp"

using namespace std;
namespace Musical_Instruments{
    
    Instrument::Instrument(){};
    
    void Instrument::makeSound() const {
        cout << "To make a sound... \n";
    }
    
    

    Brass::Brass(unsigned s): Instrument(), mouthpiece_size(s){}
    
    void Brass::makeSound() const {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size "
        << mouthpiece_size << endl;;
    }
    
    Trombone::Trombone(unsigned s): Brass(s){}
//    void Trombone::makeSound() const {
//        Brass::makeSound();
//    }
    
    void Trombone::playInstrument() const {
        cout << "Blat";
    }
    
    Trumpet::Trumpet(unsigned s): Brass(s){}
//    void Trumpet::makeSound() const {
//        Brass::makeSound();
//    }
    
    void Trumpet::playInstrument() const {
        cout << "Toot";
    }
    

    String::String(unsigned p): Instrument(), pitch(p){}
    
    void String::makeSound() const {
        Instrument::makeSound();
        cout << "bow a string with pitch "
        << pitch << endl;
    }
    
    Cello::Cello(unsigned p): String(p){}
    
//    void Cello::makeSound() const {
//        cout << "Cello sound\n";
//    }
    
    void Cello::playInstrument() const {
        cout << "Squawk";
    }
    

    Violin::Violin(unsigned p): String(p){}
    
//    void Violin::makeSound() const {
//        cout << "Violin sound\n";
//    }
    void Violin::playInstrument() const {
        cout << "Screech";
    }
    
    
    
    Percussion::Percussion(): Instrument(){};
    
    void Percussion::makeSound() const {
        Instrument::makeSound();
        cout << "hit me!\n";
    }
    Drum::Drum(): Percussion(){};
    
//    void Drum::makeSound() const {
//        cout << "Drum sound\n";
//    }
    
    void Drum::playInstrument() const {
        cout << "Boom";
    }
    
    Cymbal::Cymbal(): Percussion(){};
    
//    void Cymbal::makeSound() const {
//        cout << "Cymbal sound\n";
//    }
    
    void Cymbal::playInstrument() const {
        cout << "Crash";
    }
};
