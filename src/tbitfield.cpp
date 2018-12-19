// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП 
// 
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001 
// Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015) 
// 
// Битовое поле 

#include "tbitfield.h" 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <algorithm> 

/* int BitLen; // длина битового поля - макс. к-во битов
TELEM *pMem; // память для представления битового поля
int MemLen; // к-во эл-тов Мем для представления бит.поля
*/

TBitField::TBitField(int len)
{
	if (len <= 0)
		throw "Length is uncorrect";
	BitLen = len;
	MemLen = BitLen / (8 * sizeof(TELEM)) + 1; //sizeof - это унарный оператор, возвращающий длину в байтах переменной 
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
		pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования 
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
}

TBitField::~TBitField()
{
	delete[]pMem;
	pMem = NULL;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n 
{
<<<<<<< HEAD
	return 0;
=======
	if (n < 0 || n >= BitLen)
		throw "Uncorrect bit";
	return (n / (8 * sizeof(TELEM)));
>>>>>>> master
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n 
{
<<<<<<< HEAD
	return 0;
=======
	if (n < 0 || n >= BitLen)
		throw "Uncorrect bit";
	return (1 << (n - 1) % (8 * sizeof(TELEM)));
>>>>>>> master
}

// доступ к битам битового поля 

int TBitField::GetLength(void) const // получить длину (к-во битов) 
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит 
{
	if ((n < 0) || (n >= BitLen))
		throw "Uncorrect bit";
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит 
{
	if ((n < 0) || (n >= BitLen))
		throw "Uncorrect bit";
	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита 
{
	if ((n < 0) || (n >= BitLen))
		throw "Uncorrect bit";
	return (pMem[GetMemIndex(n)] & GetMemMask(n));
}

// битовые операции 

TBitField& TBitField::operator=(const TBitField &bf) // присваивание 
{
<<<<<<< HEAD
=======
	if (this != &bf)
	{
		delete[]pMem;
		BitLen = bf.BitLen;
		MemLen = bf.MemLen;
		pMem = new TELEM[MemLen];
		for (int i = 0; i < MemLen; i++)
			pMem[i] = bf.pMem[i];
	}
>>>>>>> master
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение 
{
	if (BitLen != bf.BitLen || MemLen != bf.MemLen)
		return 0;
	for (int i = 0; i < MemLen; i++)
		if (pMem[i] != bf.pMem[i])
			return 0;
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение 
{
	if (BitLen != bf.BitLen || MemLen != bf.MemLen)
		return 1;
	for (int i = 0; i < MemLen; i++)
		if (pMem[i] != bf.pMem[i])
			return 1;
	return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или" 
{
<<<<<<< HEAD
	return TBitField(1);
=======
	TBitField tmp(max(BitLen, bf.BitLen));
	for (int i = 0; i < MemLen; i++)
		tmp.pMem[i] = pMem[i];
	for (int i = 0; i < bf.MemLen; i++)
		tmp.pMem[i] |= bf.pMem[i];
	return tmp;
>>>>>>> master
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и" 
{
<<<<<<< HEAD
	return 0;
=======
	TBitField tmp(max(BitLen, bf.BitLen));
	for (int i = 0; i < min(MemLen, bf.MemLen); i++)
		tmp.pMem[i] = pMem[i] & bf.pMem[i];
	return tmp;
>>>>>>> master
}

TBitField TBitField::operator~(void) // отрицание 
{
<<<<<<< HEAD
	return TBitField(1);
=======
	TBitField tmp(BitLen);
	for (int i = 0; i < BitLen; i++) {
		if (this->GetBit(i) == 0)
			tmp.SetBit(i);
	}
	return tmp;
>>>>>>> master
}

// ввод/вывод 

istream &operator>>(istream &istr, TBitField &bf) // ввод 
{
<<<<<<< HEAD
=======
	string temp;
	istr >> temp;
	if (temp.size() != bf.GetLength())
		throw "Uncorrect length";
	for (int i = 0; i < bf.GetLength(); i++)
	{
		if (temp[i] == '0')
			bf.ClrBit(i);
		else if (temp[i] == '1')
			bf.SetBit(i);
		else
			throw "Uncorrect input";
	}
>>>>>>> master
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод 
{
<<<<<<< HEAD
=======
	for (int i = 0; i < bf.GetLength(); i++)
		ostr << bf.GetBit(i);
>>>>>>> master
	return ostr;
}
