#include "Personne.hpp"

Personne::Personne(const std::string& nom, int etat) : m_nom(nom), m_etat(etat) {}

std::string Personne::getNom() const {
    return m_nom;
}

int Personne::getEtat() const {
    return m_etat;
}

void Personne::setEtat(int etat) {
    m_etat = etat;
}

Personne::~Personne() {
    // Pas de ressources dynamiques à libérer
}
