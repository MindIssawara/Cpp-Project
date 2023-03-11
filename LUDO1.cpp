#include "add.h"
#include <windows.h>
#include<chrono>
#include<thread>
#pragma comment(lib, "winmm.lib")
using namespace std::this_thread;
using namespace std::chrono;

void playSound(int);

int main()
{
    playSound(1);
    Texture cs, hm, st, ht, ex, htp, hb1,mu;
    Texture bg, d, fd, winR, winB, winG, winY;
    Texture g, r, y, b;
    srand(time(0));
    RenderWindow window(VideoMode(1500, 900), "LUDO!");
    window.setMouseCursorVisible(false);
    window.setKeyRepeatEnabled(false);
    mu.loadFromFile("image/onoff.png");
    htp.loadFromFile("image/HowToPage.png");
    hb1.loadFromFile("image/homebot.png");
    winR.loadFromFile("image/winR.png");
    winG.loadFromFile("image/winG.png");
    winB.loadFromFile("image/winB.png");
    winY.loadFromFile("image/winY.png");
    ht.loadFromFile("image/HowTo.png");
    ex.loadFromFile("image/exit.png");
    cs.loadFromFile("image/cursor.png");
    st.loadFromFile("image/start.png");
    hm.loadFromFile("image/home.png");
    fd.loadFromFile("image/frame_dice.png");
    d.loadFromFile("image/dice2.png");
    g.loadFromFile("image/gรวม.png");
    r.loadFromFile("image/rรวม.png");
    b.loadFromFile("image/bรวม.png");
    y.loadFromFile("image/yรวม.png");
    bg.loadFromFile("image/background.png");
    Sprite background(bg), dice(d), frame(fd), home(hm), start(st), cursor(cs), howto(ht), exit(ex), howtoP(htp), homebut1(hb1),mute(mu);
    Sprite winnerR(winR), winnerB(winB), winnerG(winG), winnerY(winY);
    Sprite r1(r), r2(r), r3(r), r4(r), b1(b), b2(b), b3(b), b4(b), g1(g), g2(g), g3(g), g4(g), y1(y), y2(y), y3(y), y4(y);
    bool wait = 0,muteornot=0,mutepressed=0;

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (Mouse::isButtonPressed(Mouse::Button::Left) && page == 1) {
                if (pos.x >= 1121 && pos.x <= 1371 && pos.y >= 660 && pos.y <= 760) {
                    cout << "click";
                    window.close();
                }
            }
        }

        if (Mouse::isButtonPressed(Mouse::Button::Left) && page == 1) {
            if (pos.x >= 1121 && pos.x <= 1371 && pos.y >= 354 && pos.y <= 454) {
                cout << "click";
                timeToRoll = 1;
                page = 0;
            }
            if (pos.x >= 1071 && pos.x <= 1421 && pos.y >= 506 && pos.y <= 606) {
                cout << "click";
                page = 2;
            }
        }

        if (Mouse::isButtonPressed(Mouse::Button::Left) && page == 2) {
            if (pos.x >= 1200 && pos.x <= 1425 && pos.y >= 725 && pos.y <= 875) {
                cout << "click";
                page = 1;
            }
        }

        if (Mouse::isButtonPressed(Mouse::Button::Left) && page == 0) {
            if (pos.x >= 1353 && pos.x <= 1433 && pos.y >= 100 && pos.y <= 180) {
                cout << "click";
                sleep_for(nanoseconds(200000000));
                muteornot = !muteornot;
                mutepressed = 1;
            }
        }

        if (mutepressed) {
            mutepressed = 0;
            if (muteornot == 1) playSound(0);
            else playSound(1);
        }

        if (Mouse::isButtonPressed(Mouse::Button::Left) && timeToRoll) {
            if (pos.x >= 182 && pos.x <= 340 && pos.y <= 258 && pos.y >= 100 && Round == 1) {
                cout << "click";
                Roll = roll_dice();
                if (!six)Round++;
                Finished = 0;
                timeToRoll = 0;
            }
            if (pos.x >= 1160 && pos.x <= 1328 && pos.y <= 258 && pos.y >= 100 && Round == 2) {
                cout << "click";
                Roll = roll_dice();
                if (!six) Round++;
                Finished = 0;
                timeToRoll = 0;
            }
            if (pos.x >= 1160 && pos.x <= 1328 && pos.y <= 850 && pos.y >= 692 && Round == 3) {
                cout << "click";
                Roll = roll_dice();
                if (!six) Round++;
                Finished = 0;
                timeToRoll = 0;
            }
            if (pos.x >= 182 && pos.x <= 340 && pos.y <= 850 && pos.y >= 692 && (Round == 4 || Round == 0)) {
                cout << "click";
                Roll = roll_dice();
                if (!six) Round++;
                if (Round == 5) Round = 1;
                Finished = 0;
                timeToRoll = 0;
            }


        }
        window.clear(Color::White);

        if (event.key.code == Keyboard::Up) {
            Finished = 1;
            timeToRoll = 1;
        }//unused for now

        if (Roll == 6) {
            six = 1;
            if (event.key.code == Mouse::Left) {
                if (pos.x >= 375 && pos.x <= 675 && pos.y >= 100 && pos.y <= 400 || pos.x >= 375 && pos.x <= 675 && pos.y >= 550 && pos.y <= 850 || pos.x >= 825 && pos.x <= 1125 && pos.y >= 100 && pos.y <= 400 || pos.x >= 825 && pos.x <= 1125 && pos.y >= 550 && pos.y <= 850) {
                    xc = pos.x;
                    yc = pos.y;
                    getstart(xc, yc, Round);
                    int* X, * Y;
                    do {
                        X = searchx(xc, yc, Round);
                        Y = searchy(xc, yc, Round);
                        chase_back(X, Y);
                    } while (*X && *Y);
                }
                else {
                    if (event.key.code == Mouse::Left && pos.x >= 375 && pos.x <= 1125 && pos.y <= 850 && pos.y >= 100) {
                        if (pos.x >= 375 && pos.x <= 675 && pos.y >= 400 && pos.y <= 550 || pos.x >= 825 && pos.x <= 1125 && pos.y >= 400 && pos.y <= 550 || pos.x >= 675 && pos.x <= 825 && pos.y >= 100 && pos.y <= 400 || pos.x >= 675 && pos.x <= 825 && pos.y >= 550 && pos.y <= 850) {
                            xc = pos.x;
                            yc = pos.y;
                            return_position(xc, yc);
                            int* px = searchx(xc, yc, 0), * py = searchy(xc, yc, 0);
                            if (*px != 0 && *py != 0) {
                                if (px == &green[0][0] || px == &green[1][0] || px == &green[2][0] || px == &green[3][0]) {
                                    if (py == &green[0][1] || py == &green[1][1] || py == &green[2][1] || py == &green[3][1]) {
                                        if (Round == 1 && !Finished) {
                                            num[0] = move_green(*px, *py, Roll);
                                            win[0] = win[0] + num[0];
                                            pick[0] -= num[0];
                                            int* X, * Y;
                                            do {
                                                X = searchx(*px, *py, Round);
                                                Y = searchy(*px, *py, Round);
                                                chase_back(X, Y);
                                            } while (*X && *Y);
                                        }
                                    }
                                }
                                if (px == &yellow[0][0] || px == &yellow[1][0] || px == &yellow[2][0] || px == &yellow[3][0]) {
                                    if (py == &yellow[0][1] || py == &yellow[1][1] || py == &yellow[2][1] || py == &yellow[3][1]) {
                                        if (Round == 2 && !Finished) {
                                            num[1] = move_yellow(*px, *py, Roll);
                                            win[1] = win[1] + num[1];
                                            pick[1] -= num[1];
                                            int* X, * Y;
                                            do {
                                                X = searchx(*px, *py, Round);
                                                Y = searchy(*px, *py, Round);
                                                chase_back(X, Y);
                                            } while (*X && *Y);
                                        }
                                    }
                                }
                                if (px == &blue[0][0] || px == &blue[1][0] || px == &blue[2][0] || px == &blue[3][0]) {
                                    if (py == &blue[0][1] || py == &blue[1][1] || py == &blue[2][1] || py == &blue[3][1]) {
                                        if (Round == 3 && !Finished) {
                                            num[2] = move_blue(*px, *py, Roll);
                                            win[2] = win[2] + num[2];
                                            pick[2] -= num[2];
                                            int* X, * Y;
                                            do {
                                                X = searchx(*px, *py, Round);
                                                Y = searchy(*px, *py, Round);
                                                chase_back(X, Y);
                                            } while (*X && *Y);
                                        }
                                    }
                                }
                                if (px == &red[0][0] || px == &red[1][0] || px == &red[2][0] || px == &red[3][0]) {
                                    if (py == &red[0][1] || py == &red[1][1] || py == &red[2][1] || py == &red[3][1]) {
                                        if (Round == 4 && !Finished) {
                                            num[3] = move_red(*px, *py, Roll);
                                            win[3] = win[3] + num[3];
                                            pick[3] -= num[3];
                                            int* X, * Y;
                                            do {
                                                X = searchx(*px, *py, Round);
                                                Y = searchy(*px, *py, Round);
                                                chase_back(X, Y);
                                            } while (*X && *Y);
                                        }
                                    }
                                }

                            }

                        }

                    }
                }

            }
            if (Round == 1 && pick[0] == 0 || Round == 2 && pick[1] == 0 || Round == 3 && pick[2] == 0 || Round == 4 && pick[3] == 0) {
                wait = 1;
            }
        }
        else if (Roll == 1 || Roll == 2 || Roll == 3 || Roll == 4 || Roll == 5) {
            six = 0;
            if (Round == 1 && pick[0] == 0 || Round == 2 && pick[1] == 0 || Round == 3 && pick[2] == 0 || Round == 4 && pick[3] == 0 && !wait) {
                Finished = 1;
                timeToRoll = 1;
            }
            if (wait) {
                sleep_for(nanoseconds(100000000));
                wait = 0;
            }
            if (event.key.code == Mouse::Left && pos.x >= 375 && pos.x <= 1125 && pos.y <= 850 && pos.y >= 100) {
                if (pos.x >= 375 && pos.x <= 675 && pos.y >= 400 && pos.y <= 550 || pos.x >= 825 && pos.x <= 1125 && pos.y >= 400 && pos.y <= 550 || pos.x >= 675 && pos.x <= 825 && pos.y >= 100 && pos.y <= 400 || pos.x >= 675 && pos.x <= 825 && pos.y >= 550 && pos.y <= 850) {
                    xc = pos.x;
                    yc = pos.y;
                    return_position(xc, yc);
                    int* px = searchx(xc, yc, 0), * py = searchy(xc, yc, 0);
                    if (*px != 0 && *py != 0) {
                        if (px == &green[0][0] || px == &green[1][0] || px == &green[2][0] || px == &green[3][0]) {
                            if (py == &green[0][1] || py == &green[1][1] || py == &green[2][1] || py == &green[3][1]) {
                                if (Round == 1 && !Finished) {
                                    num[0] = move_green(*px, *py, Roll);
                                    win[0] = win[0] + num[0];
                                    pick[0] -= num[0];
                                    int* X, * Y;
                                    do {
                                        X = searchx(*px, *py, Round);
                                        Y = searchy(*px, *py, Round);
                                        chase_back(X, Y);
                                    } while (*X && *Y);
                                }
                            }
                        }
                        if (px == &yellow[0][0] || px == &yellow[1][0] || px == &yellow[2][0] || px == &yellow[3][0]) {
                            if (py == &yellow[0][1] || py == &yellow[1][1] || py == &yellow[2][1] || py == &yellow[3][1]) {
                                if (Round == 2 && !Finished) {
                                    num[1] = move_yellow(*px, *py, Roll);
                                    win[1] = win[1] + num[1];
                                    pick[1] -= num[1];
                                    int* X, * Y;
                                    do {
                                        X = searchx(*px, *py, Round);
                                        Y = searchy(*px, *py, Round);
                                        chase_back(X, Y);
                                    } while (*X && *Y);
                                }
                            }
                        }
                        if (px == &blue[0][0] || px == &blue[1][0] || px == &blue[2][0] || px == &blue[3][0]) {
                            if (py == &blue[0][1] || py == &blue[1][1] || py == &blue[2][1] || py == &blue[3][1]) {
                                if (Round == 3 && !Finished) {
                                    num[2] = move_blue(*px, *py, Roll);
                                    win[2] = win[2] + num[2];
                                    pick[2] -= num[2];
                                    int* X, * Y;
                                    do {
                                        X = searchx(*px, *py, Round);
                                        Y = searchy(*px, *py, Round);
                                        chase_back(X, Y);
                                    } while (*X && *Y);
                                }
                            }
                        }
                        if (px == &red[0][0] || px == &red[1][0] || px == &red[2][0] || px == &red[3][0]) {
                            if (py == &red[0][1] || py == &red[1][1] || py == &red[2][1] || py == &red[3][1]) {
                                if (Round == 4 && !Finished) {
                                    num[3] = move_red(*px, *py, Roll);
                                    win[3] = win[3] + num[3];
                                    pick[3] -= num[3];
                                    int* X, * Y;
                                    do {
                                        X = searchx(*px, *py, Round);
                                        Y = searchy(*px, *py, Round);
                                        chase_back(X, Y);
                                    } while (*X && *Y);
                                }
                            }
                        }

                    }
                }

            }
        }



        picCount = searchx(green[0][0], green[0][1], 1, 1);
        if (green[0][0] == 675 && green[0][1] == 450) g1.setTextureRect(IntRect((win[0] - 1) * 50, 0, 50, 50));
        else g1.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(green[1][0], green[1][1], 1, 1);
        if (green[1][0] == 675 && green[1][1] == 450) g2.setTextureRect(IntRect((win[0] - 1) * 50, 0, 50, 50));
        else g2.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(green[2][0], green[2][1], 1, 1);
        if (green[2][0] == 675 && green[2][1] == 450) g3.setTextureRect(IntRect((win[0] - 1) * 50, 0, 50, 50));
        else g3.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(green[3][0], green[3][1], 1, 1);
        if (green[3][0] == 675 && green[3][1] == 450) g4.setTextureRect(IntRect((win[0] - 1) * 50, 0, 50, 50));
        else g4.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(yellow[0][0], yellow[0][1], 2, 1);
        if (yellow[0][0] == 725 && yellow[0][1] == 400) y1.setTextureRect(IntRect((win[1] - 1) * 50, 0, 50, 50));
        else y1.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(yellow[1][0], yellow[1][1], 2, 1);
        if (yellow[1][0] == 725 && yellow[1][1] == 400) y2.setTextureRect(IntRect((win[1] - 1) * 50, 0, 50, 50));
        else y2.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(yellow[2][0], yellow[2][1], 2, 1);
        if (yellow[2][0] == 725 && yellow[2][1] == 400) y3.setTextureRect(IntRect((win[1] - 1) * 50, 0, 50, 50));
        else y3.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(yellow[3][0], yellow[3][1], 2, 1);
        if (yellow[3][0] == 725 && yellow[3][1] == 400) y4.setTextureRect(IntRect((win[1] - 1) * 50, 0, 50, 50));
        else y4.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(blue[0][0], blue[0][1], 3, 1);
        if (blue[0][0] == 775 && blue[0][1] == 450) b1.setTextureRect(IntRect((win[2] - 1) * 50, 0, 50, 50));
        else b1.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(blue[1][0], blue[1][1], 3, 1);
        if (blue[1][0] == 775 && blue[1][1] == 450) b2.setTextureRect(IntRect((win[2] - 1) * 50, 0, 50, 50));
        else b2.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(blue[2][0], blue[2][1], 3, 1);
        if (blue[2][0] == 775 && blue[2][1] == 450) b3.setTextureRect(IntRect((win[2] - 1) * 50, 0, 50, 50));
        else b3.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(blue[3][0], blue[3][1], 3, 1);
        if (blue[3][0] == 775 && blue[3][1] == 450) b4.setTextureRect(IntRect((win[2] - 1) * 50, 0, 50, 50));
        else b4.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(red[0][0], red[0][1], 4, 1);
        if (red[0][0] == 725 && red[0][1] == 500) r1.setTextureRect(IntRect((win[3] - 1) * 50, 0, 50, 50));
        else r1.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(red[1][0], red[1][1], 4, 1);
        if (red[1][0] == 725 && red[1][1] == 500) r2.setTextureRect(IntRect((win[3] - 1) * 50, 0, 50, 50));
        else r2.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(red[2][0], red[2][1], 4, 1);
        if (red[2][0] == 725 && red[2][1] == 500) r3.setTextureRect(IntRect((win[3] - 1) * 50, 0, 50, 50));
        else r3.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));
        picCount = searchx(red[3][0], red[3][1], 4, 1);
        if (red[3][0] == 725 && red[3][1] == 500) r4.setTextureRect(IntRect((win[3] - 1) * 50, 0, 50, 50));
        else r4.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));

        window.draw(background);
        r1.setPosition(red[0][0], red[0][1]);
        r2.setPosition(red[1][0], red[1][1]);
        r3.setPosition(red[2][0], red[2][1]);
        r4.setPosition(red[3][0], red[3][1]);
        b1.setPosition(blue[0][0], blue[0][1]);
        b2.setPosition(blue[1][0], blue[1][1]);
        b3.setPosition(blue[2][0], blue[2][1]);
        b4.setPosition(blue[3][0], blue[3][1]);
        g1.setPosition(green[0][0], green[0][1]);
        g2.setPosition(green[1][0], green[1][1]);
        g3.setPosition(green[2][0], green[2][1]);
        g4.setPosition(green[3][0], green[3][1]);
        y1.setPosition(yellow[0][0], yellow[0][1]);
        y2.setPosition(yellow[1][0], yellow[1][1]);
        y3.setPosition(yellow[2][0], yellow[2][1]);
        y4.setPosition(yellow[3][0], yellow[3][1]);
        window.draw(r1);
        window.draw(r2);
        window.draw(r3);
        window.draw(r4);
        window.draw(b1);
        window.draw(b2);
        window.draw(b3);
        window.draw(b4);
        window.draw(g1);
        window.draw(g2);
        window.draw(g3);
        window.draw(g4);
        window.draw(y1);
        window.draw(y2);
        window.draw(y3);
        window.draw(y4);
        frame.setTextureRect(IntRect(Round * 204, 0, 204, 216));
        window.draw(frame);
        mute.setPosition(1353,100);
        mute.setTextureRect(IntRect(!muteornot * 80, 0, 80, 80));
        window.draw(mute);
        dice.setTextureRect(IntRect((Roll - 1) * 158 + timeToRoll * 948, 0, 158, 158));
        if (Round == 1) {
            dice.setPosition(182, 147);
            frame.setPosition(160, 100);
        }
        if (Round == 2) {
            dice.setPosition(1160, 147);
            frame.setPosition(1138, 100);
        }
        if (Round == 3) {
            dice.setPosition(1160, 692);
            frame.setPosition(1138, 645);
        }
        if (Round == 4 || Round == 0) {
            dice.setPosition(182, 692);
            frame.setPosition(160, 645);
        }
        window.draw(dice);
        if (page == 1) {
            window.draw(home);
            start.setPosition(1121, 354);
            window.draw(start);
            howto.setPosition(1071, 506);
            window.draw(howto);
            exit.setPosition(1121, 660);
            window.draw(exit);
        }
        if (page == 2) {
            window.draw(howtoP);
            homebut1.setPosition(1200, 725);
            window.draw(homebut1);
        }
        cursor.setPosition(pos.x, pos.y);
        if (win[0] == 4) {
            window.draw(winnerG);
            page = 4;
        }
        if (win[1] == 4) {
            window.draw(winnerY);
            page = 4;
        }
        if (win[2] == 4) {
            window.draw(winnerB);
            page = 4;
        }
        if (win[3] == 4) {
            window.draw(winnerR);
            page = 4;
        }
        window.draw(cursor);
        window.display();

    }

    return 0;
}

void playSound(int x=1) {
    if(x==0) PlaySound(TEXT("audio/click.wav"), NULL, SND_FILENAME | SND_ASYNC);
    if(x==1) PlaySound(TEXT("audio/Wallpaper.wav"), NULL, SND_LOOP | SND_ASYNC);
}
