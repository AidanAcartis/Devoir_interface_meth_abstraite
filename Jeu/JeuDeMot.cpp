#include "JeuDeMot.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

JeuDeMot::JeuDeMot(const std::string& fichier) : fichier(fichier) {
    chargerMotsDepuisFichier();
}

void JeuDeMot::start() {
    std::string mot_mystere;
    int compteur(0), size(0), choix(0), choice(0);

    do {
        std::cout << "Appuiez sur 1 pour jouer et sur une autre touche pour quitter" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            srand(static_cast<unsigned>(time(NULL)));
            if (mots.empty()) {
                std::cout << "Erreur : Aucun mot disponible." << std::endl;
                exitJeu();
                return;
            }

            int random_index = rand() % mots.size();
            std::string mot = mots[random_index];
            std::string output = desord(mot);
            std::cout << "desordre: " << output << std::endl;
            std::cout << "Quel est le mot?" << std::endl;
            std::cin >> mot_mystere;

            compteur = Jeu(mot, mot_mystere);
            size = mot.length();
            if (compteur == size) {
                std::cout << "Bravo!" << std::endl;
            } else {
                do {
                    compteur = 0;
                    std::cout << "Faux!\nAppuiez sur 1 pour continuer:";
                    std::cin >> choix;
                    if (choix == 1) {
                        std::cout << "Quel est le mot?" << std::endl;
                        std::cin >> mot_mystere;
                        compteur = Jeu(mot, mot_mystere);
                        if (compteur == size) {
                            std::cout << "Vrai!" << std::endl;
                        }
                    } else {
                        std::cout << "Bye!" << std::endl;
                        exitJeu();
                        return;
                    }
                } while (compteur != size);
            }
        } else {
            std::cout << "Bye!" << std::endl;
            exitJeu();
            return;
        }
    } while (choice == 1);
}

void JeuDeMot::restart() {
    start();
}

void JeuDeMot::pause() {
    std::cout << "Le jeu est en pause." << std::endl;
}

void JeuDeMot::exitJeu() {
    std::cout << "Fin du jeu." << std::endl;
}

JeuDeMot::~JeuDeMot() {
    // Pas de ressources dynamiques à libérer
}

std::string JeuDeMot::desord(const std::string& line) {
    std::vector<int> n_indexTaken;
    std::string mot = line;
    int max = line.length() - 1;

    for (size_t i = 0; i < line.length(); ++i) {
        int n;
        if (i == line.length() - 2 || i == line.length() - 1) {
            for (size_t a = 0; a < n_indexTaken.size(); ++a) {
                size_t taille = n_indexTaken.size();
                int c = 0;
                for (size_t b = 0; b < taille; ++b) {
                    if (n_indexTaken[b] == static_cast<int>(a)) {
                        b = taille;
                    } else {
                        ++c;
                    }
                }
                if (c == static_cast<int>(taille)) {
                    n = a;
                    n_indexTaken.push_back(n);
                    a = taille;
                }
            }
            n_indexTaken.push_back(n);
        } else {
            int compteur;
            size_t taille;
            do {
                compteur = 0;
                taille = n_indexTaken.size();
                n = rand() % max;
                for (size_t j = 0; j < taille; ++j) {
                    if (n_indexTaken[j] == n) {
                        j = taille;
                    } else {
                        ++compteur;
                    }
                }
                if (compteur == static_cast<int>(taille)) {
                    n_indexTaken.push_back(n);
                }
            } while (compteur != static_cast<int>(taille));
            n_indexTaken.push_back(n);
        }
        mot[i] = line[n];
    }

    return mot;
}

int JeuDeMot::Jeu(const std::string& mot, const std::string& answer) {
    int size = mot.length();
    int compteur(0);
    for (int i = 0; i < size; ++i) {
        if (mot[i] == answer[i]) {
            ++compteur;
        }
    }

    return compteur;
}

void JeuDeMot::chargerMotsDepuisFichier() {
    std::ifstream file(fichier);
    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << fichier << std::endl;
        exitJeu();
    }

    std::string mot;
    while (file >> mot) {
        mots.push_back(mot);
    }
}

