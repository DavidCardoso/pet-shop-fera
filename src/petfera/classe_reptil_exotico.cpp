/**
  * @file 		classe_reptil_exotico.cpp
  * @brief 		Classe ReptilExotico
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/classe_reptil_exotico.cpp
  */
 
#include "../../include/petfera/classe_reptil_exotico.h"

/**
 * construtor da classe ReptilExotico
 */
ReptilExotico::ReptilExotico(int id, string classe, string batismo):
	Reptil(id, classe, batismo)
{}

/**
 * construtor da classe ReptilExotico
 */
ReptilExotico::ReptilExotico(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, bool venenoso, string tipo_veneno, string ibama, string pais_origem):
	Reptil(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, venenoso, tipo_veneno),
	Exotico(ibama, pais_origem)
{}

/**
 * destrutor da classe ReptilExotico
 */
ReptilExotico::~ReptilExotico(){
  delete m_veterinario;
  delete m_tratador;
}

/**
 * imprimir dados do reptil exotico
 */
void 	ReptilExotico::printAnimal(void){
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
	cout << "Venenoso:\t"  		<< (this->getVenenoso()?"Sim":"Não") << endl;
	cout << "Tipo Veneno:\t"  	<< this->getTipoVeneno() << endl;
	cout << "Ibama:\t\t"    	<< this->getIbama() << endl;
	cout << "País Origem:\t"    << this->getPaisOrigem() << endl;
	cout << endl;
}