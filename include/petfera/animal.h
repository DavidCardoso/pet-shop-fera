/**
  * @file 		animal.h
  * @brief 		Classe abstrata Animal
  * @details 	Declaração dos atributos e dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		07/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/animal.h
  */
 
#ifndef ANIMAL_H
#define ANIMAL_H
#pragma once

#include <iostream>
#include <string>
#include "pessoa.h"

using namespace std;

/**
 * classe abstrata Animal
 */
class Animal
{

private:
	virtual std::ostream& print(std::ostream&) const = 0;

protected:
	int 			m_id;
	string 			m_classe;
	string 			m_nome;
	string 			m_cientifico;
	string 			m_batismo;
	string 			m_dieta;
	char 			m_sexo;
	float 			m_tamanho;
	Pessoa* 		m_veterinario;
	Pessoa*	 		m_tratador;
	

public:

	/**
	 * construtor da classe abstrata Animal
	 */
	Animal(int id, string classe, string batismo);

	/**
	 * construtor da classe abstrata Animal
	 */
	Animal(int, string, string, string, string, string, char, float, Pessoa*, Pessoa*);

	/**
	 * destrutor da classe abstrata Animal
	 */
	virtual ~Animal(){};
	
	// getters

	int 	getID(void);
	string 	getClasse(void);
	string 	getNome(void);
	string 	getCientifico(void);
	string 	getBatismo(void);
	string 	getDieta(void);
	char 	getSexo(void);
	float 	getTamanho(void);
	Pessoa* getVeterinario(void);
	Pessoa* getTratador(void);

	// setters

	void 	setID(int);
	void 	setClasse(string);
	void 	setNome(string);
	void 	setCientifico(string);
	void 	setBatismo(string);
	void 	setDieta(string);
	void 	setSexo(char);
	void 	setTamanho(float);
	void 	setVeterinario(Pessoa*);
	void 	setTratador(Pessoa*);

	// print
	virtual void 	printAnimal(void) = 0;

	// operadores
	friend std::ostream& operator << (std::ostream& os, const Animal& b) {
		return b.print(os); // polymorphic print via reference
	}
};

#endif // ANIMAL_H
