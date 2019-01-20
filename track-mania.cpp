#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

//Init game const
    const double SCREEN_WIDTH=900;
    const double SCREEN_HEIGH=650;
    const int borderLeft=220;
    const int borderRight=550;
    const int racerWidth=40;
    const int racerHeight=70;
    string stringscore="";
    int score=0;
    int highscore1=0;
    int qq=0;
    int zz=0;

//Create Main Windows
RenderWindow app(VideoMode(SCREEN_WIDTH, SCREEN_HEIGH), "Car Racing");


//app.getPosition(100,10);

int gameOver();
int getRandomNumber(int a, int b);
int manu();
int game();
int highscore();
int selectcar();
int level_2();
int level();
int level_3();

int main()
{

    app.setPosition(Vector2i(200, 10));
    manu();
}

int manu()
{

    freopen("cars/data", "r", stdin);
    cin>>highscore1;
    fclose(stdin);

    Texture manu1;
    if (!manu1.loadFromFile("cars/manu.png")) return EXIT_FAILURE;
    Sprite Manu(manu1);
    Manu.setPosition(0,0);

    Texture tr;
    if (!tr.loadFromFile("cars/trm.png")) return EXIT_FAILURE;
    Sprite Trm(tr);
    Trm.setPosition(250,0);



    SoundBuffer sm;
        sm.loadFromFile("sound/manu2.wav");
    Sound Sm;
        Sm.setBuffer(sm);
        Sm.setVolume(30);
        Sm.play();
        Sm.setLoop(true);



        SoundBuffer click1;
        click1.loadFromFile("sound/click.wav");
        Sound Click;
        Click.setBuffer(click1);
        Click.setVolume(40);
       // Click.play();


    int cursor=50;
    int y=0;
    while(app.isOpen())
    {

//        Arrow.setPosition(40,cursor);
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Return)
                {
                        if(cursor==50)
                        {
                            Sm.stop();
                            game();
                        }
                        if(cursor==100)
                        {
                            Sm.stop();
                            selectcar();
                        }
                        if(cursor==150)
                        {
                            Sm.stop();
                            level();
                        }
                        if(cursor==250)
                        {
                            Sm.stop();
                            highscore();
                        }
                        if(cursor==300)
                        {
                            app.close();
                        }
                }
                if (event.key.code == sf::Keyboard::Up)
                    {
                        Click.play();
                        cursor-=50;
                        if(cursor<50) cursor=300;
                    }
                if (event.key.code == sf::Keyboard::Down)
                    {
                        Click.play();
                        cursor+=50;
                        if(cursor>300) cursor=50;
                    }
            }
        }

        Font myfont;
        myfont.loadFromFile("font/xirod.ttf");
//      stringscore="YOUR SCORE:"+to_string(score);
        Text t("SELECT CAR", myfont, 30);
        Text t1   ("PLAY", myfont,30);
        Text t2   ("INSTRUCTIONS", myfont,30);
        Text t3   ("HIGHSCORE", myfont,30);
        Text t4   ("EXIT", myfont,30);
        Text t5    ("DEVELOPED BY JAHID & IMRUL",myfont,30);
        Text t6    ("LEVEL", myfont,30);


        t1.setPosition(80,50);
        t.setPosition(20,100);
        t6.setPosition(75,150);
        t2.setPosition(15,200);
        t3.setPosition(40,250);
        t4.setPosition(85,300);
        t5.setPosition(200,620);


        t.setFillColor(Color::Red);
        t1.setFillColor(Color::Red);
        t2.setFillColor(Color::Red);
        t3.setFillColor(Color::Red);
        t4.setFillColor(Color::Red);
        t5.setFillColor(Color::Green);
        t6.setFillColor(Color::Red);



        if(cursor==50)
        {
            t1.setFillColor(Color::Blue);

        }
        if(cursor==100)
        {
            t.setFillColor(Color::Blue);

        }
        if(cursor==150)
        {
            t6.setFillColor(Color::Blue);

        }
        if(cursor==200)
        {
            t2.setFillColor(Color::Blue);

        }
        if(cursor==250)
        {
            t3.setFillColor(Color::Blue);

        }
        if(cursor==300)
        {
            t4.setFillColor(Color::Blue);

        }


        app.clear();
        app.draw(Manu);
