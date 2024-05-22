#include "JeuCombat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Combat::Combat(Personne* combattants[2]) {
    this->combattants[0] = combattants[0];
    this->combattants[1] = combattants[1];
}

void Combat::start() {
    std::cout << "Le combat commence entre " << combattants[0]->getNom() 
              << " et " << combattants[1]->getNom() << "!" << std::endl;
    bataille();
}

void Combat::pause() {
    std::cout << "Le combat est en pause." << std::endl;
}

void Combat::restart() {
    std::cout << "Le combat redémarre." << std::endl;
    combattants[0]->setEtat(100);
    combattants[1]->setEtat(100);
    bataille();
}

void Combat::exitJeu() {
    std::cout << "Le combat se termine." << std::endl;
	exit(0);
}

void Combat::bataille() {
    std::srand(std::time(0));
	int compteur(0);

    while (combattants[0]->getEtat() > 0 && combattants[1]->getEtat() > 0) {
        int combattantIndex = std::rand() % 2;
        int actionIndex = std::rand() % 2;

        Personne* attaquant = combattants[combattantIndex];
        Personne* defenseur = combattants[1 - combattantIndex];
        std::string actionChoisie = actions[actionIndex];

        std::cout << attaquant->getNom() << " choisit de " << actionChoisie << "!" << std::endl;

        if (actionChoisie == "attaquer") {
            defenseur->setEtat(defenseur->getEtat() - 10);
            std::cout << defenseur->getNom() << " est attaqué! État restant: " 
                      << defenseur->getEtat() << std::endl;
        } else if (actionChoisie == "defendre") {
            std::cout << attaquant->getNom() << " se défend!" << std::endl;
        }

        if ((combattants[0]->getEtat() == 10 || combattants[1]->getEtat() == 10) && compteur==0) {
            pause();
            std::string reponse;
            std::cout << "Un des combattants est en état critique (10 points de vie)." << std::endl;
            std::cout << "Voulez-vous redémarrer le combat ? (oui/non) : ";
            std::cin >> reponse;
            if (reponse == "oui") {
                restart();
                return; // Sortir de la méthode bataille pour redémarrer le combat
            } else {
                std::cout << "Le combat continue." << std::endl;
            }
			compteur++;
        }

        if (combattants[0]->getEtat() <= 0 || combattants[1]->getEtat() <= 0) {
            Personne* vaincu = combattants[0]->getEtat() <= 0 ? combattants[0] : combattants[1];
            std::cout << vaincu->getNom() << " est vaincu!" << std::endl;
            std::string reponse;
            std::cout << "Voulez-vous redémarrer le combat ? (oui/non) : ";
            std::cin >> reponse;
            if (reponse == "oui") {
                restart();
                return; // Sortir de la méthode bataille pour redémarrer le combat
            } else {
                exitJeu();
                return; // Sortir de la méthode bataille pour terminer le combat
            }
        }
    }
}

Combat::~Combat() {
    // Les objets Personne ne sont pas alloués dynamiquement dans cette classe, donc pas de delete nécessaire.
}
