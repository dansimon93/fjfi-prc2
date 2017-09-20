#include <QApplication>
#include "text-editor.h"

/*
*------------------------------------------------------------------------------
* This project has been created for the course of Programming in C++ 2        |
* at the Faculty of Nuclear Sciences and Physical Engineering. It is based    |
* on the programming language C++ and Qt graphic library. This program is an  |
* easy text editor with basic functions - similar to Notepad or GEdit.        |
* -----------------------------------------------------------------------------
* Daniel Simon| dansimon93@gmail.com |
* ------------------------------------
* 2017 |
* ------
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Qt Text Editor v1.0");
    TextEditor t;
    t.show();
    return a.exec();
}

