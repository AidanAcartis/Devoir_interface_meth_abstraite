#ifndef JEUCOMBAT_HPP
#define JEUCOMBAT_HPP

#include "Jeu.hpp"
#include "Personne.hpp"
#include <string>

class Combat : public Jeu {
public:
    Combat(Personne* combattants[2]);
    void start() override;
    void pause() override;
    void restart() override;
    void exitJeu() override;
    void bataille();
    ~Combat();

private:
    Personne* combattants[2];
    std::string actions[2] = {"attaquer", "defendre"};
};

#endif // JEUCOMBAT_HPP
