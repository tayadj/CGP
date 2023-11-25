#ifndef NAIVEALGORITHM_H
#define NAIVEALGORITHM_H

#include "qpainterpath.h"
#include <QtWidgets>

class NaiveAlgorithm : public QWidget
{
    Q_OBJECT

    public:
        explicit NaiveAlgorithm(int, int, int, int, QWidget *parent = nullptr);
        void paintEvent(QPaintEvent*)
        {
            QPainter painter(this);
            double hScale = 40, wScale = 40;

            painter.translate(this->width()/2,this->height()/2);
            painter.setPen(QPen(QColor("#42aaff"), 1));
            painter.setBrush(QColor("#42aaff"));

            for(int i = 0; i < (int)points.size(); i++)
            {
                painter.drawRect(points[i].x()*wScale,
                                 (points[i].y()-1)*hScale,
                                 wScale,
                                 hScale);
            }

            QPainterPath text;
            QFont f ("Segoe UI", 8);
            f.setStyleStrategy(QFont::ForceOutline);

            painter.setPen(QPen(Qt::black, 1));
            painter.drawLine(-this->width()/2, 0, this->width()/2, 0);
            painter.drawLine(0, -this->height()/2, 0, this->height()/2);

            text.addText(5, -5, f, QString::number(0));

            for(int i = 1; i < (int) this->width() / (wScale * 2); ++i){
                painter.setPen(QPen(Qt::black, 3));
                text.addText(i * wScale + 5, -5, f, QString::number(i));
                text.addText(-i * wScale + 5, -5, f, QString::number(-i));
                painter.setPen(QPen(Qt::black, 1));
                painter.drawLine(-i * wScale, -this->height()/2, -i * wScale, this->height()/2);
                painter.drawLine(i * wScale, -this->height()/2, i*wScale, this->height()/2);
            }

            for(int i = 1; i < (int) this->height() / (hScale * 2); ++i){
                painter.setPen(QPen(Qt::black, 3));
                text.addText(5, -i*hScale - 5, f, QString::number(-i));
                text.addText(5, i*hScale - 5, f, QString::number(i));
                painter.setPen(QPen(Qt::black, 1));
                painter.drawLine(-this->width()/2, -i*hScale, this->width()/2, -i*hScale);
                painter.drawLine(-this->width()/2, i*hScale, this->width()/2, i*hScale);
            }

            painter.setPen(QPen(Qt::black, 1));
            painter.setBrush(QBrush(Qt::black));
            painter.drawPath(text);
        }
    signals:

    private:
        std::vector <QPointF> points;
};

#endif // NAIVEALGORITHM_H
