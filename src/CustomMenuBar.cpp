#include "CustomMenuBar.h"
#include "CustomDialog.h"
#include <QDebug>
#include <QMenu>

CustomMenuBar::CustomMenuBar()
{
	// 1. File
	fileMenu = new QMenu("File");
	printAct = new QAction("Print hi");
	fileMenu->addAction(printAct);
	connect(printAct, SIGNAL(triggered()), this, SLOT(printHi()));

	// 2. Edit
	editMenu = new QMenu("Edit");
	paintAct = new QAction("Paint");
	editMenu->addAction(paintAct);
	connect(paintAct, SIGNAL(triggered()), this, SLOT(showPaintDialog()));

	// 3. View
	viewMenu = new QMenu("View");


	this->addMenu(fileMenu);
	this->addMenu(editMenu);
	this->addMenu(viewMenu);
}

void CustomMenuBar::showPaintDialog()
{
	CustomDialog customDialog;
	customDialog.exec();
}

void CustomMenuBar::printHi()
{
	qDebug() << "hi";
}