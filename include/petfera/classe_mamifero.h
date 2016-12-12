/**
  * @file 		classe_mamifero.h
  * @brief 		Classe abstrata Mamifero
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/classe_mamifero.h
  */
 
#ifndef CLASSE_MAMIFERO_H
#define CLASSE_MAMIFERO_H
#pragma once

#include "animal.h"

/**
 * classe abstrata Mamifero
 */
class Mamifero: public Animal
{

protected:
	string 	m_cor_pelo;

public:

	/**
	 * construtor
	 */
	Mamifero(int id, string classe, string batismo);

	/**
	 * construtor da classe abstrata Mamifero
	 */
	Mamifero(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, string);

	// getters
	
	string 	getCorPelo(void);

	// setters
	 
	void 	setCorPelo(string);

	// print
	virtual void 	printAnimal(void) = 0;
	
};

#endif // CLASSE_MAMIFERO_H
 