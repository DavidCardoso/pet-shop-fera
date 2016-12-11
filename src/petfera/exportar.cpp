/**
  * @file 		exportar.cpp
  * @brief 		Programa Exportar Pet Fera
  * @details 	Esse programa tem como finalidade ler um arquivo com dados previamente salvos
  *           	pelo programa principal Pet Fera, fazer uma pesquisa com base nos parâmetros
  *           	via linha de comando e exportar para um arquivo de saída.
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/12/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/exportar.cpp
  */

#include <iostream>     // biblioteca de entrada e saída do C++
#include <fstream>    	// biblioteca de manipulação de arquivos do C++
#include "../../include/petfera/auxiliar.h" // funções auxiliares

using namespace std;
using namespace auxiliar;

/**
 * @brief 	Função principal do programa Exportar Pet Fera
 * @return 	inteiro
 */
int main( int argc, char* const argv[] ){

	cout << endl;
	cout << "######## Programa Exportar Pet Fera ########" << endl << endl;

	string path_pessoas = "data/petfera/pessoas.csv"; /**< path_pessoas - caminho do arquivo de pessoas */
	string path_animais = "data/petfera/animais.csv"; /**< path_animais - caminho do arquivo de animais */
	string path_exportar = "data/petfera/exportar.csv"; /**< path_exportar - caminho do arquivo para animais exportados */

	map<int, Pessoa*> pessoas; /**< pessoas - dicionario de objetos Pessoa */
	map<int, Animal*> animais; /**< animais - dicionario de objetos Animal */

	int pessoas_last_id = 0; /**< pessoas_last_id - ultimo ID de pessoas */
	int animais_last_id = 0; /**< animais_last_id - ultimo ID de animais */

	int user_option = 0; /**< user_option - opção escolhida pelo usuario */

	// valida parametros passados via linha de comando
	if(argc < 2 || argc > 9) {
		cerr << "Erro: quantidade de parametros incorreta!" << endl;
		return -1;
	}

	cout << "Atenção: os dados serão salvos em:" << endl;
	cout << path_exportar << endl;
	cout << endl;

	// preenche dicionario de pessoas
	fillPessoas(pessoas, path_pessoas, pessoas_last_id);

	// preenche dicionario de animais
	fillAnimais(pessoas, animais, path_animais, animais_last_id);

	// tratamento das combinações dos paramêtros
	cout << endl;

	if(user_option){

		switch(user_option){

			case 1: // pesquisar pessoa
				searchPessoa(pessoas);
			break;

			case 2: // pesquisar animal
				searchAnimal(animais);
			break;

			default:
				cout << "Sorry! Opção não implementada! =/" << endl;

		}

	}

	// exporta dados pesquisados para um arquivo
	if ( export2File(pessoas, animais, path_pessoas, path_animais) ){
		cout << endl;
		cout << "Dados salvos no arquivo:" << endl;
		cout << path_pessoas << endl;
		cout << endl;

		// limpa os dicionarios em memoria
		pessoas.clear();
		animais.clear();
	}else{
		cerr << "Erro: Informações não puderam ser salvas!" << endl;
		return -1;
	}


	return 0;
}
