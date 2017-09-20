#include "text-editor.h"

#include<QPlainTextEdit>
#include<QMenu>
#include<QMenuBar>
#include<QToolBar>
#include<QAction>
#include<QCloseEvent>
#include<QMessageBox>
#include<QStatusBar>


/*Implementation of text-editor class*/

TextEditor::TextEditor(QWidget *parent) : QMainWindow(parent)
{
    createActions();
    createMenuBar();
    createToolBar();
    createTextEdit();
    createStatusBar();
    setSize();
}

void TextEditor::createActions()
{
    QIcon iconNew = QIcon::fromTheme("document-new",
                    QIcon(":/icons/new.png"));
    actionNew = new QAction(tr("&New"), this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setToolTip(tr("New file"));
    actionNew->setStatusTip(tr("New file"));
    actionNew->setIcon(iconNew);

    QIcon iconOpen = QIcon::fromTheme("document-open",
                     QIcon(":/icons/open.png"));
    actionOpen = new QAction(tr("&Open"), this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setToolTip(tr("Open file"));
    actionOpen->setStatusTip(tr("Open file"));
    actionOpen->setIcon(iconOpen);

    QIcon iconSave = QIcon::fromTheme("document-save",
                     QIcon(":/icons/save.png"));
    actionSave = new QAction(tr("&Save"), this);
    actionSave->setShortcut(QKeySequence::Save);
    actionSave->setToolTip(tr("Save file"));
    actionSave->setStatusTip(tr("Save file"));
    actionSave->setIcon(iconSave);

    QIcon iconSaveAs = QIcon::fromTheme("document-save-as",
                       QIcon(":/icons/saveas.png"));
    actionSaveAs = new QAction(tr("Save &as"), this);
    actionSaveAs->setShortcut(QKeySequence::SaveAs);
    actionSaveAs->setToolTip(tr("Save file &as .."));
    actionSaveAs->setStatusTip(tr("Save file &as .."));
    actionSaveAs->setIcon(iconSaveAs);

    QIcon iconPrint = QIcon::fromTheme("document-print",
                      QIcon(":/icons/print.png"));
    actionPrint = new QAction(tr("&Print"), this);
    actionPrint->setShortcut(QKeySequence::Print);
    actionPrint->setStatusTip(tr("Print"));
    actionPrint->setToolTip(tr("Print"));
    actionPrint->setIcon(iconPrint);

    QIcon iconQuit = QIcon::fromTheme("application-exit",
                     QIcon(":/icons/quit.png"));
    actionQuit = new QAction(tr("&Quit"), this);
    actionQuit->setShortcut(QKeySequence::Quit);
    actionQuit->setStatusTip(tr("Quit"));
    actionQuit->setToolTip(tr("Quit"));
    actionQuit->setIcon(iconQuit);

    QIcon iconCut = QIcon::fromTheme("edit-cut",
                    QIcon(":/icons/cut.png"));
    actionCut = new QAction(tr("Cut"),this);
    actionCut->setShortcut(QKeySequence::Cut);
    actionCut->setStatusTip(tr("Cut the selected text"));
    actionCut->setToolTip(tr("Cut the selected text"));
    actionCut->setIcon(iconCut);

    QIcon iconCopy = QIcon::fromTheme("edit-copy",
                     QIcon(":/icons/copy.png"));
    actionCopy = new QAction(tr("&Copy"), this);
    actionCopy->setShortcut(QKeySequence::Copy);
    actionCopy->setStatusTip(tr("Copy to clipboard"));
    actionCopy->setToolTip(tr("Copy to clipboard"));
    actionCopy->setIcon(iconCopy);

    QIcon iconPaste = QIcon::fromTheme("edit-paste",
                      QIcon(":/icons/paste.png"));
    actionPaste = new QAction(tr("&Paste"), this);
    actionPaste->setShortcut(QKeySequence::Paste);
    actionPaste->setStatusTip(tr("Insert from clipboard"));
    actionPaste->setToolTip(tr("Insert from clipboard"));
    actionPaste->setIcon(iconPaste);

    QIcon iconDocumentation = QIcon::fromTheme("help-contents",
                      QIcon(":/icons/help.png"));
    actionDocumentation = new QAction(tr("&Help"), this);
    actionDocumentation->setShortcut(QKeySequence::HelpContents);
    actionDocumentation->setStatusTip(tr("Documentation"));
    actionDocumentation->setToolTip(tr("Documentation"));
    actionDocumentation->setIcon(iconDocumentation);

    QIcon iconAbout = QIcon::fromTheme("help-about",
                      QIcon(":/icons/about.png"));
    actionAbout = new QAction(tr("&About"), this);
    actionAbout->setStatusTip(tr("About editor"));
    actionAbout->setToolTip(tr("About editor"));
    actionAbout->setIcon(iconAbout);


}

void TextEditor::createMenuBar()
{
    menuFile = new QMenu(tr("File"), this);
    menuFile->addAction(actionNew);
    menuFile->addSeparator();
    menuFile->addAction(actionOpen);
    menuFile->addSeparator();
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSaveAs);
    menuFile->addSeparator();
    menuFile->addAction(actionPrint);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);
    menuBar()->addMenu(menuFile);

    menuEdit = new QMenu(tr("Edit"), this);
    menuEdit->addAction(actionCut);
    menuEdit->addAction(actionCopy);
    menuEdit->addAction(actionPaste);
    menuBar()->addMenu(menuEdit);

    menuHelp = new QMenu(tr("Help"), this);
    menuHelp->addAction(actionDocumentation);
    menuHelp->addSeparator();
    menuHelp->addAction(actionAbout);
    menuBar()->addMenu(menuHelp);
}

void TextEditor::createToolBar()
{
    mainToolbar = addToolBar(tr("Main tool bar"));
    mainToolbar->addAction(actionOpen);
}

void TextEditor::createTextEdit()
{
    textEdit = new QPlainTextEdit;
    setCentralWidget(textEdit);
}

void TextEditor::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void TextEditor::setSize()
{
    width = 800;
    height = 600;
    resize(width,height);
}
