#include "minifunction.h"

struct termios new_term;

int main(void)
{
	tcgetattr(STDIN_FILENO, &new_term);
}