/**
  * @file 		pessoa_veterinario.h
  * @brief 		Classe Veterinario
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/pessoa_veterinario.h
  */
 
#ifndef PESSOA_VETERINARIO_H
#define PESSOA_VETERINARIO_H
#pragma once

#include "pessoa_funcionario.h"

/**
 * classe Veterinario
 */
class Veterinario : public Funcionario
{
private:
  /**
   * imprimir dados do veterinario em formato csv para salvar em arquivo
   * @param  os - objeto stream
   * @return    objeto stream
   */
  ostream& print(ostream& os) const {
	return os << this->m_id << ";" 
			  << this->m_funcao << ";" 
			  << this->m_nome << ";" 
			  << this->m_cpf << ";" 
			  << this->m_tipo_sangue << ";" 
			  << this->m_idade << ";" 
			  << this->m_fator_rh << ";" 
			  << this->m_especialidade << "" 
			  << endl;
  }

public:

	/**
	 * construtor
	 */
	Veterinario(int, string, string, string, string, short, char, string);

	// print
	void     printPessoa(void);

};

#endif // PESSOA_VETERINARIO_H
 