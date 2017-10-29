/**
 * @file	fruta.cpp
 * @brief	Implemencao dos metodos da classe Fruta
 *			para representar uma fruta
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	26/10/2017
 */

#include <iomanip>
#include "fruta.h"

//Construtor padrao
Fruta::Fruta() {}


/**
 * @param _codigo Codigo da fruta
 * @param _descricao Descricao da fruta 
 * @param _preco Preco da fruta
 * @param _data Data do lote do fruta
 * @param _validade Validade da fruta  
 */
Fruta::Fruta(std::string _codigo, std::string _descricao, double _preco, 
	std::string _data, int _validade):
	Produto(_codigo, _descricao, _preco), m_data_lote(_data), m_validade(_validade) {}

//Destrutor padrao
Fruta::~Fruta() {}

/** @return Data do lote da fruta */
std::string 
Fruta::getDataLote() {
	return m_data_lote;
}

/** @return Validade da fruta */
int 
Fruta::getValidade() {
	return m_validade;
}

/** @param _data Data do lote da fruta */
void 
Fruta::setDataLote(std::string _data) {
	m_data_lote = _data;
}

/** @param _validade Validade da fruta */
void 
Fruta::setValidade(int _validade) {
	m_validade = _validade;
}

/** 
 * @param o Referencia para stream de saida
 * @return Referencia para Stream de saida
 */
std::ostream& 
Fruta::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << m_validade; 
	return o;
}