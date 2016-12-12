/**
  * @file 		classe_reptil.cpp
  * @brief 		Classe abstrata Reptil
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/classe_reptil.cpp
  */
 
#include "../../include/petfera/classe_reptil.h"

/**
 * construtor da classe abstrata Reptil
 */
Reptil::Reptil(int id, string classe, string batismo):
  Animal(id, classe, batismo)
{}

/**
 * construtor da classe abstrata Reptil
 */
Reptil::Reptil(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, bool venenoso, string tipo_veneno):
	Animal(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador),
	m_venenoso(venenoso),
	m_tipo_veneno(tipo_veneno)
{}

/**
 * pegar venenoso
 * @return  boolean
 */
bool 	Reptil::getVenenoso(void){
	return m_venenoso;
}

/**
 * pegar tipo de veneno
 * @return  tipo de veneno
 */
string 	Reptil::getTipoVeneno(void){
	return m_tipo_veneno;
}

/**
 * definir veneneso
 * @param  venenoso
 */
void 	Reptil::setVenenoso(bool venenoso){
	m_venenoso = venenoso;
}

/**
 * definir tipo de veneno
 * @param  tipo_veneno
 */
void 	Reptil::setTipoVeneno(string tipo_veneno){
	m_tipo_veneno = tipo_veneno;
}