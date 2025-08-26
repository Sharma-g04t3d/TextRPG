#include <iostream>
#include "samurai.h"

samurai::samurai() {
    maxHealth = 150;
    Health = maxHealth;
    Name = "Samurai";
    std::cout << "[" << Name << "] : Created" << std::endl;
}

// Overriding base functions
void samurai::attack(int typeofatk) {
    if (typeofatk == 1) {
        atk = basicatk_s;
    }
    else if(typeofatk == 0){
        atk = basicatk_s;
    }
    else if(typeofatk == 2 && turn % 5 == 0){
        atk = slash_s;
    }
    {
        /* code */
    }
    
}

void samurai::damage(int atk) {
    Health -= atk;
}

void samurai::heal() {
    if (Health + healamt > maxHealth) {
        Health = maxHealth;
    } else {
        Health += healamt;
    }
}

void samurai::display() {
    std::cout << "[" << Name << " Health] : " << Health << std::endl;
}

samurai::~samurai() {
    std::cout << "[" << Name << "] : Destroyed" << std::endl;
}
