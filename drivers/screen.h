#define VIDEO_ADDRESS 0xb8000
#define NUM_COLS 80
#define NUM_ROWS 25

typedef unsigned char byte;

void printk(const char *str);
void print_at(const char c, int row, int col);
void clear();