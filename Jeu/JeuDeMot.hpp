#ifndef JEUDEMOT_HPP
#define JEUDEMOT_HPP

#include "Jeu.hpp"
#include <string>
#include <vector>

class JeuDeMot : public Jeu {
public:
    JeuDeMot(const std::string& fichier);
    void start() override;
    void restart() override;
    void pause() override;
    void exitJeu() override;
    ~JeuDeMot();
    
private:
    std::string desord(const std::string& line);
    int Jeu(const std::string& mot, const std::string& answer);
    void chargerMotsDepuisFichier();
    
    std::string fichier;
    std::vector<std::string> mots;
};

#endif // JEUDEMOT_HPP

