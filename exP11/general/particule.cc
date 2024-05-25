#include "Particule.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& sortie, Particule* const p ){
    sortie << "pos :" << p->get_pos() <<" v :" <<p->get_vit() << " m : "<< p->infos() <<" ;";
    return sortie;
}
void Particule::evolue(double dt){
    pos += (vit.vect_mult(dt));
}

void Particule::paroi(double h , int i , double pose , double vite  ){
    double ecart (pose-h) ;
    vit.set_coord(i, -vite);
    pos.set_coord( i, h-(ecart));
    }

bool Particule::rencontre(Particule& p2 , double e ){
    bool meet = false ;
    if ((abs(pos.get_x() - p2.get_pos().get_x()) < e) && (abs(pos.get_y() - p2.get_pos().get_y()) < e) && (abs(pos.get_z() - p2.get_pos().get_z()) < e)){
        meet = true ;
    }
    return meet ;
    }

void Particule::set_vit(Vecteur3D v ){
    vit=v;
}
