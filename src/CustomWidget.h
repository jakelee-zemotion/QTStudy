#pragma once
#include <QWidget>

class QPushButton; 
class QRadioButton;
class QVBoxLayout;
class QHBoxLayout;
class QListWidget;
class QListView;
class CustomItemDelegate;
class QTimer;
class CustomEventFilter;
class CustomWidget : public QWidget
{
	Q_OBJECT

public:
	CustomWidget();

protected:
	void resizeEvent(QResizeEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

private :
	QPushButton* qPushB1;
	QPushButton* qPushB2;
	QRadioButton* qRadioB;

	QVBoxLayout* qvlayout;
	QHBoxLayout* qhLayout1;
	QHBoxLayout* qhLayout2;
	QHBoxLayout* qhLayout3;

	QListWidget* qListWidget;
	QListView* qListView;

	CustomItemDelegate* customItemDelegate;

	QTimer* qTimer;

	CustomEventFilter* cEventFilter;

private slots:
	void timerProc();
	void btnClick();
	void showMessageBox();

	void toggleEventFilter(bool checked);
};

