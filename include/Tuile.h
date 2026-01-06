#ifndef TUILE_H
#define TUILE_H
#include <string>

using namespace std;

// Part 3, Questions 2-3: Classe Tuile pour stocker les infos du dictionnaire
class Tuile {
private:
  string _nom;
  int _x;
  int _y;
  string _propriete;

public:
  // Constructeur par defaut
  Tuile();

  // Constructeur avec parametres (Q2)
  Tuile(const string &nom, int x, int y, const string &propriete);

  // Q3: Afficher les attributs
  void afficher() const;

  // Q18: Modifier la propriete
  void setPropriete(const string &p);

  // Getters
  string getNom() const;
  int getX() const;
  int getY() const;
  string getPropriete() const;
};

#endif
