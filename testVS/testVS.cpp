#include "testVS.h"

testVS::testVS(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Matematyka Dyskretna - Projekt");

    scena = new QGraphicsScene(0, 0, 600,568);

    scena->addPixmap(QPixmap("C:\\Users\\Marcin\\Desktop\\Projects\\testVS\\poland.jpg"));


    

    ui.graphicsView->setScene(scena);

    connect(ui.Wroclaw_Btn, SIGNAL(clicked()), this, SLOT(wroclaw_label()));
    connect(ui.Warszawa_Btn, SIGNAL(clicked()), this, SLOT(warszawa_label()));
    connect(ui.Szczecin_Btn, SIGNAL(clicked()), this, SLOT(szczecin_label()));
    connect(ui.Gdansk_Btn, SIGNAL(clicked()), this, SLOT(gdansk_label()));
    connect(ui.Olsztyn_Btn, SIGNAL(clicked()), this, SLOT(olsztyn_label()));
    connect(ui.Bydgoszcz_Btn, SIGNAL(clicked()), this, SLOT(bydgoszcz_label()));
    connect(ui.Bialystok_Btn, SIGNAL(clicked()), this, SLOT(bialystok_label()));
    connect(ui.Krakow_Btn, SIGNAL(clicked()), this, SLOT(krakow_label()));
    connect(ui.Poznan_Btn, SIGNAL(clicked()), this, SLOT(poznan_label()));
    connect(ui.ZielonaG_Btn, SIGNAL(clicked()), this, SLOT(zielonag_label()));
    connect(ui.Lublin_Btn, SIGNAL(clicked()), this, SLOT(lublin_label()));
    connect(ui.Katowice_Btn, SIGNAL(clicked()), this, SLOT(katowice_label()));
    connect(ui.Rzeszow_Btn, SIGNAL(clicked()), this, SLOT(rzeszow_label()));
    connect(ui.Kielce_Btn, SIGNAL(clicked()), this, SLOT(kielce_label()));
    connect(ui.Lodz_Btn, SIGNAL(clicked()), this, SLOT(lodz_label()));
    connect(ui.Opole_Btn, SIGNAL(clicked()), this, SLOT(opole_label()));

    uzupelnij_pozycje();
    obj = new Graph(16);

    obj->add_edge(0, 1, 246, "Bialystok", "Lublin");
    obj->add_edge(0, 5,200, "Bialystok", "Warszawa");
    obj->add_edge(0, 6, 223, "Bialystok", "Olsztyn");
    obj->add_edge(1, 2, 184, "Lublin", "Rzeszow");
    obj->add_edge(1, 5, 173, "Lublin", "Warszawa");
    obj->add_edge(1, 4, 195, "Lublin", "Kielce");
    obj->add_edge(2, 3, 172, "Rzeszow", "Krakow");
    obj->add_edge(2, 4, 155, "Rzeszow", "Kielce");
    obj->add_edge(3, 4, 114, "Krakow", "Kielce");
    obj->add_edge(3, 9, 80, "Krakow", "Katowice");
    obj->add_edge(4, 5, 181, "Kielce", "Warszawa");
    obj->add_edge(5, 8, 142, "Warszawa", "Lodz");
    obj->add_edge(5, 6, 214, "Warszawa", "Olsztyn");
    obj->add_edge(7, 6, 224, "Bydgoszcz", "Olsztyn");
    obj->add_edge(7, 8, 226, "Bydgoszcz", "Lodz");
    obj->add_edge(7, 11, 221, "Bydgoszcz", "Gdansk");
    obj->add_edge(9, 4, 156, "Katowice", "Kielce");
    obj->add_edge(9, 8, 203, "Katowice", "Lodz");
    obj->add_edge(15, 9, 104, "Opole", "Katowice");
    obj->add_edge(15, 12, 97, "Opole", "Wroclaw");
    //obj->add_edge(9, 12, 194, "Katowice", "Wroclaw");
    obj->add_edge(10, 12, 182, "Poznan", "Wroclaw");
    obj->add_edge(10, 7, 138, "Poznan", "Bydgoszcz");
    obj->add_edge(8, 4, 153, "Lodz", "Kielce");
    obj->add_edge(10, 14, 265, "Poznan", "Szczecin");
    obj->add_edge(13, 14, 213, "Zielona Gora", "Szczecin");
    obj->add_edge(13, 12, 166, "Zielona Gora", "Wroclaw");
    obj->add_edge(14, 11, 358, "Szczecin", "Gdansk");
    obj->add_edge(6, 11, 166, "Olsztyn", "Gdansk");
    obj->add_edge(13, 10, 153, "Zielona Gora", "Poznan");
    obj->add_edge(10, 8, 206, "Poznan", "Lodz");

    Rysuj_Graf();
    

    ui.graphicsView->show();
    
    
    connect(ui.Dij_Btn, SIGNAL(clicked()), this, SLOT(oblicz_droge()));
}

