/**
 * @file	movimentacao.cpp
 * @brief	Implemencao dos metodos da classe Movimentacao
 *			para representar uma movimentacao
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @date	28/10/2017
 */


#include "movimentacao.h"

//Construtor padrao
Movimentacao::Movimentacao() {}

//Destrutor padrao
Movimentacao::~Movimentacao() {}

/**
 * @param _descricao Descricao da movimentacao
 * @param _valor valor da movimentacao
 * @param _indicacao tipo(credito ou debito) da movimentacao
 */
Movimentacao::Movimentacao(string _descricao, int _valor, Indicacao _indicacao) {
	descricao = _descricao;
	valor = _valor;
	indicacao = _indicacao;
}

/** @return Descricao da movimentacao */
string Movimentacao::getDescricao() {
	return descricao;
}

/** @return Valor da movimentacao */
float Movimentacao::getValor() {
	return valor;
}

/** @return Tipo(credito ou debito) da movimentacao */
Indicacao Movimentacao::getIndicacao() {
	return indicacao;
}

/** @param _descricao Descricao da movimentacao */	
void Movimentacao::setDescricao(string _descricao) {
	descricao = _descricao;
}

/** @param _valor Valor da movimentacao */	
void Movimentacao::setValor(int _valor) {
	valor = _valor;
}

/** @param _indicacao Tipo(credito ou debito) da movimentacao */	
void Movimentacao::setIndicacao(Indicacao _indicacao) {
	indicacao =_indicacao;
}