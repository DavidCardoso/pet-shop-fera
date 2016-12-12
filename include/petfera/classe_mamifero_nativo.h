/**
  * @file 		classe_mamifero_nativo.h
  * @brief 		Classe MamiferoNativo
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/include/petfera/classe_mamifero_nativo.h
  */
 
#ifndef CLASSE_MAMIFERO_NATIVO_H
#define CLASSE_MAMIFERO_NATIVO_H
#pragma once

#include "classe_mamifero.h"
#include "animal_nativo.h"

/**
 * classe MamiferoNativo
 */
class MamiferoNativo: public Mamifero, Nativo
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
				  << this->m_cor_pelo << ";"
				  << this->m_ibama << ";"
				  << this->m_uf_origem << ";"
				  << this->m_autorizacao << ""
				  << endl;
		}

public:

	/**
	* construtor da classe MamiferoNativo
	*/
	MamiferoNativo(int id, string classe, string batismo);

	/**
	 * construtor da classe MamiferoNativo
	 */
	MamiferoNativo(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*, string, string, string, string);

	/**
	* destrutor da classe MamiferoNativo
	*/
	~MamiferoNativo();

	// print
	void  printAnimal(void);

};

#endif // CLASSE_MAMIFERO_NATIVO_H
 