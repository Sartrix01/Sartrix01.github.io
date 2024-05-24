#pragma once
#include "support_a_dessin.h"
#include <vector>
#include <cmath>
#include <string>
#include "Vecteur3D.h"

typedef double dimension;


class Enceinte{
public:
    protected:
        dimension h,l,p;/*h===z ; l === x ; p ===y*/
    private:
        coord x,y,z;
    public:
        Enceinte(dimension h=2,dimension l=2, dimension p=2,coord x=0, coord y=0, coord z=0): h(h),l(l),p(p),x(x),y(y),z(z){}
        double get_enceinte(int i ) const {
            switch (i)
            {
            case 0:
                return l;
                break;
            case 1:
                return p;
                break;
            case 2:
                return h;
                break;
                
            default:
                return 0;
                break;
            }
        }
    void dessine_sur(SupportADessin& support)
    { support.dessine(*this); }
};
