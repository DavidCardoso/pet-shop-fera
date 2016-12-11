/**
  * @file 		pessoa_funcionario.h
  * @brief 		Classe abstrata Funcionario
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/pessoa_funcionario.h
  */
 
#ifndef PESSOA_FUNCIONARIO_H
#define PESSOA_FUNCIONARIO_H
#pragma once

#include "pessoa.h"

/**
 * classe abstrata Funcionario
 */
class Funcionario : public Pessoa
{

protected:
	string 	m_especialidade;

public:

	/**
	 * construtor
	 */
	Funcionario(int, string, string, string, string, short, char, string);

	/**
	 * pegar especialidade do funcionario
	 */
	string 	getEspecialidade(void);

	/**
	 * definir especialidade do funcionario
	 */
	void 	setEspecialidade(string);

	// print
	virtual void 	printPessoa(void) = 0;

	
};
 
 
#endif // PESSOA_FUNCIONARIO_H
 