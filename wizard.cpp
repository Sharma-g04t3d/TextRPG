#include <iostream>
#include "wizard.h"

mage::mage() {
    maxHealth = 100;
    Health = maxHealth;
    Name = "Wizard";
    std::cout << "[" << Name << "] : Created" << std::endl;
}

// Overriding base functions
void mage::attack(int typeofatk) {
    if(typeofatk == 0){
        atk = fireball_w; // currently ignores typeofatk, which is fine if mage always casts fireball
    }
    else if(typeofatk == 1){
        atk = thunderbolt_w;
    }
    else if (typeofatk == 2 && turn % 5 == 0)
    {
        atk = meteor_shower_w;
    }
    
}

void mage::damage(int atk) {
    Health -= atk;
}

void mage::heal() {
    if (Health + healamt > maxHealth) {
        Health = maxHealth;
    } else {
        Health += healamt;
    }
}

void mage::display() {
    std::cout << "[" << Name << " Health] : " << Health << std::endl;
}

mage::~mage() {
    std::cout << "[" << Name << "] : Destroyed" << std::endl;
}
