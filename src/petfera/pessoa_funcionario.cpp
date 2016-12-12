/**
  * @file 		pessoa_funcionario.cpp
  * @brief 		Classe abstrata Funcionario
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/pessoa_funcionario.cpp
  */
 
#include "../../include/petfera/pessoa_funcionario.h"

/**
 * construtor da classe abstrata Funcionario
 * @param   id
 * @param   funcao
 * @param   nome
 * @param   cpf
 * @param   tipo_sangue
 * @param   idade
 * @param   fator_rh
 * @param   especialidade
 */
Funcionario::Funcionario(int id, string funcao, string nome, string cpf, string tipo_sangue, short idade, char fator_rh, string especialidade):
	Pessoa(id, funcao, nome, cpf, tipo_sangue, idade, fator_rh),
	m_especialidade(especialidade)
{}

/**
 * pegar especialidade do funcionario
 * @return 	especialidade
 */
string 	Funcionario::getEspecialidade(void){
	return m_especialidade;
}

/**
 * definir especialidade do funcionario
 * @param 	especialidade
 */
void 	Funcionario::setEspecialidade(string especialidade){
	m_especialidade = especialidade;
}
