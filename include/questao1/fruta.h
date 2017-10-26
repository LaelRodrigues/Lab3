/**
 * @file	fruta.h
 * @brief	Definicao da classe Fruta para representar um fruta
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @data	26/10/2017
 */

#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"


/**
 * @class 	Fruta fruta.h
 * @brief	Classe que representa um produto
 * @details Os atributos do produto: codigo, descricao,
 *  		preco, data e validade			
 */

class Fruta : public Produto
{
public:

	/** @brief Construtor padrao */
	Fruta();

	/** @brief Construtor parametrizado */
	Fruta(std::string _codigo, std::string _descricao, short _preco, 
			std::string _data, short _validade);

	/** @brief Destrutor padrao */
	~Fruta();

private:
	std::string m_data_lote; 	/**< Data do lote */
	short m_validade;			/**< Validade */	

public:
	/** @brief Retorna a data do lote */
	std::string getDataLote();

	/** @brief Retorna a validade */
	short getValidade();

	/** @brief Modifica a data do lote */
	void setDataLote(std::string _data);

	/** @brief Modifica a validade */
	void setValidade(short _validade);

private:
	/** @brief Metodo para imprimir os dados de uma fruta */
	std::ostream& print(std::ostream &o) const;
};

#endif