#include "HeaderFiles/Player.h"

Player::Player(bool playerOne)
{   
    debugmode = false; // draws debug lines etcetra
    setupDone = false;
    this->playerOne = playerOne;
    this->WindowWidth = 1280;
    this->WindowHeight = 800;
    levels.push_back(Levels(WindowWidth, WindowHeight));
    defaultRadius = 11.43f;
    friction = 0.8f;
    CueMultiplier = 5.f;
    mass = 10 * defaultRadius;
    levels[0].setupLevels();
    level = 0;
    SetupLevel(level);
    GolfBall = levels[0].GetLevel(level)->getBall();

    SwingsThisRound = 0;
    totalSwings = 0;
}

void Player::Update()
{
    totalSwings = 0;
    for (auto swing : allSwings)
    {
        totalSwings += swing;
    }

    // check current level
    if (!currentLevel.holePointer->getHasBall())
    {

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && canSwing) // if button pressed
        {
            pselectedBall = nullptr; // unselect previous selects

            if (CheckCollisionCircles(GetMousePosition(), 1, GolfBall->getPos(), static_cast<float>(GolfBall->getRadius())))
            {
                pselectedBall = GolfBall;
            }
        }

        // har bolen rörelse?
        if (GolfBall->getvx() > 0 || GolfBall->getvy() > 0)
        {
            canSwing = false;
        }
        else if (GolfBall->getvx() == 0 && GolfBall->getvy() == 0)
        {
            canSwing = true;
        }

        if (IsKeyPressed(KEY_SPACE) && canSwing) // if button released
        {
            if (pselectedBall != nullptr) // vi lägger till velocity
            {
                float vx, vy;
                vx = CueMultiplier * ((pselectedBall->getPos().x) - GetMousePosition().x);
                vy = CueMultiplier * ((pselectedBall->getPos().y) - GetMousePosition().y);
                pselectedBall->setVelocity({vx, vy});
            }
            pselectedBall = nullptr;
            SwingsThisRound += 1;
            // turen går över
        }
        // bollar får nu fysiiik

        GolfBall->setax(-GolfBall->getvx() * friction); // acceleration = hastighet * friction
        GolfBall->setay(-GolfBall->getvy() * friction);
        float vx, vy;
        vx = GolfBall->getVelocity().x + (GolfBall->getAcceleration().x * GetFrameTime()); // v = v0 + at
        vy = GolfBall->getVelocity().y + (GolfBall->getAcceleration().y * GetFrameTime());
        GolfBall->setVelocity({vx, vy});

        GolfBall->setPy(GolfBall->getPos().y + (GolfBall->getVelocity().y * GetFrameTime())); // s = s0 + vt
        GolfBall->setPx(GolfBall->getPos().x + (GolfBall->getVelocity().x * GetFrameTime()));

        levels[0].GetLevel(level)->CheckCollision(); //check collision in level class

        if (fabs(GolfBall->getvx() * GolfBall->getvx() + GolfBall->getvy() * GolfBall->getvy()) < 1.5f) // om farten är väldigt liten så ska den bli noll bara
        {
            GolfBall->setVx(0);
            GolfBall->setVy(0);
        }

        Vector2 centerBall = {GolfBall->getPos().x, GolfBall->getPos().y};
        Vector2 centerHole = {currentLevel.holePointer->getx(), currentLevel.holePointer->gety()};

        if (CheckCollisionCircles(centerBall, defaultRadius / 0.75f, centerHole, currentLevel.holePointer->getRadius() / 1.2) && abs(GolfBall->getvx()) < 800 && abs(GolfBall->getvy() < 800))
        {
            currentLevel.holePointer->setHasBall(true);
            // add score to vector
            allSwings.push_back(SwingsThisRound);
            // set swings to zero
            SwingsThisRound = 0;
        }
        GolfBall->Update();
    }
    else
    {
        setupDone = false;
        if (level < maxLevel)
        {
            int newlevel = level + 1;
            SetupLevel(newlevel);
        }
        else
        {
            // du är färdig
        }
    }
}

void Player::SetupLevel(int _level)
{
    this->level = _level;
    pselectedBall = nullptr;
    currentLevel.holePointer = nullptr;
    GolfBall = nullptr;
    golfHoleSetToPntr = false;
    currentLevel.holePointer = levels[0].GetHolePointer(_level);
    GolfBall = levels[0].GetLevel(_level)->getBall();

    SwingsThisRound = 0;
    currentLevel.px = levels[0].GetLevel(_level)->getpx();
    currentLevel.py = levels[0].GetLevel(_level)->getpy();
    currentLevel.holex = levels[0].GetLevel(_level)->getHolex();
    currentLevel.holey = levels[0].GetLevel(_level)->getHoley();
    currentLevel.holeRadius = levels[0].GetLevel(_level)->getHoleRadius();
    currentLevel.holePointer->setHasBall(false);
    setupDone = true;
}

void Player::Draw()
{
    if (setupDone)
    {
        if (!golfHoleSetToPntr) // setpointer to ball and hole
        {
            currentLevel.holePointer = levels[0].GetHolePointer(level);
            GolfBall = levels[0].GetLevel(level)->getBall();
            golfHoleSetToPntr = true;
        }
        levels[0].GetLevel(level)->Draw(); //draw level
        GolfBall->Draw();
        if (pselectedBall != nullptr)
        {
            // Draw BiljardKö
            DrawLine(pselectedBall->getPos().x, pselectedBall->getPos().y, GetMouseX(), GetMouseY(), GREEN);
            // Draw aim
            DrawAim();
        }
    }
}

void Player::DrawAim()
{

    // Draw aim
    float px = pselectedBall->getPos().x + (pselectedBall->getPos().x - GetMousePosition().x);
    float py = pselectedBall->getPos().y + (pselectedBall->getPos().y - GetMousePosition().y);
    float xfromBall = pselectedBall->getPos().x - GetMousePosition().x;
    float yfromBall = pselectedBall->getPos().y - GetMousePosition().y;
    float Angle = Vector2Angle({xfromBall, 0.f}, {xfromBall, yfromBall});
    px = pselectedBall->getPos().x + (cos(Angle) * 30);
    py = pselectedBall->getPos().y + (sin(Angle) * 30);
    if ((pselectedBall->getPos().x - GetMousePosition().x) < 0)
    {
        Angle = Vector2Angle({-xfromBall, 0.f}, {xfromBall, yfromBall});
        px = pselectedBall->getPos().x + (cos(Angle) * 30);
        py = pselectedBall->getPos().y + (sin(Angle) * 30);
    }
    DrawLine(pselectedBall->getPos().x, pselectedBall->getPos().y, px, py, WHITE);
}

Player::~Player()
{
}
