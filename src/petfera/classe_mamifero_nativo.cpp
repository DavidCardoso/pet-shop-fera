/**
  * @file 		classe_mamifero_nativo.cpp
  * @brief 		Classe MamiferoNativo
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/classe_mamifero_nativo.cpp
  */
 
#include "../../include/petfera/classe_mamifero_nativo.h"

/**
 * construtor da classe MamiferoNativo
 */
MamiferoNativo::MamiferoNativo(int id, string classe, string batismo):
	Mamifero(id, classe, batismo)
{}

/**
 * construtor da classe MamiferoExotico
 */
MamiferoNativo::MamiferoNativo(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, string cor_pelo, string ibama, string uf_origem, string autorizacao):
	Mamifero(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, cor_pelo),
	Nativo(ibama, uf_origem, autorizacao)
{}

/**
 * destrutor da classe MamiferoNativo
 */
MamiferoNativo::~MamiferoNativo(){
  delete m_veterinario;
  delete m_tratador;
}

/**
 * imprimir dados do mamifero exotivo
 */
void 	MamiferoNativo::printAnimal(void){
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
	cout << "UF Origem:\t"  	<< this->getUFOrigem() << endl;
	cout << "Autorizacao:\t" 	<< this->getAutorizacao() << endl;
	cout << endl;
}