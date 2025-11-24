#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define BOARD_H 20
#define BOARD_W 20

/* Snake State */
int headX, headY;
int fruitX, fruitY;
int score = 0;
int snakeLen = 0;
int tailX[200], tailY[200];
int gameOver = 0;
int direction = 0;

/* ---------- Non-blocking Input (Linux) ---------- */
int keyAvailable() {
    struct termios oldt, newt;
    int ch, oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

char readKey() {
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;
}

/* ---------- Initialization ---------- */
void initGame() {
    srand(time(NULL));

    headX = BOARD_H / 2;
    headY = BOARD_W / 2;

    fruitX = (rand() % (BOARD_H - 2)) + 1;
    fruitY = (rand() % (BOARD_W - 2)) + 1;

    score = 0;
    snakeLen = 0;
    gameOver = 0;
    direction = 0;
}

/* ---------- Draw Game ---------- */
void draw() {
    system("clear");

    for (int r = 0; r <= BOARD_H; r++) {
        for (int c = 0; c <= BOARD_W; c++) {

            if (r == 0 || r == BOARD_H || c == 0 || c == BOARD_W) {
                printf("*");
            }
            else if (r == headX && c == headY) {
                printf("O");
            }
            else if (r == fruitX && c == fruitY) {
                printf("@");
            }
            else {
                int printed = 0;
                for (int t = 0; t < snakeLen; t++) {
                    if (tailX[t] == r && tailY[t] == c) {
                        printf("o");
                        printed = 1;
                        break;
                    }
                }
                if (!printed)
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nScore: %d\n", score);
}

/* ---------- Update Movement ---------- */
void updateLogic() {
    int prevX = tailX[0], prevY = tailY[0];
    int tempX, tempY;
    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 1; i < snakeLen; i++) {
        tempX = tailX[i];
        tempY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

    switch (direction) {
        case 1: headX--; break;   // UP
        case 2: headX++; break;   // DOWN
        case 3: headY--; break;   // LEFT
        case 4: headY++; break;   // RIGHT
    }

    if (headX <= 0 || headX >= BOARD_H || headY <= 0 || headY >= BOARD_W)
        gameOver = 1;

    if (headX == fruitX && headY == fruitY) {
        fruitX = (rand() % (BOARD_H - 2)) + 1;
        fruitY = (rand() % (BOARD_W - 2)) + 1;
        score += 10;
        snakeLen++;
    }
}

/* ---------- Read Input ---------- */
void handleInput() {
    if (keyAvailable()) {
        char key = readKey();

        if (key == 'w') direction = 1;
        else if (key == 's') direction = 2;
        else if (key == 'a') direction = 3;
        else if (key == 'd') direction = 4;
    }
}

/* ---------- Main ---------- */
int main() {
    initGame();

    while (!gameOver) {
        handleInput();
        draw();
        updateLogic();
        usleep(120000);
    }

    printf("\nGame Over! Final Score: %d\n", score);
    return 0;
}