#pragma once
#include <iostream>
#include "particule.h"

class Argon :  public Particule{
    public:
    virtual void add(Vecteur3D v) override{};
    virtual void dessine_sur(SupportADessin& support) override
    {
        support.dessine(*this);
    }
    Argon(Vecteur3D pos, Vecteur3D vit, double m): Particule(pos,vit,m){}
};


