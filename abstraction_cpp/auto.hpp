#ifndef AUTO_HPP
#define AUTO_HPP
#include<string>
#include"vehicule.hpp"

using namespace std;
class Auto : public Vehicule
{
	public:
		Auto(string marque, int portes);
		void conduire() const override;
		~Auto();
	private:
		int m_portes;
};
#endif //AUTO_HPP
