#include "deck.h"

/* compare_cards -Compare function for qsort 
*@a: first qsort
*@b: second qsort
*/
int compare_cards(const void *a, const void *b) 
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    if (card_a->kind == card_b->kind) {
        return strcmp(card_a->value, card_b->value);
    } else {
        return (int)(card_a->kind - card_b->kind);
    }
}

/* sort_deck - function sorts a deck
* of cards using the provided data structures
*@*deck: a deck of cards
*/

void sort_deck(deck_node_t **deck) 
{
    // Count the number of cards in the deck
    int count = 0;
    deck_node_t *current = *deck;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Create an array of pointers to the deck nodes
    deck_node_t **card_array = (deck_node_t **)malloc(count * sizeof(deck_node_t *));
    current = *deck;
    int i = 0;
    while (current != NULL) {
        card_array[i] = current;
        current = current->next;
        i++;
    }

    // Sort the array using qsort
    qsort(card_array, count, sizeof(deck_node_t *), compare_cards);

    // Reconstruct the sorted deck
    *deck = card_array[0];
    current = *deck;
    for (i = 1; i < count; i++) {
        current->next = card_array[i];
        card_array[i]->prev = current;
        current = current->next;
    }
    current->next = NULL;

    // Free the temporary array
    free(card_array);
}
