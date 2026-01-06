#include "Ennemie.h"
#include "Image.h"
#include "Niveau.h"
#include "Personnage.h"
#include <SDL.h>
#include <iostream>

using namespace std;

Ennemie::Ennemie(const Image &img, int x, int y, int dir, int skin_x,
                 int skin_y) {
  _perso = Personnage(img, x, y, dir, skin_x, skin_y);
}

void Ennemie::display(int l, int h) const { _perso.display(l, h); }

// Question 23: Avancer dans la direction courante, inverser si bord atteint
void Ennemie::avancer() {
  Direction dir = _perso.getDirection();

  // Si on ne peut pas bouger, inverser la direction
  if (!_perso.peutBougerVers(dir)) {
    _perso.inverserDirection();
    dir = _perso.getDirection();
  }

  // Bouger dans la nouvelle direction
  switch (dir) {
  case GAUCHE:
    _perso.deplacer(-TAILLE_CASE, 0);
    break;
  case DROITE:
    _perso.deplacer(TAILLE_CASE, 0);
    break;
  case HAUT:
    _perso.deplacer(0, -TAILLE_CASE);
    break;
  case BAS:
    _perso.deplacer(0, TAILLE_CASE);
    break;
  }
}

// Question 23 avec collision niveau (Part 3 Q16)
void Ennemie::avancer(const Niveau &niveau) {
  Direction dir = _perso.getDirection();

  // Si on ne peut pas bouger, inverser la direction
  if (!_perso.peutBougerVers(dir, niveau)) {
    _perso.inverserDirection();
    dir = _perso.getDirection();
  }

  // Bouger dans la nouvelle direction si possible
  if (_perso.peutBougerVers(dir, niveau)) {
    switch (dir) {
    case GAUCHE:
      _perso.deplacer(-TAILLE_CASE, 0);
      break;
    case DROITE:
      _perso.deplacer(TAILLE_CASE, 0);
      break;
    case HAUT:
      _perso.deplacer(0, -TAILLE_CASE);
      break;
    case BAS:
      _perso.deplacer(0, TAILLE_CASE);
      break;
    }
  }
}

// Getters pour la collision
int Ennemie::getX() const { return _perso.getX(); }

int Ennemie::getY() const { return _perso.getY(); }