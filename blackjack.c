#include "../luca-project-18/deck.h" //I had the ai do it
#include "stdbool.h"
#include <unistd.h>


void rules(void)
{
    printf("                                            THE OBJECT OF THE GAME:\n\n");

    printf("Participants attempt to beat the dealer by getting a count as close to 21 as possible, without going over 21.\n\n");

    printf("                                                CARD VALUE/SCORING\n\n");

    printf("It is up to each individual player if an ace is worth 1 or 11. Face cards are 10 and any other card is its pip value.\n\n");

    printf("                                                     BETTING\n\n");

    printf("Before the deal begins, each player places a bet, in chips, in front of them in the designated area. Minimum and maximum limits are\nestablished on the betting, and the general limits are from $2 to $500.\n\n");

    printf("                                                     THE DEAL\n\n");

    printf("When all the players have placed their bets, the dealer gives one card face up to each player in rotation clockwise, and then one card face\nup to themselves. Another round of cards is then dealt face up to each player, but the dealer takes the second card face down. Thus, each\nplayer except the dealer receives two cards face up, and the dealer receives one card face up and one card face down.\n\n");

    printf("                                                      NATURALS\n\n");

    printf("If a player's first two cards are an ace and a 'ten-card' (a picture card or 10), giving a count of 21 in two cards, this is a natural or 'blackjack.'\nIf any player has a natural and the dealer does not, the dealer immediately pays that player one and a half times the amount of their bet. If\nthe dealer has a natural, they immediately collect the bets of all players who do not have naturals, (but no additional amount). If the dealer\nand another player both have naturals, the bet of that player is a stand-off (a tie), and the player takes back his chips.\n\nIf the dealer's face-up card is a ten-card or an ace, they look at their face-down card to see if the two cards make a natural. If the face-up\ncard is not a ten-card or an ace, they do not look at the face-down card until it is the dealer's turn to play.\n\n");

    printf("                                                   THE PLAY\n\n");

    printf("The player to the left goes first and must decide whether to 'stand' (not ask for another card) or 'hit' (ask for another card in an\nattempt to get closer to a count of 21, or even hit 21 exactly). Thus, a player may stand on the two cards originally dealt to them, or they\nmay ask the dealer for additional cards, one at a time, until deciding to stand on the total (if it is 21 or under), or goes 'bust' (if it is\nover 21). In the latter case, the player loses and the dealer collects the bet wagered.\n\n");

    printf("                                                THE DEALER'S PLAY\n\n");

    printf("When the dealer has served every player, the dealer's face-down card is turned up. If the total is 17 or more, it must stand. If the\ntotal is 16 or under, they must take a card. The dealer must continue to take cards until the total is 17 or more, at which point the dealer\nmust stand. If the dealer has an ace, and counting it as 11 would bring the total to 17 or more (but not over 21), the dealer must count\nthe ace as 11 and stand.\n\n\n");

    printf("Please note that the deck is shuffled every hand.\n\n");

    char choic;
    printf("Enter Y when you're ready to continue.\ny ");
    (void)!scanf(" %c", &choic);
    if (choic == 'Y' || choic == 'y')
    {
        
    }
    else
    {
        printf("\nERR0R\n");
    }
}

void shuffle(deck *d)
{
    Deck_shuffle(&d);
    printf("\nDealer is shuffling.");
    fflush(stdout);
    usleep(500000);
    printf(".");
    fflush(stdout);
    usleep(500000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf("done!\n");
}

void deal(deck *d, card player[2], card dealer)
{
    Deck_deal(d, &player[0]);
    Deck_deal(d, &player[1]);
    Deck_deal(d, &dealer);
}

int main(void)
{
    char choice;
    printf("Would you like to see the rules?\n(Y/n) ");
    (void)!scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        rules();
    }
    else if (choice == 'N' || choice == 'n')
    {
    }
    else if (choice == 'N' || choice == 'n')
    {

    }
    else
    {
        printf("ERR0R");
        return 1;
    }
    // Making variables
    int bet;
    deck d;
    Deck_init(&d);
    card playerHand[2];
    card dealerUpCard;
    card dealerHidCard;
    bool GAMEOVER = 0;
    while(!GAMEOVER)
    {
        //Beting
        printf("\nHow much would you like to bet?\n");
        scanf("%d", &bet);
        if (bet > 500)
        {
            printf("Your bet is too high, lowering to 500.\n");
            bet = 500;
        }
        else
        {
            printf("Bet placed");
        }
        //Shuffling
        deck d;
        Deck_init(&d);
        shuffle(&d);
        GAMEOVER = true;
    }
    return 0;



    //WHAT HAPPENS IN A GAME
    //Betting
    //Shuffling
    //Dealing
    //Playing (player)
    //Playing (dealer)
    //quit (optional)

}