#include "../luca-project-18/deck.h" //I had the ai do it
#include <stdbool.h>
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

    printf("                                                   DOUBLING DOWN\n\n");

    printf("Another option open to the player is doubling their bet when they haven't hit a single time. When the player's turn comes,\nthey place a bet equal to the original bet, and the dealer gives the player just one card, which is placed face down and is not turned up until\nthe bets are settled at the end of the hand.\n\n");

    printf("Please note that the deck is shuffled every hand. Also, your final score is how much money you won/lost.\n Additionally, naturals get no special treatment. Finally, aces are 11.\n\n");

    char choic;
    printf("Enter Y when you're ready to continue.\n ");
    (void)!scanf(" %c", &choic);
    if (choic == 'Y' || choic == 'y')
    {
        
    }
    else
    {
        printf("\nERR0R\n");
    }
}

// Prints a card as "<a|an> <Rank> of <Suit>", e.g. "a Jack of Clubs".
void printCard(card c)
{
    static const char *rankNames[] = {"Ace", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suitName;
    switch (c.suit)
    {
        case 'S':
            suitName = "Spades";
            break;
        case 'H':
            suitName = "Hearts";
            break;
        case 'D':
            suitName = "Diamonds";
            break;
        case 'C':
            suitName = "Clubs";
            break;
        default:
            suitName = "???";
            break;
    }
    printf("%s %s of %s", (c.rank == 1 || c.rank == 8) ? "an" : "a", rankNames[c.rank - 1], suitName);
}

// Best total of a hand: face cards are 10 and aces are 11,
// downgraded to 1 whenever 11 would bust the hand.
int handTotal(card hand[8], int count)
{
    int total = 0;
    int aces = 0;
    for (int i = 0; i < count; i++)
    {
        if (hand[i].rank == 1)
        {
            aces++;
            total += 11;
        }
        else if (hand[i].rank > 10)
        {
            total += 10;
        }
        else
        {
            total += hand[i].rank;
        }
    }
    while (total > 21 && aces > 0)
    {
        total -= 10;
        aces--;
    }
    return total;
}

int dealerPlay(card cards[8], deck *d)
{
    int count = 2;
    int total;
    Deck_deal(d, &cards[1]);
    total = handTotal(cards, count);
    // The dealer must draw until the total is 17 or more, then stand.
    while (total < 17 && count < 8)
    {
        Deck_deal(d, &cards[count]);
        count++;
        total = handTotal(cards, count);
    }
    if (total > 21)
    {
        return 0; // the dealer went broke (a real total is never 0)
    }
    return total;
}

void shuffle(deck *d)
{
    Deck_shuffle(d);
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

void creepyMessage(void)
{
    printf("I know where you live.");
    fflush(stdout);
    sleep(3);
    printf("\033[2K");
    fflush(stdout);
    printf("\rI'm coming for you.");
    fflush(stdout);
    sleep(3);
    printf("\033[2K\r");
    fflush(stdout);
}

void deal(deck *d, card player[8], card *dealer, int *cardCount)
{
    Deck_deal(d, dealer);
    printf("\nDealer is dealing.");
    fflush(stdout);
    usleep(500000);
    printf(".");
    fflush(stdout);
    usleep(500000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf("done!\n");
    for (int i = 0; i < 8; i++)
    {
        player[i].rank = 0;
        player[i].suit = 'N';
    }
        Deck_deal(d, &player[0]);
    Deck_deal(d, &player[1]);
    *cardCount += 2;
}

void displayCards(card playerCards[8], card dealerCard[8])
{
    printf("The cards you have on the table are:");
    for (int i = 0; i < 8; i++)
    {
        if (playerCards[i].rank == 0)
        {
            continue; // a a4, a a5, a a6, ... a a9
        }
        printf(" ");
        printCard(playerCards[i]);
        printf(",");
    }
    printf(" and the dealer's face-up card is ");
    printCard(dealerCard[0]);
    printf("\n");
}

int brokeCheck(card hand[8], int count, int *playerCardTotal)
{
    *playerCardTotal = handTotal(hand, count);
    return *playerCardTotal > 21;
}

int main(void)
{
    char choice;
    printf("Would you like to see the rules?\n(Y/n) ");
    (void)!scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        rules();
    }
    else if (choice == 'N' || choice == 'n')
    {

    }
    else
    {
        sleep(2);
        creepyMessage();
        printf("ERR0R");
        return 1;
    }
    // Making variables
    int bet = 0;
    deck d;
    Deck_init(&d);
    card playerHand[8];
    int cardCount = 0;
    int playerCardTotal = 0;
    card dealerUpCards[8];
    bool QUIT = 0;
    bool BET = 0;
    bool STAND = 0;
    bool hit = 0;
    bool BROKE = 0;
    int score = 0;
    int dPlay = 0;
    while(!QUIT)
    {
        cardCount = 0;
        //Beting
        if(!BET)
        {
            printf("\nHow much would you like to bet?\n");
            if (scanf("%d", &bet) != 1)
            {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("That is not a number, betting the minimum(2).\n");
                bet = 2;
            }
            if (bet > 500)
            {
                printf("Your bet is too high, lowering to 500.\n");
                bet = 500;
            }
            else if (bet < 2)
            {
                printf("Your bet is too low, raising to 2.");
                bet = 2;
            }
            else
            {
                printf("Bet placed");
            }
            BET = true;
        }
        //Shuffling
        shuffle(&d);
        //dealing
        deal(&d, playerHand, &dealerUpCards[0], &cardCount);
        STAND = false;
        BROKE = false;
        while(!STAND && !BROKE)
        {
            if (brokeCheck(playerHand, cardCount, &playerCardTotal))
            {
                printf("You went broke after getting ");
                printCard(playerHand[cardCount - 1]);
                printf(". You lost %d$\n\n", bet);
                BROKE = true;
                score -= bet;
                break;
            }
            displayCards(playerHand, dealerUpCards);
            printf("Do you want to stand(s), hit(h), or Double Down(d)?\n");
            (void)!scanf(" %c", &choice);
            if (choice == 's' || choice == 'S')
            {
                // let the dealer play
                STAND = true;
            }
            else if (choice == 'h' || choice == 'H')
            {
                if (cardCount < 8)
                {
                    Deck_deal(&d, &playerHand[cardCount]);
                    hit = true;
                    cardCount++;
                }
                else
                {
                    printf("Your hand is full, you have to stand.\n");
                    STAND = true;
                }
            }
            else if (choice == 'd' || choice == 'D')
            {
                if (hit != true)
                {
                    bet = bet * 2;
                    Deck_deal(&d, &playerHand[cardCount]);
                    printf("You drew ");
                    printCard(playerHand[cardCount]);
                    printf(".\n\n");
                    fflush(stdout);
                    cardCount += 1;
                    STAND = 1;
                    if (brokeCheck(playerHand, cardCount, &playerCardTotal))
                    {
                        printf("You went broke and lost %d$ after getting ", bet);
                        printCard(playerHand[cardCount]);
                        printf("\n\n");
                        fflush(stdout);
                        BROKE = true;
                    }
                }
                else
                {
                    printf("Speaking Yoda you to is. Down Doubling valid not at time this.\n");
                }
            }
            else if (choice == 'a' || choice == 'A')
            {
                printf("Your score is %d\n", score);
            }
            
            else
            {
                printf("ERROR\n");
                sleep(2);
                creepyMessage();
            }
        }
        sleep(3);
        //Dealer plays.
        if (!BROKE)
        {
            dPlay = dealerPlay(dealerUpCards, &d);
            if (dPlay == 0)
            {
                printf("The dealer went broke!!! -(^v^)-\nYour score has been updated.\n");
                score += bet;
            }
            else
            {
                if (dPlay >= playerCardTotal)
                {
                    printf("The dealer drew until they got a total of %d, and your total was %d.\nBecause your total was lower(or equal to) the dealer's, you lost your bet(%d)\n.\n\n\n", dPlay, playerCardTotal, bet);
                    score -= bet;
                }
                else
                {
                    printf("The dealer drew until they got a total of %d, and your total was %d.\nBecause your total was higher, you gained your bet(%d)!\n\n\n", dPlay, playerCardTotal, bet);
                    score += bet;
                }
            }
        }
        else
        {
            printf("It doesn't matter if the dealer went broke, you still lost your bet. Therefore, it isn't displayed\n");
        }
        //Ask if the player wants to quit.
        printf("Would you like to quit and score now?\n(Y/n)");
        (void)!scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            QUIT = true;
        }
        else if (choice == 'n' || choice == 'N')
        {
            // the deck is shuffled and the cards are dealt at the top of the loop
        }
        else if (choice == 'a' || choice == 'A')
        {
            score += 20;
            printf("Your score is now %d", score);
        }
        BET = false;
        hit = false;
    }
    printf("Your final score is %d.\n", score);
    fflush(stdout);
    sleep(2);
    creepyMessage();

    return 0;
    //WHAT HAPPENS IN A GAME
    //Betting
    //Shuffling
    //Dealing
    //Playing (player)
    //Playing (dealer)
    //quit (optional)

}