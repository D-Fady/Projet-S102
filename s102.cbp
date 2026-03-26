#include "Objet.h"
#include "Moteur.h"
#include <iostream>

using namespace std;

Objet::Objet() {
  _x = 0;
  _y = 0;
}

Objet::Objet(const Image &img, const string &nom, Dictionnaire &dict, int x,
             int y) {
  _img = img;
  _x = x;
  _y = y;

  // rechercher la tuile dans le dictionnaire
  Tuile tuile;
  if (dict.recherche(nom, tuile)) {
    _tuile = tuile;
  } else {
    cerr << "Erreur: tuile '" << nom << "' non trouvee dans le dictionnaire"
         << endl;
  }
}

void Objet::dessiner() const {
  _img.dessiner(_x * TAILLE_CASE, _y * TAILLE_CASE, _tuile.getX() * TAILLE_CASE,
                _tuile.getY() * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}

// getters
int Objet::getX() const { return _x; }

int Objet::getY() const { return _y; }

string Objet::getPropriete() const { return _tuile.getPropriete(); }

// Q18-19 modifie la propriete
void Objet::setPropriete(const string &p) { _tuile.setPropriete(p); }