//        app.draw(Arrow);
        app.draw(t);
        app.draw(t1);
        app.draw(t6);
        app.draw(t2);
        app.draw(t3);
        app.draw(t4);
        app.draw(t5);
        app.draw(Trm);
        app.display();
    }
}
int gameOver()
{
    freopen("cars/data", "w", stdout);
    if(highscore1<=score) cout<<score<<endl;
    else cout<<highscore1<<endl;
    fclose(stdout);

    Texture gameover,troll,yscore;
        if (!gameover.loadFromFile("cars/road.png")) return EXIT_FAILURE;
        if(!troll.loadFromFile("cars/gameover.png")) return EXIT_FAILURE;
        if(!yscore.loadFromFile("cars/yscore.png")) return EXIT_FAILURE;

    Sprite Gameover(gameover), Yscore(yscore);
    Sprite Troll(troll);
    Troll.setPosition(250,50);
    Yscore.setPosition(280,400);

    SoundBuffer gameOver;
        gameOver.loadFromFile("sound/crash.wav");
    Sound GameOver;
        GameOver.setBuffer(gameOver);
        GameOver.play();
    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");
    while (app.isOpen())
    {
        char overScore[25];
        sprintf(overScore, "%d", score);
        Text text(overScore, myfont, 40);
        text.setPosition(530,398);
        text.setColor(Color::Red);

        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
        }

        app.clear();
        app.draw(Gameover);
        app.draw(text);
        app.draw(Troll);
        app.draw(Yscore);
        app.display();

    }

}

int getRandomNumber(int a, int b)
    {
        static bool first = true; if (first){srand( time(NULL) );first = false;}
        int result=a + rand() % (( b + 1 ) - a);
        result=(result/10)*10;
        return result;
    }


int highscore()
{
    Texture high1;
    if (!high1.loadFromFile("cars/high.png")) return EXIT_FAILURE;
    Sprite High(high1);
    //High.setPosition(0,0);
    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");



    while(app.isOpen())
    {
//        Arrow.setPosition(40,cursor);
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if (event.key.code == sf::Keyboard::Escape)
            {
                manu();
            }
        }

    char printHigh[20];
    sprintf(printHigh, "Highscore : %d", highscore1);
    Text textHigh(printHigh, myfont, 40);
    textHigh.setPosition(280, 200);
    textHigh.setColor(Color::Black);

    Text backText("BACK", myfont, 40);
    backText.setPosition(750, 550);
    backText.setColor(Color::Black);
    //app.clear();

    //app.display();
    app.draw(High);
    app.draw(textHigh);
    app.draw(backText);
    app.display();
    }
}

int cc=1;
int selectcar()
{
    Texture m1,m2,m3;
    if (!m1.loadFromFile("car/moto1.png")) return EXIT_FAILURE;
    if (!m2.loadFromFile("car/moto2.png")) return EXIT_FAILURE;
    //if (!m3.loadFromFile("car/moto3.png")) return EXIT_FAILURE;

    Sprite M1(m1),M2(m2);

    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");

    while(app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.key.code == sf::Keyboard::Right)
            {
                cc=2;
                if(cc>2) cc=1;
                cout<<" "<<cc<<endl;
            }
            if (event.key.code == sf::Keyboard::Left)
            {
                cc=1;
                if(cc<1) cc=2;

            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                manu();
            }

        }

        Text mo("SELECT YOUR CAR", myfont, 40);
        mo.setPosition(250, 150);
        mo.setColor(Color::Blue);




        app.clear();
        if(cc==1)
        {
            M1.setPosition(370,250);
            app.draw(M1);
        }
        if(cc==2)
        {
            M2.setPosition(370,250);
            app.draw(M2);
        }
        //app.draw(M2);
        //app.draw(M3);
        app.draw(mo);
        app.display();
    }
}
    int cr=200;

