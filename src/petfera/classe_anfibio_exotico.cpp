/**
* @file 		classe_anfibio_exotico.cpp
* @brief 		Classe AnfibioExotico
* @details 		Implementação dos métodos da classe
* @author		David Cardoso
* @since		31/10/2016
* @date			07/11/2016
* @copyright 	2016 - All rights reserveds
* @sa 			http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/classe_anfibio_exotico.cpp
*/

#include "../../include/petfera/classe_anfibio_exotico.h"

/**
 * construtor da classe AnfibioExotico
 */
AnfibioExotico::AnfibioExotico(int id, string classe, string batismo):
	Anfibio(id, classe, batismo)
{}

/**
 * construtor
 */
AnfibioExotico::AnfibioExotico(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, int total_mudas, string ultima_muda, string ibama, string pais_origem):
	Anfibio(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, total_mudas, ultima_muda),
	Exotico(ibama, pais_origem)
{}

/**
 * destrutor da classe AnfibioExotico
 */
AnfibioExotico::~AnfibioExotico(){
  delete m_veterinario;
  delete m_tratador;
}

/**
 * imprimir dados do anfibio exotico
 */
void 	AnfibioExotico::printAnimal(void){
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
	cout << "Mudas:\t\t"  		<< this->getTotalMudas() << endl;
	cout << "Ult Muda:\t"  		<< this->getUltimaMuda() << endl;
	cout << "Ibama:\t\t"    	<< this->getIbama() << endl;
	cout << "País Origem:\t"    << this->getPaisOrigem() << endl;
	cout << endl;
}