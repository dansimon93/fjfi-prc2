#ifndef TEXTEDITOR
#define TEXTEDITOR

#include<QMainWindow>

/*Imported classes*/
class QPlainTextEdit;
class QMenu;
class QToolBar;
class QAction;
class QCloseEvent;
class QString;


class TextEditor : public QMainWindow
{

    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = 0);

private:
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

    /*File name*/
    QString FILE;

    /*Init of components*/
    void createActions();
    void createMenuBar();
    void createToolBar();
    void createTextEdit();
    void createStatusBar();
    void setSize();
    void connectSignals();
    /*Text-editor methods*/
    void isModified();
    bool checkChanges();
    void openFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setFile(const QString &fileName);

    void closeEvent(QCloseEvent *event);

signals:

public slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void printPDF();
    void about();
    void documentation();
};

#endif // TEXTEDITOR

