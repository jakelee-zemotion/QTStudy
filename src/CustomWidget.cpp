#include "CustomWidget.h"
#include "CustomItemDelegate.h"
#include "CustomEventFilter.h"
#include "CustomItemModel.h"

#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QListWidget>
#include <QStringListModel>
#include <QTimer>
#include <QTableView>
#include <QStandardItemModel>

CustomWidget::CustomWidget()
{
	// QLayout
	qPushB1 = new QPushButton("One");
	qPushB2 = new QPushButton("Timer");
	qRadioB = new QRadioButton("EventFilter Toggle");
	
	qvlayout = new QVBoxLayout(this);
	qhLayout1 = new QHBoxLayout();
	qhLayout2 = new QHBoxLayout();
	qhLayout3 = new QHBoxLayout();
	qvlayout->addLayout(qhLayout1);
	qvlayout->addLayout(qhLayout2);
	qvlayout->addLayout(qhLayout3);

	qhLayout1->addWidget(qPushB1, 0, Qt::AlignLeft);
	qhLayout2->addWidget(qPushB2, 0, Qt::AlignCenter);
	qhLayout3->addWidget(qRadioB, 0, Qt::AlignRight);

	//connect(qPushB1, SIGNAL(clicked(bool)), this, SLOT(printClick()));
	connect(qPushB2, SIGNAL(clicked(bool)), this, SLOT(btnClick()));
	connect(qRadioB, SIGNAL(toggled(bool)), this, SLOT(toggleEventFilter(bool)));

	qPushB1->setProperty("btn1", QString("str1"));
	QStringList strlist1 = { "abc", "def", "avdvd" };
	qPushB1->setProperty("btn2", QVariant::fromValue(strlist1));

	connect(qPushB1, &QPushButton::clicked, [this](bool checked) 
		{
			auto myData = qPushB1->property("btn1").toString();
			qDebug() << myData;

			auto myData2 = qPushB1->property("btn2").value<QStringList>();
			for (const auto& data : myData2)
			{
				qDebug() << data;
			}
		});

	// QListWidget
	qListWidget = new QListWidget();
	QStringList qstrList = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQR"};
	qListWidget->addItems(qstrList);

	qvlayout->addWidget(qListWidget);


	// QListView
	qListView = new QListView();

	CustomItemModel* customItemModel = new CustomItemModel();

	QStandardItemModel* qm = new QStandardItemModel(4, 4);
	QModelIndex index = qm->index(0, 0, QModelIndex());
	qm->setData(index, 100);


	QStringListModel* qstrListModel = new QStringListModel();
	qstrListModel->setStringList(qstrList);
	//qDebug() << qstrL

	//QModelIndex index = customItemModel->index(0, 0, QModelIndex());
	//customItemModel->setData(index, 1);


	QTableView* qq = new QTableView();
	qq->setModel(customItemModel);
	qvlayout->addWidget(qq);

	qListView->setModel(customItemModel);
	qvlayout->addWidget(qListView);

	customItemDelegate = new CustomItemDelegate();
	qListView->setItemDelegate(customItemDelegate);

	connect(customItemDelegate, SIGNAL(ItemClicked()), this, SLOT(showMessageBox()));




	// QTimer
	qTimer = new QTimer(this);
	connect(qTimer, SIGNAL(timeout()), this, SLOT(timerProc()));


	// EventFilter
	cEventFilter = new CustomEventFilter();
	qPushB1->installEventFilter(cEventFilter);
}

void CustomWidget::resizeEvent(QResizeEvent* event)
{
	qDebug() << "resize";
}

void CustomWidget::mousePressEvent(QMouseEvent* event)
{
	QMessageBox::information(this, "PressBox", "MousePressEvent");
}

void CustomWidget::btnClick()
{
	qTimer->start(1000);
}

void CustomWidget::showMessageBox()
{
	QMessageBox::information(this, "PressBox", "Item Clicked!");
}

void CustomWidget::toggleEventFilter(bool checked)
{
	if (checked)
	{
		qPushB1->removeEventFilter(cEventFilter);
	}
	else
	{
		qPushB1->installEventFilter(cEventFilter);
	}
}

void CustomWidget::timerProc()
{
	static int i = 0;
	qDebug() << i++;
}