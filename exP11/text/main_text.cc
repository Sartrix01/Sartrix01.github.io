#include "systeme.h"
#include "Neon.h"
#include "Argon.h"
#include "enceinte.h"
#include "Helium.h"
#include "vecteur3D.h"
#include "particule.h"
#include "GenerateurAleatoire.h"
#include "text_viewer.h"
#include <iostream>
using namespace std;

int main(){
    TextViewer ecran(cout);
    Systeme s;
    Helium* helium =new Helium({1,1,1},{0,0,0}, 4.002602);
    Neon* neon= new Neon({1,18.5,1},{0,0.2,0},20.1797);
    Argon* argon= new Argon({1,1,3.1},{0,0,-0.5},39.948);

    s.ajoute(helium);
    s.ajoute(neon);
    s.ajoute(argon);
    s.dessine_sur(ecran);
    cout<<"lancement de la simulation : "<< endl ;
    for (int i = 0; i < 10; i++){
        s.evolue(1.0,1.0);
        s.dessine_sur_(ecran);
    }
    return 0;
}
