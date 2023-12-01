#include "CustomItemModel.h"


CustomItemModel::CustomItemModel(int row, int column)
{
}

QModelIndex CustomItemModel::index(int row, int column, const QModelIndex& parent) const
{
	return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QModelIndex CustomItemModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

int CustomItemModel::rowCount(const QModelIndex& parent) const
{
	return 1;
}

int CustomItemModel::columnCount(const QModelIndex& parent) const
{
	return 2;
}

QVariant CustomItemModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
		return "foo";
	else
		return QVariant();
}
