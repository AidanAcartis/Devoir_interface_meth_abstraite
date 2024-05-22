
#include<iostream>
#include"auto.hpp"
#include<string>

using namespace std;
Auto::Auto(string marque, int portes)
	:Vehicule(marque), m_portes(portes)
{}
Auto::~Auto()
{}
void Auto::conduire() const
{
	cout<<"Ceci est un Auto de marques "<<m_marque<<" Il a "<<m_portes<<" portes"<<endl;
	cout<<"On utilise un volant pour conduire un voiture\n"<<endl;	
}
