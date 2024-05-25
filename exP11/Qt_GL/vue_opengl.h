#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "support_a_dessin.h"
#include "glsphere.h"

class Enceinte;
class Neon;
class Argon;
class Helium;
class Trainee;
class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineSphere(QMatrix4x4 const& point_de_vue,double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineCube_(int longueur, int largeur, int hauteur);

  virtual void dessine(Enceinte const& a_dessiner) override;
  virtual void dessine( Argon const& a_dessiner) override;
  virtual void dessine( Neon   const& a_dessiner) override;
  virtual void dessine(Trainee const& a_dessiner) override;
  virtual void dessine(Helium const& a_dessiner) override;


 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere sphere;
  // Caméra
  QMatrix4x4 matrice_vue;
};
