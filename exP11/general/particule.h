#pragma once
#include "dessinable.h"
#include "support_a_dessin.h"
#include "vecteur3D.h"


class Particule : public Dessinable {
public:
  Particule(Vecteur3D position , Vecteur3D vitesse , double masse): pos(position) , vit(vitesse), m(masse) {}
  virtual ~Particule() = default;
  Particule(Particule const&)            = default;
  Particule& operator=(Particule const&) = default;
  Particule(Particule&&)                 = default;
  Particule& operator=(Particule&&)      = default;
  Vecteur3D get_pos() const {return pos ;}
  Vecteur3D get_vit() const {return vit ;}
  void paroi(double h , int rang , double pos , double vit  );
  bool rencontre(Particule&  p2 , double e );
  void set_vit(Vecteur3D v );
  void evolue(double dt);

  // accesseur
  double infos() const { return m; }

private:
  double m;
  Vecteur3D pos;
  Vecteur3D vit;
};
