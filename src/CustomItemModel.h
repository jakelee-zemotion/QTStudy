#pragma once
#include <QAbstractItemModel>

class CustomItemModel : public QAbstractItemModel
{
public:
	CustomItemModel(int row = 1, int column = 1);

	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
	QModelIndex	parent(const QModelIndex& index) const override;
	int	rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int	columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

private:
	int *i = new int(400);
};

