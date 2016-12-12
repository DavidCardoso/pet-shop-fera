/**
  * @file 		classe_anfibio.cpp
  * @brief 		Classe abstrata Anfibio
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/classe_anfibio.cpp
  */

#include "../../include/petfera/classe_anfibio.h"

/**
 * construtor da classe abstrata Anfibio
 */
Anfibio::Anfibio(int id, string classe, string batismo):
	Animal(id, classe, batismo)
{}

/**
 * construtor da classe abstrata Anfibio
 */
Anfibio::Anfibio(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, int total_mudas, string ultima_muda):
	Animal(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador),
	m_total_mudas(total_mudas), 
	m_ultima_muda(ultima_muda)
{}

/**
 * pegar total de mudas
 * @return  total de mudas
 */
int 	Anfibio::getTotalMudas(void){
	return m_total_mudas;
}

/**
 * pegar ultima muda
 * @return  ultimo muda
 */
string 	Anfibio::getUltimaMuda(void){
	return m_ultima_muda;
}

/**
 * definir total mudas
 * @param  total_mudas
 */
void 	Anfibio::setTotalMudas(int total_mudas){
	m_total_mudas = total_mudas;
}

/**
 * definir ultima muda
 * @param  ultima_muda
 */
void 	Anfibio::setUltimaMuda(string ultima_muda){
	m_ultima_muda = ultima_muda;
}