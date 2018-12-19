// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"
/*
int MaxPower;       // максимальная мощность множества
TBitField BitField;  //битовое поле 
*/

TSet::TSet(int mp) : BitField(mp)
{	if (mp >= 0)
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
		MaxPower = s.MaxPower;
		BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
	BitField = bf;
}

TSet::operator TBitField()
<<<<<<< HEAD
{
	return TSet(1);
=======
{	
	TBitField tmp = (TBitField)*this;
	return tmp;
>>>>>>> master
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
<<<<<<< HEAD
	return 0;
=======
	return MaxPower;
>>>>>>> master
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (Elem < 0 || Elem >= MaxPower)
		throw "Uncorrect element";
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if (Elem < 0 || Elem >= MaxPower)
		throw "Uncorrect element";
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	if (Elem < 0 || Elem >= MaxPower)
		throw "Uncorrect element";
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
<<<<<<< HEAD
{ 
=======
{
	if (this != &s)
	{
		MaxPower = s.MaxPower;
		BitField = s.BitField;
	}
>>>>>>> master
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	if (BitField == s.BitField)
		return 1;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
<<<<<<< HEAD
	return 0;
=======
	int flag = 0;
	if (BitField != s.BitField)
		return flag=1;
	if (MaxPower != s.MaxPower)
		return flag=1;
>>>>>>> master
}

TSet TSet::operator+(const TSet &s) // объединение
{
<<<<<<< HEAD
	return TSet(1);
=======
	int len = MaxPower;
	if (s.MaxPower > MaxPower)
		len = s.MaxPower;
	TSet tmp(len);
	tmp.BitField = BitField | s.BitField;
	return tmp;
>>>>>>> master
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
<<<<<<< HEAD
	return TSet(1);
=======
	if (Elem < 0 || Elem >= MaxPower)
		throw "Uncorrect element";
	TSet tmp(*this);
	tmp.InsElem(Elem);
	return tmp;
>>>>>>> master
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
<<<<<<< HEAD
	return TSet(1);
=======
	if (Elem < 0 || Elem >= MaxPower)
		throw "Uncorrect element";
	TSet tmp(*this);
	tmp.DelElem(Elem);
	return tmp;

>>>>>>> master
}

TSet TSet::operator*(const TSet &s) // пересечение
{
<<<<<<< HEAD
	return TSet(1);
=======
	int len = MaxPower;
	if (s.MaxPower > MaxPower)
		len = s.MaxPower;
	TSet tmp(len);
	tmp = BitField & s.BitField;
	return tmp;
>>>>>>> master
}

TSet TSet::operator~(void) // дополнение
{
<<<<<<< HEAD
	return TSet(1);
=======
	TSet tmp = *this;
	tmp.BitField = ~BitField;
	return tmp;
>>>>>>> master
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
<<<<<<< HEAD
=======
	istr >> s.BitField;
	s.MaxPower = s.BitField.GetLength();
>>>>>>> master
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
<<<<<<< HEAD
=======
	ostr << s.BitField;
>>>>>>> master
	return ostr;
}
