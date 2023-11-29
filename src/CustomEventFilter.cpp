#include "CustomEventFilter.h"
#include <QEvent>

CustomEventFilter::CustomEventFilter()
{
}

bool CustomEventFilter::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress
		|| event->type() == QEvent::MouseButtonRelease
		|| event->type() == QEvent::MouseButtonDblClick)
		return true;
	else
		return QObject::eventFilter(obj, event);
}
