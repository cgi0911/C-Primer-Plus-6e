#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int suit;
    int num;
} Card;

void print_card (Card card) {
    switch (card.suit) {
        case 0:
            printf ("%c%02d ", 'S', card.num);
            break;
        case 1:
            printf ("%c%02d ", 'H', card.num);
            break;
        case 2:
            printf ("%c%02d ", 'D', card.num);
            break;
        case 3:
            printf ("%c%02d ", 'C', card.num);
            break;
        default:
            printf ("??? ");
            break;
    }
}

void print_deck (Card *deck) {
    for (int i = 0 ; i < 52 ; i++) {
        print_card (deck[i]);
        if (i % 13 == 12) {
            printf ("\n");
        }
    }
}

Card *create_deck () {
    Card *deck = (Card *) malloc (sizeof (Card) * 52);
    
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 1 ; j <= 13 ; j++) {
            deck[i * 13 + j - 1].suit = i;
            deck[i * 13 + j - 1].num = j;
        }
    }
    
    return deck;
}

void fisher_yates_shuffle (Card *deck) {
    for (int i = 51 ; i >= 1 ; i--) {
        Card temp = deck[i];        
        int j = rand () % (i + 1);
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main () {
    srand (time (NULL));
    
    Card *deck = create_deck ();
    
    printf ("Current deck:\n");
    print_deck (deck);
    
    printf ("\n");
        
    fisher_yates_shuffle (deck);
    
    printf ("Shuffled deck:\n");
    print_deck (deck);
}