
#include <vector>

#include "Viiva.h"

void Viiva::laskeKeskinopeus(int otanta) {
    float summa = 0;

    if (pisteet.size() < otanta) {
        for (int i = 0; i < pisteet.size() - 1; i++) {
            summa += (pisteet[i + 1] - pisteet[i]).length();
        }
        keskinopeus = summa / pisteet.size();
    } else {
        for (int i = pisteet.size() - otanta; i < pisteet.size() - 1; i++) {
            summa += (pisteet[i + 1] - pisteet[i]).length();
        }
        keskinopeus = summa / otanta;
    }



    if (pisteet.empty())
        keskinopeus = 0;
}

void Viiva::laskeKeskiherkkyys(int otanta){
    float summa = 0;

    if (pisteet.size() < otanta) {
        for (int i = 0; i < pisteet.size() - 1; i++) {
            summa += pisteet[i + 1].z - pisteet[i].z;
        }
        keskiherkkyys = summa / pisteet.size();
    } else {
        for (int i = pisteet.size() - otanta; i < pisteet.size() - 1; i++) {
            summa += pisteet[i + 1].z - pisteet[i].z;
        }
        keskiherkkyys = summa / otanta;
    }



    if (pisteet.empty())
        keskiherkkyys = 0;
    
}