int level()
{
    Texture level2;
        if (!level2.loadFromFile("car/level1.png")) return EXIT_FAILURE;

    Sprite Level(level2);

    SoundBuffer click1;
        click1.loadFromFile("sound/click.wav");
        Sound Click;
        Click.setBuffer(click1);
        Click.setVolume(40);

        Font myfont;
        myfont.loadFromFile("font/xirod.ttf");

        Text m1("LEVEL-1",myfont,40);
        Text m2("LEVEL-2",myfont,40);
        Text m3("LEVEL-3",myfont,40);

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                    {
                        Click.play();
                        cr+=50;
                        if(cr>300) cr=200;
                    }
                if (event.key.code == sf::Keyboard::Up)
                    {
                        Click.play();
                        cr-=50;
                        if(cr<200) cr=300;
                    }
                if (event.key.code == sf::Keyboard::Return)
                {
                    //Click.play();
                        if(cr==200)
                        {
                            game();
                        }
                        if(cr==250)
                        {
                            level_2();
                        }
                        if(cr==300)
                        {
                            level_3();
                        }
                }
                if (event.key.code == sf::Keyboard::Escape)
                {
                    manu();
                }
            }

        }

        m1.setPosition(300,200);
        m2.setPosition(300,250);
        m3.setPosition(300,300);

        m1.setColor(Color::Red);
        m2.setColor(Color::Red);
        m3.setColor(Color::Red);




        if(cr==200)
        {
            m1.setColor(Color::Blue);
        }
        if(cr==250)
        {
            m2.setColor(Color::Blue);
        }
        if(cr==300)
        {
            m3.setColor(Color::Blue);
        }

        app.clear();

        app.draw(Level);
        app.draw(m1);
        app.draw(m2);
        app.draw(m3);
        app.display();

    }

}

