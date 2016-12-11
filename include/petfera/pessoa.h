/**
  * @file 		pessoa.h
  * @brief 		Classe abstrata Pessoa
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/pessoa.h
  */
 
#ifndef PESSOA_H
#define PESSOA_H
#pragma once

#include <iostream>
#include <string>

using namespace std;

/**
 * classe abstrata Pessoa
 */
class Pessoa
{
private:
	virtual std::ostream& print(std::ostream&) const = 0;

protected:
	int 	m_id;
	string 	m_funcao;
	string 	m_nome;
	string 	m_cpf;
	string	m_tipo_sangue;
	short 	m_idade;
	char 	m_fator_rh;

public:

	/**
	 * construtor
	 */
	Pessoa(int, string, string, string, string, short, char);

	/**
	 * destrutor
	 */
	virtual ~Pessoa(){};

	// getters
	
	int 	getID(void);
	string 	getFuncao(void);
	string 	getNome(void);
	string 	getCPF(void);
	string 	getTipoSangue(void);
	short 	getIdade(void);
	char 	getFatorRH(void);

	// setters
	
	void 	setID(int);
	void 	setFuncao(string);
	void 	setNome(string);
	void 	setCPF(string);
	void 	setTipoSangue(string);
	void 	setIdade(short);
	void 	setFatorRH(char);

	// print
	virtual void 		printPessoa(void) = 0;
	

	// operadores
	bool 	operator== (int id);
	Pessoa* operator< (Pessoa* p);
	friend std::ostream& operator << (std::ostream& os, const Pessoa& b) {
		return b.print(os); // polymorphic print via reference
	}
};
 
 
#endif // PESSOA_H
 