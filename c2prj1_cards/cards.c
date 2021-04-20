#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  int ans_value; // c card value
  int ans_suit; // c card suit
  
  //checking if the card value is valid
  assert(ans_value >= 2);
  assert(ans_value <= VALUE_ACE);

  //checking if the card suit is valid
  assert(ans_suit >= SPADES);
  assert(ans_suit <= NUM_SUITS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case 0:
    return "STRAIGHT_FLUSH ";
  case 1:
    return "FOUR_OF_A_KIND";
  case 2:
    return "FULL_HOUSE";
  case 3:
    return "FLUSH";
  case 4:
    return "STRAIGHT";
  case 5:
    return "THREE_OF_A_KIND";
  case 6:
    return "TWO_PAIR";
  case 7:
    return "PAIR";
  case 8:
    return "NOTHING";
  }
  return "error";
}
char value_letter(card_t c){
  unsigned c_value = c.value;
  if ((c_value >= 2) && (c_value <=10))
    {   
      c_value = c_value + 48;
    }
 else if (c_value == 10)
    {
      c_value = 0;
    }
    
 else if ((c_value >= 11) && (c_value <= 14)) 
  {
    switch (c_value)
      {
       case 11:
	 return 'J';
       case 12:
	 return 'Q';
       case 13:
	 return 'K';
       case 14:
	 return 'A';
      }
  }
  return '@';
}

char suit_letter(card_t c)
{
   switch(c.suit)
     {
     case 0:
       return 's';
     case 1:
       return 'h';
     case 2:
       return 'd';
     case 3:
       return 'c';
     case 4:
       assert(0);
     }
   return '@';
}

void print_card(card_t c)
{
  char c_value_print;
  char  c_suit_print;

  c_value_print = value_letter(c); // store the correct value character in a variable to be printed
  c_suit_print = suit_letter(c); // store the correct suit character in a variable to be printed

  printf("%c%c", c_value_print, c_suit_print); // print the variables : value and suit

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch (value_let)
    {
    case '2':
      temp.value = 2;
    case '3':
      temp.value = 3;
    case '4':
      temp.value = 4;
    case '5':
      temp.value = 5;
    case '6':
      temp.value = 6;
    case '7':
      temp.value = 7;
    case '8':
      temp.value = 8;
    case '9':
      temp.value = 9;
    case '0':
      temp.value = 10;
    case 'J':
      temp.value = 11;
    case 'Q':
      temp.value = 12;
    case 'K':
      temp.value = 13;
    case 'A':
      temp.value = 14;
    default:
      assert(0);
    }
  switch (suit_let)
    {
    case 's':
      temp.suit = SPADES;
    case 'h':
      temp.suit = HEARTS;
    case 'd':
      temp.suit = DIAMONDS;
    case 'c':
      temp.suit = CLUBS;
    default:
      assert(0);
    }	
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned array_cards_value[52];
  unsigned array_cards_suit[52];
  unsigned j;
  for (unsigned i = 0; i < 52; i++)
    {
      if (i == 0)
	{
	  temp.suit = SPADES;
	  j = 2;
	}
      if (i == 12)
	{
	  temp.suit = HEARTS;
	}
      if (i == 25)
	{
	  temp.suit = DIAMONDS;
	}
      if (i == 38)
	{
	  temp.suit = CLUBS;
	}
      array_cards_value[i] = j;
      array_cards_suit[i] = temp.suit;
      j++;
      if (j == 15)
	{
	  j = 2;
	}
    }
  temp.value = array_cards_value[c];
  temp.suit = array_cards_suit[c];
  return temp;
}
