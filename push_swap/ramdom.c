#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ft_random() {
    static int initialized = 0;
    if (!initialized) {
        srand((unsigned int) time(NULL)); // 시드 값을 현재 시간으로 설정
        initialized = 1;
    }
    return rand() % 7 + 1;
}

int main() {
    int i;
    // for (i = 0; i < 10; i++) {
        printf("%d\n", ft_random());
    // }
    return 0;
}
