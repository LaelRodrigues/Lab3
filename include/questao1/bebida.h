	/**
 * @file	bebida.h
 * @brief	Definicao da classe Bebida para representar uma bebida
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	29/10/2017
 */

#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"

/**
 * @class 	Bebida bebida.h
 * @brief	Classe que representa uma bebida
 * @details Atributos da bebida: codigo, descricao,
 *			preco e teor alcoolico
 */

class Bebida : public Produto
{
public:

	/** @brief Construtor padrao */
	Bebida();

	/** @brief Construtor parametrizado */
	Bebida(std::string _codigo, std::string _descricao, double _preco, 
			int _teor_alcoolico);

	/** @brief Destrutor padrao*/
	~Bebida();

private:
	int teor_alcoolico;	/**< Teor alcoolico da bebida */

public:
	/** @brief Retorna o teor alcoolico da bebida */
	int getTeorAlcoolico();

	/** @brief Modifica o teor alcoolico da bebida */
	void setTeorAlcoolico(int _teor_alcoolico);

private:
	/** @brief Metodo para imprimir os dados de uma bebida */
	std::ostream& print(std::ostream &o) const;

};

#endif