#include<iostream>
#include"auto.hpp"
#include"Moto.hpp"
#include<string>

using namespace std;
int main()
{
	Vehicule* vehicules[2];
	vehicules[0] = new Auto("Toyota", 4);
	vehicules[1] = new Moto("France rider",20);

	for(int i=0; i<2; i++)
	{	
		vehicules[i]->conduire();
	}

	for(int j=0; j<2; j++)
	{
	
		delete vehicules[j];
	}

return 0;
}
