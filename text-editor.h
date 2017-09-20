#ifndef TEXTEDITOR
#define TEXTEDITOR

#include<QMainWindow>

/*Imported classes*/
class QPlainTextEdit;
class QMenu;
class QToolBar;
class QAction;
class QCloseEvent;


class TextEditor : public QMainWindow
{
private:
    Q_OBJECT

    QPlainTextEdit *textEdit;

    /*Categories of the menu*/
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuSearch; //mozna
    QMenu *menuHelp;

    /*Toolbar for icons*/
    QToolBar *mainToolbar;

    /*All editor actions*/
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelectAll; // mozna
    QAction *actionSearch; // mozna
    QAction *actionDocumentation;
    QAction *actionAbout;

    /*Integerers for window size*/
    quint16 width, height;

    /*Text editor methods*/
    void createActions();
    void createMenuBar();
    void createToolBar();
    void createTextEdit();
    void createStatusBar();
    void setSize();
public:
    explicit TextEditor(QWidget *parent = 0);

signals:

public slots:
};

#endif // TEXTEDITOR

