#pragma once
#include <string>
#include<map>

// Base Entity
struct entity {

    std::map<std::string,std::pair< int , int>> inventory;
    int slot_no = 0;
    int item_count = 0;
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
    void inventory_add(std::string item_name) {
        auto it = inventory.find(item_name);
        if(it == inventory.end()){
            slot_no += 1;
            inventory.emplace(item_name, std::make_pair(slot_no,1));
        }
        else{
            it->second.second += 1;
        }
    }
    void inventory_use(std::string item_name) {
        // First check if the item exists
        auto it = inventory.find(item_name);
        if(it->second.second == 1){
            if (it != inventory.end()) {
                // Get the slot number of the item to be removed
                int removed_slot = it->second.first;
                
                // Remove the item
                inventory.erase(it);
                // Decrease slot numbers for items that came after the removed item
                for (auto& item : inventory) {
                    if (item.second.first > removed_slot) {
                        item.second.first -= 1;
                    }
                }
                slot_no--; // Decrease total slot count
            }
        }
        else{
            it->second.second -= 1;
        }
    }
    // Virtual destructor (important for cleanup via base pointer)
    virtual ~entity() = default;
};
