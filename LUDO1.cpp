#include "add.h" //ใส่ไฟล์รวมฟังก์ชั่นที่ทำไว้

int main()
{
    playSound(1); //เรียกเล่นเสียงคลอเกม
    //ใส่Textureคล้ายการโหลดรูปเข้าโปรแกรมว่าถ้า Spriteนี้ใช้Texture อะไร
    //ประกาศตัวแปรTextureทั้งหมด หรือรูปที่จะเอาเข้าโปรแกรมทั้งหมด
    Texture cs, hm, st, ht, ex, htp, hb1, hb2, mu, ng, rb; //texture ปุ่ม และcursor
    Texture bg, d, fd, winR, winB, winG, winY; //ฉากหลัง เต๋า กรอบเต๋า ภาพผู้ชนะ
    Texture g, r, y, b; //ตัวหมาก
    srand(time(0)); //ไว้random
    RenderWindow window(VideoMode(1500, 900), "LUDO!!!"); //วาดหน้าต่างแสดงผลขนาด 1500*900
    window.setMouseCursorVisible(false); //ปิดภาพcursorอันปกติ ไว้ใช้ภาพที่เตรียมไว้แทน
    window.setKeyRepeatEnabled(false); //กดซ้ำไม่ได้
    rb.loadFromFile("image/reset.png"); //ปุ่มรีเซ็ต
    ng.loadFromFile("image/NG.png"); //ปุ่ม new game เมื่อชนะจบเกม
    mu.loadFromFile("image/onoff.png"); //ปุ่มปิดเปิดเพลง
    htp.loadFromFile("image/HowToPage.png"); //หน้าฮาวทู
    hb1.loadFromFile("image/homebot.png"); //ปุ่มโฮมที่หน้าฮาวทู
    hb2.loadFromFile("image/homegamepage.png"); //ปุ่มโฮมที่หน้าเกม
    winR.loadFromFile("image/winR.png"); //สีแดงชนะ
    winG.loadFromFile("image/winG.png"); //สีเขียวชนะ
    winB.loadFromFile("image/winB.png"); //สีฟ้าชนะ
    winY.loadFromFile("image/winY.png"); //สีเหลืองชนะ
    ht.loadFromFile("image/HowTo.png"); //ปุ่มฮาวทู
    ex.loadFromFile("image/exit.png"); //ปุ่มออก
    cs.loadFromFile("image/cursor.png"); //Cursor
    st.loadFromFile("image/start.png"); //ปุ่มเริ่มเกม
    hm.loadFromFile("image/home.png"); //ปุ่มโฮม
    fd.loadFromFile("image/frame_dice.png"); //กรอบลูกเต๋า
    d.loadFromFile("image/dice2.png"); //ลูกเต๋า
    g.loadFromFile("image/gรวม.png"); //หมากเขียว
    r.loadFromFile("image/rรวม.png"); //หมากแดง
    b.loadFromFile("image/bรวม.png"); //หมากฟ้า
    y.loadFromFile("image/yรวม.png"); //หมากเหลือง
    bg.loadFromFile("image/background.png"); //พื้นหลัง
    //สร้างสไปร์ทแล้วใส่Textureตามที่กำหนดไว้
    Sprite background(bg), dice(d), frame(fd), home(hm), start(st), cursor(cs), howto(ht), exit(ex), howtoP(htp), homebot1(hb1), mute(mu), newgame(ng), homebot2(hb2), resetbot(rb);
    Sprite winnerR(winR), winnerB(winB), winnerG(winG), winnerY(winY);
    Sprite r1(r), r2(r), r3(r), r4(r), b1(b), b2(b), b3(b), b4(b), g1(g), g2(g), g3(g), g4(g), y1(y), y2(y), y3(y), y4(y);

    //ลูปขณะเปิดwindow
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window); //ตัวแปรVector2iไว้เก็บค่าตำแหน่งของเมาส์
        Event event; //ตัวแปรevent
        while (window.pollEvent(event))
        {
            //เมื่อปิดหน้าต่างด้วยปุ่มปิดโปรแกรม
            if (event.type == sf::Event::Closed)
                window.close();
            //เมื่อเมาส์คลิกและอยู๋หน้าโฮม
            if (Mouse::isButtonPressed(Mouse::Button::Left) && page == 1) {
                //ขอบเขตตำแหน่งปุ่มexit
                if (pos.x >= 1121 && pos.x <= 1371 && pos.y >= 660 && pos.y <= 760) {
                    window.close();
                }
            }
        }

        //เมื่อคลิกเมาส์ซ้าย
        if (Mouse::isButtonPressed(Mouse::Button::Left)) {
            //หน้าโฮม
            if (page == 1) {
                //ปุ่มเริ่มเกม
                if (pos.x >= 1121 && pos.x <= 1371 && pos.y >= 354 && pos.y <= 454) {
                    timeToRoll = 1; //เปลี่ยนสถานะให้ลูกเต๋าทอยได้
                    page = 0; //ไปหน้าเกม
                }
                //ปุ่มฮาวทู
                if (pos.x >= 1071 && pos.x <= 1421 && pos.y >= 506 && pos.y <= 606) {
                    page = 2;//หน้าฮาวทู
                }
            }
            //หน้าฮาวทู
            if (page == 2) {
                //ปุ่มกลับหน้าโฮม
                if (pos.x >= 1099 && pos.x <= 1467 && pos.y >= 758 && pos.y <= 888) {
                    page = 1; //ไปหน้าโฮม
                }
            }
            //หน้าชนะเกม จบเกม
            if (page == 3) {
                //ปุ่มเริ่มเกมใหม่
                if (pos.x >= 582 && pos.x <= 921 && pos.y >= 747 && pos.y <= 839) {
                    ResetAll(1); //รีเซตไปหน้าโฮม
                }
            }
            //หน้าเกม
            if (page == 0) {
                //ปุ่มปิดเปิดเสียง
                if (pos.x >= 1353 && pos.x <= 1433 && pos.y >= 100 && pos.y <= 180) {
                    sleep_for(nanoseconds(200000000)); //ดีเลย์
                    muteornot = !muteornot; //สลับสถานะเปิดปิด
                    mutepressed = 1; //ปุ่มถูกกด
                }
                //ปุ่มกลับหน้าโฮม
                if (pos.x >= 1353 && pos.x <= 1433 && pos.y >= 190 && pos.y <= 270) {
                    ResetAll(1); //รีเซตไปหน้าโฮม
                }
                //ปุ่มรีเซตกระดาน
                if (pos.x >= 1353 && pos.x <= 1433 && pos.y >= 280 && pos.y <= 360) {
                    ResetAll(0); //รีเซตหน้าเกม
                    timeToRoll = 1; //เปลี่ยนสถานะลูกเต๋าให้ถึงเวลาทอย
                }
            }
        }

        //ถ้าปุ่มปิดเปิดเสียงโดนกด
        if (mutepressed) {
            mutepressed = 0;//เปลี่ยนสถานะเป็นไม่ได้กด
            if (muteornot == 1) playSound(0); //เล่นเสียงปิด
            else playSound(1); //เล่นเพลงคลอเกมต่อ
        }

        if (Mouse::isButtonPressed(Mouse::Button::Left) && timeToRoll) {//เมื่อคลิกซ้ายเมาส์ลงและอยู่ในเงื่อนไขที่สามารถทอยเต๋าได้(timeToRoll == 1)
            //ใช้สำหรับทอยลูกเต๋า โดยใช้Roundเพื่อแยกเป็นแต่ละturnของแต่ละสี
            if (pos.x >= 182 && pos.x <= 340 && pos.y <= 258 && pos.y >= 100 && Round == 1) {//positionของลูกเต๋าของแต่ละRound
                Roll = roll_dice();
                if (!six)Round++;
                Finished = 0;//ยังไม่เสร็จturn
                timeToRoll = 0;//ยังไม่สามารถทอยลูกเต๋าต่อได้
            }
            if (pos.x >= 1160 && pos.x <= 1328 && pos.y <= 258 && pos.y >= 100 && Round == 2) {
                Roll = roll_dice();
                if (!six) Round++;
                Finished = 0;
                timeToRoll = 0;
            }
            if (pos.x >= 1160 && pos.x <= 1328 && pos.y <= 850 && pos.y >= 692 && Round == 3) {
                Roll = roll_dice();
                if (!six) Round++;
                Finished = 0;
                timeToRoll = 0;
            }
            if (pos.x >= 182 && pos.x <= 340 && pos.y <= 850 && pos.y >= 692 && (Round == 4 || Round == 0)) {
                Roll = roll_dice();
                if (!six) Round++;
                if (Round == 5) Round = 1;//ถ้าครบ 4 รอบจะวนไปยังสีแรกใหม่
                Finished = 0;
                timeToRoll = 0;
            }
        }

        window.clear(Color::White);

        if (Round == 1 && Ggoal.size() == pick[0]) {//เช็คว่าหมากทั้งหมดในกระดานอยู่ในเลนเข้าเส้นชัยไหม
            can = 0;//หมากในกระดานไม่สามารถเดินต่อไปได้ถ้าจำนวนแต้มจากการทอยลูกเต๋าเกินช่องที่เหลือให้เดินเข้าเส้นชัยจะskip turn
            if (Roll == 6 && in_start[0] != 0) {//ถ้าทอยได้ 6 แล้วยังมีหมากในฐานสามารถเล่นต่อได้
                can = 1;
            }
            else {
                for (auto i : Ggoal) {
                    if (Roll <= (675 - *i) / w) {//ถ้าจำนวนแต้มของหมากตัวใดตัวนึงในเลนเส้นชัยไม่เกินสามารถเล่นturnนี้ได้
                        can = 1;
                    }
                }
            }
        }
        if (Round == 2 && Ygoal.size() == pick[1]) {
            can = 0;
            if (Roll == 6 && in_start[1] != 0) {
                can = 1;
            }
            else {
                for (auto i : Ygoal) {
                    if (Roll <= (400 - *i) / w) {
                        can = 1;
                    }
                }
            }
        }
        if (Round == 3 && Bgoal.size() == pick[2]) {
            can = 0;
            if (Roll == 6 && in_start[2] != 0) {
                can = 1;
            }
            else {
                for (auto i : Bgoal) {
                    if (Roll <= (*i - 775) / w) {
                        can = 1;
                    }
                }
            }
        }
        if (Round == 4 && Rgoal.size() == pick[3]) {
            can = 0;
            if (Roll == 6 && in_start[3] != 0) {
                can = 1;
            }
            else {
                for (auto i : Rgoal) {
                    if (Roll <= (*i - 500) / w) {
                        can = 1;
                    }
                }
            }
        }
        if (!can) {//ใช้ข้ามตาเวลาที่ไม่มีตัวที่สามารถเดินได้บนกระดาน(can == 0)
            if (wait) {//delayหลักกดคลิกลูกเต๋า
                sleep_for(nanoseconds(100000000));
                wait = 0;
            }
            Finished = 1;//จบturn
            timeToRoll = 1;//ทอยลูกเต๋าต่อได้
            can = 1;
        }

        if (Roll == 6) {//ถ้าทอยลูกเต๋าได้แต้มเป็น 6 จะสามารถทอยเพิ่มได้อีกครั้ง 
            six = 1;
        }
        else {
            six = 0;
        }


        if (event.key.code == Mouse::Left) {//เมื่อคลิกซ้ายที่เมาส์
            //เมื่อpositionของเมาส์อยู่ที่บริเวณฐานของหมากแต่ละสี
            if ((pos.x >= 375 && pos.x <= 675 && pos.y >= 100 && pos.y <= 400 && Round == 1) || (pos.x >= 375 && pos.x <= 675 && pos.y >= 550 && pos.y <= 850 && Round == 4) || (pos.x >= 825 && pos.x <= 1125 && pos.y >= 100 && pos.y <= 400 && Round == 2) || (pos.x >= 825 && pos.x <= 1125 && pos.y >= 550 && pos.y <= 850 && Round == 3)) {
                if (Roll == 6) { //หมากจะออกจากฐานเมื่อทอยได้เลข 6 เท่านั้น
                    xc = pos.x;
                    yc = pos.y;
                    return_position(xc, yc, 1);
                    int* px = searchx(xc, yc, 0), * py = searchy(xc, yc, 0);
                    getstart(px, py, Round);
                    int* X, * Y;
                    do {//เมื่อหมากที่เดินทับลงไปในหมากที่อยู่ในช่องนั้นจะส่งหมากทุกตัวที่มีกลับไปยังฐานของตัวเอง
                        X = searchx(*px, *py, Round);
                        Y = searchy(*px, *py, Round);
                        chase_back(X, Y);
                    } while (*X && *Y);
                }
            }
            //เมื่อpositionของเมาส์อยู่ในช่วงของกระดานเดินหมาก
            else if (pos.x >= 375 && pos.x <= 675 && pos.y >= 400 && pos.y <= 550 || pos.x >= 825 && pos.x <= 1125 && pos.y >= 400 && pos.y <= 550 || pos.x >= 675 && pos.x <= 825 && pos.y >= 100 && pos.y <= 400 || pos.x >= 675 && pos.x <= 825 && pos.y >= 550 && pos.y <= 850) {
                if (Roll != 6) {
                    //ใช้เพื่อskip turnเวลาที่ไม่มีหมากบนกระดานและทอยไม่ได้ 6 ทำให้ไม่สามารถเอาหมากออกมาได้
                    if (Round == 1 && pick[0] == 0 || Round == 2 && pick[1] == 0 || Round == 3 && pick[2] == 0 || Round == 4 && pick[3] == 0 && !wait) {
                        six = 0;
                        Finished = 1;
                        timeToRoll = 1;
                    }
                    if (wait) {//delayหลังกดลูกเต๋า
                        sleep_for(nanoseconds(100000000));
                        wait = 0;
                    }
                }
                xc = pos.x;
                yc = pos.y;
                return_position(xc, yc);
                int* px = searchx(xc, yc, 0), * py = searchy(xc, yc, 0);
                if (*px != 0 && *py != 0) {//ถ้าบริเวณที่กดมีหมากอยู่จึงจะเข้าเงื่อนไข
                    if (px == &green[0][0] || px == &green[1][0] || px == &green[2][0] || px == &green[3][0]) {//หมากของสีเขียว
                        if (py == &green[0][1] || py == &green[1][1] || py == &green[2][1] || py == &green[3][1]) {
                            if (Round == 1 && !Finished) {
                                num[0] = move_green(*px, *py, Roll);//รับค่า 1 เมื่อหมากเดินเข้าเส้นชัย
                                win[0] = win[0] + num[0];//เก็บค่าจำนวนตัวที่เข้าเส้นชัย
                                pick[0] -= num[0];//จำนวนหมากที่เดินอยู่ในกระดานลดลง
                                if (*px >= 425 && *px <= 625 && *py == 450) {//ถ้าเข้าเลนเส้นชัย
                                    Ggoal.insert(px);//เก็บค่าหมากที่อยู่ในเลนเส้นชัย
                                    wait = 1;
                                }
                                if (num[0] == 1) {
                                    Ggoal.erase(px);//ลบค่าหมากออกเมื่อหมากเขาเส้นชัย
                                }
                                int* X, * Y;
                                do {//เมื่อหมากที่เดินทับลงไปในหมากที่อยู่ในช่องนั้นจะส่งหมากทุกตัวที่มีกลับไปยังฐานของตัวเอง
                                    X = searchx(*px, *py, Round);
                                    Y = searchy(*px, *py, Round);
                                    chase_back(X, Y);
                                } while (*X && *Y);
                            }
                        }
                    }
                    if (px == &yellow[0][0] || px == &yellow[1][0] || px == &yellow[2][0] || px == &yellow[3][0]) {//หมากสีเหลือง
                        if (py == &yellow[0][1] || py == &yellow[1][1] || py == &yellow[2][1] || py == &yellow[3][1]) {
                            if (Round == 2 && !Finished) {
                                num[1] = move_yellow(*px, *py, Roll);
                                win[1] = win[1] + num[1];
                                pick[1] -= num[1];
                                if (*py >= 150 && *py <= 350 && *px == 725) {
                                    Ygoal.insert(py);
                                    wait = 1;
                                }
                                if (num[1] == 1) {
                                    Ygoal.erase(py);
                                }
                                int* X, * Y;
                                do {
                                    X = searchx(*px, *py, Round);
                                    Y = searchy(*px, *py, Round);
                                    chase_back(X, Y);
                                } while (*X && *Y);
                            }
                        }
                    }
                    if (px == &blue[0][0] || px == &blue[1][0] || px == &blue[2][0] || px == &blue[3][0]) {//หมากสีฟ้า
                        if (py == &blue[0][1] || py == &blue[1][1] || py == &blue[2][1] || py == &blue[3][1]) {
                            if (Round == 3 && !Finished) {
                                num[2] = move_blue(*px, *py, Roll);
                                win[2] = win[2] + num[2];
                                pick[2] -= num[2];
                                if (*px <= 1025 && *px >= 825 && *py == 450) {
                                    Bgoal.insert(px);
                                    wait = 1;
                                }
                                if (num[2] == 1) {
                                    Bgoal.erase(px);
                                }

                                int* X, * Y;
                                do {
                                    X = searchx(*px, *py, Round);
                                    Y = searchy(*px, *py, Round);
                                    chase_back(X, Y);

                                } while (*X && *Y);
                            }
                        }
                    }
                    if (px == &red[0][0] || px == &red[1][0] || px == &red[2][0] || px == &red[3][0]) {//หมากสีแดง
                        if (py == &red[0][1] || py == &red[1][1] || py == &red[2][1] || py == &red[3][1]) {
                            if (Round == 4 && !Finished) {
                                num[3] = move_red(*px, *py, Roll);
                                win[3] = win[3] + num[3];
                                pick[3] -= num[3];
                                if (*py >= 550 && *py <= 750 && *px == 725) {
                                    Rgoal.insert(py);
                                    wait = 1;
                                }
                                if (num[3] == 1) {
                                    Rgoal.erase(py);
                                }
                                int* X, * Y;
                                do {
                                    X = searchx(*px, *py, Round);
                                    Y = searchy(*px, *py, Round);
                                    chase_back(X, Y);

                                } while (*X && *Y);
                            }
                        }
                    }
                    if ((Round == 1 && pick[0] == 0 || Round == 2 && pick[1] == 0 || Round == 3 && pick[2] == 0 || Round == 4 && pick[3] == 0) && six) {
                        wait = 1;//delayเมื่อหมากทอยได้ 6 ให้ไม่ไปกดลูกเต๋าซ้ำ
                    }



                }
            }
        }

        picCount = searchx(green[0][0], green[0][1], 1, 1); //หาจำนวนหมากสีเดียวกันที่ยืนตำแหน่งเดียวกัน
        //setTextureRectคือเลือกภาพเฉพาะส่วนบนรูปเต็ม โดย setTextureRect(IntRect(เริ่มที่ x, เริ่มที่ y, ความกว้างรูป,ความสูงรูป))
        if (green[0][0] == 675 && green[0][1] == 450) g1.setTextureRect(IntRect((win[0] - 1) * 50, 0, 50, 50));//ที่จุดเส้นชัย
        else g1.setTextureRect(IntRect(*picCount * 50, 0, 50, 50));//ซ้อนกัน ณ ตำแหน่งใดๆบนกระดาน
        //เหมือนเดิมจนครบทุกตัว
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

        window.draw(background);//ภาพพื้นหลัง
        //เซ็ตตำแหน่งหมากบนกระดาน ซึ่งเปลี่ยนไปเรื่อยๆระหว่างเล่นตามตำแหน่งที่เก็บไว้บนarray
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
        //วาดหมาก
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
        //ให้กรอบเต๋าเปลี่ยนสีตามรอบที่สีใดกำลังเล่นอยู่
        frame.setTextureRect(IntRect(Round * 204, 0, 204, 216));
        window.draw(frame);//วาด
        mute.setPosition(1353, 100);
        mute.setTextureRect(IntRect(!muteornot * 80, 0, 80, 80));//ภาพปิดหรือเปิดเสียงสลับกัน
        window.draw(mute);
        homebot2.setPosition(1353, 190);
        window.draw(homebot2);
        resetbot.setPosition(1353, 280);
        window.draw(resetbot);
        dice.setTextureRect(IntRect((Roll - 1) * 158 + timeToRoll * 948, 0, 158, 158));//สลับว่าทอยได้เท่าไหร่และถึงสเตจว่าทอยต่อได้รึยัง ถ้าทอยได้สีดำ ถ้ารอactionของผู้เล่นสีแดง
        //ย้ายตำแหน่งเต๋าตามรอบของสีใดๆ
        if (Round == 1) {
            dice.setPosition(182, 147);//สีเขียวซ้ายบน
            frame.setPosition(160, 100);
        }
        if (Round == 2) {
            dice.setPosition(1160, 147);//สีเหลืองขวาบน
            frame.setPosition(1138, 100);
        }
        if (Round == 3) {
            dice.setPosition(1160, 692);//สีฟ้าขวาล่าง
            frame.setPosition(1138, 645);
        }
        if (Round == 4 || Round == 0) {
            dice.setPosition(182, 692);//สีแดงซ้ายล่าง
            frame.setPosition(160, 645);
        }
        window.draw(dice);//วาดเต๋า
        //วาดหน้าโฮม
        if (page == 1) {
            window.draw(home);
            start.setPosition(1121, 354);
            window.draw(start);
            howto.setPosition(1071, 506);
            window.draw(howto);
            exit.setPosition(1121, 660);
            window.draw(exit);
        }
        //วาดหน้าฮาวทู
        if (page == 2) {
            window.draw(howtoP);
            homebot1.setPosition(1099, 758);
            window.draw(homebot1);
        }
        cursor.setPosition(pos.x, pos.y);//วาดcursorให้เปลี่ยนตำแหน่งตามเมาส์เคลื่อน
        newgame.setPosition(582, 747);
        //วาดฉากชนะ
        if (win[0] == 4) {
            window.draw(winnerG);//วาดฉากสีเขียวชนะ
            window.draw(newgame);//ปุ่มเกมใหม่
            GotWinner = 1;//ได้ผู้ชนะแล้ว
        }
        if (win[1] == 4) {
            window.draw(winnerY);//สีเหลืองชนะ
            window.draw(newgame);
            GotWinner = 1;
        }
        if (win[2] == 4) {
            window.draw(winnerB);//สีฟ้าชนะ
            window.draw(newgame);
            GotWinner = 1;
        }
        if (win[3] == 4) {
            window.draw(winnerR);//สีแดงชนะ
            window.draw(newgame);
            GotWinner = 1;
        }
        //ได้ผู้ชนะ
        if (GotWinner == 1 && page != 3) {
            GotWinner = 0;//เปลี่ยนสถานะได้ผู้ชนะ
            playSound(2);//เล่นเสียงชนะ
            page = 3;//เปลี่ยนสถานะเป็นหน้าชนะ
        }
        window.draw(cursor);//วาดcursorไว้บนสุด
        window.display();


    }
    return 0;
}
