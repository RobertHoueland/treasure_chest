/*****************************************************
   ** Program: assign5_treasure.cpp
   ** Author: Robert Houeland
   ** Date: 3/8/2020
   ** Description: A treasure chest of water bottles that the user can control.
   ** Input: Changes to the treasure chest.
   ** Output: Shows layout of the treasure chest, and the value of the items.
   *****************************************************/

#include <iostream>  
#include <string>    
#include <cstdlib>   /* for srand() */
#include <ctime>  /* for time() */

using namespace std;

struct waterBottle {
   /* Color is a string because the user will type in the color */
   string color;
   /* Size is float because the water bottle mL could be any float */
   float size;
   /* Brand is a string because the user will type in brand */
   string brand;
   /* Value can be any float */
   float value;
};


/*******************************************************************
   ** Function: addItem
   ** Description: Adds an item to treasure chest of user's desired location
   ** Parameters: Takes in an array of struct type, and a row and column.
   ** Pre-Conditions: Needs 2D dynamic array of struct type, and row and column count.
   ** Post-Conditions: Changes value of array at given location. 
   *******************************************************************/
void addItem(waterBottle* arr[], short addRow, short addColumn){  
   cout << "Enter color of water bottle (string): ";
   cin.ignore(1,'\n');
   getline(cin, arr[addRow][addColumn].color); 
   cout << "Enter size of water bottle (float, fluid ounces): ";
   cin >> arr[addRow][addColumn].size;
   cout << "Enter brand (string): ";
   cin.ignore(1,'\n');
   getline(cin, arr[addRow][addColumn].brand);
   cout << "Enter value (float, USD): $";
   cin >> arr[addRow][addColumn].value;
}


/*******************************************************************
   ** Function: removeItem
   ** Description: Removes an item from treasure chest of user's desired location
   ** Parameters: Takes in an array of struct type, and a row and column.
   ** Pre-Conditions: Needs 2D dynamic array of struct type, and row and column count.
   ** Post-Conditions: Changes value of array at given location.
   *******************************************************************/
void removeItem(waterBottle* arr[], short removeRow, short removeColumn){  
   arr[removeRow][removeColumn].color = "";
   arr[removeRow][removeColumn].size = 0;
   arr[removeRow][removeColumn].brand = "";
   arr[removeRow][removeColumn].value = 0;
}


/*******************************************************************
   ** Function: randomItem
   ** Description: Creates an item with random attributes.
   ** Parameters: Takes in an array of struct type, and a row and column.
   ** Pre-Conditions: Needs 2D dynamic array of struct type, and row and column count.
   ** Post-Conditions: Changes value of array at given location.
   *******************************************************************/
void randomItem(waterBottle* arr[], short randomRow, short randomColumn){ 
   short randSize = rand() % 41 + 1; 
   float randValue = float(rand() % 10000)/100 + 1;
   short digit = rand() % 4;
   arr[randomRow][randomColumn].size = randSize;
   arr[randomRow][randomColumn].value = randValue;
   if (digit == 0)
   {
      arr[randomRow][randomColumn].color = "Red";
      arr[randomRow][randomColumn].brand = "Hydroflask";
   }
   if (digit == 1)
   {
      arr[randomRow][randomColumn].color = "Blue";
      arr[randomRow][randomColumn].brand = "Thermoflask";
   }
   if (digit == 2)
   {
      arr[randomRow][randomColumn].color = "Black";
      arr[randomRow][randomColumn].brand = "Dasani";
   }
   if (digit == 3)
   {
      arr[randomRow][randomColumn].color = "White";
      arr[randomRow][randomColumn].brand = "Thermoflask";
   }
}


/*******************************************************************
   ** Function: displayItem
   ** Description: Displays a item of desired location and attributes.
   ** Parameters: Takes in an array of struct type, and a row and column.
   ** Pre-Conditions: Needs 2D dynamic array of struct type, and row and column count.
   ** Post-Conditions: Returns information about an item at given location.
   *******************************************************************/
void displayItem(waterBottle* arr[], short displayRow, short displayColumn){  
   cout << "Water Bottle info:" << endl;
   cout << "Color: " << arr[displayRow][displayColumn].color << endl;
   cout << "Size: " << arr[displayRow][displayColumn].size << " mL" << endl;
   cout << "Brand: " << arr[displayRow][displayColumn].brand << endl;  
   cout << "Value: " << arr[displayRow][displayColumn].value << endl;
}


