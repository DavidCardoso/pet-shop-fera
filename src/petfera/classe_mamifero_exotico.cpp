/**
  * @file 		classe_mamifero_exotico.cpp
  * @brief 		Classe MamiferoExotico
  * @details 	Implementaçao dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/classe_mamifero_exotico.cpp
  */

#include "../../include/petfera/classe_mamifero_exotico.h"

/**
 * construtor da classe MamiferoExotico
 */
MamiferoExotico::MamiferoExotico(int id, string classe, string batismo):
	Mamifero(id, classe, batismo)
{}

/**
 * construtor da classe MamiferoExotico
 */
MamiferoExotico::MamiferoExotico(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, string cor_pelo, string ibama, string pais_origem):
	Mamifero(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, cor_pelo),
	Exotico(ibama, pais_origem)
{}

/**
 * destrutor da classe MamiferoExotico
 */
MamiferoExotico::~MamiferoExotico(){
  delete m_veterinario;
  delete m_tratador;
}

/**
 * imprimir dados do mamifero exotivo
 */
void 	MamiferoExotico::printAnimal(void){
	cout << endl;
	cout << ">>>>> Ficha do animal <<<<<" << endl;
	cout << "ID:\t\t"			<< this->getID() << endl;
	cout << "Classe:\t\t"		<< this->getClasse() << endl;
	cout << "Nome:\t\t"			<< this->getNome() << endl;
	cout << "Cientifico:\t"		<< this->getCientifico() << endl;
	cout << "Batismo:\t"		<< this->getBatismo() << endl;
	cout << "Dieta:\t\t"		<< this->getDieta() << endl;
	cout << "Sexo:\t\t"    		<< this->getSexo() << endl;
	cout << "Veterinario:\t"  	<< (this->getVeterinario()!=nullptr?this->getVeterinario()->getNome():"") << endl;
	cout << "Tratador:\t"  		<< (this->getTratador()!=nullptr?this->getTratador()->getNome():"") << endl;
	cout << "Cor do pelo:\t"	<< this->getCorPelo() << endl;
	cout << "Ibama:\t\t" 		<< this->getIbama() << endl;
	cout << "País Origem:\t"  	<< this->getPaisOrigem() << endl;
	cout << endl;
}
