void chase_back(int* px, int* py) {
    if (px == &blue[0][0] && py == &blue[0][1]) {
        *px = 900;
        *py = 625;
    }
    if (px == &blue[1][0] && py == &blue[1][1]) {
        *px = 1000;
        *py = 625;
    }
    if (px == &blue[2][0] && py == &blue[2][1]) {
        *px = 900;
        *py = 725;
    }
    if (px == &blue[3][0] && py == &blue[3][1]) {
        *px = 1000;
        *py = 725;
    }
    if (px == &red[0][0] && py == &red[0][1]) {
        *px = 450;
        *py = 625;
    }
    if (px == &red[1][0] && py == &red[1][1]) {
        *px = 550;
        *py = 625;
    }
    if (px == &red[2][0] && py == &red[2][1]) {
        *px = 450;
        *py = 725;
    }
    if (px == &red[3][0] && py == &red[3][1]) {
        *px = 550;
        *py = 725;
    }
    if (px == &green[0][0] && py == &green[0][1]) {
        *px = 450;
        *py = 175;
    }
    if (px == &green[1][0] && py == &green[1][1]) {
        *px = 550;
        *py = 175;
    }
    if (px == &green[2][0] && py == &green[2][1]) {
        *px = 450;
        *py = 275;
    }
    if (px == &green[3][0] && py == &green[3][1]) {
        *px = 550;
        *py = 275;
    }
    if (px == &yellow[0][0] && py == &yellow[0][1]) {
        *px = 900;
        *py = 175;
    }
    if (px == &yellow[1][0] && py == &yellow[1][1]) {
        *px = 1000;
        *py = 175;
    }
    if (px == &yellow[2][0] && py == &yellow[2][1]) {
        *px = 900;
        *py = 275;
    }
    if (px == &yellow[3][0] && py == &yellow[3][1]) {
        *px = 1000;
        *py = 275;
    }
}
