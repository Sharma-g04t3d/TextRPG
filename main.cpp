#include <iostream>
#include "samurai.h"
#include "wizard.h"

int main() {
    //Initalizing all entities
    entity e;
    // Initializing players
    mage m;
    samurai w;

    // Player inputs
    int atkname;

    // Main game loop
    while (m.Health > 0 && w.Health > 0) {
        switch (e.turn) {
            case 0: {
                std::cout << "\n[Warrior's Turn] Enter action (0 = Basic Attack, 1 = Special Attack): ";
                std::cin >> atkname;

                w.attack(atkname);
                m.damage(w.atk);

                w.display();
                m.display();

                e.turn = 1; // switch turn
                break;
            }

            case 1: {
                std::cout << "\n[Mage's Turn] Enter action (0 = Attack, 1 = Heal): ";
                std::cin >> atkname;

                if (atkname == 0) {
                    m.attack(0);
                    w.damage(m.atk);
                } else {
                    m.heal();
                }

                w.display();
                m.display();

                e.turn = 0; // switch turn
                break;
            }
        }
    }

    // Aftermath of battle
    if (m.Health <= 0) {
        std::cout << "\n[Mage Status] : Fainted\n";
    } else if (w.Health <= 0) {
        std::cout << "\n[Warrior Status] : Fainted\n";
    }
    m.~mage();
    w.~samurai();
    std::string EndQuote;
    std::cin >> EndQuote;

    std::cin.get(); // prevent console from closing immediately
}
