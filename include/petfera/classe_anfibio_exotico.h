/**
  * @file 		classe_anfibio_exotico.h
  * @brief 		Classe AnfibioExotico
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/classe_anfibio_exotico.h
  */
 
#ifndef CLASSE_ANFIBIO_EXOTICO_H
#define CLASSE_ANFIBIO_EXOTICO_H
#pragma once

#include "classe_anfibio.h"
#include "animal_exotico.h"

/**
 * classe AnfibioExotico
 */
class AnfibioExotico: public Anfibio, Exotico
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
			  << this->m_total_mudas << ";"
			  << this->m_ultima_muda << ";"
			  << this->m_ibama << ";"
			  << this->m_pais_origem << ""
			  << endl;
	}

public:
	
	/**
	* construtor da classe AnfibioExotico
	*/
	AnfibioExotico(int id, string classe, string batismo);

	/**
	 * construtor da classe AnfibioExotico
	 */
	AnfibioExotico(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, int, string, string, string);

	/**
	 * destrutor da classe AnfibioExotico
	 */
	~AnfibioExotico();
	
	// print
	void 	printAnimal(void);

};

#endif // CLASSE_ANFIBIO_EXOTICO_H