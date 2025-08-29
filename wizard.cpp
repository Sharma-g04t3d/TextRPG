#include <iostream>
#include "wizard.h"

wizard::wizard() {
    maxHealth = 100;
    Health = maxHealth;
    Name = "Wizard";
    std::cout << "[" << Name << "] : Created" << std::endl;
}

// Overriding base functions
void wizard::attack(int typeofatk) {
    if(typeofatk == 0){
        atk = fireball_w; // currently ignores typeofatk, which is fine if wizard always casts fireball
    }
    else if(typeofatk == 1){
        atk = thunderbolt_w;
    }
    else if (typeofatk == 2 && turn % 5 == 0)
    {
        atk = meteor_shower_w;
    }
    
}

void wizard::damage(int atk) {
    Health -= atk;
}

void wizard::heal() {
    if (Health + healamt > maxHealth) {
        Health = maxHealth;
    } else {
        Health += healamt;
    }
}

void wizard::display() {
    std::cout << "[" << Name << " Health] : " << Health << std::endl;
}

wizard::~wizard() {
    std::cout << "[" << Name << "] : Destroyed" << std::endl;
}
