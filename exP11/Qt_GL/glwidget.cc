#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidget.h"
#include "enceinte.h"
#include "particule.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "trainee.h"
#include <iostream>


GLWidget::GLWidget(QWidget* parent)
  : QOpenGLWidget(parent)
{   chronometre.restart();
    /*Helium* h = new Helium({1,1,1},{0,0,0}, 4.002602);
    Neon* n= new Neon({1,1.5,1},{0,0.2,0},20.1797);
    Argon* a=new Argon({1,1,3.1},{0,0,-0.5},39.948);
    Helium* h_ = new Helium({0,1,1},{0,0,0}, 4.002602);
    Neon* n_= new Neon({0,1.5,1},{10,0.2,0},20.1797);
    Trainee* t= new Trainee({0.0,0.0,0},{1.0,1.0,0},20.1797);
    Argon* a_=new Argon({0,1,3.1},{0,0,0.5},39.948);

    c.ajoute(a_);
    c.ajoute(n_);
    c.ajoute(h_);
    c.ajoute(a);
    c.ajoute(n);
    c.ajoute(h);
    c.ajoute(t);*/
    c.alea_part("Helium",20,250);
    c.alea_part("Argon",20,250);

}

// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
  timerId = startTimer(20);
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  /* On commance par dire sur quelle partie de la 
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur 
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   * Plus de détail sur cette matrice
   *     http://www.songho.ca/opengl/gl_projectionmatrix.html
   * Puis on upload la matrice sur le shader à l'aide de la
   * méthode de la classe VueOpenGL
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  c.dessine_e(vue);
  c.dessine_sur(vue);
}


// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);

  switch (event->key()) {

  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
	pause();
	break;
  };

  update(); // redessine
}

// ======================================================================
void GLWidget::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  const double dt = chronometre.elapsed() / 1000.0;
  chronometre.restart();

  c.evolue(dt,0.1);
  update();
}

// ======================================================================
void GLWidget::pause()
{
  if (timerId == 0) {
	// dans ce cas le timer ne tourne pas alors on le lance
	timerId = startTimer(20);
	chronometre.restart();
  } else {
	// le timer tourne alors on l'arrête
	killTimer(timerId);
	timerId = 0;
  }
}