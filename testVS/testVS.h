#pragma once

#include <QtWidgets/QWidget>
#include <qgraphicsscene.h>
#include "ui_testVS.h"
#include <QtCore>
#include <QtGui>
#include <qpainter.h>
#include <qgraphicsitem.h>
#include <qdebug.h>
//#include "myCity.h"
#include "Graf.h"

class testVS : public QWidget
{
    Q_OBJECT

public:
    testVS(QWidget *parent = Q_NULLPTR);
    void uzupelnij_pozycje();
    void Rysuj_krawedzie(QString miasto_poczatek, QString miasto_koniec, QString color);
    void Rysuj_Graf();

protected:
    void paintEvent(QPaintEvent* event);


private slots:
    void wroclaw_label();
    void warszawa_label();
    void szczecin_label();
    void gdansk_label();
    void olsztyn_label();
    void bydgoszcz_label();
    void bialystok_label();
    void krakow_label();
    void poznan_label();
    void zielonag_label();
    void lublin_label();
    void katowice_label();
    void rzeszow_label();
    void kielce_label();
    void lodz_label();
    void opole_label();

    void oblicz_droge();

private:
    void set_label(QString miasto);
    Ui::testVSClass ui;
    QGraphicsScene *scena;
    Graph* obj;
    Miasto_pozycja m_Miasta[16];
    //myCity* square;
    //myCity* square_2;
};
