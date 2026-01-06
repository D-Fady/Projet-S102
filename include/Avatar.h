#ifndef AVATAR_H
#define AVATAR_H
#include "Personnage.h"

class Niveau;  // Declaration anticipee
class Ennemie; // Declaration anticipee

class Avatar {
  Personnage _perso;

public:
  Avatar(const Image &img, int x, int y, int dir, int skin_x, int skin_y);
  void display(int l, int h) const;

  // Question 18-19: Methodes de deplacement (tourne + bouge)
  void allerDroite();
  void allerGauche();
  void allerHaut();
  void allerBas();

  // Question 18-21 avec collision niveau
  void allerDroite(const Niveau &niveau);
  void allerGauche(const Niveau &niveau);
  void allerHaut(const Niveau &niveau);
  void allerBas(const Niveau &niveau);

  // Question 25: Tester si on touche un ennemi
  bool touche(const Ennemie &ennemi) const;

  // Getters pour acceder aux coordonnees
  int getX() const;
  int getY() const;
};

#endif