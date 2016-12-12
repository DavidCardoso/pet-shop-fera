/**
  * @file 		pessoa_tratador.cpp
  * @brief 		Classe Tratador
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/12/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/pessoa_tratador.cpp
  */
 
#include "../../include/petfera/pessoa_tratador.h"

/**
 * construtor da classe Tratador
 * @param   id
 * @param   funcao
 * @param   nome
 * @param   cpf
 * @param   tipo_sangue
 * @param   idade
 * @param   fator_rh
 * @param   especialidade
 */
Tratador::Tratador(int id, string funcao, string nome, string cpf, string tipo_sangue, short idade, char fator_rh, string especialidade):
	Funcionario(id, funcao, nome, cpf, tipo_sangue, idade, fator_rh, especialidade)
{}

/**
 * imprimir dados do tratador
 */
void  Tratador::printPessoa(void){
	cout << endl;
	cout << ">>>>> Ficha do funcionário <<<<<" << endl;
	cout << "ID:\t\t"			<< this->getID() << endl;
	cout << "Função:\t\t"     	<< this->getFuncao() << endl;
	cout << "Nome:\t\t"     	<< this->getNome() << endl;
	cout << "CPF:\t\t"     		<< this->getCPF() << endl;
	cout << "Tipo Sanque:\t"    << this->getTipoSangue() << endl;
	cout << "Idade:\t\t"      	<< this->getIdade() << endl;
	cout << "Fator RH:\t"     	<< this->getFatorRH() << endl;
	cout << "Especialidade:\t" 	<< this->getEspecialidade() << endl;
	cout << endl;
}
