/**
 * @file	produto.cpp
 * @brief	Implemencao dos metodos da classe Produto
 *			para representar um produto
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	25/10/2017
 */


#include <iostream>
#include "produto.h"

//Construtor padrao
Produto::Produto() {}

//Destrutor padrao	
Produto::~Produto(){}

/**
 * @param _codigo Codigo do produto
 * @param _descricao Descricao do produto 
 * @param _preco Preco do produto
 */
Produto::Produto(std::string _codigo, std::string _descricao, short _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}


/** @return Codigo do produto */
std::string 
Produto::getCodBarras() {
	return m_cod_barras;
}
/** @return Descricao do produto */	
std::string 
Produto::getDescricao() {
	return m_descricao;
}

/** @return Preco do produto */
double 
Produto::getPreco() {
	return m_preco;
}

/** @param _codigo Codigo do produto */	
void 
Produto::setCodBarras(std::string _codigo) {
	m_cod_barras = _codigo;
}

/** @param _descricao Descricao do produto */
void 
Produto::setDescricao(std::string _descricao) {
	m_descricao = _descricao;
}

/** @param _preco Preco do produto */
void 
Produto::setPreco(double _preco) {
	m_preco = _preco;
}

/** 
 * @param o Referencia para stream de saida
 * @param p Referencia para o objeto Produto
 * @return Referencia para Stream de saida
 */
std::ostream& operator<< (std::ostream &o, Produto const &p) {
	return p.print(o);
}

/** 
 * @param p Referencia para o objeto Produto
 * @return Soma do preco de dois produtos
 */
double Produto::operator+(const Produto &p) {
	return (m_preco+p.m_preco);
}

/** 
 * @param p Referencia para o objeto Produto
 * @return Subtracao do preco de dois produtos
 */
double Produto::operator-(const Produto &p) {
	return (m_preco-p.m_preco); 
}

/** 
 * @param p Referencia para o objeto Produto
 * @return True ou false 
 */
bool Produto::operator==(const Produto &p) {
	if(m_cod_barras == p.m_cod_barras) {
		return true;
	}
	else {
		return false;
	}
}
