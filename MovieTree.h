#ifndef MOVIETREE_H
#define MOVIETREE_H
# include <iostream>
struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    std::string genre;
    int arraysize;
    MovieNode *parent; 
    MovieNode *leftChild;
    MovieNode *rightChild;
    MovieNode *moviesarray[7];

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity, std::string in_genre)
    {
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        genre = in_genre;
    }

};

class MovieTree
{
    public:
        MovieTree();
        ~MovieTree();
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(std::string title);
        void addMovieNode(int ranking, std::string title, int releaseYear, int quantity, std::string genre);
        void findMovie(std::string title);
        void rentMovie(std::string title);
        void fillArray(MovieNode *master, MovieNode *node);
        void movieRecommend(std::string title);

    protected:
    private:
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(MovieNode * node);
        void countMovieNodes(MovieNode *node, int *c);
        MovieNode* search(std::string title);
        MovieNode *root;

};

#endif // MOVIETREE_H