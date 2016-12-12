/**
  * @file 		animal_nativo.h
  * @brief 		Classe abstrata Nativo
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/animal_nativo.h
  */
 
#ifndef ANIMAL_NATIVO_H
#define ANIMAL_NATIVO_H
#pragma once

#include "animal_silvestre.h"
 
/**
 * classe abstrata Nativo
 */
class Nativo: public Silvestre
{

protected:
	string 	m_uf_origem;
	string 	m_autorizacao;

public:
	/**
	 * construtor
	 */
	Nativo();

	/**
	 * construtor
	 */
	Nativo(string, string, string);

	// getters
	
	string 	getUFOrigem(void);
	string 	getAutorizacao(void);

	// setters
	
	void 	setUFOrigem(string);
	void 	setAutorizazcao(string);

	// print
	virtual void 	printAnimal(void) = 0;
};

#endif // ANIMAL_NATIVO_H
 