int game()
{

    double gameSpeed=0.1;
    SoundBuffer gameSoundBuffer;
        gameSoundBuffer.loadFromFile("sound/game1.ogg");
    Sound GameSound;
        GameSound.setBuffer(gameSoundBuffer);
        GameSound.setVolume(5);

    SoundBuffer gameSoundBuffer1;
        gameSoundBuffer1.loadFromFile("sound/coin.wav");
    Sound GameSound1;
        GameSound1.setBuffer(gameSoundBuffer1);
        GameSound1.setVolume(50);

    Texture background, racer, obs1, obs2, obs3, obs4,gameover,bonus1;
    //Init font
    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");

    //Load all images
    if (!background.loadFromFile("cars/road1.png")) return EXIT_FAILURE;
    //if (!racer.loadFromFile("cars/rsz_image4.png")) return EXIT_FAILURE;
    if(cc==1)
    {
        if (!racer.loadFromFile("car/moto1.png")) return EXIT_FAILURE;
    }
    else if(cc==2)
    {
        if (!racer.loadFromFile("car/moto2.png")) return EXIT_FAILURE;
    }
    if (!obs1.loadFromFile("cars/rsz_car2.png")) return EXIT_FAILURE;
    if (!obs2.loadFromFile("cars/rsz_car5.png")) return EXIT_FAILURE;
    if (!obs3.loadFromFile("cars/rsz_car6.png")) return EXIT_FAILURE;
    if (!obs4.loadFromFile("cars/rsz_car7.png")) return EXIT_FAILURE;
    if (!bonus1.loadFromFile("cars/bonus.png")) return EXIT_FAILURE;

    //Create sprite
    Sprite Background(background),Background1(background),Racer(racer),Obs1(obs1),Obs2(obs2),Obs3(obs3),Obs4(obs4),Gameover(gameover),Bonus(bonus1);

//    Bonus.setScale()
    double RacerX, RacerY,Obs1X, Obs1Y,Obs2X, Obs2Y,Obs3X, Obs3Y,Obs4X, Obs4Y,Bsx,Bsy;

    //Set racer and Obs pos
	RacerX=SCREEN_WIDTH/2;
	RacerY=SCREEN_HEIGH-racerHeight;
	Obs1X=getRandomNumber(borderLeft,borderRight);
	Obs2X=getRandomNumber(borderLeft,borderRight);
	Obs3X=getRandomNumber(borderLeft,borderRight);
	Obs4X=getRandomNumber(borderLeft,borderRight);
	Bsx=getRandomNumber(borderLeft,borderRight);
	//Bsy=getRandomNumber(borderLeft,borderRight);
    Obs1Y=0,Obs2Y=-100,Obs3Y=-200,Obs4Y=-300,Bsy=-400;
    double BackgroundY1=0;
    double BackgroundY2=-600;

    GameSound.play();
    GameSound.setLoop(true);




/*    Text gametxt;
    gametxt.setFont(style);
    gametxt.setString("Battle For Avenger!");
    gametxt.setCharacterSize(80);
    gametxt.setScale(1.f,1.f);
    gametxt.setFillColor(Color::Red);

*/



    bool qw=true;
    //GAME LOOP
    while(app.isOpen())
    {


        //Init and count score
//        stringscore="SCORE:"+to_string(score);
        char overScore[25];
        sprintf(overScore, "Your Score: %d", score);
        Text text(overScore, myfont, 15);
        text.setPosition(5,0);

        //Set car position
        Racer.setPosition(RacerX,RacerY);
        Obs1.setPosition(Obs1X,Obs1Y);
        Obs2.setPosition(Obs2X,Obs2Y);
        Obs3.setPosition(Obs3X,Obs3Y);
        Obs4.setPosition(Obs4X,Obs4Y);
        Bonus.setPosition(Bsx,Bsy);

        //Creat scrolling background
        Background.setPosition(0,BackgroundY1);
        Background1.setPosition(0,BackgroundY2);
        if (BackgroundY2>=0)
        {
            BackgroundY1=0;
            BackgroundY2=BackgroundY1-500;
        }
        BackgroundY1+=4.1;
        BackgroundY2+=7.1;

        //Set Obs LOOP
        if (Obs1Y>SCREEN_HEIGH)
            {Obs1Y=-100;Obs1X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs1Y=Obs1Y+gameSpeed;}
        if (Obs2Y>SCREEN_HEIGH)
            {Obs2Y=-100;Obs2X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs2Y=Obs2Y+gameSpeed;}
        if (Obs3Y>SCREEN_HEIGH)
            {Obs3Y=-100;Obs3X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs3Y=Obs3Y+gameSpeed;}
        if (Obs4Y>SCREEN_HEIGH)
            {Obs4Y=-100;Obs4X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs4Y=Obs4Y+gameSpeed;}
        if (Bsy>SCREEN_HEIGH)
            {Bsy=-100;Bsx=getRandomNumber(borderLeft,borderRight); zz=0;qq=0;qw=true;} else {Bsy=Bsy+gameSpeed;}

        //cout<<qq<<endl;
        //Game level
        if(score>100)
        {
            level_2();
        }
        if(score>200)
        {
            level_3();
        }

        //Create event to handle input from keyboard
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Left)
                        {if(RacerX>borderLeft) {RacerX=RacerX-10;}}
                    if (event.key.code == sf::Keyboard::Right)
                        {if(RacerX<borderRight){RacerX=RacerX+10;}}

                }
        }

        //Check if accident happen
        if (((RacerX>=(Obs1X-50)) &&(RacerX<=(Obs1X+50)))&&((RacerY>=(Obs1Y-80)) &&(RacerY)<=(Obs1Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs2X-50)) &&(RacerX<=(Obs2X+50)))&&((RacerY>=(Obs2Y-80)) &&(RacerY)<=(Obs2Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs3X-50)) &&(RacerX<=(Obs3X+50)))&&((RacerY>=(Obs3Y-80)) &&(RacerY)<=(Obs3Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs4X-50)) &&(RacerX<=(Obs4X+50)))&&((RacerY>=(Obs4Y-80)) &&(RacerY)<=(Obs4Y+80)))
            {
                GameSound.stop();gameOver();
            };
            //cout<<qq<<endl;
        if (((RacerX>=(Bsx-40)) &&(RacerX<=(Bsx+40)))&&((RacerY>=(Bsy-40)) &&(RacerY)<=(Bsy+40)))
            {
                //qw=false;
                if(qw==true)
                {

                GameSound1.play();
                qw=false;

                }
                //qw=true;

                if(zz==0)
                {
                score+=10;
                }
                zz=1;
                qq=1;

            };

        //Clear and redraw position
        app.clear();
        app.draw(Background);
        app.draw(Background1);
        app.draw(Racer);
        app.draw(Obs1);
        app.draw(Obs2);
        app.draw(Obs3);
        app.draw(Obs4);
        app.draw(text);
        //app.draw(Bonus);
        if(qq==0)
        {
            app.draw(Bonus);
        }

        //app.draw(Bonus);
