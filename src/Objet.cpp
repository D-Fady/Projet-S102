#include "Objet.h"
#include "Moteur.h"
#include <iostream>

using namespace std;

// Constructeur par defaut
Objet::Objet() {
  _x = 0;
  _y = 0;
}

// Part 3, Q10: Constructeur avec parametres
Objet::Objet(const Image &img, const string &nom, Dictionnaire &dict, int x,
             int y) {
  _img = img;
  _x = x;
  _y = y;

  // Rechercher la tuile dans le dictionnaire
  Tuile tuile;
  if (dict.recherche(nom, tuile)) {
    _tuile = tuile;
  } else {
    cerr << "Erreur: tuile '" << nom << "' non trouvee dans le dictionnaire"
         << endl;
  }
}

// Part 3, Q11: Dessiner l'objet a ses coordonnees
void Objet::dessiner() const {
  // Dessiner la portion de l'image correspondant a la tuile
  // Les coordonnees de la tuile (x,y) sont en cases dans l'image objets.png
  _img.dessiner(_x * TAILLE_CASE, _y * TAILLE_CASE, _tuile.getX() * TAILLE_CASE,
                _tuile.getY() * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}

// Getters
int Objet::getX() const { return _x; }

int Objet::getY() const { return _y; }

string Objet::getPropriete() const { return _tuile.getPropriete(); }

// Q18-19: Modifier la propriete
void Objet::setPropriete(const string &p) { _tuile.setPropriete(p); }
