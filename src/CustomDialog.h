#pragma once
#include <QDialog>

class QVBoxLayout;
class QPushButton;
class CustomPaintWidget;
class CustomDialog :public QDialog
{
	Q_OBJECT

public :
	CustomDialog();

private:
	QVBoxLayout* layout;
	QPushButton* closeB;
	CustomPaintWidget* paintW;

private slots:
	void closeDialog();
};

