# include "MovieTree.h"
# include <iostream>

using namespace std;

MovieTree::MovieTree()
{
	root = NULL;
}

MovieTree::~MovieTree()
{
	DeleteAll(root);
	cout<<"Goodbye!"<<endl;
}

void MovieTree::printMovieInventory()
{   
	printMovieInventory(root);	
}
void MovieTree::printMovieInventory(MovieNode *node)
{	
	if(node->leftChild != NULL)
	{
		printMovieInventory(node->leftChild);
	}
	cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
	if(node->rightChild != NULL)
	{
		printMovieInventory(node->rightChild);
	}
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity,string genre)
{
	MovieNode *temp = root;
	MovieNode *parent = NULL;
	MovieNode *node = new MovieNode(ranking, title, releaseYear, quantity, genre);
		//find its place in the tree

	while(temp != NULL)
	{
		parent = temp;
		if(node->title.compare(temp->title) < 0)
		{
			temp = temp->leftChild;
		}
		else
		{
			temp = temp->rightChild;
		}
	}
	if(parent == NULL)//makes it the first node
	{
		root = node;
	}
	else if (node->title.compare(parent->title) < 0)
	{
		parent->leftChild = node;//add as left child
		node->parent = parent;
	}
	else//add to right
	{
		parent->rightChild = node;
		node->parent = parent;
	}

}

void MovieTree::findMovie(string title)
{
	MovieNode *node = root;
	while(node != NULL)//searches to bottom of tree
	{
		if(node->title.compare(title) > 0)
		{
			node = node->leftChild;
		}
		else if(node->title.compare(title) < 0)
		{
			node = node->rightChild;
		}
		else
		{
			cout<<"Movie Info:"<<endl;
			cout << "===========" << endl;
			cout << "Ranking:" << node->ranking << endl;
			cout << "Title:" << node->title << endl;
			cout << "Year:" << node->year << endl;
			cout << "Quantity:" << node->quantity << endl;
			return;//returns pointer to node in tree
		}

	}
	cout<<"Movie not found"<<endl;

}

void MovieTree::rentMovie(string title)
{
	MovieNode *node = root;
	while(node != NULL)//searches to bottom of tree
	{
		if(node->title.compare(title) > 0)
		{
			node = node->leftChild;
		}
		else if(node->title.compare(title) < 0)
		{
			node = node->rightChild;
		}
		else
		{
			if(node->quantity == 0)
			{
				cout<<"Movie is out of stock."<<endl;
				return;
			}
			node->quantity--;
			cout << "Movie has been rented." << endl;
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << node->ranking << endl;
			cout << "Title:" << node->title << endl;
			cout << "Year:" << node->year << endl;
			cout << "Quantity:" << node->quantity << endl;
			return;
		}

	}
	cout<<"Movie not found"<<endl;
}
void MovieTree::deleteMovieNode(string title)//if this seg-faults, the problem is in fourth case, two children.
{
	MovieNode *node = root;
	while(node != NULL)//searches to bottom of tree
	{
		if(node->title.compare(title) > 0)
		{
			node = node->leftChild;
		}
		else if(node->title.compare(title) < 0)
		{
			node = node->rightChild;
		}
		else
		{
			if(node->leftChild == NULL && node->rightChild == NULL)
			{
				if(node->parent->leftChild == node)
				{
					node->parent->leftChild = NULL;
				}
				else
				{
					node->parent->rightChild = NULL;
				}
				delete node;
				return;
			}
			else if(node->leftChild != NULL && node->rightChild == NULL)
			{
				if(node->parent->leftChild == node)
				{
					node->parent->leftChild = node->leftChild;
					node->leftChild->parent = node->parent;
				}
				else
				{
					node->parent->rightChild = node->leftChild;
					node->leftChild->parent = node->parent;
				}
				delete node;
				return;
			}
			else if(node->leftChild == NULL && node->rightChild != NULL)
			{
				if(node->parent->leftChild == node)
				{
					node->parent->leftChild = node->rightChild;
					node->rightChild->parent = node->parent;
				}
				else
				{
					node->parent->rightChild = node->rightChild;
					node->rightChild->parent = node->parent;
				}
				delete node;
				return;

			}
			else if(node->leftChild != NULL && node->rightChild != NULL)
			{
				MovieNode *node2 = node->rightChild;
				while(node2->leftChild != NULL)
				{
					node2 = node2->leftChild;
				}
				node->title = node2->title;
				node->ranking = node2->ranking;
				node->year = node2->year;
				node->quantity = node2->quantity;
				node = node->rightChild;
				title = node2->title;
			}

		}

	}
	cout<<"Movie not found"<<endl;

}
int MovieTree::countMovieNodes()
{
	int count = 0;
	countMovieNodes(root, &count/*& is the address of the variable auto assigned by computer*/);
	return count;
	cout<<"Tree contains: "<<countMovieNodes()<<" movies."<< endl;
}
void MovieTree::countMovieNodes(MovieNode *node, int *c)
{
	if(node->leftChild != NULL)
	{
		countMovieNodes(node->leftChild, c);
	}
	(*c)++;//increments the variable at node c not the actual pointer
	if(node->rightChild != NULL)
	{
		countMovieNodes(node->rightChild, c);
	}

}
void MovieTree::DeleteAll(MovieNode * node)
{
	if(node->leftChild != NULL)
	{
		DeleteAll(node->leftChild);
	}
	if(node->rightChild != NULL)
	{
		DeleteAll(node->rightChild);
	}
	cout<<"Deleting: "<<node->title<<endl;
	delete node;
}
void MovieTree::movieRecommend(string title)
{
	MovieNode *node = root;
	while(node != NULL)//searches to bottom of tree
	{
		if(node->title.compare(title) > 0)
		{
			node = node->leftChild;
		}
		else if(node->title.compare(title) < 0)
		{
			node = node->rightChild;
		}
		else
		{
			node->arraysize = 0;
			fillArray(node, root);
			for(int i = 0; i < 7; i++)
			{
				cout<<node->moviesarray[i]->title<<endl;
			}
			return;
		}

	}
	cout<<"Movie not found"<<endl;

}
void MovieTree::fillArray(MovieNode *master, MovieNode *node)
{

	if(node->leftChild != NULL)
	{
		fillArray(master, node->leftChild);
	}
	if(node->rightChild != NULL)
	{
		fillArray(master, node->rightChild);
	}
	if(master->genre == node->genre && master->arraysize < 7)
	{

		master->moviesarray[master->arraysize] = node;
		master->arraysize++;

	}
}
