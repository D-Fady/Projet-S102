#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Image.h"
#include <SDL.h>
#include <iostream>

// Question 6: Enum pour les directions
enum Direction { BAS = 0, GAUCHE = 1, DROITE = 2, HAUT = 3 };

class Niveau; // Declaration anticipee pour Q16 Part 3

class Personnage {
private:
  Image _img;
  int _x;
  int _y;
  int _direction;
  int _skin_x;
  int _skin_y;

public:
  Personnage();
  Personnage(const Image &img, int x, int y, int dir, int skin_x, int skin_y);

  void display(int l, int h) const;

  void regarderDroite();
  void regarderGauche();
  void regarderHaut();
  void regarderBas();

  void deplacer(int dx, int dy);

  bool peutBougerVers(Direction dir) const;

  bool peutBougerVers(Direction dir, const Niveau &niveau) const;

  Direction getDirection() const;
  void inverserDirection();

  int getX() const;
  int getY() const;
};
#endif