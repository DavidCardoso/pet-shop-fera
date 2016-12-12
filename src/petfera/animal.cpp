/**
  * @file 		animal.cpp
  * @brief 		Classe abstrata Animal
  * @details 	Implementação dos métodos da classe
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/12/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto3/blob/master/src/petfera/animal.cpp
  */
 
#include "../../include/petfera/animal.h"

/**
 * construtor da classe abstrata Animal
 */
Animal::Animal(int id, string classe, string batismo):
	m_id(id),
	m_classe(classe),
	m_nome(""),
	m_cientifico(""),
	m_batismo(batismo),
	m_dieta(""),
	m_sexo('-'),
	m_tamanho(0),
	m_veterinario(nullptr),
	m_tratador(nullptr)
{}

/**
 * construtor da classe abstrata Animal
 */
Animal::Animal(int id, string classe, string nome, string cientifico, string batismo, string dieta, char sexo, float tamanho, Pessoa* veterinario, Pessoa* tratador):
	m_id(id),
	m_classe(classe),
	m_nome(nome),
	m_cientifico(cientifico),
	m_batismo(batismo),
	m_dieta(dieta),
	m_sexo(sexo),
	m_tamanho(tamanho),
	m_veterinario(veterinario),
	m_tratador(tratador)
{}

int 	Animal::getID(void){
	return m_id;
}


string 	Animal::getClasse(void){
	return m_classe;
}


string 	Animal::getNome(void){
	return m_nome;
}


string 	Animal::getCientifico(void){
	return m_cientifico;
}


string 	Animal::getBatismo(void){
	return m_batismo;
}


string 	Animal::getDieta(void){
	return m_dieta;
}


char 	Animal::getSexo(void){
	return m_sexo;
}


float 	Animal::getTamanho(void){
	return m_tamanho;
}


Pessoa*	Animal::getVeterinario(void){
	return m_veterinario;
}


Pessoa*	Animal::getTratador(void){
	return m_tratador;
}


void 	Animal::setID(int id){
	m_id = id;
}


void 	Animal::setClasse(string classe){
	m_classe = classe;
}


void 	Animal::setNome(string nome){
	m_nome = nome;
}


void 	Animal::setCientifico(string cientifico){
	m_cientifico = cientifico;
}


void 	Animal::setBatismo(string batismo){
	m_batismo = batismo;
}


void 	Animal::setDieta(string dieta){
	m_dieta = dieta;
}


void 	Animal::setSexo(char sexo){
	m_sexo = sexo;
}


void 	Animal::setTamanho(float tamanho){
	m_tamanho = tamanho;
}


void 	Animal::setVeterinario(Pessoa* veterinario){
	m_veterinario = veterinario;
}


void 	Animal::setTratador(Pessoa* tratador){
	m_tratador = tratador;
}