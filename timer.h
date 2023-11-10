
#include <chrono>
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

// Quick little timer to make my life easier
struct timer {
    inline timer() {
        startTimer();
        return;
    }
    
    inline virtual ~timer() { return; }

    inline void startTimer() {
        startTime = high_resolution_clock::now();
        return;
    }

    inline double getTime() {
        finalTime = high_resolution_clock::now();
        return duration_cast<duration<double>>(finalTime - startTime).count();
    }

    private:
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point finalTime;
};