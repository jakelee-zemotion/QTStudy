#pragma once
#include <QAbstractItemDelegate>

class CustomItemDelegate : public QAbstractItemDelegate
{
	Q_OBJECT

public:
	CustomItemDelegate();

signals:
	void ItemClicked();

protected:
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

	bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index) override;

private:

};

