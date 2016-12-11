/**
  * @file 		animal_silvestre.cpp
  * @brief 		Classe abstrata Silvestre
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/animal_silvestre.cpp
  */
 
 #include "../../include/petfera/animal_silvestre.h"

/**
 * construtor da classe abstrata Silvestre
 */
Silvestre::Silvestre(string ibama):
	m_ibama(ibama)
{}

/**
 * pegar ibama
 * @return  ibama
 */
string 	Silvestre::getIbama(void){
	return m_ibama;
}


/**
 * definir ibama
 * @param  ibama
 */
void 	Silvestre::setIbama(string ibama){
	m_ibama = ibama;
}