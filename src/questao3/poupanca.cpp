/**
 * @file	poupanca.cpp
 * @brief	Implemencao dos metodos da classe ContaPoupanca
 *			para representar um conta poupanca
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @date	28/10/2017
 */

#include "poupanca.h"

//Construtor padrao
ContaPoupanca::ContaPoupanca() {}

//Destrutor padrao
ContaPoupanca::~ContaPoupanca() {}

/**
 * @param _agencia Numero da agencia
 * @param _numero Numero da conta
 * @param _saldo Valor do saldo bancario
 */
ContaPoupanca::ContaPoupanca(string _agencia, string _numero, float _saldo):
	Conta(_agencia, _numero, _saldo) {}