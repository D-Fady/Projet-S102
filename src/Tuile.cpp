#include "Tuile.h"
#include <iostream>

using namespace std;

// Constructeur par defaut
Tuile::Tuile() {
  _nom = "";
  _x = 0;
  _y = 0;
  _propriete = "normal";
}

// Part 3, Q2: Constructeur avec parametres
Tuile::Tuile(const string &nom, int x, int y, const string &propriete) {
  _nom = nom;
  _x = x;
  _y = y;
  _propriete = propriete;
}

// Part 3, Q3: Afficher les attributs de la tuile
void Tuile::afficher() const {
  cout << "Tuile: " << _nom << " (" << _x << ", " << _y << ") - " << _propriete
       << endl;
}

// Part 3, Q18: Modifier la propriete
void Tuile::setPropriete(const string &p) { _propriete = p; }

// Getters
string Tuile::getNom() const { return _nom; }

int Tuile::getX() const { return _x; }

int Tuile::getY() const { return _y; }

string Tuile::getPropriete() const { return _propriete; }
