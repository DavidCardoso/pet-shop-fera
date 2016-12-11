/**
  * @file 		pessoa.cpp
  * @brief 		Classe abstrata Pessoa
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/pessoa.cpp
  */
 

#include "../../include/petfera/pessoa.h"


/**
 * construtor da classe abstrata Pessoa
 * @param 	id
 * @param 	funcao
 * @param 	nome
 * @param 	cpf
 * @param 	tipo_sangue
 * @param 	idade
 * @param 	fator_rh
 */
Pessoa::Pessoa(int id, string funcao, string nome, string cpf, string tipo_sangue, short idade, char fator_rh):
	m_id(id),
	m_funcao(funcao),
	m_nome(nome),
	m_cpf(cpf),
	m_tipo_sangue(tipo_sangue),
	m_idade(idade),
	m_fator_rh(fator_rh)
{}


/**
 * pegar ID da pessoa
 * @return  ID
 */
int 	Pessoa::getID(void){
	return m_id;
}

/**
 * pegar funcao da pessoa
 * @return  funcao
 */
string 	Pessoa::getFuncao(void){
	return m_funcao;
}

/**
 * pegar nome da pessoa
 * @return  nome
 */
string 	Pessoa::getNome(void){
	return m_nome;
}

/**
 * pegar CPF da pessoa
 * @return  CPF
 */
string 	Pessoa::getCPF(void){
	return m_cpf;
}

/**
 * pegar tipo de sangue da pessoa
 * @return  tipo de sangue
 */
string 	Pessoa::getTipoSangue(void){
	return m_tipo_sangue;
}

/**
 * pegar idade da pessoa
 * @return  idade
 */
short 	Pessoa::getIdade(void){
	return m_idade;
}

/**
 * pegar fator RH do sangue
 * @return  fator RH
 */
char 	Pessoa::getFatorRH(void){
	return m_fator_rh;
}

/**
 * definir ID da pessoa
 * @param  id
 */
void 	Pessoa::setID(int id){
	m_id = id;
}

/**
 * definir funcao da pessoa
 * @param  funcao
 */
void 	Pessoa::setFuncao(string funcao){
	m_funcao = funcao;
}

/**
 * definir nome da pessoa
 * @param  nome
 */
void 	Pessoa::setNome(string nome){
	m_nome = nome;
}

/**
 * definir CPF da pessoa
 * @param  cpf
 */
void 	Pessoa::setCPF(string cpf){
	m_cpf = cpf;
}

/**
 * definir tipo de sangue da pessoa
 * @param  tipo_sangue
 */
void 	Pessoa::setTipoSangue(string tipo_sangue){
	m_tipo_sangue = tipo_sangue;
}

/**
 * definir idade da pessoa
 * @param  idade
 */
void 	Pessoa::setIdade(short idade){
	m_idade = idade;
}

/**
 * definir fator RH do sangue
 * @param  fator_rh
 */
void 	Pessoa::setFatorRH(char fator_rh){
	m_fator_rh = fator_rh;
}

/**
 * sobrecarga do operador de igualdade (==)
 * @param 	id
 * @return 	boolean
 */
bool 	Pessoa::operator== (int id){
	return this->getID() == id;

}

/**
 * sobrecarga do operador de menor (<)
 * @param 	p - ponteiro para objeto Pessoa
 * @return 	ponteiro para objeto Pessoa
 */
Pessoa* 	Pessoa::operator< (Pessoa* p){
	return this->getID() < p->getID() ? this : p; 
}