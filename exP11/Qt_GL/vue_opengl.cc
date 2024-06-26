#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "systeme.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "trainee.h"
#include "glsphere.h"
#include <iostream>


// ======================================================================
void VueOpenGL::dessine(Enceinte const& a_dessiner)
{
   // Dessine le 1er cube (à l'origine)

  QMatrix4x4 matrice;
  // Dessine le 2e cube
  matrice.setToIdentity();
  matrice.translate(0, 0.0, 0.0);
  matrice.scale(a_dessiner.get_enceinte(0));
  matrice.rotate(0.5,-10,0.5);
  dessineCube_(a_dessiner.get_enceinte(0),a_dessiner.get_enceinte(1),a_dessiner.get_enceinte(2));


}
void VueOpenGL::dessine(Neon const& a_dessiner){
    QMatrix4x4 matrice;
    // Dessine le 3e cube
    matrice.setToIdentity();
    matrice.translate(a_dessiner.get_pos().get_x(), a_dessiner.get_pos().get_y(),a_dessiner.get_pos().get_z());
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.0, 0.0);
}
void VueOpenGL::dessine(Argon const& a_dessiner){
    QMatrix4x4 matrice;
    // Dessine le 4e cube
    matrice.setToIdentity();
    matrice.translate(a_dessiner.get_pos().get_x(), a_dessiner.get_pos().get_y(),a_dessiner.get_pos().get_z());
    matrice.scale(0.05);
    dessineSphere(matrice, 0.0, 1.0, 0.0);
}
void VueOpenGL::dessine(Helium const& a_dessiner){
    QMatrix4x4 matrice;
    // Dessine le 4e cube
    matrice.setToIdentity();
    matrice.translate(a_dessiner.get_pos().get_x(), a_dessiner.get_pos().get_y(),a_dessiner.get_pos().get_z());
    matrice.scale(0.05);
    dessineSphere(matrice, 0.0, 0.0, 1.0);
}
void VueOpenGL::dessine(Trainee const& a_dessiner){
    QMatrix4x4 matrice;
    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue);
    glBegin(GL_LINE_STRIP);
    for (auto const& point : a_dessiner.nuages_points()) {
        prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
        glVertex3f(point.get_x(), point.get_y(), point.get_z());
    }
    glEnd();
    // Dessine le 4e cube

    matrice.translate(a_dessiner.get_pos().get_x(), a_dessiner.get_pos().get_y(),a_dessiner.get_pos().get_z());
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 1.0, 1.0);

}
void VueOpenGL::dessineSphere(const QMatrix4x4 &point_de_vue, double rouge, double vert, double bleu){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
    sphere.draw(prog, SommetId);                           // dessine la sphère
}

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();                                      // initialise la sphère
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(-0.5,-0.25, -5.0);
  matrice_vue.rotate(0, 0, 0, 0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}
void VueOpenGL::dessineCube_(int longueur, int largeur, int hauteur)
{
    prog.setUniformValue("vue_modele", matrice_vue);

    glBegin(GL_LINES);

    // Arêtes horizontales du bas
    glVertex3f(0, 0, 0);
    glVertex3f(longueur, 0, 0);

    glVertex3f(longueur, 0, 0);
    glVertex3f(longueur, 0, largeur);

    glVertex3f(longueur, 0, largeur);
    glVertex3f(0, 0, largeur);

    glVertex3f(0, 0, largeur);
    glVertex3f(0, 0, 0);

    // Arêtes verticales
    glVertex3f(0, 0, 0);
    glVertex3f(0, hauteur, 0);

    glVertex3f(longueur, 0, 0);
    glVertex3f(longueur, hauteur, 0);

    glVertex3f(longueur, 0, largeur);
    glVertex3f(longueur, hauteur, largeur);
    glVertex3f(0, 0, largeur);
    glVertex3f(0, hauteur, largeur);

    // Arêtes horizontales du haut
    glVertex3f(0, hauteur, 0);
    glVertex3f(longueur, hauteur, 0);

    glVertex3f(longueur, hauteur, 0);
    glVertex3f(longueur, hauteur, largeur);

    glVertex3f(longueur, hauteur, largeur);
    glVertex3f(0, hauteur, largeur);

    glVertex3f(0, hauteur, largeur);
    glVertex3f(0, hauteur, 0);

    glEnd();
}
