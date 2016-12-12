/**
  * @file 		classe_mamifero.cpp
  * @brief 		Classe abstrata Mamifero
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/classe_mamifero.cpp
  */
 
 #include "../../include/petfera/classe_mamifero.h"

/**
 * construtor da classe abstrata Mamifero
 */
Mamifero::Mamifero(int id, string classe, string batismo):
  Animal(id, classe, batismo)
{}

/**
 * construtor da classe abstrata Mamifero
 */
Mamifero::Mamifero(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, string cor_pelo):
	Animal(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador),
	m_cor_pelo(cor_pelo)
{}

/**
 * pegar cor do pelo
 * @return  cor do pelo
 */
string 	Mamifero::getCorPelo(void){
  return m_cor_pelo;
}

/**
 * definir cor do pelo
 * @param  cor_pelo
 */
void 	  Mamifero::setCorPelo(string cor_pelo){
  m_cor_pelo = cor_pelo;
}