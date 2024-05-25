#pragma once
#include <vector>
#include <string>
#include "particule.h"
#include "dessinable.h"
#include "support_a_dessin.h"
#include "GenerateurAleatoire.h"
#include "enceinte.h"

class Systeme : public Dessinable {
public:
    Systeme(){}
  virtual ~Systeme() = default;
  Systeme(Systeme const&)            = default;
  Systeme& operator=(Systeme const&) = default;
  Systeme(Systeme&&)                 = default;
  Systeme& operator=(Systeme&&)      = default;

  virtual void dessine_sur(SupportADessin& support) override;
  void dessine_e(SupportADessin& support){
    enceinte.dessine_sur(support);
  };
  void dessine_sur_(SupportADessin& support);
  void alea_part(std::string element ,double T ,double nb );
  void evolue(double dt,double epsilon );
  void ajoute(Particule* particule) {
      collection.push_back(particule);
  }
  virtual void add(Vecteur3D v) override{};

private:
    std::vector<Particule*> collection;
    GenerateurAleatoire tirage;
    Enceinte enceinte;
};
