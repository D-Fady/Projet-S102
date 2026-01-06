#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include "Tuile.h"
#include <string>
#include <vector>

using namespace std;

// Part 3, Questions 4-8: Classe Dictionnaire pour charger et rechercher les
// tuiles
class Dictionnaire {
private:
  vector<Tuile> _tuiles;

public:
  // Q4: Constructeur qui charge le fichier
  Dictionnaire(const string &fichier);

  // Q5: Afficher toutes les tuiles
  void afficher() const;

  // Q7-8: Recherche dichotomique (le fichier est trie alphabetiquement)
  bool recherche(const string &nom, Tuile &resultat) const;
};

#endif
