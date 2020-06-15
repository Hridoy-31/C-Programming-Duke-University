#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  card_t **card = hand->cards;
  card_t temp;
  for(int i=0; i<(hand->n_cards); i++){
    temp = **card;
    print_card(temp);
    printf(" ");
    card++;
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t **card;
  for(int i=0; i<(d->n_cards); i++){
    card = d->cards+i;
    if((value_letter(**card) == value_letter(c)) && (suit_letter(**card) == suit_letter(c)))
      return 1;
    card++;
  }
  return 0;
}

void shuffle(deck_t * d){
  card_t *temp, **card = d->cards;
  size_t limit = d->n_cards;
  int a;
  for(size_t i=0; i<limit/2; i++){
    a = random()%(limit-i)+i;
    temp = card[i];
    card[i] = card[a];
    card[a] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  card_t **card = d->cards;
  card_t temp_card;
  deck_t deck;
  deck.cards = d->cards;
  for(int i=0; i<(d->n_cards); i++){
    temp_card = **card;
    assert_card_valid(temp_card);
    if(i>0){
      deck.n_cards = (size_t)i;
      assert(!deck_contains(&deck, temp_card));
    }
    card++;
  }
}
