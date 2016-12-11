/**
  * @file 		main.cpp
  * @brief 		Programa Pet Fera
  * @details 	Pet Fera é uma loja que comercializa animais silvestres com os devidos cuidados e autorizações do
  *           	Instituto Brasileiro do Meio Ambiente e dos Recursos Naturais Renováveis (IBAMA). Para garantir
  *           	a saúde e o bem-estar dos animais sob sua tutela, a Pet Fera mantém uma equipe de profissionais
  *           	capacitados, incluindo um grupo de veterinários e tratadores. Assim, para cada animal são
  *           	atribuídos um veterinário e um tratador que juntos garantirão a saúde e o bem-estar dele.
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/12/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/main.cpp
  */

#include <iostream>     // biblioteca de entrada e saída do C++
#include <fstream>    	// biblioteca de manipulação de arquivos do C++
#include "../../include/petfera/auxiliar.h" // funções auxiliares

using namespace std;
using namespace auxiliar;

/**
 * @brief 	Função principal do programa Pet Fera
 * @return 	inteiro
 */
int main( int argc, char* const argv[] ){

	cout << endl;
	cout << "######## Programa Pet Fera ########" << endl << endl;

	string path_pessoas = "data/petfera/pessoas.csv"; /**< path_pessoas - caminho do arquivo de pessoas */
	string path_animais = "data/petfera/animais.csv"; /**< path_animais - caminho do arquivo de animais */

	map<int, Pessoa*> pessoas; /**< pessoas - dicionario de objetos Pessoa */
	map<int, Animal*> animais; /**< animais - dicionario de objetos Animal */

	int pessoas_last_id = 0; /**< pessoas_last_id - ultimo ID de pessoas */
	int animais_last_id = 0; /**< animais_last_id - ultimo ID de animais */
	
	int user_option = 0; /**< user_option - opção escolhida pelo usuario */

	// valida parametros passados via linha de comando
	if(argc == 3) {
		path_pessoas = argv[1];
		path_animais = argv[2];
	}

	cout << "Atenção: os dados serão salvos em:" << endl;
	cout << path_pessoas << endl;
	cout << path_animais << endl;
	cout << endl;

	// preenche dicionario de pessoas
	fillPessoas(pessoas, path_pessoas, pessoas_last_id);

	// preenche dicionario de animais
	fillAnimais(pessoas, animais, path_animais, animais_last_id);

	// loop responsável pela interação com o usuário
	MENU:
	do{
		printMenu();

		cin >> user_option;

		cout << endl;

		if(!cin.fail()){

			switch(user_option){

				case 0: // sair do programa
					cout << "Finalizando..." << endl;
					goto FINALIZAR;
				break;

				case 1: // pesquisar pessoa
					searchPessoa(pessoas);
				break;

				case 2: // pesquisar animal
					searchAnimal(animais);
				break;

				case 3: // excluir cadastro da pessoa
					delPessoa(pessoas, animais);
				break;

				case 4: // excluir cadastro do animal
					delAnimal(animais);
				break;

				case 5: // realizar cadastro de funcionário
					newFuncionario(pessoas, pessoas_last_id);
				break;

				case 6: // realizar cadastro rápido de animal
					newQuickAnimal(animais, animais_last_id);
				break;

				default:
					cout << "Sorry! Opção não implementada! =/" << endl;

			}

		}else{
			cerr << "Opção inválida!" << endl;
			clearEntrada();
			user_option = 99;
		}

	}while(user_option != 0);

	FINALIZAR:
	if ( saveInFiles(pessoas, animais, path_pessoas, path_animais) ){
		cout << endl;
		cout << "Dados salvos nos arquivos:" << endl;
		cout << path_pessoas << endl;
		cout << path_animais << endl;
		cout << endl;

		// limpa as istas
		pessoas.clear();
		animais.clear();
	}else{
		cerr << "Informações não puderam ser salvas em arquivos!" << endl;
		cout << "Deseja realmente sair?" << endl
			<< "(0) Sim" << endl
			<< "(1) Não " << endl;

		cin >> user_option;

		if (!cin.fail() && user_option == 0)
			return -1;
		else
			goto MENU;
	}


	return 0;
}
