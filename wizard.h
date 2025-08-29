#pragma once
#include <iostream>
#include "entity.h"

class wizard : public entity {
public: 
    wizard();

    // Overriding base functions
    void attack(int typeofatk) override;
    void damage(int atk) override;
    void heal() override;
    void display() override;
    ~wizard();
};
