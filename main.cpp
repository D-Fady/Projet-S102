#include "Dictionnaire.h"
#include <fstream>
#include <iostream>

using namespace std;

Dictionnaire::Dictionnaire(const string &fichier) {
  ifstream file(fichier);
  if (!file.is_open()) {
    cerr << "Erreur: impossible d'ouvrir " << fichier << endl;
    return;
  }

  // lis le nombre d'elements sur la premiere ligne
  int nbElements;
  file >> nbElements;

  // lis chaque ligne nom x y propriete
  for (int i = 0; i < nbElements; i++) {
    string nom;
    int x, y;
    string propriete;

    file >> nom >> x >> y >> propriete;

    // cree et ajoute la tuile au vecteur
    Tuile tuile(nom, x, y, propriete);
    _tuiles.push_back(tuile);
  }

  file.close();
}

void Dictionnaire::afficher() const {
  for (size_t i = 0; i < _tuiles.size(); i++) {
    _tuiles[i].afficher();
  }
}

// Q7-8 recherche dichotomique
// le dictionnaire est trie par ordre alphabetique
bool Dictionnaire::recherche(const string &nom, Tuile &resultat) const {
  int debut = 0;
  int fin = _tuiles.size() - 1;

  // recherche dichotomique
  while (debut <= fin) {
    int milieu = (debut + fin) / 2;
    string nomMilieu = _tuiles[milieu].getNom();

    if (nomMilieu == nom) {
      resultat = _tuiles[milieu];
      return true;
    } else if (nomMilieu < nom) {
      debut = milieu + 1;
    } else {
      fin = milieu - 1;
    }
  }

  return false;
}
