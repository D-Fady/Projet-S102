#ifndef NIVEAU_H
#define NIVEAU_H
#include "Dictionnaire.h"
#include "Image.h"
#include "Objet.h"
#include <string>
#include <vector>

using namespace std;

// Part 3, Questions 12-25: Classe Niveau pour gerer le niveau du jeu
class Niveau {
private:
  vector<Objet> _objets;
  int _nbBonus; // Q17: Compteur de bonus

public:
  // Q12: Constructeur qui charge le fichier niveau
  Niveau(const string &fichier, const Image &img, Dictionnaire &dict);

  // Q13: Dessiner tous les objets du niveau
  void dessiner() const;

  // Q15: Verifier si une case est libre (pas d'objet solide)
  bool caseEstLibre(int x, int y) const;

  // Q19: Tester si un bonus est present et le prendre
  void testerBonusEtPrendre(int x, int y);

  // Q24: Verifier si tous les bonus ont ete collectes
  bool gagne() const;

  // Getter pour le nombre de bonus restants
  int getNbBonus() const;
};

#endif
