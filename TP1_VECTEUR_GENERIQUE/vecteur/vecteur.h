#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <cassert>
#include <iostream>
using namespace std;

template<class T>
class Vecteur {

private:
	size_t size;
	T *valeurs;

public:
	/**
	 * Constructeur de la classe Vecteur
	 *
	 * @param dimension (par défaut égale à 3)
	 * @param valeur_initiale valeur à affecter à toutes les composantes
	 */
	explicit Vecteur(size_t size = 3, T valeur_defaut = T()) :
			size(size), valeurs(new T[size]) {
		assert(size > 0);
		std::cout << "Construction d'un vecteur" << std::endl;
		for (size_t i = 0; i < size; i++) {
			valeurs[i] = valeur_defaut;
		}
	}

	/**
	 * Constructeur de copie
	 *
	 * @param v le vecteur à copier
	 */
	Vecteur(const Vecteur &v) {
		copy(v);
	}

	/**
	 * Constructeur de copie générique
	 *
	 * @param v le vecteur générique à copier
	 */
	template<class V>
	explicit Vecteur(const Vecteur<V> &v) {
		copy(v);
	}

	/**
	 * Destructeur
	 */
	~Vecteur<T>() {
		delete[] valeurs;
	}

	/**
	 * Consulter la valeur d'une coordonnée sans la modifier
	 *
	 * @param i la coordonnée de la valeur
	 * @return la valeur à la coordonnée `i`
	 */
	T get(size_t i) const {
		assert(i < size);
		return valeurs[i];
	}

	/**
	 * Modifier la valeur d'un coordonnée
	 *
	 * @param i la coordonnée de la valeur
	 * @param valeur la nouvelle valeur pour la composante `i`
	 */
	void set(size_t i, T valeur) {
		assert(i < size);
		valeurs[i] = valeur;
	}

	/**
	 * Connaitre la dimension du vecteur
	 *
	 * @return la dimension du vecteur
	 */
	size_t dimensions() const {
		return size;
	}

	/**
	 * Opérateur d'affectation générique
	 *
	 * @param v le vecteur générique à affecter
	 * @return le vecteur crée à partir du vecteur `v`
	 */
	template <class V>
	Vecteur& operator=(const Vecteur<V> &v) {
		copy(v);
		return (*this);
	}

	/**
	 * Opérateur de consultation (avec modification possible)
	 *
	 * @param i la coordonnée de la valeur à modifier
	 * @return la valeur à la coordonnée `i`
	 */
	T& operator[](size_t i) {
		assert(i < size);
		return valeurs[i];
	}

	/**
	 * Opérateur de modification
	 *
	 * @param i la coordonnée de la valeur à consulter
	 * @return la valeur à la coordonnée `i`
	 */
	T operator[](size_t i) const {
		assert(i < size);
		return valeurs[i];
	}

private:
	/**
	 * Copier un vecteur générique dans le vecteur courant
	 *
	 * @param v le vecteur générique à copier
	 */
	template <class V>
	void copy(const Vecteur<V> &v) {
		size = v.dimensions();
		valeurs = new T[size];
		for (size_t i = 0; i < size; i++) {
			valeurs[i] = v.get(i);
		}
	}
};

// Prototypes des fonctions

/**
 * Afficher un vecteur
 *
 * @param v le vecteur à affichier
 * @param out le flux de sortie
 */
template<class T>
void afficherVecteur(const Vecteur<T> *v, ostream &out = std::cout) {
	size_t dim = v->dimensions();
	out << "Vecteur de dimension " << dim << endl << "Composantes : ";
	for (size_t i = 0; i < dim; i++) {
		out << v->get(i) << " ";
	}
	out << endl;
}

/**
 * Créer un vecteur dont les caracteritiques sont fournies par l'utilisateur sur le flux d'entrée
 *
 * @param in le flux d'entrée
 * @return le vecteur crée par l'utilisateur
 */
template<class T>
Vecteur<T>* lireVecteur(istream &in = std::cin) {
	size_t size;
	std::cout << "Taille du vecteur : ";
	in >> size;
	Vecteur<T> *v = new Vecteur<T>(size);
	for (size_t i = 0; i < size; i++) {
		T valeur;
		std::cout << "Valeur composante " << i << " : ";
		in >> valeur;
		v->set(i, valeur);
	}

	return v;
}
/**
 * Opérateur d'addition
 *
 * @param v le vecteur à additionner au vecteur courant
 * @return la somme des deux vecteurs
 */
template<class T1, class T2>
Vecteur<T1> operator+(const Vecteur<T1> &v1, const Vecteur<T2> &v2) {
	assert(v1.dimensions() == v2.dimensions());
	size_t size = v1.dimensions();
	Vecteur<T1> v(size); // variable locale
	for (size_t i = 0; i < size; i++) {
		T1 valeur = v1.get(i) + v2.get(i);
		v.set(i, valeur);
	}
	return v; // on renvoie une copie du vecteur, car si on renvoyait la reference, comme c'est une variable locale elle n'existerait plus
			  // permet de ne pas faire de new
}

/**
 * Produit scalaire définie
	std::cout << "print : "<<  v3; de facçon explicite de deux vecteurs float
 *
 * @param v1 le premier vecteur
 * @param v2 le deuxième vecteur
 * @return le produit scalaire des deux vecteurs `v1` et `v2`
 */
template<class T1, class T2> // permet de suppporter le produit scalaire entre deux vecteurs de type differents (float et int par ex)
float operator*(const Vecteur<T1> &v1, const Vecteur<T2> &v2) {
	assert(
			v1.dimensions() == v2.dimensions()
					&& "Les deux vecteurs n'ont pas la même dimension");

	T1 prod_scal = 0;
	for (size_t i = 0; i < v1.dimensions(); i++) {
		prod_scal += (v1.get(i)) * (v2.get(i));
	}

	return prod_scal;
}

/**
 * Modifier un vecteur au clavier
 *
 * @param in le flux d'entrée
 * @param v le vecteur à modifier
 */
template<class T>
istream& operator>>(istream &in, Vecteur<T> &v) {
	for (size_t i = 0; i < v.dimensions(); i++) {
		std::cout << "Composante " << i + 1 << " : ";
		T valeur;
		in >> valeur;
		v.set(i, valeur);
		std::cout << endl;
	}
	return in;
}

/**
 * Afficher un vecteur sur le flux de sortie
 *
 * @param out le flux de sortie
 * @param v le vecteur à afficher
 */
template<class T>
ostream& operator<<(ostream &out, Vecteur<T> &v) {
	afficherVecteur(&v, out);
	return out;
}

#endif
