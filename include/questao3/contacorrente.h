/**
 * @file	contacorrente.h
 * @brief	Definicao da classe ContaCorrente para representar
 *			uma conta corrente
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @data	28/10/2017
 */

#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "conta.h"

/**
 * @class 	ContaCorrente contacorrente.h
 * @brief	Classe que representa uma ContaCorrente
 * @details Atributos de uma ContaCorrente: agencia, numero, saldo,
 *			status, limite, limite disponivel e a lista de
 *			movivementacaoes
 */

class ContaCorrente : public Conta {
	
	private:
		bool status;			/**< status da conta corrente(se e especial ou nao) */
		float limite;			/**< Limite da conta corrente(caso seja especial) */
		float limiteDisp;		/**< Limite disponivel da conta corrente(caso seja especial) */

	public:
		/** @brief Construtor padrao */
		ContaCorrente();

		/** @brief Construtor parametrizado */
		ContaCorrente(string _agencia, string _numero, float _saldo, bool _status, float _limite);

		/** @brief Destrutor padrao */
		~ContaCorrente();

		/** @brief Retorna se a conta corrente e especial ou nao */
		bool getStatus();

		/** @brief Retorna o limite da conta corrente(se a conta for especial) */
		float getLimite();

		/** @brief Retorna o limite disponivel da conta corrente(se a conta for especial) */
		float getLimiteDisp();

		/** @brief Modifica o status(se a conta e especial ou nao)*/
		void setStatus(bool _status);

		/** @brief Modifica o limite da conta corrente(se a conta for especial) */
		void setLimite(float _limite);

		/** @brief Modifica o limite disponivel da conta corrente(se a conta for especial) */
		void setLimiteDisp(float _limiteDisp);

};

#endif