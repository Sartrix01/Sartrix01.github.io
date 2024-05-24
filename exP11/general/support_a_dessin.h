#pragma once

class Argon;
class Enceinte;
class Neon;
class Helium;
class Trainee;
class SupportADessin
{
 public:
  virtual ~SupportADessin() = default;
  // on ne copie pas les Supports
  SupportADessin(SupportADessin const&)            = delete;
  SupportADessin& operator=(SupportADessin const&) = delete;
   // mais on peut les déplacer
  SupportADessin(SupportADessin&&)            = default;
  SupportADessin& operator=(SupportADessin&&) = default;

  SupportADessin() = default;

  virtual void dessine(Argon const& a_dessiner) = 0;
  virtual void dessine(Neon const& a_dessiner) = 0;
  virtual void dessine(Enceinte const& a_dessiner)= 0;
  virtual void dessine(Helium const& a_dessiner)= 0;
  virtual void dessine(Trainee const& a_dessiner)= 0;
};
