#include "Tuile.h"
#include <iostream>

using namespace std;

Tuile::Tuile() {
  _nom = "";
  _x = 0;
  _y = 0;
  _propriete = "normal";
}

Tuile::Tuile(const string &nom, int x, int y, const string &propriete) {
  _nom = nom;
  _x = x;
  _y = y;
  _propriete = propriete;
}

void Tuile::afficher() const {
  cout << "Tuile: " << _nom << " (" << _x << ", " << _y << ") - " << _propriete
       << endl;
}

void Tuile::setPropriete(const string &p) { _propriete = p; }

// ggetters
string Tuile::getNom() const { return _nom; }

int Tuile::getX() const { return _x; }

int Tuile::getY() const { return _y; }

string Tuile::getPropriete() const { return _propriete; }
