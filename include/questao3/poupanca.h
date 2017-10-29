/**
 * @file	poupanca.h
 * @brief	Definicao da classe ContaPoupanca para representar
 *			uma conta poupanca 
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @data	28/10/2017
 */

#ifndef POUPANCA_H
#define POUPANCA_H

#include "conta.h"

/**
 * @class 	ContaPoupanca poupanca.h
 * @brief	Classe que representa uma ContaPoupanca
 * @details Atributos de uma ContaPoupanca: agencia, numero, saldo
 *			e a lista de movivementacaoes
 */

class ContaPoupanca : public Conta {

	public:
		/** @brief Construtor padrao */
		ContaPoupanca();

		/** @brief Construtor parametrizado */
		ContaPoupanca(string _agencia, string _numero, float _saldo);

		/** @brief Destrutor padrao */
		~ContaPoupanca();
};

#endif