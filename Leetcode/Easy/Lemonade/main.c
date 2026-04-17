//860. Lemonade Change
#include <stdbool.h>
bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0, i;
    for(i = 0; i<billsSize; i++){
        if(bills[i] == 5){
            five++;
        }
        else if(bills[i] == 10){
            if(five == 0) return false;
            five--;
            ten++;
        }
        else{ // bills[i] == 20
            if(ten>0 && five>0){
                ten--;
                five--;
            } 
            else if(five >= 3){
                five -= 3;
            } 
            else {
                return false;
            }
        }
    }
    return true;
}