void testVS::wroclaw_label()
{
    set_label("Wroclaw");
}

void testVS::uzupelnij_pozycje()
{
    m_Miasta[0].city = "Szczecin";
    m_Miasta[0].x = 40;
    m_Miasta[0].y = 100;

    m_Miasta[1].city = "Poznan";
    m_Miasta[1].x = 190;
    m_Miasta[1].y = 250;

    m_Miasta[2].city = "Wroclaw";
    m_Miasta[2].x = 130;
    m_Miasta[2].y = 380;

    m_Miasta[3].city = "Zielona Gora";
    m_Miasta[3].x = 40;
    m_Miasta[3].y = 250;

    m_Miasta[4].city = "Gdansk";
    m_Miasta[4].x = 270;
    m_Miasta[4].y = 35;

    m_Miasta[5].city = "Bydgoszcz";
    m_Miasta[5].x = 270;
    m_Miasta[5].y = 170;

    m_Miasta[6].city = "Lodz";
    m_Miasta[6].x = 300;
    m_Miasta[6].y = 320;

    m_Miasta[7].city = "Katowice";
    m_Miasta[7].x = 280;
    m_Miasta[7].y = 430;

    m_Miasta[8].city = "Krakow";
    m_Miasta[8].x = 390;
    m_Miasta[8].y = 490;

    m_Miasta[9].city = "Kielce";
    m_Miasta[9].x = 410;
    m_Miasta[9].y = 380;

    m_Miasta[10].city = "Warszawa";
    m_Miasta[10].x = 410;
    m_Miasta[10].y = 250;

    m_Miasta[11].city = "Olsztyn";
    m_Miasta[11].x = 420;
    m_Miasta[11].y = 100;

    m_Miasta[12].city = "Bialystok";
    m_Miasta[12].x = 515;
    m_Miasta[12].y = 130;

    m_Miasta[13].city = "Lublin";
    m_Miasta[13].x = 520;
    m_Miasta[13].y = 365;

    m_Miasta[14].city = "Rzeszow";
    m_Miasta[14].x = 510;
    m_Miasta[14].y = 460;

    m_Miasta[15].city = "Opole";
    m_Miasta[15].x = 200;
    m_Miasta[15].y = 400;
}

void testVS::Rysuj_krawedzie(QString miasto_poczatek, QString miasto_koniec, QString color)
{
    int x1=0, y1=0;
    int x2=0, y2=0;
    QPen pen;  // creates a default pen
    pen.setWidth(3);
    if (color == "red")
    {
        pen.setBrush(Qt::red);
    }
    else
    {
        pen.setBrush(Qt::blue);
    }
    for (int i = 0; i < 16; i++)
    {
        if (m_Miasta[i].city == miasto_poczatek)
        {
            x1 = m_Miasta[i].x;
            y1 = m_Miasta[i].y;
        }
        if (m_Miasta[i].city == miasto_koniec)
        {
            x2 = m_Miasta[i].x;
            y2 = m_Miasta[i].y;
        }
        if (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0)
        {
            scena->addLine(QLineF(x1, y1, x2, y2), pen);
        }
    }
}

