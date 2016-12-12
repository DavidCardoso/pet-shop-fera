/**
	* @file 		classe_reptil_exotico.h
	* @brief 		Classe ReptilExotico
	* @details 		Declaração dos atributos e dos métodos da classe
	* @author		David Cardoso
	* @since		31/10/2016
	* @date			07/11/2016
	* @copyright 	2016 - All rights reserveds
	* @sa 			http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/classe_reptil_exotico.h
	*/
 
#ifndef CLASSE_REPTIL_EXOTICO_H
#define CLASSE_REPTIL_EXOTICO_H
#pragma once

#include "classe_reptil.h"
#include "animal_exotico.h"

/**
 * classe ReptilExotico
 */
class ReptilExotico: public Reptil, Exotico
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
				  << (this->m_venenoso?1:0) << ";"
				  << this->m_tipo_veneno << ";"
				  << this->m_ibama << ";"
				  << this->m_pais_origem << ""
				  << endl;
		}

public:

	/**
	 * construtor da classe ReptilExotico
	 */
	ReptilExotico(int id, string classe, string batismo);

	/**
	 * construtor da classe ReptilExotico
	 */
	ReptilExotico(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, bool, string, string, string);

	/**
	* destrutor da classe ReptilExotico
	*/
	~ReptilExotico();

	// print
	void 	printAnimal(void);

};

#endif // CLASSE_REPTIL_EXOTICO_H
 