//        app.draw(gametxt);
        app.display();
    }
    return EXIT_SUCCESS;
}

int level_2()
{

    double gameSpeed=0.2;
    SoundBuffer gameSoundBuffer;
        gameSoundBuffer.loadFromFile("sound/game1.ogg");
    Sound GameSound;
        GameSound.setBuffer(gameSoundBuffer);

        SoundBuffer gameSoundBuffer1;
        gameSoundBuffer1.loadFromFile("sound/coin.wav");
    Sound GameSound1;
        GameSound1.setBuffer(gameSoundBuffer1);
        GameSound1.setVolume(20);

    Texture background, racer, obs1, obs2, obs3, obs4,gameover,bonus1;
    //Init font
    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");

    //Load all images
    if (!background.loadFromFile("cars/road1.png")) return EXIT_FAILURE;
    //if (!racer.loadFromFile("cars/rsz_image4.png")) return EXIT_FAILURE;
    if(cc==1)
    {
        if (!racer.loadFromFile("car/moto1.png")) return EXIT_FAILURE;
    }
    else if(cc==2)
    {
        if (!racer.loadFromFile("car/moto2.png")) return EXIT_FAILURE;
    }
    if (!obs1.loadFromFile("cars/rsz_car2.png")) return EXIT_FAILURE;
    if (!obs2.loadFromFile("cars/rsz_car5.png")) return EXIT_FAILURE;
    if (!obs3.loadFromFile("cars/rsz_car6.png")) return EXIT_FAILURE;
    if (!obs4.loadFromFile("cars/rsz_car7.png")) return EXIT_FAILURE;
    if (!bonus1.loadFromFile("cars/bonus.png")) return EXIT_FAILURE;

    //Create sprite
    Sprite Background(background),Background1(background),Racer(racer),Obs1(obs1),Obs2(obs2),Obs3(obs3),Obs4(obs4),Gameover(gameover),Bonus(bonus1);

    double RacerX, RacerY,Obs1X, Obs1Y,Obs2X, Obs2Y,Obs3X, Obs3Y,Obs4X, Obs4Y,Bsx,Bsy;

    //Set racer and Obs pos
	RacerX=SCREEN_WIDTH/2;
	RacerY=SCREEN_HEIGH-racerHeight;
	Obs1X=getRandomNumber(borderLeft,borderRight);
	Obs2X=getRandomNumber(borderLeft,borderRight);
	Obs3X=getRandomNumber(borderLeft,borderRight);
	Obs4X=getRandomNumber(borderLeft,borderRight);
	Bsx=getRandomNumber(borderLeft,borderRight);
	//Bsy=getRandomNumber(borderLeft,borderRight);
    Obs1Y=0,Obs2Y=-100,Obs3Y=-200,Obs4Y=-300,Bsy=-400;
    double BackgroundY1=0;
    double BackgroundY2=-600;

    GameSound.play();
    GameSound.setLoop(true);




/*    Text gametxt;
    gametxt.setFont(style);
    gametxt.setString("Battle For Avenger!");
    gametxt.setCharacterSize(80);
    gametxt.setScale(1.f,1.f);
    gametxt.setFillColor(Color::Red);

*/



    bool qw=true;
    //GAME LOOP
    while(app.isOpen())
    {


        //Init and count score
//        stringscore="SCORE:"+to_string(score);
        char overScore[25];
        sprintf(overScore, "Your Score: %d", score);
        Text text(overScore, myfont, 15);
        text.setPosition(5,0);

        //Set car position
        Racer.setPosition(RacerX,RacerY);
        Obs1.setPosition(Obs1X,Obs1Y);
        Obs2.setPosition(Obs2X,Obs2Y);
        Obs3.setPosition(Obs3X,Obs3Y);
        Obs4.setPosition(Obs4X,Obs4Y);
        Bonus.setPosition(Bsx,Bsy);

        //Creat scrolling background
        Background.setPosition(0,BackgroundY1);
        Background1.setPosition(0,BackgroundY2);
        if (BackgroundY2>=0)
        {
            BackgroundY1=0;
            BackgroundY2=BackgroundY1-500;
        }
        BackgroundY1+=4.1;
        BackgroundY2+=7.1;

        //Set Obs LOOP
        if (Obs1Y>SCREEN_HEIGH)
            {Obs1Y=-100;Obs1X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs1Y=Obs1Y+gameSpeed;}
        if (Obs2Y>SCREEN_HEIGH)
            {Obs2Y=-100;Obs2X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs2Y=Obs2Y+gameSpeed;}
        if (Obs3Y>SCREEN_HEIGH)
            {Obs3Y=-100;Obs3X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs3Y=Obs3Y+gameSpeed;}
        if (Obs4Y>SCREEN_HEIGH)
            {Obs4Y=-100;Obs4X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs4Y=Obs4Y+gameSpeed;}
        if (Bsy>SCREEN_HEIGH)
            {Bsy=-100;Bsx=getRandomNumber(borderLeft,borderRight); zz=0;qq=0;qw=true;} else {Bsy=Bsy+gameSpeed;}


        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Left)
                        {if(RacerX>borderLeft) {RacerX=RacerX-20;}}
                    if (event.key.code == sf::Keyboard::Right)
                        {if(RacerX<borderRight){RacerX=RacerX+20;}}
                    if (event.key.code == sf::Keyboard::Up)
                        {if(RacerY>0){RacerY=RacerY-20;}}
                    if (event.key.code == sf::Keyboard::Down)
                        {if(RacerY<SCREEN_HEIGH-70){RacerY=RacerY+20;}}
                }
        }

        //Check if accident happen
        if (((RacerX>=(Obs1X-50)) &&(RacerX<=(Obs1X+50)))&&((RacerY>=(Obs1Y-80)) &&(RacerY)<=(Obs1Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs2X-50)) &&(RacerX<=(Obs2X+50)))&&((RacerY>=(Obs2Y-80)) &&(RacerY)<=(Obs2Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs3X-50)) &&(RacerX<=(Obs3X+50)))&&((RacerY>=(Obs3Y-80)) &&(RacerY)<=(Obs3Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs4X-50)) &&(RacerX<=(Obs4X+50)))&&((RacerY>=(Obs4Y-80)) &&(RacerY)<=(Obs4Y+80)))
            {
                GameSound.stop();gameOver();
            };
            //cout<<qq<<endl;
        if (((RacerX>=(Bsx-50)) &&(RacerX<=(Bsx+50)))&&((RacerY>=(Bsy-80)) &&(RacerY)<=(Bsy+80)))
            {
                if(qw==true)
                {

                GameSound1.play();
                qw=false;
                }

                if(zz==0)
                {
                score+=10;
                }
                zz=1;
                qq=1;

            };

        //Clear and redraw position
        app.clear();
        app.draw(Background);
        app.draw(Background1);
        app.draw(Racer);
        app.draw(Obs1);
        app.draw(Obs2);
        app.draw(Obs3);
        app.draw(Obs4);
        app.draw(text);
        //app.draw(Bonus);
        if(qq==0)
        {
            app.draw(Bonus);
        }

        //app.draw(Bonus);
