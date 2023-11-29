#pragma once

#include "CustomMenuBar.h"
#include "CustomWidget.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QMainWindow mainWindow;
	mainWindow.show();

	CustomWidget* cWidget = new CustomWidget();
	mainWindow.setCentralWidget(cWidget);

	CustomMenuBar* cMenubar = new CustomMenuBar();

	mainWindow.setMenuBar(cMenubar);

	return app.exec();
}