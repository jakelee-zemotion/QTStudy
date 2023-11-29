#pragma once
#include <QMenuBar>

class QMenu;
class QAction;
class CustomMenuBar : public QMenuBar
{
	Q_OBJECT

public :
	CustomMenuBar();

private:
	QMenu* fileMenu;
	QAction* printAct;

	QMenu* editMenu;
	QAction* paintAct;

	QMenu* viewMenu;

private slots :
	void printHi();
	void showPaintDialog();
};

