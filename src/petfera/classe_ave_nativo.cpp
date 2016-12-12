/**
  * @file 		classe_ave_nativo.cpp
  * @brief 		Classe AveNativo
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/12/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/classe_ave_nativo.cpp
  */
 
#include "../../include/petfera/classe_ave_nativo.h"

/**
 * construtor da classe AveNativo
 */
AveNativo::AveNativo(int id, string classe, string batismo):
	Ave(id, classe, batismo)
{}

/**
 * construtor da classe abstrata AveNativo
 */
AveNativo::AveNativo(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador, int tamanho_bico, int envergadura, string ibama, string uf_origem, string autorizacao):
	Ave(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador, tamanho_bico, envergadura),
	Nativo(ibama, uf_origem, autorizacao)
{}

/**
 * destrutor da classe AveNativo
 */
AveNativo::~AveNativo(){
  delete m_veterinario;
  delete m_tratador;
}


/**
 * imprimir dados da ave nativa
 */
void 	AveNativo::printAnimal(void){
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
	cout << "UF Origem:\t"    	<< this->getUFOrigem() << endl;
	cout << "Autorizacao:\t"    << this->getAutorizacao() << endl;
	cout << endl;
}