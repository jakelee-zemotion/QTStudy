#include "CustomItemDelegate.h"
#include <QtWidgets/QApplication>
#include <QStyleOption>
#include <QStyledItemDelegate>


CustomItemDelegate::CustomItemDelegate()
{
}

QSize CustomItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	return QSize(20, 20);
}

void CustomItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyleOptionButton qstyleOptBtn;
	qstyleOptBtn.text = index.data().toString();
	qstyleOptBtn.rect = option.rect;

	QApplication::style()->drawControl(QStyle::CE_PushButton, &qstyleOptBtn, painter);
}

bool CustomItemDelegate::editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	switch (event->type())
	{
		case QEvent::MouseButtonRelease :
			qDebug() << "mouseRelease";

			emit ItemClicked();
			break;
	}
	

	return true;
}