void testVS::Rysuj_Graf()
{
    Rysuj_krawedzie("Bialystok", "Lublin", "red");
    Rysuj_krawedzie("Bialystok", "Warszawa", "red");
    Rysuj_krawedzie("Bialystok", "Olsztyn", "red");
    Rysuj_krawedzie("Lublin", "Rzeszow", "red");
    Rysuj_krawedzie("Lublin", "Warszawa", "red");
    Rysuj_krawedzie("Lublin", "Kielce", "red");
    Rysuj_krawedzie("Rzeszow", "Krakow", "red");
    Rysuj_krawedzie("Rzeszow", "Kielce", "red");
    Rysuj_krawedzie("Krakow", "Kielce", "red");
    Rysuj_krawedzie("Krakow", "Katowice", "red");
    Rysuj_krawedzie("Kielce", "Warszawa", "red");
    Rysuj_krawedzie("Warszawa", "Lodz", "red");
    Rysuj_krawedzie("Warszawa", "Olsztyn", "red");
    Rysuj_krawedzie("Bydgoszcz", "Olsztyn", "red");
    Rysuj_krawedzie("Bydgoszcz", "Lodz", "red");
    Rysuj_krawedzie("Bydgoszcz", "Gdansk", "red");
    Rysuj_krawedzie("Katowice", "Kielce", "red");
    Rysuj_krawedzie("Katowice", "Lodz", "red");
    //Rysuj_krawedzie("Katowice", "Wroclaw", "red");
    Rysuj_krawedzie("Katowice", "Opole", "red");
    Rysuj_krawedzie("Opole", "Wroclaw", "red");
    Rysuj_krawedzie("Poznan", "Wroclaw", "red");
    Rysuj_krawedzie("Poznan", "Lodz", "red");
    Rysuj_krawedzie("Poznan", "Bydgoszcz", "red");
    Rysuj_krawedzie("Lodz", "Kielce", "red");
    Rysuj_krawedzie("Poznan", "Szczecin", "red");
    Rysuj_krawedzie("Zielona Gora", "Szczecin", "red");
    Rysuj_krawedzie("Zielona Gora", "Wroclaw", "red");
    Rysuj_krawedzie("Szczecin", "Gdansk", "red");
    Rysuj_krawedzie("Olsztyn", "Gdansk", "red");
    Rysuj_krawedzie("Olsztyn", "Gdansk", "red");
    Rysuj_krawedzie("Zielona Gora", "Poznan", "red");
}

void testVS::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(0, 0, 200, 200);
}

void testVS::warszawa_label()
{
    set_label("Warszawa");
}

void testVS::szczecin_label()
{
    set_label("Szczecin");
}

void testVS::gdansk_label()
{
    set_label("Gdansk");
}

void testVS::olsztyn_label()
{
    set_label("Olsztyn");
}

void testVS::bydgoszcz_label()
{
    set_label("Bydgoszcz");
}

void testVS::bialystok_label()
{
    set_label("Bialystok");
}

void testVS::krakow_label()
{
    set_label("Krakow");
}

void testVS::poznan_label()
{
    set_label("Poznan");
}

void testVS::zielonag_label()
{
    set_label("Zielona Gora");
}

void testVS::lublin_label()
{
    set_label("Lublin");
}

void testVS::katowice_label()
{
    set_label("Katowice");
}

void testVS::rzeszow_label()
{
    set_label("Rzeszow");
}

void testVS::kielce_label()
{
    set_label("Kielce");
}

void testVS::lodz_label()
{
    set_label("Lodz");
}

void testVS::opole_label()
{
    set_label("Opole");
}

void testVS::oblicz_droge()
{
    obj->path.clear();
    Rysuj_Graf();

    int n = obj->Get_m_V();
    int miasto_poczatkowe = n + 1;
    int miasto_koncowe = n + 1;
    Vertex** Graph_list = obj->Get_m_Adj();
    for (int i = 0; i < n; i++)
    {
        Vertex* tmp = Graph_list[i];
        while (tmp)
        {
            if (ui.miasto_p->text() == tmp->city)
            {
                miasto_poczatkowe = tmp->id;
            }
            if (ui.miasto_k->text() == tmp->city)
            {
                miasto_koncowe = tmp->id;
            }
            tmp = tmp->next;
        }
    }
    if ((miasto_poczatkowe != n + 1) && miasto_koncowe != n + 1)
    {
        ui.Dij_label->setText(QString::number(obj->Dijkstra(miasto_poczatkowe, miasto_koncowe))+ "km");

        std::vector<QString> nazwy_miast;
        for (const auto& value : obj->path)
        {
            for (int i = 0; i < n; i++)
            {
                Vertex* tmp = Graph_list[i];
                while (tmp)
                {
                    if (tmp->id == value)
                    {
                        nazwy_miast.push_back(tmp->city);
                    }
                    tmp = tmp->next;
                }
            }
        }
        for (int i = 1; i < nazwy_miast.size(); i++)
        {
            Rysuj_krawedzie(nazwy_miast[i-1], nazwy_miast[i], "blue");
        }
    }
    ui.graphicsView->show();
}


void testVS::set_label(QString miasto)
{
    if (ui.radioButton->isChecked())
    {
        ui.miasto_p->setText(miasto);

        if (ui.miasto_p->text() == ui.miasto_k->text())
        {
            ui.miasto_k->setText("Wybierz miasto");
        }
    }
    if (ui.radioButton_2->isChecked())
    {
        ui.miasto_k->setText(miasto);
        if (ui.miasto_p->text() == ui.miasto_k->text())
        {
            ui.miasto_p->setText("Wybierz miasto");
        }
    }
}
