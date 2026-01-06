#ifndef OBJET_H
#define OBJET_H
#include "Dictionnaire.h"
#include "Image.h"
#include "Tuile.h"
#include <string>

using namespace std;

// Part 3, Questions 9-11: Classe Objet pour un element du niveau
class Objet {
private:
  Image _img;
  int _x;
  int _y;
  Tuile _tuile;

public:
  // Constructeur par defaut
  Objet();

  // Q10: Constructeur avec parametres
  Objet(const Image &img, const string &nom, Dictionnaire &dict, int x, int y);

  // Q11: Dessiner l'objet
  void dessiner() const;

  // Getters pour la collision
  int getX() const;
  int getY() const;
  string getPropriete() const;

  // Q18-19: Modifier la propriete de la tuile
  void setPropriete(const string &p);
};

#endif
