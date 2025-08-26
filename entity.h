#pragma once
#include <string>

// Base Entity
struct entity {
    // Variables
    std::string Name;
    int maxHealth;
    int Health;
    int atk;
    int turn = 0;

    // Attack values
    enum atks {
        basicatk_s = 15, 
        splatk_s   = 20,
        slash_s = 25,
        fireball_w = 20,
        thunderbolt_w = 25,
        meteor_shower_w = 50,
        prayingstrikes_m = 15,
        headbutt_m = 25,
        finalform_m = 30

    };

    // Potion values
    enum potions {
        healamt = 20
    };

    // Base functions
    virtual void attack(int typeofatk) = 0;
    virtual void heal() = 0;
    virtual void damage(int atk) = 0;
    virtual void display() = 0;

    // Virtual destructor (important for cleanup via base pointer)
    virtual ~entity() = default;
};
