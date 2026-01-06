#ifndef ENNEMIE_H
#define ENNEMIE_H
#include "Image.h"
#include "Personnage.h"
#include <SDL.h>
#include <iostream>

class Niveau; // Declaration anticipee

class Ennemie {
  Personnage _perso;

public:
  Ennemie(const Image &img, int x, int y, int dir, int skin_x, int skin_y);
  void display(int l, int h) const;

  // Question 23: Avancer automatiquement et inverser si bord atteint
  void avancer();

  // Question 23 avec collision niveau
  void avancer(const Niveau &niveau);

  // Getters pour la collision avec l'avatar
  int getX() const;
  int getY() const;
};

#endif