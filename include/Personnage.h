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

  // Question 6-8: Regarder dans une direction
  void regarderDroite();
  void regarderGauche();
  void regarderHaut();
  void regarderBas();

  // Question 16: Deplacer le personnage
  void deplacer(int dx, int dy);

  // Question 20-21: Verifier si le personnage peut bouger (bords de l'ecran)
  bool peutBougerVers(Direction dir) const;

  // Question 20-21 Part 3 (Q16): Verifier avec collision niveau
  bool peutBougerVers(Direction dir, const Niveau &niveau) const;

  // Question 23: Getters et inversion de direction pour les ennemis
  Direction getDirection() const;
  void inverserDirection();

  // Getters pour les coordonnees (collision)
  int getX() const;
  int getY() const;
};
#endif