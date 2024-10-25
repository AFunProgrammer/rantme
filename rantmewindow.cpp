#include "rantmewindow.h"
#include "ui_rantmewindow.h"
#include <QString>

RantMeWindow::RantMeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RantMeWindow)
{
    ui->setupUi(this);
    ui->btnNumber->connect(ui->btnNumber,&QPushButton::clicked,this,&RantMeWindow::ConvertNumberToWords);
}

RantMeWindow::~RantMeWindow()
{
    delete ui;
}



void RantMeWindow::ConvertNumberToWords()
{
    QString qNumber = ui->txtNumber->toPlainText();
    string Value = qNumber.toStdString();
    string ConvertedToWords = "";
    int iDigit = 0;

    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string word = "";
    bool bNumberInGroup = false;



    string sCleaned = removeNonNumberCharacters(Value);
    sCleaned = removePrependedZeros(sCleaned);

    if( sCleaned.length() != Value.length() )
    {
        Value = sCleaned;
    }

    if ( isInScientificNotation(Value) )
    {
        Value = convertFromScientificNotation(Value);
        Value = removePrependedZeros(Value); //removes a zero if 0.##e#
    }

    iDigit = Value.length() - 1;

    for( int i = iDigit; i >= 0; i-- )
    {
        cNumber = Value[iDigit - i];
        iNumber = atoi(&cNumber);

        if ( (i + 1) % 3 == 0 )
            bNumberInGroup = false;

        if ( iNumber > 0 )
            bNumberInGroup = true;

        bool bTens = isTensDigit(i);

        if ( i+1 <= iDigit && isTensDigit(i+1) && iPrevNumber == 1 )
        {
            word = g_GetNumber.getTeensValue( iNumber );
        }
        else
        {
            if ( bTens )
                word = g_GetNumber.getTensValue( iNumber );
            else
                word = g_GetNumber.getOnesValue( iNumber );
        }

        ConvertedToWords += word;

        if ( word.length() != 0 )
            ConvertedToWords += " ";

        if ( bNumberInGroup )
        {
            word = g_GetNumber.getUnitsString(i,iNumber);

            ConvertedToWords += word;

            if ( word.length() != 0 )
                ConvertedToWords += " ";
        }

        word = "";
        iPrevNumber = iNumber;
    }

    ui->lblNumber->setText(QString(ConvertedToWords.c_str()));

    return;
}
