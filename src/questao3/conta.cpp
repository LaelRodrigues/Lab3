/**
 * @file	conta.cpp
 * @brief	Implemencao dos metodos da classe Conta
 *			para representar um conta
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @date	28/10/2017
 */


#include "conta.h"

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>

//Construtor padrao
Conta::Conta() {}

//Destrutor padrao
Conta::~Conta() {}

/**
 * @param _agencia Numero da agencia
 * @param _numero Numero da conta
 * @param _saldo Valor do saldo bancario
 */
Conta::Conta(string _agencia, string _numero, float _saldo) {
	agencia = _agencia;
	numero = _numero;
	saldo = _saldo;
}

/** @return Numero da agencia */
string Conta::getAgencia() {
	return agencia;
}

/** @return Numero da conta */
string Conta::getNumero() {
	return numero;
}

/** @return Saldo da conta */
float Conta::getSaldo() {
	return saldo;
}

/** @return um lista de movimentacoes */
vector<shared_ptr<Movimentacao>>& Conta::getMovimentacoes() {
	return movimentacoes;
}

/** @param _agencia Numero da agencia */	
void Conta::setAgencia(string _agencia) {
	agencia = _agencia;
}

/** @param _numero Numero da conta */	
void Conta::setNumero(string _numero) {
	numero = _numero;
}

/** @param _saldo Saldo da conta */	
void Conta::setSaldo(float _saldo) {
	saldo = _saldo;
}

/** @param _movimentacao Adiciona uma movimentacao a lista */
void Conta::setMovimentacoes(shared_ptr<Movimentacao>& _movimentacao) {
	movimentacoes.push_back(_movimentacao);
}

/** 
 * @param p Referencia para um objeto conta
 * @return True ou false 
 */
bool Conta::operator==(Conta& conta) {
	if(numero == conta.numero) {
		return true;
	}
	else {
		return false;
	}
}


/** 
 * @param o Referencia para stream de saida
 * @param p Referencia para um o objeto Conta
 * @return Referencia para stream de saida
 */
ostream& operator<<(ostream& o, Conta& conta) {
	
	int cont = 0;
	for(auto i = conta.getMovimentacoes().begin(); i != conta.getMovimentacoes().end(); i++) {
		if((**i).getIndicacao() == credito) {
			o << std::setfill(' ') << std::setw (15) << (**i).getDescricao() << " | "
				 << std::setfill(' ') << std::setw (10) << (**i).getValor() << " | "
				 << "tipo: credito" << endl;
				 cont++;
		}
		else if((**i).getIndicacao() == debito) {
			o << std::setfill(' ') << std::setw (15) << (**i).getDescricao() << " | "
				 << std::setfill(' ') << std::setw (10) << (**i).getValor() << " | "
				 << "tipo: debito" << endl;
				 cont++;
		}
	}
	if(cont == 0) {
		cout << "Ainda nao ocorreu movimentacoes nessa conta." << endl;
	}
	return o;
}