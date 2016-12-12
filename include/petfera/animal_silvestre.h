/**
  * @file 		animal_silvestre.h
  * @brief 		Classe abstrata Silvestre
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/animal_silvestre.h
  */
 
#ifndef ANIMAL_SILVESTRE_H
#define ANIMAL_SILVESTRE_H
#pragma once

#include <string>

using namespace std;

/**
 * classe abstrata Silvestre
 */
class Silvestre
{

protected:
	string 	m_ibama;

public:
	/**
	 * construtor
	 */
	Silvestre(string);

	// getters
	
	string 	getIbama(void);

	// setters
	
	void 	setIbama(string);

	// print
	virtual void 	printAnimal(void) = 0;
};

#endif // ANIMAL_SILVESTRE_H
 