mak #include "Avatar.h"
#include "Ennemie.h"
#include "Niveau.h"
#include "Personnage.h"
#include <iostream>

    using namespace std;

Avatar::Avatar(const Image &img, int x, int y, int dir, int skin_x,
               int skin_y) {
  Personnage Perso(img, x, y, dir, skin_x, skin_y);
  _perso = Perso;
}

void Avatar::display(int l, int h) const { _perso.display(l, h); }

// Question 18-19: Aller a droite (tourner + bouger si possible)
void Avatar::allerDroite() {
  _perso.regarderDroite();
  if (_perso.peutBougerVers(DROITE)) {
    _perso.deplacer(TAILLE_CASE, 0);
  }
}

void Avatar::allerGauche() {
  _perso.regarderGauche();
  if (_perso.peutBougerVers(GAUCHE)) {
    _perso.deplacer(-TAILLE_CASE, 0);
  }
}

void Avatar::allerHaut() {
  _perso.regarderHaut();
  if (_perso.peutBougerVers(HAUT)) {
    _perso.deplacer(0, -TAILLE_CASE);
  }
}

void Avatar::allerBas() {
  _perso.regarderBas();
  if (_perso.peutBougerVers(BAS)) {
    _perso.deplacer(0, TAILLE_CASE);
  }
}

// Question 18-21 avec collision niveau (Part 3 Q16)
void Avatar::allerDroite(const Niveau &niveau) {
  _perso.regarderDroite();
  if (_perso.peutBougerVers(DROITE, niveau)) {
    _perso.deplacer(TAILLE_CASE, 0);
  }
}

void Avatar::allerGauche(const Niveau &niveau) {
  _perso.regarderGauche();
  if (_perso.peutBougerVers(GAUCHE, niveau)) {
    _perso.deplacer(-TAILLE_CASE, 0);
  }
}

void Avatar::allerHaut(const Niveau &niveau) {
  _perso.regarderHaut();
  if (_perso.peutBougerVers(HAUT, niveau)) {
    _perso.deplacer(0, -TAILLE_CASE);
  }
}

void Avatar::allerBas(const Niveau &niveau) {
  _perso.regarderBas();
  if (_perso.peutBougerVers(BAS, niveau)) {
    _perso.deplacer(0, TAILLE_CASE);
  }
}

// Question 25: Tester collision avec un ennemi
bool Avatar::touche(const Ennemie &ennemi) const {
  // Collision si meme position
  return (_perso.getX() == ennemi.getX() && _perso.getY() == ennemi.getY());
}

// Getters
int Avatar::getX() const { return _perso.getX(); }

int Avatar::getY() const { return _perso.getY(); }