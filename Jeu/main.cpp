#include "Personne.hpp"
#include "JeuCombat.hpp"
#include "JeuDeMot.hpp"
#include <iostream>

int main() {
    Personne* protagoniste = new Personne("Protagoniste", 100);
    Personne* antagoniste = new Personne("Antagoniste", 100);
    Personne* combattants[2] = {protagoniste, antagoniste};

    Combat combat(combattants);
    JeuDeMot trouverDeMot("file.txt");

    int choix;
    do {
        std::cout << "Choisissez un jeu: 1 pour Combat, 2 pour Jeu de Mot, autre pour quitter: ";
        std::cin >> choix;

        if (choix == 1) {
            combat.start();
        } else if (choix == 2) {
            trouverDeMot.start();
        } else {
            break;
        }

        std::cout << "Voulez-vous redémarrer ? (1 pour oui, autre pour non): ";
        std::cin >> choix;
        if (choix == 1) {
            if (choix == 1) {
                combat.restart();
            } else if (choix == 2) {
                trouverDeMot.restart();
            }
        }
    } while (choix == 1);

    combat.exitJeu();
    trouverDeMot.exitJeu();

    delete protagoniste;
    delete antagoniste;

    return 0;
}

