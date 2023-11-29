#include "CustomDialog.h"
#include "CustomPaintWidget.h"
#include <QPushButton>
#include <QVBoxLayout>

CustomDialog::CustomDialog()
{
	layout = new QVBoxLayout();
	closeB = new QPushButton("Close");
	paintW = new CustomPaintWidget();

	this->setLayout(layout);
	layout->addWidget(paintW);
	layout->addWidget(closeB);

	connect(closeB, SIGNAL(clicked(bool)), this, SLOT(closeDialog()));
}

void CustomDialog::closeDialog()
{
	this->close();
}
