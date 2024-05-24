#pragma once
#include "particule.h"
#include<iostream>

class Neon :  public Particule{
    public:
    virtual void dessine_sur(SupportADessin& support) override
    {
        support.dessine(*this); }
    Neon(Vecteur3D pos, Vecteur3D vit, double m): Particule(pos,vit,m){}
};