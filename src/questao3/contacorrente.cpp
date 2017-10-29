/**
 * @file	contacorrente.cpp
 * @brief	Implemencao dos metodos da classe ContaCorrente
 *			para representar um conta corrente
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @date	28/10/2017
 */


#include "contacorrente.h"

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>

//Construtor padrao
ContaCorrente::ContaCorrente() {}

//Destrutor padrao
ContaCorrente::~ContaCorrente() {}

/**
 * @param _agencia Numero da agencia
 * @param _numero Numero da conta corrente
 * @param _saldo Valor do saldo bancario
 * @param _status Informa se a conta corrente e especial ou nao
 * @param _limite Limite da conta(se for especial)
 */
ContaCorrente::ContaCorrente(string _agencia, string _numero, float _saldo, bool _status, 
	float _limite):
	Conta(_agencia, _numero, _saldo),  status(_status), limite(_limite) {}

/** @return Se e especial ou nao */
bool ContaCorrente::getStatus() {
	return status;
}

/** @return Limite da conta(se for especial) */
float ContaCorrente::getLimite() {
	return limite;
}

/** @return Limite disponivel(se for especial) */
float ContaCorrente::getLimiteDisp() {
	return limiteDisp;
}

/** @param _status Informa se a conta e especial ou nao */	
void ContaCorrente::setStatus(bool _status) {
	status = _status;
}

/** @param _limite Limite da conta corrente(se for especial) */
void ContaCorrente::setLimite(float _limite) {
	limite = _limite;
}

/** @param _limiteDisp Limite Disponivel da contacorrente(se for especial) */
void ContaCorrente::setLimiteDisp(float _limiteDisp) {
	limiteDisp = _limiteDisp;
}
