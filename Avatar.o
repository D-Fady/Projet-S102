#ifndef NIVEAU_H
#define NIVEAU_H
#include "Dictionnaire.h"
#include "Image.h"
#include "Objet.h"
#include <string>
#include <vector>

using namespace std;

class Niveau {
private:
  vector<Objet> _objets;
  int _nbBonus; // compteur de bonus

public:
  Niveau(const string &fichier, const Image &img, Dictionnaire &dict);

  void dessiner() const;

  bool caseEstLibre(int x, int y) const;

  void testerBonusEtPrendre(int x, int y);

  bool gagne() const;

  int getNbBonus() const;
};

#endif
