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
#include <sstream>     // biblioteca de entrada e saída do C++
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

	string path_pessoas = "data/petfera/pessoas.csv"; /**< path_pessoas - arquivo de pessoas */
	string path_animais = "data/petfera/animais.csv"; /**< path_animais - arquivo de animais */
	string path_exportar = "data/petfera/exportar.csv"; /**< path_exportar - arquivo para animais exportados */

	map<int, Pessoa*> pessoas; /**< pessoas - dicionario de objetos Pessoa */
	map<int, Animal*> animais; /**< animais - dicionario de objetos Animal */

	int pessoas_last_id = 0; /**< pessoas_last_id - ultimo ID de pessoas */
	int animais_last_id = 0; /**< animais_last_id - ultimo ID de animais */

	pair<int, string> arg_classe(0, ""); 		/**< arg_classe - posicao e valor do argumento */
	pair<int, string> arg_veterinario(0, ""); 	/**< arg_veterinario - posicao e valor do argumento */
	pair<int, string> arg_tratador(0, ""); 		/**< arg_tratador - posicao e valor do argumento */

	// valida parametros passados via linha de comando
	if(argc != 2 && argc != 4 && argc != 6 && argc != 8) {
		cerr << "Erro: quantidade de parametros incorreta!" << endl;
		cout << "Exemplo de chamada correta:" << endl 
			 <<"\t./exportar.exe -c <classe> -v <veterinaro> -t <tratador> <arquivo_exportar>" << endl;
		return -1;
	}else{
		path_exportar = argv[argc-1]; // ultimo argumento

		if (argc >= 4) // tem argumentos opcionais (-c, -v, -t)
		{
			int i = 1;
			while(i < argc-1)
			{
				string ss = argv[i]; /**< ss - converte para string o valor do argumento para comparar adequadamente */
				if (ss == "-c")
				{
					arg_classe.first  = i;
					arg_classe.second = argv[i+1];
				}else
				if (ss == "-v")
				{
					arg_veterinario.first  = i;
					arg_veterinario.second = argv[i+1];
				}else
				if (ss == "-t")
				{
					arg_tratador.first  = i;
					arg_tratador.second = argv[i+1];
				}

				i+=2;
			}

			if (arg_classe.first == 0 && arg_veterinario.first == 0 && arg_tratador.first == 0){
				cerr << "Erro: parametros opcionais incorretos!" << endl;
				cout << "Exemplo de chamada correta:" << endl 
					 <<"\t./exportar.exe -c <classe> -v <veterinaro> -t <tratador> <arquivo_exportar>" << endl;
				return -1;
			}
		}
		
	}

	cout << "Atenção: os dados serão salvos em:" << endl;
	cout << path_exportar << endl;
	cout << endl << endl;

	// preenche dicionario de pessoas
	fillPessoas(pessoas, path_pessoas, pessoas_last_id);

	// preenche dicionario de animais
	fillAnimais(pessoas, animais, path_animais, animais_last_id);


	// realiza filtros no dicionario de animais antes de exportar
	if (arg_classe.first != 0){
		if (filterExport(pessoas, animais, "-c", arg_classe.second) )
			cout << "Filtro de classe realizado com sucesso!" << endl;
		else
			cout << "Sem ocorrencias para a classe informada!" << endl;
	}
	if (arg_veterinario.first != 0){
		if (filterExport(pessoas, animais, "-v", arg_veterinario.second) )
			cout << "Filtro de veterinario realizado com sucesso!" << endl;
		else
			cout << "Sem ocorrencias para o veterinario informado!" << endl;
	}
	if (arg_tratador.first != 0){
		if (filterExport(pessoas, animais, "-t", arg_tratador.second) )
			cout << "Filtro de tratador realizado com sucesso!" << endl;
		else
			cout << "Sem ocorrencias para o tratador informado!" << endl;
	}


	// exporta dados para um arquivo
	if ( export2File(pessoas, animais, path_exportar) ){
		cout << endl;
		cout << "Resultado: " << animais.size() << endl 
			 << "Dados salvos no arquivo:" << endl
			 << path_exportar << endl;

		// limpa os dicionarios em memoria
		pessoas.clear();
		animais.clear();
	}else{
		cerr << "Erro: Informações não puderam ser salvas!" << endl;
		return -1;
	}


	return 0;
}
