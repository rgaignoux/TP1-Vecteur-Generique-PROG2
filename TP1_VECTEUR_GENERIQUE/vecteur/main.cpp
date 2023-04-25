#include "vecteur.h"
#include <iostream>

int main() {

	// Addition de deux vecteurs de type float
	Vecteur<float> v1;
	std::cin >> v1;

	Vecteur<float> v2;
	std::cin >> v2;

	Vecteur<float> somme1 = v1 + v2;
	std::cout << "Somme des 2 vecteurs de type float :" << endl
			<< somme1 << endl;

	// Addition de deux vecteurs de type string
	Vecteur<std::string> v4;
	std::cin >> v4;

	Vecteur<std::string> v5;
	std::cin >> v5;

	Vecteur<std::string> somme2 = v4 + v5; // La somme pour les string est une concaténation
	std::cout << "Somme des 2 vecteurs de type string :" << endl
			<< somme2;

	// Produit scalaire de 2 vecteurs de type float
	std::cout << "Produit scalaire des deux vecteurs de type float : " << v1 * v2 << endl;

	// Produit scalaire de deux vecteurs de type float et int
	Vecteur<float> v6;
	std::cin >> v6;

	Vecteur<int> v7;
	std::cin >> v7;

	float prodScal = v6 * v7;

	std::cout << "Produit scalaire d'un vecteur de type int et d'un vecteur de type float : " << prodScal << endl;

	Vecteur<float> v8;
	Vecteur<int> v9;

	std::cout << v8;
	std::cout << v9;

	// Création d'une copie d'un vecteur de type int dans un vecteur de type float (utilisation du constructeur de copie générique)
	Vecteur<float> v10(v9);



	return 0;
}
