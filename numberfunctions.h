#ifndef NUMBERFUNCTIONS_H
#define NUMBERFUNCTIONS_H

#endif // NUMBERFUNCTIONS_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>

#pragma once
using namespace std;

bool isInScientificNotation(const string CheckForScientificNotation);
//TODO: Bugcheck extensively
string convertFromScientificNotation(const string ScientificNotation);
//TODO: Bugcheck extensively
string convertToScientificNotation(const string Value);
string removeNonNumberCharacters(const string RemoveNonNumbers);
bool isTensDigit(int DigitsPlace);
string removePrependedZeros(string Value);

