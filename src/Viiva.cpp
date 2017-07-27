
#include <vector>

#include "Viiva.h"

void Viiva::laskeKeskinopeus() {
    float summa = 0;

    for (int i = 0; i < pisteet.size() - 1; i++) {
        summa +=  (pisteet[i+1] - pisteet[i]).length();
    }
    if (!pisteet.empty())
        keskinopeus = summa / pisteet.size();
    else
        keskinopeus = 0;
}