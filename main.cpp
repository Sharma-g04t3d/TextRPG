#include <iostream>
#include "samurai.h"
#include "wizard.h"


int main() {
    // Initializing players
    wizard w;
    samurai s;
    // Player inputs
    int atkname;
    int turn = 0;
    /*
    w.inventory_add("HealSpell");
    w.inventory_add("HealSpell");
    w.inventory_add("HealSpell");
    w.inventory_add("Wand");
    w.inventory_add("Hat");

    s.inventory_add("Potion");
    s.inventory_add("Potion");
    s.inventory_add("Potion");
    s.inventory_add("Sword");
    s.inventory_add("Armour");

    std::cout<<"Inventory of : ["<<w.Name<<"]"<<std::endl;
    for(auto items : w.inventory){
        std::cout<<"Item_name : "<< items.first << std::endl;
        std::cout<<"Item_slot_no : "<< items.second.first << std::endl;
        std::cout<<"Item_count : "<< items.second.second << std::endl;
    }
    std::cout<<"Inventory of : ["<<s.Name<<"]"<<std::endl;
    for(auto items : s.inventory){
        std::cout<<"Item_name : "<< items.first << std::endl;
        std::cout<<"Item_slot_no : "<< items.second.first << std::endl;
        std::cout<<"Item_count : "<< items.second.second << std::endl;
    }*/
        
    // Main game loop
    while (w.Health > 0 && s.Health > 0) {
        switch (turn) {
            case 0: {
                std::cout << "\n[Warrior's Turn] Enter action (0 = Basic Attack, 1 = Special Attack): ";
                std::cin >> atkname;
                s.attack(atkname);
                w.damage(s.atk);
                s.display();
                w.display();
                turn = 1; // switch turn
                s.turn += 1;
                break;
            }
            case 1: {
                std::cout << "\n[Wizard's Turn] Enter action (0 = Attack, 1 = Heal): ";
                std::cin >> atkname;
                if (atkname != 3) {
                    w.attack(atkname);
                    s.damage(w.atk);
                } else {
                    w.heal();
                }
                s.display();
                w.display();
                turn = 0; // switch turn
                w.turn += 1;
                break;
            }
        }
    }
    // Aftermath of battle
    if (w.Health <= 0) {
        std::cout << "\n[Wizard Status] : Fainted\n";
    } else if (s.Health <= 0) {
        std::cout << "\n[Warrior Status] : Fainted\n";
    }
    w.~wizard();
    s.~samurai();
    std::string EndQuote;
    std::cin >> EndQuote;
    std::cin.get(); // prevent console from closing immediately
}
