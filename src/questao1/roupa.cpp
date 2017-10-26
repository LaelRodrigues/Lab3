/**
 * @file	roupa.cpp
 * @brief	Implemencao dos metodos da classe Roupa
 *			para representar uma roupa
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	25/10/2017
 */

#include <iomanip>
#include "roupa.h"

//Construtor padrao
Roupa::Roupa() {}

/**
 * @param _codigo Codigo da roupa
 * @param _descricao Descricao da roupa 
 * @param _preco Preco da roupa
 * @param _marca Marca da roupa
 * @param _sexo Sexo da roupa
 * @param _tamanho Tamanho da roupa
 */
Roupa::Roupa(std::string _codigo, std::string _descricao, short _preco, 
	std::string _marca, char _sexo, std::string _tamanho):
	Produto(_codigo, _descricao, _preco), marca(_marca), sexo(_sexo), tamanho(_tamanho) {}

//Destrutor padrao
Roupa::~Roupa() {}

/** @return Marca da roupa */
std::string
Roupa::getMarca() {
	return marca;
}

/** @return Sexo da roupa */
char
Roupa::getSexo() {
	return sexo;
}

/** @return Tamanho da roupa */
std::string 
Roupa::getTamanho() {
	return tamanho;
}

/** @param _marca Marca da roupa */
void
Roupa::setMarca(std::string _marca){
	marca = _marca;
} 

/** @param _sexo Sexo da roupa */
void 
Roupa::setSexo(char _sexo) {
	sexo = _sexo;
}

/** @param _tamanho Tamanho da roupa */
void 
Roupa::setTamanho(std::string _tamanho) {
	tamanho = _tamanho;
}

/** 
 * @param o Referencia para stream de saida
 * @return Referencia para Stream de saida
 */
std::ostream& 
Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << marca << " | " 
		<< std::setfill (' ') << std::setw (3) << sexo << " | "
		<< std::setfill (' ') << std::setw (3) << tamanho; 
	return o;
}