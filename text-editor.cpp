#include "text-editor.h"

#include<QPlainTextEdit>
#include<QMenu>
#include<QPrinter>
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
    connectSignals();
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
    actionSaveAs->setToolTip(tr("Save file as .."));
    actionSaveAs->setStatusTip(tr("Save file as .."));
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
    mainToolbar->addAction(actionNew);
    mainToolbar->addSeparator();
    mainToolbar->addAction(actionOpen);
    mainToolbar->addSeparator();
    mainToolbar->addAction(actionSave);
    mainToolbar->addAction(actionSaveAs);
    mainToolbar->addSeparator();
    mainToolbar->addAction(actionCut);
    mainToolbar->addAction(actionCopy);
    mainToolbar->addAction(actionPaste);
    mainToolbar->addSeparator();
    mainToolbar->addAction(actionPrint);
    mainToolbar->addSeparator();
    mainToolbar->addAction(actionDocumentation);
    mainToolbar->addAction(actionAbout);
    mainToolbar->addSeparator();
    mainToolbar->addAction(actionQuit);
    mainToolbar->addSeparator();
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

void TextEditor::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this, tr("Are you sure?"), tr("Do you wish to quit?"))
            == QMessageBox::Yes){
        event->accept();
    } else{
        event->ignore();
    }
}

void TextEditor::connectSignals()
{
    connect(actionQuit, SIGNAL(triggered()),
                this, SLOT(close()));
    connect(actionAbout, SIGNAL(triggered()),
                this, SLOT(about()));
    connect(actionDocumentation, SIGNAL(triggered()),
                this, SLOT(documentation()));
    connect(actionPrint, SIGNAL(triggered()),
                this, SLOT(print()));
}

void TextEditor::documentation()
{
    QMessageBox::about(this, tr("About this editor"),
            tr("<center><h3><u>Documentation</u></h3>"
               "The documentation for this editor is available online on the following link below: "
               "<br />"
               "<br />"
               "<i>http://www.people.fjfi.cvut.cz/simonda4/editor.html</i>"
               "</center>"));
}

void TextEditor::about()
{
    QMessageBox::about(this, tr("About this editor"),
            tr("<center><h3><u>Text Editor v1.1</u></h3>"
               "This editor was created for the course of Programming in C++ 2 at FNSPE CTU. "
               "It is based on Qt v5.9 and C++ 11. "
               "<br />"
               "<br />"
               "<b>Daniel Simon | dansimon93@gmail.com </b>"));
}

void TextEditor::print()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output.pdf");
    textEdit->print(&printer);

    QMessageBox::about(this, tr("Printer message"),
            tr("File has been successfully printed!"));
}
