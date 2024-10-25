#include "cgetnumber.h"


CGetNumber::CGetNumber(QObject *parent)
    : QObject{parent}
{

}

map<int,string> CGetNumber::m_NumberGroups
{
    {3  , "thousand"},
    {6  , "million"},
    {9  , "billion"},
    {12 , "trillion"},
    {15 , "quadrillion"},
    {18 , "quintillion"},
    {21 , "sextillion"},
    {24 , "septillion"},
    {27 , "octillion"},
    {30 , "nonillion"},
    {33 , "decillion"},
    {36 , "undecillion"},
    {39 , "duodecillion"},
    {42 , "tredecillion"},
    {45 , "quattuordecillion"},
    {48 , "quindecillion"},
    {51 , "sexdecillion"},
    {54 , "septendecillion"},
    {57 , "octodecillion"},
    {60 , "novemdecillion"},
    {63 , "vigintillion"},
    {66 , "unvigintillion"},
    {69 , "duovigintillion"},
    {72 , "trevigintillion"},
    {75 , "quattuorvigintillion"},
    {78 , "quinvigintillion"},
    {81 , "sexvigintillion"},
    {84 , "septenvigintillion"},
    {87 , "octovigintillion"},
    {90 , "novemvigintillion"},
    {93 , "trigintillion"},
    {96 , "untrigintillion"},
    {99 , "duotrigintillion"},
    {100, "googol"},
    {102, "tretrigintillion"},
    {105, "quattuortrigintillio"},
    {108, "quintrigintillion"},
    {111, "sextrigintillion"},
    {114, "septentrigintillion"},
    {117, "octotrigintillion"},
    {120, "novemtrigintillion"},
    {123, "quadragintillion"}
};

map<int, tuple<string,string,string>> CGetNumber::m_DigitNames
{
    {0, make_tuple("",     "ten",      "")},
    {1, make_tuple("one",  "eleven",   "")},
    {2, make_tuple("two",  "twelve",   "twenty")},
    {3, make_tuple("three","thirteen", "thirty")},
    {4, make_tuple("four", "fourteen", "fourty")},
    {5, make_tuple("five", "fifteen",  "fifty")},
    {6, make_tuple("six",  "sixteen",  "sixty")},
    {7, make_tuple("seven","seventeen","seventy")},
    {8, make_tuple("eight","eighteen", "eighty")},
    {9, make_tuple("nine", "nineteen", "ninety")},
};
