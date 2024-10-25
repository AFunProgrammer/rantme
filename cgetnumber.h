#ifndef CGETNUMBER_H
#define CGETNUMBER_H
#pragma once

#include <QObject>
#include <stdio.h>
#include <string>
#include <deque>
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

class CGetNumber : public QObject
{
    Q_OBJECT
public:
    explicit CGetNumber(QObject *parent = nullptr);
private:
    /* https://simple.wikipedia.org/wiki/Names_for_large_numbers
    1 	Ten 	Ten 	Ten 	da 	Deca-
    2 	Hundred 	Hundred 	Hundred 	h 	Hecto-
    3 	Thousand 	Thousand 	Thousand 	K 	Kilo-
    4 	Ten thousand 	Ten thousand 	Ten thousand 	my (Now obsolete) 	Myria- (Now obsolete)
    5 	Hundred thousand 	Hundred thousand 	Hundred thousand
    6 	Million 	Million 	Million 	M 	Mega-
    9 	Billion 	Milliard 	Thousand million 	G 	Giga-
    12 	Trillion 	Billion 	Billion 	T 	Tera-
    15 	Quadrillion 	Billiard 	Thousand billion 	P 	Peta-
    18 	Quintillion 	Trillion 	Trillion 	E 	Exa-
    21 	Sextillion 	Trilliard 	Thousand trillion 	Z 	Zetta-
    24 	Septillion 	Quadrillion 	Quadrillion 	Y 	Yotta-
    27 	Octillion 	Quadrilliard 	Thousand quadrillion
    30 	Nonillion 	Quintilion 	Quintillion
    33 	Decillion 	Quintilliard 	Thousand quintillion
    36 	Undecillion 	Sextillion 	Sextillion
    39 	Duodecillion 	Sextilliard 	Thousand sextillion
    42 	Tredecillion 	Septillion 	Septillion
    45 	Quattuordecillion 	Septilliard 	Thousand septillion
    48 	Quindecillion 	Octillion 	Octillion
    51 	Sexdecillion 	Octilliard 	Thousand octillion
    54 	Septendecillion 	Nonillion 	Nonillion
    57 	Octodecillion 	Nonilliard 	Thousand nonillion
    60 	Novemdecillion 	Decillion 	Decillion
    63	Vigintillion	Decilliard	Thousand decillion
    66	Unvigintillion	Undecillion	Undecillion
    69	Duovigintillion	Undecilliard	Thousand undecillion
    72	Trevigintillion	Duodecillion	Duodecillion
    75	Quattuorvigintillion	Duodecilliard	Thousand duodecillion
    78	Quinvigintillion	Tredecillion	Tredecillion
    81	Sexvigintillion	Tredecilliard	Thousand tredecillion
    84	Septenvigintillion	Quattuordecillion	Quattuordecillion
    87	Octovigintillion	Quattuordecilliard	Thousand quattuordecillion
    90	Novemvigintillion	Quindecillion	Quindecillion
    93	Trigintillion	Quindecilliard	Thousand quindecillion
    96	Untrigintillion	Sexdecillion	Sexdecillion
    99	Duotrigintillion	Sexdecilliard	Thousand sexdecillion
    100	Googol	Googol	Googol
    102 Tretrigintillion 	Septendecillion 	Septendecillion
    105 Quattuortrigintillion 	Septendecilliard 	Thousand septedecillion
    108 Quintrigintillion 	Octodecillion 	Octodecillion
    111 Sextrigintillion 	Octodecilliard 	Thousand octodecillion
    114 Septentrigintillion 	Novemdecillion 	Novemdecillion
    117 Octotrigintillion 	Novemdecilliard 	Thousand novemdecillion
    120 Novemtrigintillion 	Vigintillion 	Vigintillion
    //https://en.wikipedia.org/wiki/Names_of_large_numbers
    123	Quadragintillion	Thousand vigintillion	Vigintilliard
    */
    //map<10^x,name>
    static map<int,string> m_NumberGroups;
    static map<int, tuple<string,string,string>> m_DigitNames;

public:

    static string getUnitsString(int Place, int Value)
    {
        string unit = "";

        if ( (Place + 1) % 3 == 0 )
        {
            unit = (Value == 0 ? "" : string("hundred"));
        }
        else
        {
            unit = m_NumberGroups[Place];
        }

        return unit;
    }

    static string getOnesValue(int Value)
    {
        return get<0>(m_DigitNames[Value]);
    }

    static string getTeensValue(int Value)
    {
        return get<1>(m_DigitNames[Value]);
    }

    static string getTensValue(int Value)
    {
        return get<2>(m_DigitNames[Value]);
    }

signals:


};

#endif // CGETNUMBER_H

