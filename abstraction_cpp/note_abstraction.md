###ABSTRACTION
#####Méthode abstraite
* méthode qu'on ne peut pas définir.
#####Méthode virtuelle
Il n'a pas de définition:
virtuel void conduire()=0;

Alors, une méthode abstraite est une méthode virtuelle pure.
Une ***classe abstraite*** est une classe qui contient au moins une méthode abstraite.
Une classe abstraite n'est pas instenciable
xxxvehicule v = vehicule (); (resahina fotsiny fa tsy misy)
Ny instance an'ny classe héritaire afaka affecter amin'ny instance an'ny classe mère.

##### #Macro
Eègle le problème de déclaration multiple

(# define PI 3.14): élément constante mais pas une variable constante. Il ne réserve pas de mémoire mais est reconnue par le compilateur.
Ça sert à éviter la déclaration mutliple:
*  #define Vehicule
* ()ifdef
  #ifdef Vehicule(si Vehicule est définie execute le code entre ifdef et endif)
   ----
   ----
   ----
  #endif

####exercice
Créer un interface de ##Jeu
JeuFoot, JeuCombat, JeuStratégie

