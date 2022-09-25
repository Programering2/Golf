#include "Game.h"

Game::Game(int WindowWidth, int WindowHeight)
{
    this->WindowWidth = static_cast<float>(WindowWidth);
    this->WindowHeight = static_cast<float>(WindowHeight);
    defaultRadius = 11.43f;
    friction = 0.8f;
    CueMultiplier = 5.f;
    mass = 10 * defaultRadius;
    NmbrOfBalls = 16;

    BoardWidth = 896;
    BoardHeight = 448;
    Boardx = (WindowWidth / 2) - (BoardWidth / 2);
    Boardy = (WindowHeight / 2) - (BoardHeight / 2);
    rackDistanceY = Boardy + (BoardHeight / 2);
    rackDistanceX = Boardx + (BoardWidth * 0.66);

    debugmode = false; // draws debug lines etcetra

    // add balls
    // cueball
    addBall ball1 = {(BoardWidth * 0.25f) + Boardx, rackDistanceY, defaultRadius, true, false, false};
    // eight ball
    addBall ball6 = {rackDistanceX + (defaultRadius * 2) * 2, rackDistanceY, defaultRadius, false, true, false};
    // Player One
    addBall ball2 = {rackDistanceX, rackDistanceY, defaultRadius, false, false, true};
    addBall ball3 = {rackDistanceX + (defaultRadius * 2), rackDistanceY + defaultRadius, defaultRadius, false, false, false};
    addBall ball4 = {rackDistanceX + (defaultRadius * 2), rackDistanceY - defaultRadius, defaultRadius, false, false, false};
    addBall ball5 = {rackDistanceX + (defaultRadius * 2) * 2, rackDistanceY + (defaultRadius)*2, defaultRadius, false, false, false};
    addBall ball7 = {rackDistanceX + (defaultRadius * 2) * 2, rackDistanceY - (defaultRadius)*2, defaultRadius, false, false, true};
    addBall ball8 = {rackDistanceX + (defaultRadius * 2) * 3, rackDistanceY - (defaultRadius)*3, defaultRadius, false, false, false};
    addBall ball9 = {rackDistanceX + (defaultRadius * 2) * 3, rackDistanceY - (defaultRadius), defaultRadius, false, false, true};
    // player two
    addBall ball10 = {rackDistanceX + (defaultRadius * 2) * 3, rackDistanceY + (defaultRadius), defaultRadius, false, false, true};
    addBall ball11 = {rackDistanceX + (defaultRadius * 2) * 3, rackDistanceY + (defaultRadius)*3, defaultRadius, false, false, true};
    addBall ball12 = {rackDistanceX + (defaultRadius * 2) * 4, rackDistanceY - (defaultRadius)*4, defaultRadius, false, false, false};
    addBall ball13 = {rackDistanceX + (defaultRadius * 2) * 4, rackDistanceY - (defaultRadius)*2, defaultRadius, false, false, true};
    addBall ball14 = {rackDistanceX + (defaultRadius * 2) * 4, rackDistanceY, defaultRadius, false, false, false};
    addBall ball15 = {rackDistanceX + (defaultRadius * 2) * 4, rackDistanceY + (defaultRadius)*2, defaultRadius, false, false, true};
    addBall ball16 = {rackDistanceX + (defaultRadius * 2) * 4, rackDistanceY + (defaultRadius)*4, defaultRadius, false, false, false};

    // set in ball 1-14 first
    Preballs.push_back(ball1);
    Preballs.push_back(ball2);
    Preballs.push_back(ball3);
    Preballs.push_back(ball4);
    Preballs.push_back(ball5);
    Preballs.push_back(ball6);
    Preballs.push_back(ball7);
    Preballs.push_back(ball8);
    Preballs.push_back(ball9);
    Preballs.push_back(ball10);
    Preballs.push_back(ball11);
    Preballs.push_back(ball12);
    Preballs.push_back(ball13);
    Preballs.push_back(ball14);
    Preballs.push_back(ball15);
    Preballs.push_back(ball16);

    AddBall(Preballs);
}

