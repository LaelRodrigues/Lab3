/**
 * @file	produto.h
 * @brief	Definicao da classe Produto para representar um produto
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @date	29/10/2017
 */


#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>

/**
 * @class 	Produto produto.h
 * @brief	Classe que representa um produto
 * @details Atributos do produto: codigo, descricao
 *  		e preco			
 */

class Produto
{	
public:

	/** @brief Construtor padrao */
	Produto();

	/** @brief Construtor parametrizado */
	Produto(std::string _codigo, std::string _descricao, double _preco);

	/** @brief Destrutor padrao*/
	virtual ~Produto();

protected:
	std::string m_cod_barras;		/**< Codigo do produto */
	std::string m_descricao;		/**< Descricao do produto */
	double m_preco;					/**< Preco do produto */

public:
	/** @brief Retorna o codigo do produto */
	std::string getCodBarras();

	/** @brief Retorna a descricao do produto */
	std::string getDescricao();

	/** @brief Retorna o preco do produto */
	double getPreco();
	
	/** @brief Modifica o codigo do produto */
	void setCodBarras(std::string _codigo);

	/** @brief Modifcia a descricao do produto */
	void setDescricao(std::string _descricao);

	/** @brief Modifica o preco do produto */
	void setPreco(double _preco);
	
	/** @brief Sobrecarga do operador de insercao em stream */
	friend std::ostream& operator<< (std::ostream &o, Produto const &p); 

	/** @brief Sobrecarga do operador de adicao */
	double operator+(const Produto &p);

	/** @brief Sobrecarga do operador de subtracao */
	double operator-(const Produto &p);

	/** @brief Sobrecarga do operador de comparacao */
	bool operator==(const Produto &p);

private:
	/** @brief Metodo virtual puro para imprimir um produto */
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
