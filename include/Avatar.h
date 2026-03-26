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

  void allerDroite();
  void allerGauche();
  void allerHaut();
  void allerBas();

  void allerDroite(const Niveau &niveau);
  void allerGauche(const Niveau &niveau);
  void allerHaut(const Niveau &niveau);
  void allerBas(const Niveau &niveau);

  bool touche(const Ennemie &ennemi) const;

  int getX() const;
  int getY() const;
};

#endif