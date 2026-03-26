#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include "Tuile.h"
#include <string>
#include <vector>

using namespace std;

class Dictionnaire {
private:
  vector<Tuile> _tuiles;

public:
  Dictionnaire(const string &fichier);

  void afficher() const;

  bool recherche(const string &nom, Tuile &resultat) const;
};

#endif