//        app.draw(gametxt);
        app.display();
    }
    return EXIT_SUCCESS;

}

int level_3()
{
    double gameSpeed=0.3;
    SoundBuffer gameSoundBuffer;
        gameSoundBuffer.loadFromFile("sound/game1.ogg");
    Sound GameSound;
        GameSound.setBuffer(gameSoundBuffer);

    SoundBuffer gameSoundBuffer1;
        gameSoundBuffer1.loadFromFile("sound/coin.wav");
    Sound GameSound1;
        GameSound1.setBuffer(gameSoundBuffer1);
        GameSound1.setVolume(20);

    Texture background, racer, obs1, obs2, obs3, obs4,gameover,bonus1;
    //Init font
    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");

    //Load all images
    if (!background.loadFromFile("cars/road1.png")) return EXIT_FAILURE;
    //if (!racer.loadFromFile("cars/rsz_image4.png")) return EXIT_FAILURE;
    if(cc==1)
    {
        if (!racer.loadFromFile("car/moto1.png")) return EXIT_FAILURE;
    }
    else if(cc==2)
    {
        if (!racer.loadFromFile("car/moto2.png")) return EXIT_FAILURE;
    }
    if (!obs1.loadFromFile("cars/rsz_car2.png")) return EXIT_FAILURE;
    if (!obs2.loadFromFile("cars/rsz_car5.png")) return EXIT_FAILURE;
    if (!obs3.loadFromFile("cars/rsz_car6.png")) return EXIT_FAILURE;
    if (!obs4.loadFromFile("cars/rsz_car7.png")) return EXIT_FAILURE;
    if (!bonus1.loadFromFile("cars/bonus.png")) return EXIT_FAILURE;

    //Create sprite
    Sprite Background(background),Background1(background),Racer(racer),Obs1(obs1),Obs2(obs2),Obs3(obs3),Obs4(obs4),Gameover(gameover),Bonus(bonus1);

    double RacerX, RacerY,Obs1X, Obs1Y,Obs2X, Obs2Y,Obs3X, Obs3Y,Obs4X, Obs4Y,Bsx,Bsy;

    //Set racer and Obs pos
	RacerX=SCREEN_WIDTH/2;
	RacerY=SCREEN_HEIGH-racerHeight;
	Obs1X=getRandomNumber(borderLeft,borderRight);
	Obs2X=getRandomNumber(borderLeft,borderRight);
	Obs3X=getRandomNumber(borderLeft,borderRight);
	Obs4X=getRandomNumber(borderLeft,borderRight);
	Bsx=getRandomNumber(borderLeft,borderRight);
	//Bsy=getRandomNumber(borderLeft,borderRight);
    Obs1Y=0,Obs2Y=-100,Obs3Y=-200,Obs4Y=-300,Bsy=-400;
    double BackgroundY1=0;
    double BackgroundY2=-600;

    GameSound.play();
    GameSound.setLoop(true);



     bool qw=true;
    //GAME LOOP
    while(app.isOpen())
    {


        //Init and count score
//        stringscore="SCORE:"+to_string(score);
        char overScore[25];
        sprintf(overScore, "Your Score: %d", score);
        Text text(overScore, myfont, 15);
        text.setPosition(5,0);

        //Set car position
        Racer.setPosition(RacerX,RacerY);
        Obs1.setPosition(Obs1X,Obs1Y);
        Obs2.setPosition(Obs2X,Obs2Y);
        Obs3.setPosition(Obs3X,Obs3Y);
        Obs4.setPosition(Obs4X,Obs4Y);
        Bonus.setPosition(Bsx,Bsy);

        //Creat scrolling background
        Background.setPosition(0,BackgroundY1);
        Background1.setPosition(0,BackgroundY2);
        if (BackgroundY2>=0)
        {
            BackgroundY1=0;
            BackgroundY2=BackgroundY1-500;
        }
        BackgroundY1+=4.1;
        BackgroundY2+=7.1;

        //Set Obs LOOP
        if (Obs1Y>SCREEN_HEIGH)
            {Obs1Y=-100;Obs1X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs1Y=Obs1Y+gameSpeed;}
        if (Obs2Y>SCREEN_HEIGH)
            {Obs2Y=-100;Obs2X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs2Y=Obs2Y+gameSpeed;}
        if (Obs3Y>SCREEN_HEIGH)
            {Obs3Y=-100;Obs3X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs3Y=Obs3Y+gameSpeed;}
        if (Obs4Y>SCREEN_HEIGH)
            {Obs4Y=-100;Obs4X=getRandomNumber(borderLeft,borderRight);score++;} else {Obs4Y=Obs4Y+gameSpeed;}
        if (Bsy>SCREEN_HEIGH)
            {Bsy=-100;Bsx=getRandomNumber(borderLeft,borderRight); zz=0;qq=0;qw=true;} else {Bsy=Bsy+gameSpeed;}


        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Left)
                        {if(RacerX>borderLeft) {RacerX=RacerX-20;}}
                    if (event.key.code == sf::Keyboard::Right)
                        {if(RacerX<borderRight){RacerX=RacerX+20;}}
                    if (event.key.code == sf::Keyboard::Up)
                        {if(RacerY>0){RacerY=RacerY-20;}}
                    if (event.key.code == sf::Keyboard::Down)
                        {if(RacerY<SCREEN_HEIGH-70){RacerY=RacerY+20;}}
                }
        }


        //Check if accident happen
        if (((RacerX>=(Obs1X-50)) &&(RacerX<=(Obs1X+50)))&&((RacerY>=(Obs1Y-80)) &&(RacerY)<=(Obs1Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs2X-50)) &&(RacerX<=(Obs2X+50)))&&((RacerY>=(Obs2Y-80)) &&(RacerY)<=(Obs2Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs3X-50)) &&(RacerX<=(Obs3X+50)))&&((RacerY>=(Obs3Y-80)) &&(RacerY)<=(Obs3Y+80)))
            {
                GameSound.stop();gameOver();
            };
        if (((RacerX>=(Obs4X-50)) &&(RacerX<=(Obs4X+50)))&&((RacerY>=(Obs4Y-80)) &&(RacerY)<=(Obs4Y+80)))
            {
                GameSound.stop();gameOver();
            };
            //cout<<qq<<endl;
        if (((RacerX>=(Bsx-50)) &&(RacerX<=(Bsx+50)))&&((RacerY>=(Bsy-80)) &&(RacerY)<=(Bsy+80) ))
            {
                if(qw==true)
                {
                GameSound1.play();
                qw=false;
                }

                if(zz==0)
                {
                score+=10;
                }
                zz=1;
                qq=1;

            };


        //Clear and redraw position
        app.clear();
        app.draw(Background);
        app.draw(Background1);
        app.draw(Racer);
        app.draw(Obs1);
        app.draw(Obs2);
        app.draw(Obs3);
        app.draw(Obs4);
        app.draw(text);
        //app.draw(Bonus);
        if(qq==0)
        {
            app.draw(Bonus);
        }

        //app.draw(Bonus);
//        app.draw(gametxt);
        app.display();
    }
    return EXIT_SUCCESS;
}


