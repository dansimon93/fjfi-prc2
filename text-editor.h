#ifndef TEXTEDITOR
#define TEXTEDITOR

#include<QMainWindow>

/*Imported classes*/
class QPlainTextEdit;
class QMenu;
class QToolbar;
class Qaction;
class QCloseEvent;


class TextEditor : public QMainWindow
{
    Q_OBJECT

    QPlainTextEdit *textEdit;
    /*Categories of the menu*/
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuSearch; //mozna
    QMenu *menuHelp;
    /*Toolbar for icons*/
    QToolbar *mainToolbar;
    /*All editor actions*/
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelectAll; // mozna
    QAction *actionSearch; // mozna
    QAction *actionAbout;
    /*Integerers for window size*/
    quint16 width, height;
public:

signals:

public slots:
};

#endif // TEXTEDITOR

