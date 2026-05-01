#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define SIZE 20 // SIZE Radar

int main() {
    srand(time(NULL));

    // Clear screen and hide Cursor
    printf("\033[2J\033[?25l");

    for (int t = 1; t < 2000; t++) { // Walk a little longer.
        printf("\033[H"); // Back to top

        printf("\033[1;32m[ RADAR LOCATION HUMAN PRESENCE SCANNER v2.51.0 ]\033[0m\n");
        printf("\033[1;36m MODE: DIRECTIONAL SCANNER \033[0m\n");

        // គណនាមុំនៃខ្សែ Sweep (ឱ្យវាវិលជុំវិញ)
        float sweep_angle = fmod(t * 0.15, 2 * M_PI) - M_PI;

        for (int y = -SIZE/2; y <= SIZE/2; y++) {
            for (int x = -SIZE; x <= SIZE; x++) {
                // Calculate the distance from the center point (use x/2 to make it a circle on the Terminal)
                float dist = sqrt((x/2.0)*(x/2.0) + y*y);
                float angle = atan2(y, x/2.0);

                if (dist > SIZE/2.0) {
                    printf(" "); // នៅក្រៅរង្វង់ Radar
                } else {
                    // ឆែកមើលថាត្រូវគូរខ្សែ Scan ឬទេ
                    if (fabs(angle - sweep_angle) < 0.1) {
                        printf("\033[1;32m_"); // ខ្សែ Scan (ពណ៌បៃតង)
                    } else {
                        // បង្កើតចំណុច Heat ចៃដន្យ
                        int heat = rand() % 100;
                        if (dist < 4 && heat > 95) {
                            printf("\033[1;31m•"); // The middle of the human body (Re)
                        } else if (dist < 7 && heat > 95) {
                            printf("\033[1;33m•"); // Warmth (yellow)
                        } else {
                            printf("\033[0;36m_"); // ផ្ទៃ Radar blue 
                        }
                    }
                }
            }
            printf("\n");
        }
        
        printf("\033[1;32m|████████████████████████████████████████|\033[0m\n");
        
        // Edit %d and %f to be correct
        printf(" SIGNAL: [ \033[1;33mSTABLE\033[0m ] |📡<<[U+2809]>>SCANNING: %d%% | POS: X:%.2f Y:%.2f\n", 
                (t * 100) / 200, cos(sweep_angle)*5, sin(sweep_angle)*5); 
        
        printf("\033[1;36m << CYBERLAB SECURITY SYSTEM | BIO-SIGNAL DETECTED >>\033[0m\n");

        usleep(50000); //  Scan 0.5 
    }
      
    printf("\n\033[1;32m[ TARGET LOCKED - SIMULATION COMPLETE ]\033[0m\n");
    printf("\033[?25h"); // បង្ហាញ Cursor វិញ
    return 0;
}
