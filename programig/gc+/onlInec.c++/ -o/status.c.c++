#include <iostream>  // command ($status.c.c++ 
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function សម្រាប់លុប Screen
void clear() {
    // ANSI escape codes ដើម្បីសម្អាតអេក្រង់
    cout << "\033[2J\033[H";
}

// Function shown Progress Bar
void progressBar(double value) {
    int barWidth = 40; // ប្រវែងរបារ
    int filled = (int)(value / 100.0 * barWidth);

    cout << "\033[1;37m["; // White for the frame [
    for (int i = 0; i < barWidth; i++) {
        if (i < filled)
            cout << "\033[1;36m#"; // ពណ៌ខៀវ (Cyan) សម្រាប់ភាគរយដែលដើររួច
        else
            cout << "\033[1;30m-"; // ពណ៌ប្រផេះ សម្រាប់ភាគរយដែលនៅសល់
    }
    cout << "\033[1;37m] "; // ពណ៌ស សម្រាប់ស៊ុម ]
    cout << "\033[1;32m" << fixed << setprecision(2) << value << "%" << endl; // ពណ៌បៃតងសម្រាប់លេខ %
}

int main() {
    srand(time(0)); 
    double val = 0;

    while (true) {
        clear();

        // ចំណងជើងខាងលើ
        cout << "\033[1;36m========================================" << endl;
        cout << "       [ CYBER SCANNER ENGINE ]" << endl;
        cout << "========================================" << endl;

        // បង្កើនតម្លៃភាគរយម្តងបន្តិចៗ
        val += (rand() % 150) / 100.0;

        if (val > 100) val = 100;

        cout << "\n\033[1;33mSTATUS: \033[1;31mSCANNING IN PROGRESS..." << endl;
        
        // បង្ហាញ Progress Bar
        progressBar(val);

        cout << "\n\033[1;33mTARGET LOCK: \033[1;32mONLINE" << endl;

        // នៅពេលគ្រប់ 100%
        if (val >= 100) {
            cout << "\n\033[1;32m[+] SCAN COMPLETED SUCCESSFULLY!" << endl;
            cout << "\033\[1;35m[+] EYE RED 👁️[U+U2800] ACTIVATED!\033]0m" << endl;
            break; 
        }

        // ពន្យារពេល 50 milliseconds
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
