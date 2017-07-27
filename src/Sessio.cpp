#include "Sessio.h"

void Sessio::setup(int kalibrointiCount_, int viivaKeskenCount_) {
    kalibrointiCount = kalibrointiCount_;
    viivaKeskenCount = viivaKeskenCount_;
    updateCount = 0;
}

void Sessio::update() // valitaan moodi joka kierroksella
{
    if (hiiri.click) {
        updateCount = 0;
        hiiri.click = false;
    }

    if (hiiri.mouseState.z) {
        if (updateCount < kalibrointiCount) {
            moodi = kalibroi;
        } else {
            moodi = piirtaa;
        }
    } else {
        if (moodi == kalibroi || moodi == piirtaa) {
            moodi = viivaKesken;
            updateCount = 0;
        } else if (updateCount < viivaKeskenCount && moodi == viivaKesken) {
        } else {
            moodi = viivaValmis;
        }
    }
    updateCount++;
}

