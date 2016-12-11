/**
  * @file 		classe_ave.cpp
  * @brief 		Classe abstrata Ave
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		03/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/classe_ave.cpp
  */
 
 #include "../../include/petfera/classe_ave.h"

/**
 * construtor da classe abstrata Ave
 */
Ave::Ave(int id, string classe, string batismo):
  Animal(id, classe, batismo)
{}

/**
 * construtor da classe abstrata Ave
 */
Ave::Ave(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, int tamanho_bico, int envergadura):
	Animal(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador),
	m_tamanho_bico(tamanho_bico), 
	m_envergadura(envergadura)
{}

/**
 * pegar 	tamanho do bico
 * @return  tamanho do bico
 */
int 	Ave::getTamanhoBico(void){
	return m_tamanho_bico;
}

/**
 * pegar 	envergadura
 * @return  envergadura
 */
int 	Ave::getEnvergadura(void){
	return m_envergadura;
}

/**
 * definir tamanho do bico
 * @param  tamanho_bico
 */
void 	Ave::setTamanhoBico(int tamanho_bico){
	m_tamanho_bico = tamanho_bico;
}

/**
 * definir envergadura
 * @param  envergadura
 */
void 	Ave::setEnvergadura(int envergadura){
	m_envergadura = envergadura;
}