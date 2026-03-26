#include "Niveau.h"
#include <fstream>
#include <iostream>

using namespace std;

Niveau::Niveau(const string &fichier, const Image &img, Dictionnaire &dict) {
  _nbBonus = 0;

  ifstream file(fichier);
  if (!file.is_open()) {
    cerr << "Erreur: impossible d'ouvrir " << fichier << endl;
    return;
  }

  // lis le nombre d'objets sur la premiere ligne
  int nbObjets;
  file >> nbObjets;

  // lis chaque ligne nom x y
  for (int i = 0; i < nbObjets; i++) {
    string nom;
    int x, y;

    file >> nom >> x >> y;

    // cree l'objet et l'ajoute au vecteur
    Objet objet(img, nom, dict, x, y);
    _objets.push_back(objet);

    // Q17 compte les bonus
    if (objet.getPropriete() == "bonus") {
      _nbBonus++;
    }
  }

  file.close();
}

// Q13 dessine tous les objets du niveau -->
// --> Q21 ne dessine pas les objets avec propriete "cache"
void Niveau::dessiner() const {
  for (size_t i = 0; i < _objets.size(); i++) {
    // ignore les objets caches
    if (_objets[i].getPropriete() != "cache") {
      _objets[i].dessiner();
    }
  }
}

bool Niveau::caseEstLibre(int x, int y) const {
  for (size_t i = 0; i < _objets.size(); i++) {
    // verifie si l'objet est aux memes coordonnees
    if (_objets[i].getX() == x && _objets[i].getY() == y) {
      // verifie si l'objet est solide
      if (_objets[i].getPropriete() == "solide") {
        return false; // case occupee par un objet solide
      }
    }
  }
  return true; // case libre
}

void Niveau::testerBonusEtPrendre(int x, int y) {
  for (size_t i = 0; i < _objets.size(); i++) {
    // verifie si l'objet est aux memes coordonnees
    if (_objets[i].getX() == x && _objets[i].getY() == y) {
      // verifie si c'est un bonus
      if (_objets[i].getPropriete() == "bonus") {
        // si le joueur prend le bonus sa change sa propriete en "cache"
        _objets[i].setPropriete("cache");
        _nbBonus--;
      }
    }
  }
}

bool Niveau::gagne() const { return (_nbBonus == 0); }

int Niveau::getNbBonus() const { return _nbBonus; }
