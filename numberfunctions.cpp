#include "numberfunctions.h"

bool isInScientificNotation(const string CheckForScientificNotation)
{
    if( string::npos == CheckForScientificNotation.find("E") && string::npos == CheckForScientificNotation.find("e") )
        return false;

    return true;
}

//TODO: Bugcheck extensively
string convertFromScientificNotation(const string ScientificNotation)
{
    string converted = "";
    string eNotation = "";
    int nDecimalPos = -1;
    int nENotationPos = -1;
    int nPower = 0;
    int nAddPower = 0;

    nDecimalPos = ScientificNotation.find(".");

    nENotationPos = ScientificNotation.find("e");
    if ( string::npos == nENotationPos)
    {
        nENotationPos = ScientificNotation.find("e");
        if ( string::npos == nENotationPos)
            return string("error");
    }

    //negative ScientificNotation
    if ( ScientificNotation[nENotationPos+1] == '-' )
    {
        return string("0");
    }

    if ( ScientificNotation[nENotationPos+1] == '+' )
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+2));
    else
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+1));

    converted = ScientificNotation.substr(0,nENotationPos);

    //Add in number of digits past places already in the string
    if ( string::npos == nDecimalPos )
        nPower = 0;
    else
        nPower = converted.substr(nDecimalPos+1).length();

    for( int iAddPower = nPower; iAddPower < nAddPower; iAddPower++ )
    {
        converted += "0";
    }

    if ( string::npos != nDecimalPos)
        converted.erase(nDecimalPos,1);

    return converted;
}

//TODO: Bugcheck extensively
string convertToScientificNotation(const string Value)
{
    string converted = "";
    int iDigits = 0;

    if ( isInScientificNotation(Value) )
        return Value; //already in target Format

    //make sure to cleanup
    converted = removeNonNumberCharacters(Value);

    iDigits = converted.length();
    converted.insert(1,".");

    while ( converted[converted.length()-1] == '0' )
        converted.erase(converted.length()-1);

    converted += "e" + to_string(iDigits-1);

    return converted;
}

string removeNonNumberCharacters(const string RemoveNonNumbers)
{
    string keepOnlyNumbers = RemoveNonNumbers;

    int iChar = 0;
    int iNumber = 0;

    while ( iChar < keepOnlyNumbers.length() )
    {
        //special characters
        if ( keepOnlyNumbers[iChar] == 'e' || keepOnlyNumbers[iChar] == 'E' || keepOnlyNumbers[iChar] == '+' || keepOnlyNumbers[iChar] == '.' )
        {
            iChar++;
            continue;
        }

        iNumber = keepOnlyNumbers[iChar] - (char)'0';

        if ( iNumber >= 0 && iNumber <= 9 )
            iChar++;
        else
            keepOnlyNumbers.erase(iChar, 1);
    }

    return keepOnlyNumbers;
}


bool isTensDigit(int DigitsPlace)
{
    if ( (DigitsPlace + 2) % 3 == 0 )
        return true;

    return false;
}

string removePrependedZeros(string Value)
{
    string out = Value;

    while ( out[0] == '0' && out.length() > 1 && out[1] != '.' )
    {
        out.erase(0,1);
    }

    return out;
}
