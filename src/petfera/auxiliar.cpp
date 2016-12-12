/**
  * @file 		auxiliar.cpp
  * @brief 		Funções auxiliares - Biblioteca
  * @details 	Implementação de funções auxiliares
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/12/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/auxiliar.cpp
  */

#include "../../include/petfera/auxiliar.h" // funções auxiliares


using namespace std;

namespace auxiliar {

	/**
	 * limpar entrada padrão "cin"
	 */
	void clearEntrada(){
		cin.ignore(10000, '\n');
		cin.clear();
	}

	/**
	 * preenche dicionario de objeto Pessoa com conteudo do arquivo
	 * @param  pessoas      - referencia para a dicionario
	 * @param  path_pessoas - caminho do arquivo
	 * @param  pessoas_last_id - ultimo ID de pessoa
	 * @return boolean
	 */
	bool fillPessoas(map<int, Pessoa*> &pessoas, string path_pessoas, int &pessoas_last_id){

		// ABRE ARQUIVO PESSOAS
		ifstream file_pessoas;
		file_pessoas.open(path_pessoas, ios::in);

		// lê arquivo de pessoas
		if(file_pessoas){

			string str;
			vector<string> v;

			// instancia objeto pessoa e alimenta dicionario pessoas
			while(!file_pessoas.eof()){
				getline(file_pessoas, str);
				if(str == "") continue;
				v = explode(str,';');

				// Pessoa(id, nome, cpf, tipo_sangue, idade, fator_rh)
				// Funcionario(especialidade)
				if(v[1] == "Tratador"){
					pessoas.insert( pair<int, Pessoa*>(stoi(v[0]), new Tratador( stoi(v[0]), v[1], v[2], v[3], v[4], (short)stoi(v[5]), v[6][0], v[7] ) ) );
				}else if(v[1] == "Veterinario"){
					pessoas.insert( pair<int, Pessoa*>(stoi(v[0]), new Veterinario( stoi(v[0]), v[1], v[2], v[3], v[4], (short)stoi(v[5]), v[6][0], v[7] ) ) );
				}
				
				// pessoas.at(stoi(v[0])->printPessoa();

				pessoas_last_id = stoi(v[0]);
				str = "";
				v.clear();
			}

			file_pessoas.close();
			return true;
		}else{
			cerr << "Não foi possível abrir o arquivo de funcionarios!" << endl
			 	 << "Entretanto, os dados serão salvos no arquivo " << path_pessoas << endl;
			return false;
		}
	}

