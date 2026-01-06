#include "Personnage.h"
#include "Image.h"
#include "Niveau.h"
#include <SDL.h>
#include <iostream>

using namespace std;

// Constructeur par defaut (necessaire pour les attributs de classe)
Personnage::Personnage() {
  _x = 0;
  _y = 0;
  _direction = BAS;
  _skin_x = 0;
  _skin_y = 0;
}

// Constructeur avec parametres (Q10-11: avec skin_x et skin_y)
Personnage::Personnage(const Image &img, int x, int y, int dir, int skin_x,
                       int skin_y) {
  _img = img;
  _x = x * TAILLE_CASE; // Convertir en pixels
  _y = y * TAILLE_CASE;
  _direction = dir;
  _skin_x = skin_x;
  _skin_y = skin_y;
}

void Personnage::display(int l, int h) const {
  _img.dessiner(_x, _y, _skin_x * 16, (_skin_y + _direction) * 16, l * 16,
                h * 16);
}

// Question 6-8: Methodes pour changer la direction
void Personnage::regarderDroite() { _direction = DROITE; }

void Personnage::regarderGauche() { _direction = GAUCHE; }

void Personnage::regarderHaut() { _direction = HAUT; }

void Personnage::regarderBas() { _direction = BAS; }

// Question 16: Deplacer le personnage
void Personnage::deplacer(int dx, int dy) {
  _x += dx;
  _y += dy;
}

// Question 20-21: Verifier si on peut bouger (bords de l'ecran seulement)
bool Personnage::peutBougerVers(Direction dir) const {
  switch (dir) {
  case GAUCHE:
    return (_x - TAILLE_CASE >= 0);
  case DROITE:
    return (_x + TAILLE_CASE < LARGEUR_FENETRE);
  case HAUT:
    return (_y - TAILLE_CASE >= 0);
  case BAS:
    return (_y + TAILLE_CASE < HAUTEUR_FENETRE);
  default:
    return false;
  }
}

// Question 16 Part 3: Verifier avec collision niveau (sera complete dans Part
// 3)
bool Personnage::peutBougerVers(Direction dir, const Niveau &niveau) const {
  // D'abord verifier les bords de l'ecran
  if (!peutBougerVers(dir)) {
    return false;
  }

  // Calculer la case de destination
  int nextX = _x / TAILLE_CASE;
  int nextY = _y / TAILLE_CASE;

  switch (dir) {
  case GAUCHE:
    nextX--;
    break;
  case DROITE:
    nextX++;
    break;
  case HAUT:
    nextY--;
    break;
  case BAS:
    nextY++;
    break;
  }

  // Verifier si la case est libre dans le niveau
  return niveau.caseEstLibre(nextX, nextY);
}

// Question 23: Obtenir la direction actuelle
Direction Personnage::getDirection() const {
  return static_cast<Direction>(_direction);
}

// Question 23: Inverser la direction (pour les ennemis)
void Personnage::inverserDirection() {
  switch (_direction) {
  case GAUCHE:
    _direction = DROITE;
    break;
  case DROITE:
    _direction = GAUCHE;
    break;
  case HAUT:
    _direction = BAS;
    break;
  case BAS:
    _direction = HAUT;
    break;
  }
}

// Getters pour les coordonnees (pour la collision)
int Personnage::getX() const { return _x; }

int Personnage::getY() const { return _y; }