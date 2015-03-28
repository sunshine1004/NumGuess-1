//A game of guessing numbers

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(){
	char yn;
	int num[3], guess[3]; // define 2 arraies, one is a rand array, the other is a guessing array.
	int i=0, j, tmp, a, b, gtime, wintime=0, playtime=0;   
	//tmp is a middle variable. When tmp is different from the former numbers, its value is assigned to the new variable.
	bool flag = false;  // used in controling generating 3 different numbers.
	
	srand((unsigned)time(NULL));
	
	do {
		// to generate 3 different numbers
		i = 0;
		while (i<=2){      
			flag = false;
			tmp = rand() % 10;
			for (j=0; j<i; ++j){
				if ( tmp == num[j] )  flag = true;
			}
			if (flag == false) {
				num[i] = tmp;
				++i;
			}
		}	
		
		// to get the order whether to execute the game.
		cout << "Do you need to play the game?(Y/N)?";
		cin >> yn;
		
		if (yn=='N') 
			cout << "In all, you have played " << playtime << " times. You have won " << wintime 
			<<" times, and you have lost " << playtime - wintime << " times" << endl ; 
		else{
			for (gtime=0; gtime<7; ++gtime){
				a = 0;   b = 0;
				cout << "Please input the 3 numbers you guess: " << endl;
				cin >>  guess[0] >> guess [1] >> guess [2];
	
				for (j=0; j<3; ++j){
					if ( num[j]==guess[j] ) ++a;
				}
	
				for (i=0; i<3; ++i){
					for (j=0; j<3; ++j){
						if ( num[i]==guess[j] ) ++b;
					}
				}
				b = b - a;
			
				if (a==3){
					cout << "Congratulations! Your guess is right! " << endl;
					wintime += 1;
					break;
				} 
			
				cout << a << 'A' << b << 'B' << endl;
				
				if ( gtime == 6){
					cout << "Sorry, your have not guessed correctly in 7 times. The answer is "	<< num[0] << num[1] << num[2] << endl;
				}
			}
			playtime += 1;
		}	
		
	} while (yn == 'Y');
	 
	return 0;
} 