void Game::AddBall(std::vector<addBall> _PreBalls)
{

    for (int i = 0; i < 16; i++)
    {
        float px = _PreBalls[i].x;
        float py = _PreBalls[i].y;
        float vx = 0;
        float vy = 0;
        float ax = 0;
        float ay = 0;
        float radius = defaultRadius;
        int id = i + 1;

        if (_PreBalls[i].cueball)
        {
            balls.push_back(CueBall(px, py, vx, vy, ax, ay, radius, id, debugmode, mass));
        }
        else if (_PreBalls[i].eightBall)
        {
            balls.push_back(EightBall(px, py, vx, vy, ax, ay, radius, id, debugmode, mass));
        }
        else if (!_PreBalls[i].cueball)
        {
            balls.push_back(ColorBall(px, py, vx, vy, ax, ay, radius, id, debugmode, mass, _PreBalls[i].playerOne));
        }
    }
}

void Game::Update() // once per frame ishh
{
    // Empty vector
    collidingPairs.clear();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) // if button pressed
    {
        pselectedBall = nullptr; // unselect previous selects

        for (auto &Ball : balls)
        {
            if (CheckCollisionCircles(GetMousePosition(), 1, Ball.getPos(), static_cast<float>(Ball.getRadius())))
            {
                pselectedBall = &Ball;
                break;
            }
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if (pselectedBall != nullptr)
        {
            pselectedBall->setPos(GetMousePosition());
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) // if button released
    {
        pselectedBall = nullptr;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) // if button released
    {
        if (pselectedBall != nullptr) // vi lägger till velocity
        {
            float vx, vy;
            vx = CueMultiplier * ((pselectedBall->getPos().x) - GetMousePosition().x);
            vy = CueMultiplier * ((pselectedBall->getPos().y) - GetMousePosition().y);
            pselectedBall->setVelocity({vx, vy});
        }
        pselectedBall = nullptr;
    }
    // bollar får nu fysiiik

    for (auto &Ball : balls)
    {
        Ball.setax(-Ball.getvx() * friction); // acceleration = hastighet * friction
        Ball.setay(-Ball.getvy() * friction);
        float vx, vy;
        vx = Ball.getVelocity().x + (Ball.getAcceleration().x * GetFrameTime()); // v = v0 + at
        vy = Ball.getVelocity().y + (Ball.getAcceleration().y * GetFrameTime());
        Ball.setVelocity({vx, vy});

        Ball.setPy(Ball.getPos().y + (Ball.getVelocity().y * GetFrameTime())); // s = s0 + vt
        Ball.setPx(Ball.getPos().x + (Ball.getVelocity().x * GetFrameTime()));

        // här gör så att dem kommer tillbaka på andra sidan

        if (Ball.getPos().x < (Boardx + defaultRadius))
        {
            Ball.setVx(-Ball.getvx()); //ändra riktning
            Ball.setax(-Ball.getax()); //'ndra accelrerande riktning
            Ball.setPx(Boardx + defaultRadius);
        } // kolla vänster kanten
        if (Ball.getPos().x > (Boardx + BoardWidth - defaultRadius))
        {
            Ball.setVx(-Ball.getvx()); //ändra riktning
            Ball.setax(-Ball.getax()); //'ndra accelrerande riktning
            Ball.setPx(Boardx + BoardWidth - defaultRadius);
        } // kolla högerkanten
        if (Ball.getPos().y < (Boardy + defaultRadius))
        {
            Ball.setVy(-Ball.getvy()); //ändra riktning
            Ball.setay(-Ball.getay()); //'ndra accelrerande riktning
            Ball.setPy(Boardy + defaultRadius);
        }
        if (Ball.getPos().y > (Boardy + BoardHeight - defaultRadius))
        {
            Ball.setVy(-Ball.getvy()); //ändra riktning
            Ball.setay(-Ball.getay()); //'ndra accelrerande riktning
            Ball.setPy(Boardy + BoardHeight - defaultRadius);
        }

        if (fabs(Ball.getvx() * Ball.getvx() + Ball.getvy() * Ball.getvy()) < 0.01f) // om farten är väldigt liten så ska den bli noll bara
        {
            Ball.setVx(0);
            Ball.setVy(0);
        }
    }

    for (auto &Ball : balls)
    {
        for (auto &target : balls)
        {
            if (Ball.getID() != target.getID()) // vi vill inte testa mot oss själva
            {
                if (CheckCollisionCircles(Ball.getPos(), static_cast<float>(Ball.getRadius()), target.getPos(), static_cast<float>(target.getRadius())))
                {
                    collidingPairs.push_back({&Ball, &target});
                    // distance mellan dem
                    float fDistance = sqrtf((Ball.getPos().x - target.getPos().x) * (Ball.getPos().x - target.getPos().x) + (Ball.getPos().y - target.getPos().y) * (Ball.getPos().y - target.getPos().y));

                    float fOverlap = 0.5 * (fDistance - Ball.getRadius() - target.getRadius());

                    // visa nuvarande boll
                    float px = Ball.getPos().x - (fOverlap * (Ball.getPos().x - target.getPos().x) / fDistance);
                    float py = Ball.getPos().y - (fOverlap * (Ball.getPos().y - target.getPos().y) / fDistance);
                    Ball.setPos({px, py});

                    // visa target boll
                    float tpx = target.getPos().x + (fOverlap * (Ball.getPos().x - target.getPos().x) / fDistance);
                    float tpy = target.getPos().y + (fOverlap * (Ball.getPos().y - target.getPos().y) / fDistance);
                    target.setPos({tpx, tpy});
                }
            }
        }

        Ball.Update();
    }

    // dynamic collisions

    for (auto c : collidingPairs)
    {
        Ball *b1 = c.first;
        Ball *b2 = c.second;

        // Distance between balls
        float fDistance = sqrtf((b1->getpx() - b2->getpx()) * (b1->getpx() - b2->getpx()) + (b1->getpy() - b2->getpy()) * (b1->getpy() - b2->getpy()));

        // Normal
        float nx = (b2->getpx() - b1->getpx()) / fDistance;
        float ny = (b2->getpy() - b1->getpy()) / fDistance;

        // Tangent
        float tx = -ny;
        float ty = nx;

        // Dot Product Tangent
        float dpTan1 = b1->getvx() * tx + b1->getvy() * ty;
        float dpTan2 = b2->getvx() * tx + b2->getvy() * ty;

        // Dot Product Normal
        float dpNorm1 = b1->getvx() * nx + b1->getvy() * ny;
        float dpNorm2 = b2->getvx() * nx + b2->getvy() * ny;

        // Conservation of momentum in 1D
        float m1 = (dpNorm1 * (b1->getMass() - b2->getMass()) + 2.0f * b2->getMass() * dpNorm2) / (b1->getMass() + b2->getMass());
        float m2 = (dpNorm2 * (b2->getMass() - b1->getMass()) + 2.0f * b1->getMass() * dpNorm1) / (b1->getMass() + b2->getMass());

        // Update ball velocities
        b1->setVx(tx * dpTan1 + nx * m1);
        b1->setVy(ty * dpTan1 + ny * m1);
        b2->setVx(tx * dpTan2 + nx * m2);
        b2->setVy(ty * dpTan2 + ny * m2);
    }
}

void Game::Draw()
{
    DrawRectangle(Boardx, Boardy, BoardWidth, BoardHeight, BLUE);
    for (auto Ball : balls) // ritar bollarna
    {
        Ball.Draw();
    }

    if (debugmode)
    {
        for (auto c : collidingPairs) // rita collision lines
        {
            DrawLine(c.first->getPos().x, c.first->getPos().y, c.second->getPos().x, c.second->getPos().y, GREEN);
        }
    }
    if (pselectedBall != nullptr)
    {
        // Draw BiljardKö
        DrawLine(pselectedBall->getPos().x, pselectedBall->getPos().y, GetMouseX(), GetMouseY(), GREEN);
    }
}

Game::~Game()
{
}
/*
float px = Ball.getPos().x - (fOverlap * (Ball.getPos().x - target.getPos().x) / fDistance);
float py = Ball.getPos().y - (fOverlap * (Ball.getPos().y - target.getPos().y) / fDistance);
Ball.setx(px);
Ball.sety(py);

// visa target boll
float tpx = target.getPos().x + (fOverlap * (Ball.getPos().x - target.getPos().x) / fDistance);
float tpy = target.getPos().y + (fOverlap * (Ball.getPos().y - target.getPos().y) / fDistance);
Ball.setx(tpx);
Ball.sety(tpy);
*/