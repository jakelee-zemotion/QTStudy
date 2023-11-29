#pragma once
#include <QWidget>

class CustomPaintWidget : public QWidget
{
public:
	CustomPaintWidget();

protected:
	void paintEvent(QPaintEvent* event) override;

private:
};

