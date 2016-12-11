/**
  * @file 		animal_nativo.cpp
  * @brief 		Classe abstrata Nativo
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		03/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/animal_nativo.cpp
  */
 
#include "../../include/petfera/animal_nativo.h"

/**
 * construtor da classe abstrata Nativo
 */
Nativo::Nativo():
  Silvestre(""),
  m_uf_origem(""),
  m_autorizacao("")
{}

/**
 * construtor
 */
Nativo::Nativo(string ibama, string uf_origem, string autorizacao):
	Silvestre(ibama),
	m_uf_origem(uf_origem),
	m_autorizacao(autorizacao)
{}


string 	Nativo::getUFOrigem(void){
	return m_uf_origem;
}


string 	Nativo::getAutorizacao(void){
	return m_autorizacao;
}


void 	Nativo::setUFOrigem(string uf_origem){
	m_uf_origem = uf_origem;
}


void 	Nativo::setAutorizazcao(string autorizacao){
	m_autorizacao = autorizacao;
}