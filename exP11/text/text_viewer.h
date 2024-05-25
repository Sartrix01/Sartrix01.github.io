#pragma once

#include <iostream>
#include "support_a_dessin.h"
class Argon;
class Enceinte;
class Neon;
class Helium;
class Trainee;
class TextViewer : public SupportADessin {
public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  TextViewer(TextViewer const&)            = delete;
  TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  TextViewer(TextViewer&&)            = default;
  TextViewer& operator=(TextViewer&&) = default;

  virtual void dessine(Argon const& a_dessiner) override;
  virtual void dessine(Neon const& a_dessiner) override;
  virtual void dessine(Enceinte const& a_dessiner) override;
  virtual void dessine(Helium const& a_dessiner) override;
  virtual void dessine(Trainee const& a_dessiner) override;

private:
  std::ostream& flot;
};
