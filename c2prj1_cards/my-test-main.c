#include "cards.h"
#include <stdio.h>
int main(void) {
  card_t testcard;
  testcard = card_from_letters('K','d');
  printf("teste func card_from_letter Kd : card value %d, card suit %d\n",testcard.value,testcard.suit);

  testcard = card_from_num(51);
  printf("test func card_from_num 51 : card value %d, card suit %d\n", testcard.value, testcard.suit);

  testcard = card_from_num(50);
  printf("test func card_from_num 50 : card value %d, card suit %d\n", testcard.value, testcard.suit);

  testcard = card_from_num(49);
  printf("test func card_from_num 49 : card value %d, card suit %d\n", testcard.value, testcard.suit);

  testcard = card_from_num(48);
  printf("test func card_from_num 48 : card value %d, card suit %d\n", testcard.value, testcard.suit);

  testcard = card_from_num(47);
  printf("test func card_from_num 47 : card value %d, card suit %d\n", testcard.value, testcard.suit);

  for(unsigned i = 0; i < 52; i++) {
    card_t c = card_from_num(i);
    print_card(c);
  }
}
