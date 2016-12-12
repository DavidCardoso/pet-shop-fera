/**
  * @file 		classe_reptil.h
  * @brief 		Classe abstrata Reptil
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/classe_reptil.h
  */
 
#ifndef CLASSE_REPTIL_H
#define CLASSE_REPTIL_H
#pragma once

#include "animal.h"

/**
 * classe abstrata Reptil
 */
class Reptil: public Animal
{

protected:
	bool 	m_venenoso;
	string 	m_tipo_veneno;

public:

	/**
	 * construtor da classe abstrata Reptil
	 */
	Reptil(int id, string classe, string batismo);

	/**
	 * destrutor
	 */
	virtual ~Reptil(){};
	
	/**
	 * construtor da classe abstrata Reptil
	 */
	Reptil(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, bool, string);

	// getters
	
	bool 	getVenenoso(void);
	string 	getTipoVeneno(void);

	// setters
	 
	void 	setVenenoso(bool);
	void 	setTipoVeneno(string);

	// print
	void 	printAnimal(void) = 0;

};

#endif // CLASSE_REPTIL_H
 