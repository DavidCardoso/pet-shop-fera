/**
  * @file 		classe_ave_exotico.h
  * @brief 		Classe AveExotico
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/classe_ave_exotico.h
  */
 
#ifndef CLASSE_AVE_EXOTICO_H
#define CLASSE_AVE_EXOTICO_H
#pragma once

#include "classe_ave.h"
#include "animal_exotico.h"

/**
 * classe AveExotico
 */
class AveExotico: public Ave, Exotico
{
private:
	/**
	* imprimir dados do animal em formato csv para salvar em arquivo
	* @param  os - objeto stream
	* @return    objeto stream
	*/
	ostream& print(ostream& os) const {
		return os << this->m_id << ";" 
				  << this->m_classe << ";" 
				  << this->m_nome << ";" 
				  << this->m_cientifico << ";" 
				  << this->m_batismo << ";" 
				  << this->m_dieta << ";" 
				  << this->m_sexo << ";" 
				  << this->m_tamanho << ";" 
				  << (this->m_veterinario!=nullptr?this->m_veterinario->getID():0) << ";" 
			  	  << (this->m_tratador!=nullptr?this->m_tratador->getID():0) << ";"
				  << this->m_tamanho_bico << ";"
				  << this->m_envergadura << ";"
				  << this->m_ibama << ";"
				  << this->m_pais_origem << ""
				  << endl;
		}

public:

	/**
	* construtor da classe AveExotico
	*/
	AveExotico(int id, string classe, string batismo);

	/**
	 * construtor
	 */
	AveExotico(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, int, int, string, string);

	/**
	* destrutor da classe AveExotico
	*/
	~AveExotico();

	// print
	void 	printAnimal(void);

};

#endif // CLASSE_AVE_EXOTICO_H
 