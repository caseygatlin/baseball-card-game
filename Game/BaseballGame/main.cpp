/* ************************
 * ** BASEBALL CARD GAME **
 * ************************
 * **   Programmed by    **
 * **   Casey Gatlin     **
 * ************************
 * **   Game Design by   **
 * **    Kanen Reuter    **
 * **         &          **
 * **    Casey Gatlin    **
 * ************************
 *
 * Created by Casey Gatlin on 9/20/18.
 * Copyright © 2018 Casey Gatlin. All rights reserved.
 */
#include "Game.h"
#include "GameClasses.h"




int main()
{

    int allGames = 5000;
    Results results = Results();
    results.setNumberOfGames(allGames);
    
    for (int totalGames = 0; totalGames < allGames; totalGames++)
    {
        CardDeck deck = CardDeck();
        deck.splitDeck();
        
        Player player1;
        Player player2;
        
        player1.setStartingDeck(deck.halfDeckP1);
        player2.setStartingDeck(deck.halfDeckP2);
        
        player1.removeJokerAndAces();
        player2.removeJokerAndAces();
        
        player1.shuffleStartDeck();
        player2.shuffleStartDeck();
        
        player1.setStartingAreas();
        player2.setStartingAreas();
        player1.setIsBatting(false);
        player2.setIsBatting(true);
        // Game is ready to go
        
        BoxScore boxScore = BoxScore();
        playGame(player1, player2, boxScore);
        
        results.calculateTotals(boxScore);
        
    }
    
    results.displayResults();
    
    
    return 0;
}
