#include <iostream> // pour endl
#include "text_viewer.h"
#include "Neon.h"
#include "Argon.h"
#include "enceinte.h"
#include "Helium.h"

void TextViewer :: dessine(Neon const& neon)  {
    flot << "Particule Neon : pos : "<< neon.get_pos()<< " v : "<< neon.get_vit() << " m : "<< neon.infos() << std::endl;
}
void TextViewer ::  dessine(Argon const& argon)  {
    flot << "Particule Argon : pos : "<< argon.get_pos()<< " v : "<< argon.get_vit() << " m : "<< argon.infos() << std::endl;
}
void TextViewer :: dessine(Helium const& hel)  {
    flot << "Particule Helium : pos : "<< hel.get_pos()<< " v : "<< hel.get_vit() << " m : "<< hel.infos() << std::endl;
}
void TextViewer::dessine(Enceinte const& a_dessiner __attribute__((unused)))
{
  flot << "Bloc : immobile" << std::endl;
}
void TextViewer::dessine(Trainee const& a_dessiner)
{
  flot << "Bloc : immobile" << std::endl;
}
