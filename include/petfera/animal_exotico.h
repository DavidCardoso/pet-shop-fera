/**
  * @file 		animal_exotico.h
  * @brief 		Classe abstrata Exotico
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/animal_exotico.h
  */
 
#ifndef ANIMAL_EXOTICO_H
#define ANIMAL_EXOTICO_H
#pragma once

#include "animal_silvestre.h"

/**
 * classe abstrata Exotico
 */
class Exotico: public Silvestre
{

protected:
	string 	m_pais_origem;

public:
	/**
	 * construtor da classe abstrata Exotico
	 */
	Exotico();

	/**
	 * construtor da classe abstrata Exotico
	 */
	Exotico(string, string);

	// getters
	
	string 	getPaisOrigem(void);

	// setters
	
	void 	setPaisOrigem(string);

	// print
	virtual void 	printAnimal(void) = 0;
};

#endif // ANIMAL_EXOTICO_H
 