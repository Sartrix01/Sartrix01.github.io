#pragma once
#include <iostream>
#include <vector>
#include "particule.h"

class Trainee :  public Particule{
    public:
    virtual void dessine_sur(SupportADessin& support) override
    {
        support.dessine(*this);
    }
    Trainee(Vecteur3D pos, Vecteur3D vit, double m): Particule(pos,vit,m){}
    void add(Vecteur3D point){
        point_memories.push_back(point);
    }
    private:
    std::vector<Vecteur3D> point_memories;

};
