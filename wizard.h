#pragma once
#include <iostream>
#include "entity.h"

class mage : public entity {
public: 
    mage();

    // Overriding base functions
    void attack(int typeofatk) override;
    void damage(int atk) override;
    void heal() override;
    void display() override;
    ~mage();
};
