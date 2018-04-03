// constant definitions
#define ESC 0x1B
#define BAR "\u25B2"
#define UNICODE	//conditional compiling

enum FGCOLORS {BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
// function prototypes

void clearScreen(void);

void gotoxy(int, int);

void bar(int, double);

void setColor(int);
