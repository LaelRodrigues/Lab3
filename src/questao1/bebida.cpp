/**
 * @file	bebida.cpp
 * @brief	Implemencao dos metodos da classe Bebida
 *			para representar uma bebida
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	26/10/2017
 */

#include <iomanip>
#include "bebida.h"

//Construtor padrao
Bebida::Bebida() {}

/**
 * @param _codigo Codigo da bebida
 * @param _descricao Descricao da bebida 
 * @param _preco Preco da bebida
 * @param _teor_alcoolico Teor alcoolico da bebida  
 */
Bebida::Bebida(std::string _codigo, std::string _descricao, double _preco, 
	int _teor_alcoolico):
	Produto(_codigo, _descricao, _preco), teor_alcoolico(_teor_alcoolico) {}

//Destrutor padrao
Bebida::~Bebida() {}

/** @return Teor alcoolico da bebida */
int
Bebida::getTeorAlcoolico() {
	return teor_alcoolico;
}

/** @param _teor_alcoolico Teor alcoolico da bebida */
void
Bebida::setTeorAlcoolico(int _teor_alcoolico) {
	teor_alcoolico = _teor_alcoolico;
}

/** 
 * @param o Referencia para stream de saida
 * @return Referencia para Stream de saida
 */
std::ostream& 
Bebida::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (3) << teor_alcoolico << "%"; 
	return o;
}