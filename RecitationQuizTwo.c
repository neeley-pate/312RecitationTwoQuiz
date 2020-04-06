#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int helperFunction(uint32_t array[], uint32_t length, uint32_t numElem, uint32_t sum);


bool sumsTo(uint32_t x[], uint32_t n, uint32_t k, uint32_t v){
    if(helperFunction(x, n, k, v) == 1){
        return true;
    }else{
        return false;
    }
}

int helperFunction(uint32_t array[], uint32_t length, uint32_t numElem, uint32_t sum){
    if(sum == 0 && numElem == 0){
        return 1;
    }
    if(sum != 0 && numElem == 0){
        return 0;
    }
    if(length == 0){
        return 0;
    }
    int resultOne = 0;
    if(sum >= array[0]){
        resultOne = helperFunction(array + 1, length - 1, numElem - 1, sum - array[0]);
    }
    int resultTwo = helperFunction(array + 1, length - 1, numElem, sum);
    if(resultOne + resultTwo > 0){
        return 1;
    }
    return 0;
}

void assess(bool def){
    if(def == true){
        printf("true!\n");
    }
    else{
        printf("false.\n");
    }
}

int main() {
    uint32_t array[20];
    for(int i = 0; i < 20; i++){
        array[i] = i + 1;
    }
    for(int i = 1; i < 20; i++){
        assess(sumsTo(array, 20, i, 20));
    }
    return 0;
}
