#include "HeaderFiles/Level.h"
Level::Level(float px, float py, GolfHole hole, std::vector<Rectangle> Rectangles, std::vector<Vector3> BarrierTop, std::vector<Vector3> BarrierLeft, std::vector<Vector3> BarrierDown, std::vector<Vector3> BarrierRight)
{
    this->BarrierTop = BarrierTop;
    this->BarrierLeft = BarrierLeft;
    this->BarrierDown = BarrierDown;
    this->BarrierRight = BarrierRight;

    this->Rectangles = Rectangles;
    this->px = px;
    this->py = py;
    GolfBall.push_back(Ball(px, py, 0, 0, 0, 0, 7.5, 1, false, 10));
    this->holex = hole.getx();
    this->holey = hole.gety();
    this->holeradius = hole.getRadius();
}

Level::~Level()
{
}

void Level::Draw()
{
    // rectangles
    for (auto rectangle : Rectangles)
    {
        DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, GREEN);
    }

    // Hole
    DrawCircle(holex, holey, holeradius, BLACK);
    // Draw Ball
}

void Level::CheckCollision()
{

    // studs mot vägg
    /*
    if (GolfBall->getPos().x < (currentLevel.grassx + defaultRadius))
    {
        GolfBall->setVx(-GolfBall->getvx()); //ändra riktning
        GolfBall->setax(-GolfBall->getax()); //'ndra accelrerande riktning
        GolfBall->setPx(currentLevel.grassx + defaultRadius);
    } // kolla vänster kanten
    if (GolfBall->getPos().x > (currentLevel.grassx + currentLevel.grassWidth - defaultRadius))
    {
        GolfBall->setVx(-GolfBall->getvx()); //ändra riktning
        GolfBall->setax(-GolfBall->getax()); //'ndra accelrerande riktning
        GolfBall->setPx(currentLevel.grassx + currentLevel.grassWidth - defaultRadius);
    } // kolla högerkanten
    if (GolfBall->getPos().y < (currentLevel.grassy + defaultRadius))
    {
        GolfBall->setVy(-GolfBall->getvy()); //ändra riktning
        GolfBall->setay(-GolfBall->getay()); //'ndra accelrerande riktning
        GolfBall->setPy(currentLevel.grassy + defaultRadius);
    }
    if (GolfBall->getPos().y > (currentLevel.grassy + currentLevel.grassHeight - defaultRadius))
    {
        GolfBall->setVy(-GolfBall->getvy()); //ändra riktning
        GolfBall->setay(-GolfBall->getay()); //'ndra accelrerande riktning
        GolfBall->setPy(currentLevel.grassy + currentLevel.grassHeight - defaultRadius);
    }
    */

    // check top
    for (auto Line : BarrierTop)
    {
        Rectangle req{Line.x, Line.y, Line.z, 2};
        if (CheckCollisionCircleRec({GolfBall[0].getpx(), GolfBall[0].getpy()}, GolfBall[0].getRadius(), req)) // barrier uppåt
        {
            GolfBall[0].setVy(-GolfBall[0].getvy()); //ändra riktning
            GolfBall[0].setay(-GolfBall[0].getay()); //'ndra accelrerande riktning
            GolfBall[0].setPy(Line.y + GolfBall[0].getRadius() + 4);
        }
    }

    for (auto Line : BarrierLeft)
    {
        Rectangle req{Line.x, Line.y, 2, Line.z};
        if (CheckCollisionCircleRec({GolfBall[0].getpx(), GolfBall[0].getpy()}, GolfBall[0].getRadius(), req)) // Barriär vänster
        {
            GolfBall[0].setVx(-GolfBall[0].getvx()); //ändra riktning
            GolfBall[0].setax(-GolfBall[0].getax()); //'ndra accelrerande riktning
        }
    }

    for (auto Line : BarrierDown)
    {
        Rectangle req{Line.x, Line.y, Line.z, 2};
        if (CheckCollisionCircleRec({GolfBall[0].getpx(), GolfBall[0].getpy()}, GolfBall[0].getRadius(), req)) // barriär höger
        {
            GolfBall[0].setVy(-GolfBall[0].getvy()); //ändra riktning
            GolfBall[0].setay(-GolfBall[0].getay()); //'ndra accelrerande riktning
            GolfBall[0].setPy((Line.y) - GolfBall[0].getRadius() - 4);
        }
    }
}