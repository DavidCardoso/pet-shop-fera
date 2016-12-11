/**
  * @file 		classe_anfibio_nativo.h
  * @brief 		Classe AnfibioNativo
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/classe_anfibio_nativo.h
  */
 
#ifndef CLASSE_ANFIBIO_NATIVO_H
#define CLASSE_ANFIBIO_NATIVO_H
#pragma once

#include "classe_anfibio.h"
#include "animal_nativo.h"

/**
 * classe AnfibioNativo
 */
class AnfibioNativo: public Anfibio, Nativo
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
			  << this->m_uf_origem << ";"
			  << this->m_autorizacao << ""
			  << endl;
	}
	
public:

	/**
	* construtor da classe AnfibioNativo
	*/
	AnfibioNativo(int id, string classe, string batismo);

	/**
	 * construtor
	 */
	AnfibioNativo(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, int, string, string, string, string);

	/**
	* destrutor da classe AnfibioNativo
	*/
	~AnfibioNativo();

	// print
	void 	printAnimal(void);
};

#endif // CLASSE_ANFIBIO_NATIVO_H
 