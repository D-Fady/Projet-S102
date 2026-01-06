#include "Dictionnaire.h"
#include <fstream>
#include <iostream>

using namespace std;

// Part 3, Q4: Constructeur qui charge le fichier
Dictionnaire::Dictionnaire(const string &fichier) {
  ifstream file(fichier);
  if (!file.is_open()) {
    cerr << "Erreur: impossible d'ouvrir " << fichier << endl;
    return;
  }

  // Lire le nombre d'elements sur la premiere ligne
  int nbElements;
  file >> nbElements;

  // Lire chaque ligne: nom x y propriete
  for (int i = 0; i < nbElements; i++) {
    string nom;
    int x, y;
    string propriete;

    file >> nom >> x >> y >> propriete;

    // Creer et ajouter la tuile au vecteur
    Tuile tuile(nom, x, y, propriete);
    _tuiles.push_back(tuile);
  }

  file.close();
}

// Part 3, Q5: Afficher toutes les tuiles
void Dictionnaire::afficher() const {
  for (size_t i = 0; i < _tuiles.size(); i++) {
    _tuiles[i].afficher();
  }
}

// Part 3, Q7-8: Recherche dichotomique (binary search)
// Le dictionnaire est trie par ordre alphabetique
bool Dictionnaire::recherche(const string &nom, Tuile &resultat) const {
  int debut = 0;
  int fin = _tuiles.size() - 1;

  // Recherche dichotomique (binary search)
  while (debut <= fin) {
    int milieu = (debut + fin) / 2;
    string nomMilieu = _tuiles[milieu].getNom();

    if (nomMilieu == nom) {
      // Trouve!
      resultat = _tuiles[milieu];
      return true;
    } else if (nomMilieu < nom) {
      // Chercher dans la moitie droite
      debut = milieu + 1;
    } else {
      // Chercher dans la moitie gauche
      fin = milieu - 1;
    }
  }

  // Non trouve
  return false;
}
