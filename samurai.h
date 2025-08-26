#pragma once
#include<iostream>
#include "entity.h"
//A samurai

class samurai : public entity {
public:
    //overriding base funtnctions
    samurai();
    void attack(int typeofatk) override;
    void damage(int atk) override;
    void heal() override;
    void display() override;
    ~samurai();
};
