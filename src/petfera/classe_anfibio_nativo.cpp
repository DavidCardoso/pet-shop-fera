/**
  * @file 		classe_anfibio_nativo.cpp
  * @brief 		Classe AnfibioNativo
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/src/petfera/classe_anfibio_nativo.cpp
  */

#include "../../include/petfera/classe_anfibio_nativo.h"

/**
 * construtor da classe AnfibioNativo
 */
AnfibioNativo::AnfibioNativo(int id, string classe, string batismo):
	Anfibio(id, classe, batismo)
{}

/**
 * construtor
 */
AnfibioNativo::AnfibioNativo(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, int total_mudas, string ultima_muda, string ibama, string uf_origem, string autorizacao):
	Anfibio(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, total_mudas, ultima_muda),
	Nativo(ibama, uf_origem, autorizacao)
{}

/**
 * destrutor da classe AnfibioNativo
 */
AnfibioNativo::~AnfibioNativo(){
  delete m_veterinario;
  delete m_tratador;
}

/**
 * imprimir dados do anfibio nativo
 */
void 	AnfibioNativo::printAnimal(void){
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
	cout << "UF Origem:\t"    	<< this->getUFOrigem() << endl;
	cout << "Autorizacao:\t"    << this->getAutorizacao() << endl;
	cout << endl;
}