#ifndef OBJET_H
#define OBJET_H
#include "Dictionnaire.h"
#include "Image.h"
#include "Tuile.h"
#include <string>

using namespace std;

class Objet {
private:
  Image _img;
  int _x;
  int _y;
  Tuile _tuile;

public:
  Objet();

  Objet(const Image &img, const string &nom, Dictionnaire &dict, int x, int y);

  void dessiner() const;

  int getX() const;
  int getY() const;
  string getPropriete() const;
  void setPropriete(const string &p);
};

#endif
