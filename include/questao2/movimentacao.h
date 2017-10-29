/**
 * @file	movimentacao.h
 * @brief	Definicao da classe Movimentacao para representar 
 *			uma movimentacao
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	28/10/2017
 * @data	28/10/2017
 */

#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
using std::string;

/**
 * @brief Tipo enumeracao que identifica se a
 *		  e de credito ou debito
 */ 
enum Indicacao {
	credito = 1, 	/**< Movimentacao do tipo credito */
	debito, 		/**< Movimentacao do tipo debito */
};

/**
 * @class 	Movimentacao movimentacao.h
 * @brief	Classe que representa uma Movimentacao
 * @details Atributos de uma movimentacao: descricao,
 *			valor e indicacao
 */


class Movimentacao {
	private:
		string descricao;   	/**< Descricao da movimentacao */
		float valor;			/**< Valor da movimentacao */
		Indicacao indicacao;    /**< Indicacao da movimentacao */

	public:
		/** @brief Construtor padrao */
		Movimentacao();

		/** @brief Construtor parametrizado */
		Movimentacao(string _descricao, int _valor, Indicacao _indicacao);

		/** @brief Destrutor padrao */
		~Movimentacao();

		/** @brief Retorna a descricao da movimentacao */
  		string getDescricao();

		/** @brief Retorna o valor da movimentacao */
		float getValor();

		/** @brief Retorna A indicacao da movimentacao */
		Indicacao getIndicacao();

		/** @brief Modifica A descricao da movimentacao */
		void setDescricao(string _descricao);

		/** @brief Modifica o Valor da movimentacao */
		void setValor(int _valor);

		/** @brief Modifica a Indicacao da movimentacao */
		void setIndicacao(Indicacao _indicacao);
};

#endif