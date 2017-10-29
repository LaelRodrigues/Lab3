/**
 * @file	fruta.h
 * @brief	Definicao da classe Fruta para representar um fruta
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	29/10/2017
 */

#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"


/**
 * @class 	Fruta fruta.h
 * @brief	Classe que representa um fruta
 * @details Os atributos do produto: codigo, descricao,
 *  		preco, data do lote e validade			
 */

class Fruta : public Produto
{
public:

	/** @brief Construtor padrao */
	Fruta();

	/** @brief Construtor parametrizado */
	Fruta(std::string _codigo, std::string _descricao, double _preco, 
			std::string _data, int _validade);

	/** @brief Destrutor padrao */
	~Fruta();

private:
	std::string m_data_lote; 	/**< Data do lote */
	int m_validade;			/**< Validade */	

public:
	/** @brief Retorna a data do lote */
	std::string getDataLote();

	/** @brief Retorna a validade */
	int getValidade();

	/** @brief Modifica a data do lote */
	void setDataLote(std::string _data);

	/** @brief Modifica a validade */
	void setValidade(int _validade);

private:
	/** @brief Metodo para imprimir os dados de uma fruta */
	std::ostream& print(std::ostream &o) const;
};

#endif