#pragma once
#include <QObject>

class CustomEventFilter : public QObject
{
public:
	CustomEventFilter();

protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
};

