/**
  * @file 		classe_anfibio.h
  * @brief 		Classe abstrata Anfibio
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/classe_anfibio.h
  */
 
#ifndef CLASSE_ANFIBIO_H
#define CLASSE_ANFIBIO_H
#pragma once

#include "animal.h"

/**
 * classe abstrata Anfibio
 */
class Anfibio: public Animal
{

protected:
	int 	m_total_mudas;
	string 	m_ultima_muda;

public:
	
	/**
	 * construtor
	 */
	Anfibio(int id, string classe, string batismo);

	/**
	 * construtor
	 */
	Anfibio(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, int, string);

	// getters
	
	int 	getTotalMudas(void);
	string 	getUltimaMuda(void);

	// setters
	 
	void 	setTotalMudas(int);
	void 	setUltimaMuda(string);

	// print
	void 	printAnimal(void) = 0;
};

#endif // CLASSE_ANFIBIO_H
 