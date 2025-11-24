#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <time.h>
#include <string.h>

// Define the dimensions of the game board
#define BOARD_HEIGHT 25
#define BOARD_WIDTH 25
#define MAX_OBSTACLES 5

// Struct for positions
typedef struct {
    int x, y;
} Position;

// Struct for snake segments (linked list)
typedef struct SnakeSegment {
    Position pos;
    struct SnakeSegment* next;
} SnakeSegment;

// Struct for game state
typedef struct {
    SnakeSegment* head;
    Position fruit;
    int fruitType;  // 0: normal (10 points), 1: special (20 points)
    Position obstacles[MAX_OBSTACLES];
    int obstacleCount;
    int score;
    int direction;  // 1: up, 2: down, 3: left, 4: right
    int gameOver;
    int speed;  // microseconds for delay
} GameState;

// Global buffer for rendering
char boardBuffer[BOARD_HEIGHT + 1][BOARD_WIDTH + 1];

// Function to initialize the game state
void initializeGame(GameState* state) {
    srand(time(NULL));

    // Initialize snake head
    state->head = (SnakeSegment*)malloc(sizeof(SnakeSegment));
    state->head->pos.x = BOARD_HEIGHT / 2;
    state->head->pos.y = BOARD_WIDTH / 2;
    state->head->next = NULL;

    // Place fruit randomly
    state->fruit.x = (rand() % (BOARD_HEIGHT - 2)) + 1;
    state->fruit.y = (rand() % (BOARD_WIDTH - 2)) + 1;
    state->fruitType = rand() % 2;  // Random fruit type

    // Add obstacles
    state->obstacleCount = MAX_OBSTACLES;
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        state->obstacles[i].x = (rand() % (BOARD_HEIGHT - 2)) + 1;
        state->obstacles[i].y = (rand() % (BOARD_WIDTH - 2)) + 1;
    }

    // Reset other state
    state->score = 0;
    state->direction = 0;
    state->gameOver = 0;
    state->speed = 150000;  // Initial speed
}

// Function to check for non-blocking input using select()
int checkForInput() {
    fd_set readfds;
    struct timeval tv;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) > 0;
}

// Function to read a single key press
char getInputKey() {
    char inputChar;
    read(STDIN_FILENO, &inputChar, 1);
    return inputChar;
}

// Function to handle user input
void processUserInput(GameState* state) {
    if (checkForInput()) {
        char key = getInputKey();
        if (key == 'w' && state->direction != 2) state->direction = 1;  // Up, not down
        else if (key == 's' && state->direction != 1) state->direction = 2;  // Down, not up
        else if (key == 'a' && state->direction != 4) state->direction = 3;  // Left, not right
        else if (key == 'd' && state->direction != 3) state->direction = 4;  // Right, not left
    }
}

// Function to update the board buffer
void updateBoardBuffer(GameState* state) {
    // Clear buffer
    memset(boardBuffer, ' ', sizeof(boardBuffer));

    // Draw borders
    for (int i = 0; i <= BOARD_WIDTH; i++) {
        boardBuffer[0][i] = '*';
        boardBuffer[BOARD_HEIGHT][i] = '*';
    }
    for (int i = 0; i <= BOARD_HEIGHT; i++) {
        boardBuffer[i][0] = '*';
        boardBuffer[i][BOARD_WIDTH] = '*';
    }

    // Draw obstacles
    for (int i = 0; i < state->obstacleCount; i++) {
        boardBuffer[state->obstacles[i].x][state->obstacles[i].y] = '#';
    }

    // Draw snake
    SnakeSegment* current = state->head;
    while (current != NULL) {
        boardBuffer[current->pos.x][current->pos.y] = (current == state->head) ? 'O' : 'o';
        current = current->next;
    }

    // Draw fruit
    boardBuffer[state->fruit.x][state->fruit.y] = (state->fruitType == 0) ? '@' : '$';
}

// Function to render the board from buffer
void renderBoard(GameState* state) {
    updateBoardBuffer(state);

    // Clear screen and print buffer
    system("clear");
    for (int r = 0; r <= BOARD_HEIGHT; r++) {
        for (int c = 0; c <= BOARD_WIDTH; c++) {
            putchar(boardBuffer[r][c]);
        }
        putchar('\n');
    }

    // Display score and fruit type
    printf("\nScore: %d | Fruit: %s (%d points)\n", state->score, 
           (state->fruitType == 0) ? "Normal" : "Special", 
           (state->fruitType == 0) ? 10 : 20);
}

// Function to update game logic
void updateGameLogic(GameState* state) {
    if (state->direction == 0) return;  // No movement if no direction set

    // Calculate new head position
    Position newHeadPos = state->head->pos;
    switch (state->direction) {
        case 1: newHeadPos.x--; break;  // Up
        case 2: newHeadPos.x++; break;  // Down
        case 3: newHeadPos.y--; break;  // Left
        case 4: newHeadPos.y++; break;  // Right
    }

    // Check wall collision
    if (newHeadPos.x <= 0 || newHeadPos.x >= BOARD_HEIGHT || 
        newHeadPos.y <= 0 || newHeadPos.y >= BOARD_WIDTH) {
        state->gameOver = 1;
        return;
    }

    // Check obstacle collision
    for (int i = 0; i < state->obstacleCount; i++) {
        if (newHeadPos.x == state->obstacles[i].x && newHeadPos.y == state->obstacles[i].y) {
            state->gameOver = 1;
            return;
        }
    }

    // Check self collision
    SnakeSegment* current = state->head;
    while (current != NULL) {
        if (newHeadPos.x == current->pos.x && newHeadPos.y == current->pos.y) {
            state->gameOver = 1;
            return;
        }
        current = current->next;
    }

    // Create new head segment
    SnakeSegment* newHead = (SnakeSegment*)malloc(sizeof(SnakeSegment));
    newHead->pos = newHeadPos;
    newHead->next = state->head;
    state->head = newHead;

    // Check if fruit eaten
    if (newHeadPos.x == state->fruit.x && newHeadPos.y == state->fruit.y) {
        // Add points based on fruit type
        state->score += (state->fruitType == 0) ? 10 : 20;

        // Reposition fruit
        do {
            state->fruit.x = (rand() % (BOARD_HEIGHT - 2)) + 1;
            state->fruit.y = (rand() % (BOARD_WIDTH - 2)) + 1;
        } while (boardBuffer[state->fruit.x][state->fruit.y] != ' ');  // Ensure not on obstacle/snake

        state->fruitType = rand() % 2;

        // Increase speed every 50 points
        if (state->score % 50 == 0 && state->speed > 50000) {
            state->speed -= 10000;
        }
    } else {
        // Remove tail if no fruit eaten
        SnakeSegment* tail = state->head;
        while (tail->next != NULL && tail->next->next != NULL) {
            tail = tail->next;
        }
        if (tail->next != NULL) {
            free(tail->next);
            tail->next = NULL;
        }
    }
}

// Function to free snake memory
void freeSnake(SnakeSegment* head) {
    SnakeSegment* current = head;
    while (current != NULL) {
        SnakeSegment* next = current->next;
        free(current);
        current = next;
    }
}

// Main game loop
int main() {
    GameState gameState;
    initializeGame(&gameState);

    while (!gameState.gameOver) {
        processUserInput(&gameState);
        renderBoard(&gameState);
        updateGameLogic(&gameState);
        usleep(gameState.speed);
    }

    // Clean up
    freeSnake(gameState.head);

    printf("\nGame Over! Final Score: %d\n", gameState.score);
    return 0;
}
