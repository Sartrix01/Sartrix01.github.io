#include "Systeme.h"
#include "Neon.h"
#include "Argon.h"
#include "enceinte.h"
#include "Helium.h"
#include "Particule.h"
#include "Vecteur3D.h"
#include "GenerateurAleatoire.h"
#include "dessinable.h"
#include "support_a_dessin.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

void Systeme::dessine_sur(SupportADessin& support){
    std::cout<<"Le systeme est constitué des " << collection.size() <<" particules suivantes :"<< endl;
    std::cout << endl;
    for(auto& item : collection){
      item->dessine_sur(support);
     }
}
void Systeme::dessine_sur_(SupportADessin& support){
    for(auto item:collection){
      item->dessine_sur(support);
    }
}
void Systeme::alea_part(string element ,double T ,double nb ){

    double M ;
    double temperature = (275.15+T);
    static constexpr double R = 8.314472;
    static constexpr double M_He = 4.002602;
    static constexpr double M_Ne = 20.1797;
    static constexpr double M_Ar = 39.948;
        if (element=="Helium"){
            M=M_He;
        for(int i(1);i<=nb;i++){

           Helium p({tirage.uniforme(0,20),tirage.uniforme(0,20),tirage.uniforme(0,20)},{tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature)),tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature)),tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature))},M);

        collection.push_back(new Helium(p));
        }
    }

      if (element=="Argon"){
            M=M_Ar;
        for(int i(1);i<=nb;i++){

           Argon p({tirage.uniforme(0,20),tirage.uniforme(0,20),tirage.uniforme(0,20)},{tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature)),tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature)),tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature))},M);

        collection.push_back(new Argon(p));
        }
    }
     if (element=="Neon"){
            M=M_Ne;
        for(int i(1);i<=nb;i++){

           Neon p({tirage.uniforme(0,20),tirage.uniforme(0,20),tirage.uniforme(0,20)},{tirage.gaussienne(0.0, sqrt((1e-3*R/M) * temperature)),tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature)),tirage.gaussienne(0.0, sqrt((0.001*R/M) * temperature))},M);

        collection.push_back(new Neon(p));
        }

    }
}
void Systeme::evolue(double dt,double epsilon ){
    cout<<"==========----------"<<endl;

    //On s'occupe dans un premier temps des redond contre la paroi
    for (size_t j(0) ;j<collection.size(); ++j  ){
        collection[j]->evolue(dt);
        for(int i(0); i<3 ;++i){
            if((collection[j]->get_pos().get_coord(i)) > ( enceinte.get_enceinte(i))){
                cout<< "La particule "<<j+1 << " rebondit avec la face " << i+4 << endl;
                collection[j]->paroi( enceinte.get_enceinte(i) ,i,collection[j]->get_pos().get_coord(i) ,collection[j]->get_vit().get_coord(i) );

            }
            if (collection[j]->get_pos().get_coord(i)<0){
                    cout<< "La particule "<<j+1 << " rebondit avec la face " << i+1 << endl;
                    collection[j]->paroi( 0 ,i,collection[j]->get_pos().get_coord(i) ,collection[j]->get_vit().get_coord(i));

            }
        }
    }
    //on s'occupe maintenant des chocs

    for (size_t k(0); k<collection.size();++k){
        vector<size_t> liste_chocs;
        for (size_t l(k+1); l<collection.size();++l){
            if(collection[k]->rencontre(*collection[l],epsilon))liste_chocs.push_back(l);
        }
        if (not liste_chocs.empty()){
          double L,z,phi;
          cout<< "La particule "<< k+1 <<" entre en collision avec une autre particule ."<< endl
          << " Avant le chocs : " << endl
          <<"part ."<< k+1 <<" : : pos :" << collection[k]->get_pos()<< " ; v :" <<collection[k]->get_vit() << endl
          <<"autre   : : pos :" << collection[liste_chocs[0]]->get_pos()<< " ; v :" <<collection[liste_chocs[0]]->get_vit() << endl;


        //on calcule les differentes valeurs intermediare necessaire au calcul des nouvelles vitesses
           Vecteur3D vg(collection[k]->get_vit().vect_mult(collection[k]->infos()/(collection[k]->infos()+collection[liste_chocs[0]]->infos())) + collection[liste_chocs[0]]->get_vit().vect_mult(collection[liste_chocs[0]]->infos()/(collection[k]->infos()+collection[liste_chocs[0]]->infos())) ) ;

             L = ((collection[k]->get_vit()  - vg).norme());
             // z = tirage.uniforme(L , -L);       // normalement on prendra les valeur aleatoire mais pour
             // phi = tirage.uniforme(0, 2*3.14159265358979323846);   //la similation de l'exo 9 on a besoin de valeur precise
             z= 0;
             phi= (3.14159265358979323846/3);

            Vecteur3D v0(sqrt((L*L) - (z*z))*cos(phi),sqrt((L*L) - (z*z))*sin(phi),z);

        //on remet les bonne vitesse a nos 2 particules :


            collection[k]->set_vit(vg+v0);
            collection[liste_chocs[0]]->set_vit(vg-(v0.vect_mult((collection[k]->infos())/collection[liste_chocs[0]]->infos())));

        cout<< "Apres le choc : "<< endl
        <<"part ."<<k+1<<" : : pos :" << collection[k]->get_pos()<< " ; v :" <<collection[k]->get_vit() << endl
        <<"autre   : : pos :" << collection[liste_chocs[0]]->get_pos()<< " ; v :" <<collection[liste_chocs[0]]->get_vit() << endl;

        }
    }
}

