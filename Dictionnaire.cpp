#ifndef TUILE_H
#define TUILE_H
#include <string>

using namespace std;

class Tuile {
private:
  string _nom;
  int _x;
  int _y;
  string _propriete;

public:
  Tuile();

  Tuile(const string &nom, int x, int y, const string &propriete);

  // afichee les attribut
  void afficher() const;

  void setPropriete(const string &p);

  // getter
  string getNom() const;
  int getX() const;
  int getY() const;
  string getPropriete() const;
};

#endif
