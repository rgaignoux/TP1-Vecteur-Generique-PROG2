#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <iostream>
using namespace std;

class Vecteur {
private:
	size_t size;
	float *valeurs;
public:
	/**
	 * Constructeur de la classe Vecteur
	 *
	 * @param dimension (par défaut égale à 3)
	 * @param valeur_initiale valeur à affecter à toutes les composantes (par défaut égale à 0)
	 */
	Vecteur(size_t size = 3, float valeur_defaut = 0.0);

	/**
	 * Constructeur de copie
	 *
	 * @param v le vecteur à copier
	 */
	Vecteur(const Vecteur &v);

	/**
	 * Destructeur
	 */
	~Vecteur();

	/**
	 * Consulter la valeur d'une coordonnée sans la modifier
	 *
	 * @param i la coordonnée de la valeur
	 * @return la valeur à la coordonnée `i`
	 */
	float get(size_t i) const;

	/**
	 * Modifier la valeur d'un coordonnée
	 *
	 * @param i la coordonnée de la valeur
	 * @param valeur la nouvelle valeur pour la composante `i`
	 */
	void set(size_t i, float valeur);

	/**
	 * Connaitre la dimension du vecteur
	 *
	 * @return la dimension du vecteur
	 */
	size_t dimensions() const;

	/**
	 * Opérateur d'affectation
	 *
	 * @param v le vecteur à affecter
	 * @return le vecteur crée à partir du vecteur `v`
	 */
	Vecteur& operator=(const Vecteur &v);

	/**
	 * Opérateur d'addition
	 *
	 * @param v le vecteur à additionner au vecteur courant
	 * @return la somme des deux vecteurs
	 */
	Vecteur operator+(const Vecteur &v);

	/**
	 * Opérateur de consultation (avec modification possible)
	 *
	 * @param i la coordonnée de la valeur à modifier
	 * @return la valeur à la coordonnée `i`
	 */
	float& operator[](size_t i);

	/**
	 * Opérateur de modification
	 *
	 * @param i la coordonnée de la valeur à consulter
	 * @return la valeur à la coordonnée `i`
	 */
	float operator[](size_t i) const;

private:
	/**
	 * Copier un vecteur dans le vecteur courant
	 *
	 * @param v le vecteur à copier
	 */
	void copy(const Vecteur &v);
};

// Prototypes des fonctions

/**
 * Afficher un vecteur
 *
 * @param v le vecteur à affichier
 * @param out le flux de sortie
 */
void afficherVecteur(const Vecteur *v, ostream &out = std::cout);

/**
 * Créer un vecteur dont les caracteritiques sont fournies par l'utilisateur sur le flux d'entrée
 *
 * @param in le flux d'entrée
 */
Vecteur* lireVecteur(istream &in = std::cin);

/**
 * Additionner deux vecteurs
 *
 * @param v1 le premier vecteur
 * @param v2 le deuxième vecteur
 * @return la somme des deux vecteurs `v1` et `v2`
 */
Vecteur add(const Vecteur *v1, const Vecteur *v2);

/**
 * Produit scalaire de deux vecteurs
 *
 * @param v1 le premier vecteur
 * @param v2 le deuxième vecteur
 * @return le produit scalaire des deux vecteurs `v1` et `v2`
 */
float operator*(const Vecteur &v1, const Vecteur &v2);

/**
 * Modifier un vecteur au clavier
 *
 * @param in le flux d'entrée
 * @param v le vecteur à modifier
 */
istream& operator>>(istream &in, Vecteur &v);

/**
 * Afficher un vecteur sur le flux de sortie
 *
 * @param out le flux de sortie
 * @param v le vecteur à afficher
 */
ostream& operator<<(ostream &out, Vecteur &v);

#endif
