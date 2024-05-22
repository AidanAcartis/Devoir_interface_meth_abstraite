#ifndef VEHICULE_HPP
#define VEHICULE_HPP
#include<string>

using namespace std;
class Vehicule
{
		public :
			Vehicule(string marque);
			~Vehicule();
			virtual void conduire() const = 0; //MÉTHODE ABSTRAITE
		protected : 
			string m_marque;
};
#endif // VEHICULE_HPP

