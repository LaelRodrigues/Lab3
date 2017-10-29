/**
 * @file	agencia.h
 * @brief	Definicao da classe Agencia para representar uma agencia
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @data	28/10/2017
 */


#ifndef AGENCIA_H
#define AGENCIA_H

#include "conta.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

/**
 * @class 	Conta conta.h
 * @brief	Classe que representa uma Conta
 * @details Atributos de uma conta: agencia, numero, saldo,
 *			status, limite, limite disponivel e a lista de
 *			movivementacaoes
 */

class Agencia {
	private:
		string numeroAgencia;  					/**< Numero da agencia */
		vector<shared_ptr<Conta>> contas;		/**< Contas da agencia*/

	public:
		/** @brief Construtor padrao */
		Agencia();

		/** @brief Construtor parametrizado */
		Agencia(string _numeroAgencia, vector<shared_ptr<Conta>> _contas);

		/** @brief Destrutor padrao */
		~Agencia();

		/** @brief Retorna o numero da agencia */
		string getNumeroAgencia();

		/** @brief Modifica o numero da agencia */
		void setNumeroAgencia(string _numeroAgencia);

		/** @brief Retorna a lista de contas*/
		vector<shared_ptr<Conta>> getContas();

		/** @brief Funcao para criar um conta */
		void criarConta(shared_ptr<Conta> conta);

		/** @brief Funcao para remover uma conta */
		void removerConta(string numeroConta);

		/** @brief Funcao que realiza saque */
		void saque(string numeroConta, float valor);

		/** @brief Funcao que realiza desposito */
		void deposito(string numeroConta, float valor);

		/** @brief Funcao que realiza transferencia entre contas */
		void transferencia(string numeroConta1, string numeroConta2, float valor);

		/** @brief Funcao que realiza a emissao do saldo */
		void imitirSaldo(string numeroConta);
};

#endif