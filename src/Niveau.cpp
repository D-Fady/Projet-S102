#include "Niveau.h"
#include <fstream>
#include <iostream>

using namespace std;

// Part 3, Q12: Constructeur qui charge le fichier niveau
Niveau::Niveau(const string &fichier, const Image &img, Dictionnaire &dict) {
  _nbBonus = 0;

  ifstream file(fichier);
  if (!file.is_open()) {
    cerr << "Erreur: impossible d'ouvrir " << fichier << endl;
    return;
  }

  // Lire le nombre d'objets sur la premiere ligne
  int nbObjets;
  file >> nbObjets;

  // Lire chaque ligne: nom x y
  for (int i = 0; i < nbObjets; i++) {
    string nom;
    int x, y;

    file >> nom >> x >> y;

    // Creer l'objet et l'ajouter au vecteur
    Objet objet(img, nom, dict, x, y);
    _objets.push_back(objet);

    // Q17: Compter les bonus
    if (objet.getPropriete() == "bonus") {
      _nbBonus++;
    }
  }

  file.close();
}

// Part 3, Q13: Dessiner tous les objets du niveau
// Q21: Ne pas dessiner les objets avec propriete "cache"
void Niveau::dessiner() const {
  for (size_t i = 0; i < _objets.size(); i++) {
    // Q21: Ignorer les objets caches
    if (_objets[i].getPropriete() != "cache") {
      _objets[i].dessiner();
    }
  }
}

// Part 3, Q15: Verifier si une case est libre
bool Niveau::caseEstLibre(int x, int y) const {
  for (size_t i = 0; i < _objets.size(); i++) {
    // Verifier si l'objet est aux memes coordonnees
    if (_objets[i].getX() == x && _objets[i].getY() == y) {
      // Verifier si l'objet est solide
      if (_objets[i].getPropriete() == "solide") {
        return false; // Case occupee par un objet solide
      }
    }
  }
  return true; // Case libre
}

// Part 3, Q19: Tester si un bonus est present et le prendre
void Niveau::testerBonusEtPrendre(int x, int y) {
  for (size_t i = 0; i < _objets.size(); i++) {
    // Verifier si l'objet est aux memes coordonnees
    if (_objets[i].getX() == x && _objets[i].getY() == y) {
      // Verifier si c'est un bonus
      if (_objets[i].getPropriete() == "bonus") {
        // Prendre le bonus: changer sa propriete en "cache"
        _objets[i].setPropriete("cache");
        _nbBonus--;
      }
    }
  }
}

// Part 3, Q24: Verifier si tous les bonus ont ete collectes
bool Niveau::gagne() const { return (_nbBonus == 0); }

// Getter pour le nombre de bonus restants
int Niveau::getNbBonus() const { return _nbBonus; }