/*******************************************************************
   ** Function: moveItem
   ** Description: Moves an item to a new location.
   ** Parameters: Takes in an array of struct type, and two rows and columns.
   ** Pre-Conditions: Needs 2D dynamic array of struct type, and 2 rows and 2 columns.
   ** Post-Conditions: Replaces the second row and column with the first.
   *******************************************************************/
void moveItem(waterBottle* arr[], short r1, short c1, short r2, short c2){
   arr[r2][c2].color = arr[r1][c1].color;
   arr[r2][c2].size = arr[r1][c1].size;
   arr[r2][c2].brand = arr[r1][c1].brand;
   arr[r2][c2].value = arr[r1][c1].value;
}


int main()
{
   srand(time(NULL));
   /* Used shorts for variables because inputs could be within limits of short
    * size and need signed to check for invalid negative user input
    */
   short n_rows;
   short n_columns;
   cout << "Welcome to The Treasure Chest of Water Bottles!" << endl;
   
   do{   /* Use do while loops to check user input */
   cout << "Enter number of rows for treasure chest: ";
   cin >> n_rows;
   if (n_rows < 1)
      cout << "Invalid input. Please retry." << endl;
   } while (n_rows < 1);

   do{
   cout << "Enter number of columns for treasure chest: ";
   cin >> n_columns;
   if (n_columns < 1)
      cout << "Invalid input. Please retry." << endl;
   } while (n_columns < 1);

   /* Create dynamic 2D array using user input rows and columns made of struct 
    * First initalizes rows, and then dooes columns
    */
   waterBottle** treasureChest = new waterBottle*[n_rows];
   for (short i = 0; i < n_rows; i++)
      treasureChest[i] = new waterBottle[n_columns];  

   /* Fill in blank NULL values */
   for (short i = 0; i < n_rows; i++)
   {
      for (short j = 0; j < n_columns; j++)
      {
         treasureChest[i][j].color = "";
         treasureChest[i][j].size = 0;
         treasureChest[i][j].brand = "";
         treasureChest[i][j].value = 0;
      }
   }

   short choice;
   do{   /* Loop to keep showing treasure chest and options until user quits */
   /* Print array */
   cout << endl;
   cout << "Treasure Chest of Water Bottles: (sizes are shown, in mL)" << endl;
   for (short i = 0; i < n_rows; i++){
      for (short j = 0; j < n_columns; j++)
        cout << "|" << treasureChest[i][j].size;
      cout << "|" << endl;
   }

   /* Computes total value of every item and number of items*/
   float totalValue = 0;
   short totalItems = 0;
   for (short i = 0; i < n_rows; i++)
   {
      for (short j = 0; j < n_columns; j++){
         if (treasureChest[i][j].size > 0){
            totalValue += treasureChest[i][j].value;
            totalItems += 1;
         }
      }
   }
   if (totalItems == 1){
      cout << "Total value of " << totalItems << " water bottle: $";
      cout << totalValue << endl;
   }
   /* Only says "bottle" for 1 bottle, and "bottles" for any more */
   else{
      cout << "Total value of " << totalItems << " water bottles: $";
      cout << totalValue << endl;
   }

   cout << "Options: 1. Add, 2. Remove, 3. Add random water bottle, ";
   cout << "4. Show water bottle data, 5. Move, 0. Quit" << endl;
   cin >> choice;

   /* Luck aspect */
   short luck = rand() % 10;
   if (luck == 0)
   {
      cout << "Oh no! You were robbed! There was a 10% chance of this!" << endl;
      cout << "All of your water bottles have been stolen, and your treasure";
      cout << " chest is empty now. " << endl;
      cout << endl;

      for (short i = 0; i < n_rows; i++)
      {
         for (short j = 0; j < n_columns; j++)
         {
            treasureChest[i][j].color = "";
            treasureChest[i][j].size = 0;
            treasureChest[i][j].brand = "";
            treasureChest[i][j].value = 0;
         }
      }
   }

   if (choice == 1)
   {
      short addRow;
      short addColumn;

      do{
      cout << "Enter row to add water bottle to: ";
      cin >> addRow;
      if (addRow < 1 || addRow > n_rows)
         cout << "Invalid input. Please retry." << endl;
      } while (addRow < 1 || addRow > n_rows);
      /* Had to take 1 away from each row and column the user input
       * to account for row and column 0 
       */
      addRow--;

      do{
      cout << "Enter column to add water bottle to: ";
      cin >> addColumn;  
      if (addColumn < 1 || addColumn > n_columns)
         cout << "Invalid input. Please retry." << endl;
      } while (addColumn < 1 || addColumn > n_columns);
      addColumn--;  

      addItem(treasureChest, addRow, addColumn);
   }
  
   if (choice == 2)
   {
      short removeRow;
      short removeColumn;

      do{
      cout << "Enter row to remove water bottle from: ";
      cin >> removeRow;
      if (removeRow < 1 || removeRow > n_rows)
         cout << "Invalid input. Please retry." << endl;
      } while (removeRow < 1 || removeRow > n_rows);
      removeRow--;

      do{
      cout << "Enter column to remove water bottle from: ";
      cin >> removeColumn;
      if (removeColumn < 1 || removeColumn > n_columns)
         cout << "Invalid input. Please retry." << endl;
      } while (removeColumn < 1 || removeColumn > n_columns);
      removeColumn--;

      removeItem(treasureChest, removeRow, removeColumn);
   }
  
   if (choice == 3)
   {
      short randomRow;
      short randomColumn;

      do{
      cout << "Enter row to add random water bottle to: ";
      cin >> randomRow;
      if (randomRow < 1 || randomRow > n_rows)
         cout << "Invalid input. Please retry." << endl;
      } while (randomRow < 1 || randomRow > n_rows);
      randomRow--;

      do{
      cout << "Enter column to add random water bottle to: ";
      cin >> randomColumn;
      if (randomColumn < 1 || randomColumn > n_columns)
         cout << "Invalid input. Please retry." << endl;
      } while (randomColumn < 1 || randomColumn > n_columns);
      randomColumn--;

      cout << endl;
      randomItem(treasureChest, randomRow, randomColumn);

      cout << "Random water bottle:" << endl;
      cout << "Color: " << treasureChest[randomRow][randomColumn].color << endl;
      cout << "Size: " << treasureChest[randomRow][randomColumn].size << " mL";
      cout << endl;
      cout << "Brand: " << treasureChest[randomRow][randomColumn].brand << endl;
      cout << "Value: $" << treasureChest[randomRow][randomColumn].value << endl;
   }

   if (choice == 4)
   {
      short viewRow;
      short viewColumn;

      do{
      cout << "Enter row to view water bottle at: ";
      cin >> viewRow;
      if (viewRow < 1 || viewRow > n_rows)
         cout << "Invalid input. Please retry." << endl;
      } while (viewRow < 1 || viewRow > n_rows);
      viewRow--;

      do{
      cout << "Enter column to view water bottle at: ";
      cin >> viewColumn;
      if (viewColumn < 1 || viewColumn > n_columns)
         cout << "Invalid input. Please retry." << endl;
      } while (viewColumn < 1 || viewColumn > n_columns);
      viewColumn--;

      displayItem(treasureChest, viewRow, viewColumn);
	}

	if (choice == 5)
	{
		short moveRow1;
		short moveColumn1;
		short moveRow2;
		short moveColumn2;

		do{
			cout << "Enter row to take water bottle from: ";
			cin >> moveRow1;
			if (moveRow1 < 1 || moveRow1 > n_rows)
				cout << "Invalid input. Please retry." << endl;
		} while (moveRow1 < 1 || moveRow1 > n_rows);

		do{
			cout << "Enter column to take water bottle from: ";
			cin >> moveColumn1;
			if (moveColumn1 < 1 || moveColumn1 > n_columns)
				cout << "Invalid input. Please retry." << endl;
		} while (moveColumn1 < 1 || moveColumn1 > n_columns);

		do{
			cout << "Enter row to move water bottle to: ";
			cin >> moveRow2;
			if (moveRow2 < 1 || moveRow2 > n_rows)
				cout << "Invalid input. Please retry." << endl;
		} while (moveRow2 < 1 || moveRow2 > n_rows);

		do{
			cout << "Enter column to move water bottle to: ";
			cin >> moveColumn2;
			if (moveColumn2 < 1 || moveColumn2 > n_columns)
				cout << "Invalid input. Please retry." << endl;
		} while (moveColumn2 < 1 || moveColumn2 > n_columns);

		moveItem(treasureChest, moveRow1, moveColumn1, moveRow2, moveColumn2);
	}

	/* Check for invalid input */
	if (choice < 0 || choice > 5)
		cout << "Invalid choice." << endl;

	} while (choice != 0);

	/* Free memory */
	for (short i = 0; i < n_rows; i++){
		delete [] treasureChest[i];
	}
	delete [] treasureChest;
	treasureChest = NULL;

	return 0;
}