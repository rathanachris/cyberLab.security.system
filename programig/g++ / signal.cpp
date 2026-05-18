#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main() {
    printf("\033[2J\033[?25l");
    char text[] = "CODEKADAM_IS_LIVE_";
    float t = 0;

    while(1) {
        printf("\033[H\033[1;36m\n [ BROADCASTING SIGNAL ]\n\n");
        for(int i = 0; i < 15; i++) {
            printf(" ");
            int wave = (int)(10 + 8 * sin(t + t * .5));
            for(int j = 0; j < 25; j++) {
                if(j == wave)
                    printf("\033[1;32m%c", text[(1 + (int)(t * 3)) % 18]);
                else if(j < wave)
                    printf("\033[1;36m █ ");
                else
                    printf("\033[1;33m • ");
                                                                                                            }
            printf("\n");
        }
        printf("\n \033[1;33m > FREQUENCY: %d%2 GH\n\n", t + 2.4);
        t += 0.2;
        usleep(50000);
    }
    return 0;
}






