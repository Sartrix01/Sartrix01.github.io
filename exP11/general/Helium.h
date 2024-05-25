#pragma once
#include "particule.h"
#include<iostream>
class Helium :  public Particule{
    public:
    virtual void add(Vecteur3D v) override{};
    virtual void dessine_sur(SupportADessin& support) override
    {
        support.dessine(*this); }
    Helium(Vecteur3D pos, Vecteur3D vit, double m): Particule(pos,vit,m){}
};
