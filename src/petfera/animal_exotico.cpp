/**
  * @file 		animal_exotico.cpp
  * @brief 		Classe abstrata Exotico
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		03/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/animal_exotico.cpp
  */
 
#include "../../include/petfera/animal_exotico.h"

/**
 * construtor da classe abstrata Exotico
 */
Exotico::Exotico():
	Silvestre(""),
	m_pais_origem("")
{}

/**
 * construtor da classe abstrata Exotico
 */
Exotico::Exotico(string ibama, string pais_origem):
  Silvestre(ibama),
  m_pais_origem(pais_origem)
{}

/**
 * pegar país de origem do animal
 * @return  páis de origem
 */
string 	Exotico::getPaisOrigem(void){
	return m_pais_origem;
}

/**
 * definir país de origem
 * @param  pais_origem
 */
void 	Exotico::setPaisOrigem(string pais_origem){
	m_pais_origem =  pais_origem;
}