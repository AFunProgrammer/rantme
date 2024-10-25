#ifndef RANTMEWINDOW_H
#define RANTMEWINDOW_H

#include <QMainWindow>
#include "cgetnumber.h"
#include "numberfunctions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RantMeWindow; }
QT_END_NAMESPACE

class RantMeWindow : public QMainWindow
{
    Q_OBJECT

public:
    RantMeWindow(QWidget *parent = nullptr);
    ~RantMeWindow();
    void ConvertNumberToWords();

private:
    CGetNumber g_GetNumber;
    Ui::RantMeWindow *ui;
};
#endif // RANTMEWINDOW_H
