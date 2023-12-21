#pragma once

#include "CustomMenuBar.h"
#include "CustomWidget.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QMainWindow mainWindow;
	mainWindow.show();

	CustomWidget* cWidget = new CustomWidget();
	mainWindow.setCentralWidget(cWidget);

	CustomMenuBar* cMenubar = new CustomMenuBar();

	mainWindow.setMenuBar(cMenubar);


	QJsonObject jsonObj;
	jsonObj.insert("insert", 11);
	jsonObj["test1"] = "test";
	jsonObj["test2"] = 1;

	QFile saveFile(QStringLiteral("deviceInfo.json"));
	saveFile.open(QIODevice::WriteOnly);

	QJsonDocument saveDoc(jsonObj);
	saveFile.write(saveDoc.toJson());
	saveFile.close();

	return app.exec();
}