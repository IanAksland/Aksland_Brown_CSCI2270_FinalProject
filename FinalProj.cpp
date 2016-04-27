# include "MovieTree.h"
# include <iostream>
# include <fstream>
# include <sstream>
using namespace std;


int userinput = 0;

int main(int argc, char *argv[])
{
	MovieTree movtree;

	ifstream file;
	file.open(argv[1]);
	string movieline;
	while(getline(file, movieline))
	{
		stringstream streamsent(movieline);
		string rating;
		string title;
		string year;
		string quantity;
		string genre;
		getline(streamsent, rating, ',');
		getline(streamsent, title, ',');
		getline(streamsent, year, ',');
		getline(streamsent, quantity, ',');
		getline(streamsent, genre, ',');
		movtree.addMovieNode(stoi(rating), title, stoi(year), stoi(quantity), genre);
	}
	

	while(userinput != 7)
	{	cout << "======Main Menu======" << endl;
		cout << "1. Find a movie" << endl;
		cout << "2. Rent a movie" << endl;
		cout << "3. Print the inventory" << endl;
		cout << "4. Delete a movie" << endl;
		cout << "5. Count the movies" << endl;
		cout << "6. Recommend movies" << endl;
		cout << "7. Quit" << endl;

		string ui;
		getline(cin, ui);
		userinput = stoi(ui);

		if(userinput == 1)
		{
			string movie;
			cout<< "Enter title:" << endl;
			getline(cin, movie);
			movtree.findMovie(movie);
		}
		if(userinput == 2)
		{
			string movie;
			cout<< "Enter title:" << endl;
			getline(cin, movie);
			movtree.rentMovie(movie);
		}
		if(userinput == 3)
		{
			movtree.printMovieInventory();
		}
		if(userinput == 4)
		{
			string movie;
			cout<<"Enter title:"<<endl;
			getline(cin, movie);
			movtree.deleteMovieNode(movie);
		}
		if(userinput == 5)
		{
			cout<<"Tree contains: "<<movtree.countMovieNodes()<<" movies."<< endl;
		}
		if(userinput == 6)
		{
			string movie;
			cout<<"Enter title:"<<endl;
			getline(cin, movie);
			cout<< "We think you would like these movies!!!" <<endl;
			movtree.movieRecommend(movie);
		}

	}
}