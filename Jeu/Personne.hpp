#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>

class Personne {
public:
    Personne(const std::string& nom, int etat);
    std::string getNom() const;
    int getEtat() const;
    void setEtat(int etat);
    ~Personne();

protected:
    int m_etat;
    std::string m_nom;
};

#endif // PERSONNE_HPP
