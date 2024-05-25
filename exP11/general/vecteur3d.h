#pragma once
#include <vector>
#include <cmath>
#include <string>

typedef double erreur ;
typedef double coord;

class Vecteur3D {
    private :
    coord x,y,z ;
    erreur Delta=0.1 ;

    public :
    Vecteur3D(coord val_x,coord val_y,coord val_z): x(val_x),y(val_y),z(val_z) {}

    // redefinition des operateur

    void operator+=(Vecteur3D const& v2); // addition de 2 vecteurs du type V1+ V2
    Vecteur3D operator+(Vecteur3D const& v2);// addition de 2 vecteurs du type V3= V1+V2
    void operator-=(Vecteur3D const& v2);//soustraction de 2 vecteurs du type V1 - V2
    Vecteur3D operator-(Vecteur3D const& v2);//soustraction de 2 vecteurs du type V3=V1-V2
    Vecteur3D operator^(Vecteur3D const& v2);// operateur pour effectuer un produit vectoriel entre 2 vecteurs
    bool operator==(Vecteur3D const& v2);// regarde si 2 vecteur sont egaux
    double operator%(Vecteur3D const& v2) ;// produit scalaire entre 2 vecteurs
    Vecteur3D operator~();//Vectuer unitaire directeur d'un vecteur

    //autres methodes pour les vecteurs
    Vecteur3D vect_mult(double a);// multiplication d'un vecteur par un scalaire
    void vect_inverse(){vect_mult(-1);} // l'opposé d'un vectpeur initiale v
    double norme() const ;// calcule la norme d'un vecteur
    double norme2()const;//calcule le carrée de la norme
    double D() const {return Delta;} // pour accerder a la valeur pour verifier que 2 vecteur soit egaux

    //methodes pour acceder aux coordonnées

    double get_x() const {return x ;}
    double get_y() const {return y ;}
    double get_z() const {return z ;}

    //methode pour redefinir une seule coordonée

    void set_coord(int coord,double nouvelle_coordonee);
    double get_coord(int coord);
};
std::ostream& operator<<(std::ostream& sortie , Vecteur3D const& v);
