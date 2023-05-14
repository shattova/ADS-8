// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool light) {
    Cage* nCage = nullptr;
    if (first == nullptr) {
        first = new Cage;
        first->next = first;
        first->prev = first;
        first->light = light;
    } else {
        nCage = new Cage;
        nCage->next = first;
        nCage->prev = first->prev;
        first->prev = nCage;
        nCage->prev->next = nCage;
        nCage->light = light;
    }
}
int Train::getLength() {
    Cage* lCage = first;
    lCage->light = true;
    int count = 1;
    while (true) {
        lCage = lCage->next;
        if (lCage->light == false) {
            count++;
            countOp++;
        } else {
            lCage->light = false;
            for (int i = count; i > 0; i--) {
                lCage = lCage->prev;
                countOp++;
            }
            countOp++;
            if (lCage->light == false) {
                return count;
            } else {
                count = 1;
            }
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
