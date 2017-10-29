/**
 * @file	conta.h
 * @brief	Definicao da classe Conta para representar uma Conta
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @data	28/10/2017
 */

#ifndef CONTA_H
#define CONTA_H

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

#include "movimentacao.h"

/**
 * @class 	Conta conta.h
 * @brief	Classe que representa uma Conta
 * @details Atributos de uma conta: agencia, numero, saldo
 *			 e a lista demovivementacaoes
 */

class Conta {
	
	private:
		string agencia; 		/**< Numero da agencia */
		string numero;			/**< Numero da conta */
		float saldo;			/**< Saldo da conta */
		vector<shared_ptr<Movimentacao>> movimentacoes;  /**< Lista de movimentacoes */

	public:
		/** @brief Construtor padrao */
		Conta();

		/** @brief Construtor parametrizado */
		Conta(string _agencia, string _numero, float _saldo);

		/** @brief Destrutor padrao */
		virtual ~Conta();

		/** @brief Retorna o numero da agencia */
		string getAgencia();

		/** @brief Retorna o numero da conta */
		string getNumero();

		/** @brief Retorna o saldo da conta */
		float getSaldo();

		/** @brief Retorna A lista de movimentacoes */
		vector<shared_ptr<Movimentacao>>& getMovimentacoes();

		/** @brief Modifica o numero da agencia */
		void setAgencia(string _agencia);

		/** @brief Modifica o numero da conta */
		void setNumero(string _numero);

		/** @brief Modifica o saldo da conta*/
		void setSaldo(float _saldo);

		/** @brief Adiciona uma movimentacao a lista de movimentacoes */
		void setMovimentacoes(shared_ptr<Movimentacao>& _movimentacao);

		/** @brief Sobrecarga do operador de comparacao */
		bool operator==(Conta& conta);

		/** @brief Sobrecarga do operador de insercao em stream */
		friend ostream& operator<<(ostream& o, Conta& conta);

};

#endif