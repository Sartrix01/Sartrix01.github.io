#include "vecteur3D.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

void Vecteur3D::operator+=(Vecteur3D const& v2) {
x += v2.x; y += v2.y; z += v2.z;
}
Vecteur3D Vecteur3D::operator+(Vecteur3D const& v2){
    Vecteur3D v3(x+v2.x,y+v2.y,z+v2.z);
    return v3;
}
void Vecteur3D::operator-=(Vecteur3D const& v2) {
x -= v2.x; y -= v2.y; z -= v2.z;
}
Vecteur3D Vecteur3D::operator-(Vecteur3D const& v2){
    Vecteur3D v3(x-v2.x,y-v2.y,z-v2.z);
    return v3;
}
Vecteur3D Vecteur3D::operator^(Vecteur3D const& v){
Vecteur3D v3(z*v.y-v.z*y,x*v.z-z*v.x,v.x*y-x*v.y);
    return v3;
}
bool Vecteur3D::operator==(const Vecteur3D& v) {
    bool verif = false;
    if ((abs(x - v.x) < D()) && (abs(y - v.y) < D()) && (abs(z - v.z) < D())) {
        verif = true;
        cout << "Les 2 vecteurs  sont egaux" << endl;
    } else {
        cout << "Les 2 vecteurs ne sont pas egaux " << endl;
    }
    return verif;
}
double Vecteur3D::operator%(Vecteur3D const& v2){
    return (x*v2.x+y*v2.y+z*v2.z);
}
Vecteur3D Vecteur3D::operator~(){
    Vecteur3D u(x/norme(),y/norme(),z/norme());
    return u;
}
Vecteur3D Vecteur3D::vect_mult(double a){
    Vecteur3D vD (a*x, a*y , a*z);
    return vD;
}
double Vecteur3D::norme() const {
    //cout<<"la norme vaut : "<<sqrt( x*x + y*y + z*z)<<endl;
    return (sqrt( x*x + y*y + z*z));
}
double Vecteur3D::norme2() const {
    cout<<"la norme au carré vaut : "<< x*x + y*y + z*z<<endl;
    return ( x*x + y*y + z*z);
}
ostream& operator<<(ostream& sortie , Vecteur3D const& v){
    sortie<<' '<< v.get_x() << ' '<< v.get_y() <<' '<< v.get_z() <<";";
    return sortie;
}
void Vecteur3D::set_coord(int coord, double neew){
    switch (coord){
        case 0 :
        x=neew;
        break;

        case 1 :
        y=neew;
        break;

        case 2 :
        z=neew;
        break;

        default:
        break;
    }
}
 double Vecteur3D::get_coord(int coord){
        switch (coord){
        case 0 :
        return x;
        break;

        case 1 :
        return y;
        break;

        case 2 :
        return z;
        break;

        default:
        break;

    }
 }