	/**
	 * preenche dicionario de objeto Animal com conteudo do arquivo
	 * @param  pessoas      - referencia para a dicionario
	 * @param  animais      - referencia para a dicionario
	 * @param  path_animais - caminho do arquivo
	 * @param  animais_last_id - ultimo ID de animal
	 * @return boolean
	 */
	bool fillAnimais(map<int, Pessoa*> &pessoas, map<int, Animal*> &animais, string path_animais, int &animais_last_id){

		// ABRE ARQUIVO DE ANIMAIS
		ifstream file_animais;
		file_animais.open(path_animais, ios::in);

		// lê arquivo de animais
		if(file_animais){

			string str;
			vector<string> v;

			// instancia objeto animal e alimenta dicionario animais
			while(!file_animais.eof()){
				getline(file_animais, str);
				if(str == "") continue;
				v = explode(str,';');

				Pessoa* veterinario = nullptr;
				Pessoa* tratador 	= nullptr;

				for (map<int, Pessoa*>::iterator it = pessoas.begin(); it != pessoas.end(); ++it){
					if( it->second->getID() == stoi(v[8]) )
						veterinario = it->second;
					if( it->second->getID() == stoi(v[9]) )
						tratador = it->second;
				}
				
				// Animal(id, classe, nome, cientifico, batismo, dieta, sexo, tamanho, veterinario, tratador)
				// Anfibio(total_mudas, ultima_muda)
				// Ave(tamanho_bico, envergadura)
				// Mamifero(cor_pelo)
				// Reptil(venenoso, tipo_veneno)
				// Exotico(ibama, pais_origem)
				// Nativo(ibama, uf_origem, autorizacao)
				// 
				// 1;MamiferoExotico;Leão;Panthera leo;Simba;Carne;M;2;6;5;laranja;ibama;Congo
				
				if(v[1] == "AnfibioExotico")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new AnfibioExotico( 	stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, stoi(v[10]), v[11], v[12], v[13] ) ) );
				
				else if(v[1] == "AnfibioNativo")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new AnfibioNativo( 	stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, stoi(v[10]), v[11], v[12], v[13], v[14] ) ) );
				
				else if(v[1] == "AveExotico")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new AveExotico( 		stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, stoi(v[10]), stoi(v[11]), v[12], v[13] ) ) );
				
				else if(v[1] == "AveNativo")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new AveNativo( 		stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, stoi(v[10]), stoi(v[11]), v[12], v[13], v[14] ) ) );
				
				else if(v[1] == "MamiferoExotico")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new MamiferoExotico( 	stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, v[10], v[11], v[12] ) ) );
				
				else if(v[1] == "MamiferoNativo")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new MamiferoNativo( 	stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, v[10], v[11], v[12], v[13] ) ) );
				
				else if(v[1] == "ReptilExotico")
					animais.insert(
						pair<int, Animal*>(stoi(v[0]), new ReptilExotico( 	stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, v[10]=="1", v[11], v[12], v[13] ) ) );
				
				else if(v[1] == "ReptilNativo")
					animais.insert( 
						pair<int, Animal*>(stoi(v[0]), new ReptilNativo( 	stoi(v[0]), v[1], v[2], v[3], v[4], v[5], v[6][0], stof(v[7]), veterinario!=nullptr?veterinario:0, tratador!=nullptr?tratador:0, v[10]=="1", v[11], v[12], v[13], v[14] ) ) );
				
				// animais.at(stoi(v[0])->printAnimal();

				animais_last_id = stoi(v[0]);
				str = "";
				v.clear();
			}

			file_animais.close();
			return true;
		}else{
			cerr << "Não foi possível abrir o arquivo de animais!" << endl;
			cerr << "Entretanto, os dados serão salvos no arquivo " << path_animais << endl;
			return false;
		}
	}
		

	/**
	 * função explode()
	 * @details 	quebra uma string de acordo com um caracter separador
	 * @param 		s - string
	 * @param 		c - caracter
	 * @return 		vetor contendo as partes da string
	 */
	const vector<string> explode(const string s, const char c){
		
		string buff{""};
		vector<string> v;
		
		for(auto n:s)
		{
			if(n != c) buff+=n; else
			if(n == c) { v.push_back(buff); buff = ""; }
		}
		if(buff != "") { v.push_back(buff); buff = ""; }
		
		return v;
	}

	/**
	 * salvar dados das dicionarios de objetos Pessoa e Animal em arquivos
	 * @param 	dicionario_pessoas - dicionario de ponteiro para objeto Pessoa
	 * @param 	dicionario_animais - dicionario de ponteiro para objeto Animal
	 * @param 	path_pessoas - caminho do arquivo pessoa
	 * @param 	path_animais - caminho do arquivo animal
	 * @return 	boolean
	 */
	bool saveInFiles(map<int, Pessoa*> dicionario_pessoas, map<int, Animal*> dicionario_animais, string path_pessoas, string path_animais){

		// PESSOA
		ofstream save_pessoa;
		save_pessoa.open(path_pessoas, ios::out | ios::trunc);

		if ( save_pessoa ){
			for (map<int, Pessoa*>::iterator it = dicionario_pessoas.begin(); it != dicionario_pessoas.end(); ++it){
				save_pessoa << *(it->second);
			}
			save_pessoa.close();
		}else{
			cerr << "Não foi possível abrir o arquivo " << path_pessoas << endl;
			return false;
		}

		// ANIMAL
		ofstream save_animal;
		save_animal.open(path_animais, ios::out | ios::trunc);

		if ( save_animal ){
			for (map<int, Animal*>::iterator it = dicionario_animais.begin(); it != dicionario_animais.end(); ++it){
				save_animal << *(it->second);
			}
			save_animal.close();
		}else{
			cerr << "Não foi possível abrir o arquivo " << path_animais << endl;
			return false;
		}

		return true;
	}

	/**
	 * salvar dados dos animais filtrados em um arquivo de exportação
	 * @param 	dicionario_pessoas - dicionario de ponteiro para objeto Pessoa
	 * @param 	dicionario_animais - dicionario de ponteiro para objeto Animal
	 * @param 	path_exportar - caminho do arquivo de exportação
	 * @return 	boolean
	 */
	bool export2File(map<int, Pessoa*> dicionario_pessoas, map<int, Animal*> dicionario_animais, string path_exportar){

		// ANIMAL
		ofstream save_animal;
		save_animal.open(path_exportar, ios::out | ios::trunc);

		if ( save_animal ){
			for (map<int, Animal*>::iterator it = dicionario_animais.begin(); it != dicionario_animais.end(); ++it){
				save_animal << *(it->second);
			}
			save_animal.close();
		}else{
			cerr << "Não foi possível abrir o arquivo " << path_exportar << endl;
			return false;
		}

		return true;
	}

	/**
	 * filtrar animais antes de exportar
	 * @param 	dicionario_pessoas - dicionario de ponteiro para objeto Pessoa
	 * @param 	dicionario_animais - dicionario de ponteiro para objeto Animal
	 * @param 	arg_tipo 	- tipo do argumento a ser usado como filtro
	 * @param 	arg_valor 	- valor do argumento a ser usado como filtro
	 * @return 	boolean
	 */
	bool filterExport(map<int, Pessoa*> &dicionario_pessoas, map<int, Animal*> &dicionario_animais, string arg_tipo, string arg_valor){

		bool retorno = false;

		// varre o dicionario de animais deletando aqueles que não passam no filtro
		for (map<int, Animal*>::iterator it = dicionario_animais.begin(); it != dicionario_animais.end(); ++it){

			if( arg_tipo == "-v" && it->second->getVeterinario() != nullptr ){

				string v = it->second->getVeterinario()->getNome();
				transform(v.begin(), v.end(), v.begin(), ::tolower); // converte (iterator) para minusculo
				transform(arg_valor.begin(), arg_valor.end(), arg_valor.begin(), ::tolower); // converte (digitada) para minusculo

				if(v.find(arg_valor) != std::string::npos) // testa se não há ocorrencia da string digitada e apaga animal
					retorno = true;
				else
					dicionario_animais.erase(it);
			} 
			else
			if( arg_tipo == "-t" && it->second->getTratador() != nullptr ){

				string t = it->second->getTratador()->getNome();
				transform(t.begin(), t.end(), t.begin(), ::tolower); // converte (iterator) para minusculo
				transform(arg_valor.begin(), arg_valor.end(), arg_valor.begin(), ::tolower); // converte (digitada) para minusculo

				if(t.find(arg_valor) != std::string::npos) // testa se não há ocorrencia da string digitada e apaga animal
					retorno = true;
				else
					dicionario_animais.erase(it);
			} 
			else
			if( arg_tipo == "-c" ){

				string c = it->second->getClasse();
				transform(c.begin(), c.end(), c.begin(), ::tolower); // converte (iterator) para minusculo
				transform(arg_valor.begin(), arg_valor.end(), arg_valor.begin(), ::tolower); // converte (digitada) para minusculo

				if(c.find(arg_valor) != std::string::npos) // testa se não há ocorrencia da string digitada e apaga animal
					retorno = true;
				else
					dicionario_animais.erase(it);
			}
		}

		return retorno;
	}

	/**
	 * pesquisar uma pessoa pelo ID
	 * @param dicionario_pessoas
	 * @return iterador para dicionario de pessoas
	 */
	map<int, Pessoa*>::iterator searchPessoa(map<int, Pessoa*> &dicionario_pessoas){

		int id;

		cout << "Digite o ID do funcionário: ";
		cin >> id;

		if(!cin.fail()){

			for (map<int, Pessoa*>::iterator it = dicionario_pessoas.begin(); it != dicionario_pessoas.end(); ++it){
				
				if( it->second->getID() == id ){
					it->second->printPessoa();
					return it;
				}
			}
		}

		else 
			cerr << "ID inválido!" << endl;
		
		cout << "Fim da busca!" << endl;
		return dicionario_pessoas.end();
	}

	/**
	 * pesquisar um animal pelo ID
	 * @param dicionario_animais
	 * @param all_options - se true, mostra todas as opções
	 * @return iterador para dicionario de animais
	 */
	map<int, Animal*>::iterator searchAnimal(map<int, Animal*> &dicionario_animais, bool all_options){

		int 	id = 0;
		int 	funcionario = 0;
		string 	classe = "";
		int 	user_option = 1;

		if(all_options){
			cout << "Pesquisar animal por:" << endl
				<< " (1) ID" << endl
				<< " (2) Veterinário" << endl
				<< " (3) Tratador" << endl
				<< " (4) Classe" << endl;

			cin >> user_option;

			cout << endl;

			switch(user_option){

				case 1: // por ID do animal
					cout << "Digite o ID do animal: ";
					cin >> id;
				break;

				case 2: // por ID veterinario
					cout << "Digite o ID do veterinario: ";
					cin >> funcionario;
				break;

				case 3: // por ID tratador
					cout << "Digite o ID do tratador: ";
					cin >> funcionario;
				break;

				case 4: // por classe do animal
					cout << "Digite uma classe ou parte da palavra: ";
					cin >> classe;
				break;

				default:
					cerr << "Erro: Opção inválida!" << endl;
			}
		}else{
			cout << "Digite o ID do animal: ";
			cin >> id;
		}

		

		if(!cin.fail()){

			for (map<int, Animal*>::iterator it = dicionario_animais.begin(); it != dicionario_animais.end(); ++it){
				
				if( user_option == 1 && it->second->getID() == id ){
					it->second->printAnimal();
					return it;
				} else
				if( user_option == 2 && it->second->getVeterinario() != nullptr && it->second->getVeterinario()->getID() == funcionario ){
					it->second->printAnimal();
				} else
				if( user_option == 3 && it->second->getTratador() != nullptr && it->second->getTratador()->getID() == funcionario ){
					it->second->printAnimal();
				} else
				if( user_option == 4 ){
					string c = it->second->getClasse();
					transform(c.begin(), c.end(), c.begin(), ::tolower); // converte classe (iterator) para minusculo
					transform(classe.begin(), classe.end(), classe.begin(), ::tolower); // converte classe (digitada) para minusculo

					// if(c == classe)
					if(c.find(classe) != std::string::npos) // testa se há ocorrencia da string digitada
						it->second->printAnimal();
				}
			}
		}
		else
			cerr << "Erro: Entrada inválida!" << endl;

		cout << "Fim da busca!" << endl;
		return dicionario_animais.end();
	}

	/**
	 * cadastro rápido de um novo animal (id, classe e batismo)
	 * @param  animais - dicionario de animais
	 * @param  animais_last_id - ultimo ID animal
	 * @return boolean
	 */
	bool newQuickAnimal(map<int, Animal*> &animais, int &animais_last_id){
		int 	id;
		string 	batismo;
		string 	classe;

		clearEntrada();

		cout << "Digite o nome de batismo do animal: ";
		getline(cin, batismo);

		cout << endl;

		cout << "Digite a classe do animal: ";
		getline(cin, classe);

		cout << endl;

		if(!cin.fail()){

			if (!animais.empty())
				id = animais_last_id + 1;
			else
				id = 1;

			if(classe == "AnfibioExotico")
				animais.insert( pair<int, Animal*>(id, new AnfibioExotico( id, classe, batismo ) ) );
			
			else if(classe == "AnfibioNativo")
				animais.insert( pair<int, Animal*>(id, new  AnfibioNativo( id, classe, batismo ) ) );
			
			else if(classe == "AveExotico")
				animais.insert( pair<int, Animal*>(id, new  AveExotico( id, classe, batismo ) ) );
			
			else if(classe == "AveNativo")
				animais.insert( pair<int, Animal*>(id, new  AveNativo( id, classe, batismo ) ) );
			
			else if(classe == "MamiferoExotico")
				animais.insert( pair<int, Animal*>(id, new  MamiferoExotico( id, classe, batismo ) ) );
			
			else if(classe == "MamiferoNativo")
				animais.insert( pair<int, Animal*>(id, new  MamiferoNativo( id, classe, batismo ) ) );
			
			else if(classe == "ReptilExotico")
				animais.insert( pair<int, Animal*>(id, new  ReptilExotico( id, classe, batismo ) ) );
			
			else if(classe == "ReptilNativo")
				animais.insert( pair<int, Animal*>(id, new  ReptilNativo( id, classe, batismo ) ) );

			else {
				cerr << "Classe inválida!" << endl
					 << "Digite uma das classes abaixo: " << endl
					 << "AnfibioExotico" << endl
					 << "AnfibioNativo" << endl
					 << "AveExotico" << endl
					 << "AveNativo" << endl
					 << "MamiferoExotico" << endl
					 << "MamiferoNativo" << endl
					 << "ReptilExotico" << endl
					 << "ReptilNativo" << endl
					 << endl;

					 return false;
			}

			cout << "Cadastro rápido realizado com sucesso!" << endl;
			animais_last_id++;
			return true;
		}else{
			cerr << "Erro na leitura dos dados!" << endl;
			clearEntrada();
			return false;
		}
	}

	/**
	 * cadastro de novo funcionário
	 * @param  	dicionario_pessoas 
	 * @param  	pessoas_last_id 
	 * @return 	boolean
	 */
	bool newFuncionario(map<int, Pessoa*> &dicionario_pessoas, int &pessoas_last_id){

		int 	id, idade;
		string 	nome, funcao, cpf, tipo_sangue, especialidade;
		char 	fator_rh;

		clearEntrada();

		// funcao
		cout 	<< "Escolha a função do funcionário: " << endl
				<< "(1) Veterinario" << endl
				<< "(2) Tratador" << endl;
		getline(cin, funcao);

		// nome
		cout << "Digite o nome: ";
		getline(cin, nome);
		cout << endl;

		// cpf
		cout << "Digite o CPF: ";
		getline(cin, cpf);
		cout << endl;

		// tipo_sangue
		cout << "Digite o tipo de sangue: ";
		getline(cin, tipo_sangue);
		cout << endl;

		// idade
		cout << "Digite a idade: ";
		cin >> idade;
		cout << endl;

		// fator_rh
		cout << "Digite o fator RH (+ ou -) do sangue: ";
		cin >> fator_rh;
		cout << endl;

		clearEntrada();

		// especialidade
		cout << "Digite a especialidade: ";
		getline(cin, especialidade);
		cout << endl;

		if( !cin.fail() ){

			if (fator_rh != '+' && fator_rh != '-'){
				cerr << "Erro: Fator RH inválido!" << endl;
				return false;
			}

			if(!dicionario_pessoas.empty())
				id = pessoas_last_id + 1;
			else
				id = 1;

			// Pessoa(id, nome, cpf, tipo_sangue, idade, fator_rh)
			// Funcionario(especialidade)
			if (funcao == "1"){
				funcao = "Veterinario";
				dicionario_pessoas.insert( pair<int, Pessoa*>(id, new Veterinario( id, funcao, nome, cpf, tipo_sangue, idade, fator_rh, especialidade ) ) );
			}else if (funcao == "2"){
				funcao = "Tratador";
				dicionario_pessoas.insert( pair<int, Pessoa*>(id, new Tratador( id, funcao, nome, cpf, tipo_sangue, idade, fator_rh, especialidade ) ) );
			}else{
				cerr << "Erro: Função inválida!" << endl;
				return false;
			}
			
			cout << "Cadastro realizado com sucesso!" << endl << endl;
			pessoas_last_id++;
			return true;

		}else{
			cerr << "Erro na leitura dos dados!" << endl;
			clearEntrada();

			return false;
		}

	}

	/**
	 * excluir funcionário pelo ID
	 * @param dicionario_pessoas
	 * @param dicionario_animais
	 */
	void delPessoa(map<int, Pessoa*> &dicionario_pessoas, map<int, Animal*> &dicionario_animais){

		map<int, Pessoa*>::iterator it_pessoa;
		map<int, Animal*>::iterator it_animal;

		it_pessoa = searchPessoa(dicionario_pessoas);

		for(it_animal = dicionario_animais.begin(); it_animal != dicionario_animais.end(); ++it_animal){

			if( it_animal->second->getVeterinario() == it_pessoa->second )
				it_animal->second->setVeterinario(nullptr);

			if( it_animal->second->getTratador() == it_pessoa->second )
				it_animal->second->setTratador(nullptr);
		}

		if(it_pessoa != dicionario_pessoas.end()){

			it_pessoa = dicionario_pessoas.erase(it_pessoa);
			cout << "Exclusão realizada com sucesso!" << endl;

		}else{
			cerr << "Erro: Exclusão não realizada!" << endl;
		}
		
	}

	/**
	 * excluir animal pelo ID
	 * @param dicionario_animais
	 */
	void delAnimal(map<int, Animal*> &dicionario_animais){

		map<int, Animal*>::iterator it_animal;

		it_animal = searchAnimal(dicionario_animais, false);

		if (it_animal != dicionario_animais.end()){

			it_animal = dicionario_animais.erase(it_animal);
			cout << "Exclusão realizada com sucesso!" << endl;

		}else{
			cerr << "Erro: Exclusão não realizada!" << endl;
		}	

	}

	/**
	 * Imprimir menu de opçoes para o usuário
	 */
	void printMenu(void){

		cout << endl;
		cout << ">>>>>>>>>>>>>> MENU <<<<<<<<<<<<<< "<< endl;
		cout << " (0) Sair" << endl;
		cout << " (1) Pesquisar funcionário" << endl;
		cout << " (2) Pesquisar animal" << endl;
		cout << " (3) Excluir funcionário pelo ID" << endl;
		cout << " (4) Excluir animal pelo ID" << endl;
		cout << " (5) Cadastro de funcionário" << endl;
		cout << " (6) Cadastro rápido de animal" << endl;
		cout << endl;
		cout << " Digite o número de uma opção: ";
	}

}