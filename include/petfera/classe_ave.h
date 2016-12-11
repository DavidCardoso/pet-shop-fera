/**
  * @file 		classe_ave.h
  * @brief 		Classe abstrata Ave
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/classe_ave.h
  */
 
#ifndef CLASSE_AVE_H
#define CLASSE_AVE_H
#pragma once

#include "animal.h"

/**
 * classe abstrata Ave
 */
class Ave: public Animal
{

protected:
	int 	m_tamanho_bico;
	int 	m_envergadura;

public:
	
	/**
	 * construtor
	 */
	Ave(int id, string classe, string batismo);

	/**
	 * construtor
	 */
	Ave(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, int, int);

	// getters
	
	int 	getTamanhoBico(void);
	int 	getEnvergadura(void);

	// setters
	 
	void 	setTamanhoBico(int);
	void 	setEnvergadura(int);

	// print
	void 	printAnimal(void) = 0;

};

#endif // CLASSE_AVE_H
 