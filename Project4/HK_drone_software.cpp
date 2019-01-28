//HK Drone Software (Binary Search)
//Allows input and output
#include <iostream>

//Includes functions involving memory allocation, process control, conversions and others
#include <cstdlib>

//Needed for random numbers
#include <time.h>

//Allows me to avoid retyping std namespace infront of each function that uses it
using namespace std;

//Lets me break a line with specified characters and not have to repeat myself as much
#define BREAKLINE cout << "=======================================================" << endl;

int main()
{
	//Generating the random enemy location on 8x8 grid
	cout << "Generating Random enemy location on 8x8 grid..." << endl;
	
	//Randomizing the number by help of seeding using ctime
	srand(time(0));

	//Randomizing the number between 1-64
	//Same pattern without srand to seed the random number sequence
	//Setting the high number for the grid
	int searchGridHighNumber = 64;
	//Setting the low number for the grid
	int searchGridLowNumber = 1;
	//Setting the prediction for the binary search
	int targetLocationPrediction;
	//Setting the enemy's location randomly using rand()
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	cout << "The enemy is located at #" << enemyLocation << " on 8x8 frid with 1-64 sectors." << endl;

	cout << "Skynet HK Drone Software Initializing software..." << endl;
	//Number of target location predictions it took to find enemy location
	int targetLocationPredictionCounter = 0;
	//Is the enemy found and taken care of
	bool targetFound = false;

	//Loop for finding the enemy
	while (targetFound == false) 
	{

		//Softeare selection target location prediction in flyover hunt for enemy
		cout << "Skynet HK Drone Radar sending out ping #" << targetLocationPredictionCounter << endl;

		//Radar Ping of enemy location
		//Binary Search
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//In this simulation thing ping tells the user if the target loaction is higher or lower
		//or right on the enemy location. If target location predicition is higher than enemy location

		if (targetLocationPrediction > enemyLocation)
		{
			//The target location prediction was higher than the enemyLocation
			//no need to search anymore at or above target location prediction
			//reset the searchGridHighNumber of the search grid.
			//We subtract 1 because we don't need to search the number guessed
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of "
				<< enemyLocation << endl;
			searchGridHighNumber = targetLocationPrediction - 1;
			targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCounter + 1;

			//The breakline that was assigned above
			BREAKLINE;

		}
		else if (targetLocationPrediction < enemyLocation)
		{
			//The target location prediction was lower than the enemyLocation
			//no need to search anymore at or below the target location prediction.
			//We add 1 because we don't needd to search the number guessed.
			cout << "The target location prediction of " << targetLocationPrediction
				<< " was lower than the actual enemy location of " << enemyLocation << endl;
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "searchGridLowNumber: " << searchGridLowNumber << endl;
			targetLocationPredictionCounter++; //targetLocationPredictionCounter = targetLocationPredictionCOunter + 1;

			//The breakline that was assigned above
			BREAKLINE;

		}
		else
		{
			cout << "Enemy was hiding at Sector #" << enemyLocation << endl;
			cout << "Enemy was found at Sector #" << enemyLocation << endl;
			cout << "Skynet took " << targetLocationPredictionCounter
				<< " predictions to find the enemy location on a grid size of 8x8 (64)" << endl;
			//End the loop when true
			targetFound = true;
		}


	}

	system("pause");


	return 0;
}