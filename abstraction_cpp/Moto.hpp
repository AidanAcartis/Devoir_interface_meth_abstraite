#ifndef MOTO_HPP
#define MOTO_HPP
#include<string>
#include"vehicule.hpp"

using namespace std;
class Moto : public Vehicule
{
	public:
		Moto(string marque, double vitesse);
		virtual void conduire() const override;
		~Moto();
	private:
		double m_vitesse;
};
#endif //MOTO_HPP
