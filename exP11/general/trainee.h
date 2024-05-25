#pragma once
#include <iostream>
#include <vector>
#include "particule.h"

class Trainee :  public Particule{
    private:
    std::vector<Vecteur3D> points_memorises;
    public:
    virtual void dessine_sur(SupportADessin& support) override
    {
        support.dessine(*this);
    }
    Trainee(Vecteur3D pos, Vecteur3D vit, double m): Particule(pos,vit,m,true){}
    virtual void add(Vecteur3D point) override{
        points_memorises.push_back(point);
    }
    std::vector<Vecteur3D> nuages_points()const{return points_memorises;};

};
