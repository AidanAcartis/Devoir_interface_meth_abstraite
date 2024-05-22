#include<iostream>
#include"Moto.hpp"
#include<string>

using namespace std;
Moto::Moto(string marque, double vitesse)
	:Vehicule(marque), m_vitesse(vitesse)
{}
Moto::~Moto()
{}
void Moto::conduire() const
{	
	cout<<"Ceci est un Moto de marques "<<m_marque<<" qui roule à une vitesse max de "<<m_vitesse<<"km/h"<<endl;
	cout<<"Il faut travailler l'équilibre quand on conduit un moto\n"<<endl;
}
