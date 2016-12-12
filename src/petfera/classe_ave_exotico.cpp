/**
  * @file 		classe_ave_exotico.cpp
  * @brief 		Classe AveExotico
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/classe_ave_exotico.cpp
  */
 
#include "../../include/petfera/classe_ave_exotico.h"

/**
 * construtor da classe AveExotico
 */
AveExotico::AveExotico(int id, string classe, string batismo):
	Ave(id, classe, batismo)
{}

/**
 * construtor da classe abstrata AveExotico
 */
AveExotico::AveExotico(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, int tamanho_bico, int envergadura, string ibama, string pais_origem):
	Ave(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, tamanho_bico, envergadura),
	Exotico(ibama, pais_origem)
{}

/**
 * destrutor da classe AveExotico
 */
AveExotico::~AveExotico(){
  delete m_veterinario;
  delete m_tratador;
}

/**
 * imprimir dados da ave exotica
 */
void 	AveExotico::printAnimal(void){
	cout << endl;
	cout << ">>>>> Ficha do animal <<<<<" << endl;
	cout << "ID:\t\t"     		<< this->getID() << endl;
	cout << "Classe:\t\t"   	<< this->getClasse() << endl;
	cout << "Nome:\t\t"     	<< this->getNome() << endl;
	cout << "Cientifico:\t"  	<< this->getCientifico() << endl;
	cout << "Batismo:\t"    	<< this->getBatismo() << endl;
	cout << "Dieta:\t\t"    	<< this->getDieta() << endl;
	cout << "Sexo:\t\t"    		<< this->getSexo() << endl;
	cout << "Veterinario:\t"  	<< (this->getVeterinario()!=nullptr?this->getVeterinario()->getNome():"") << endl;
	cout << "Tratador:\t"  		<< (this->getTratador()!=nullptr?this->getTratador()->getNome():"") << endl;
	cout << "Bico:\t\t"  		<< this->getTamanhoBico() << endl;
	cout << "Envergadura:\t"  	<< this->getEnvergadura() << endl;
	cout << "Ibama:\t\t"    	<< this->getIbama() << endl;
	cout << "País Origem:\t"    << this->getPaisOrigem() << endl;
	cout << endl;
}