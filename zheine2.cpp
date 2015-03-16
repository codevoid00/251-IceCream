#include<cstdlib>
#include<cstdio>
#include<cstring>

int main()
{

	return 0;
}


Update:

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct adjNode
{
	int val;
	struct adjNode* next;
}adjNode;

typedef struct adjList
{
	struct adjNode *head;
}adjList;

void initGraph(adjList* &arr, int size)
{
	int i;
	arr = new adjList [size+1];
	for(i = 1; i < (size+1); i++)
		arr[i].head = NULL;


}

void addNode(adjList* &arr, int x,  int index)
{
	adjNode* newNode = new adjNode;
	newNode->val = x;
	newNode->next = NULL;
	//first case: empty list
	if(arr[index].head == NULL)
	{
		arr[index].head = newNode;
	}
	else //just add it to the end of the current index
	{
		//create a walker node that will walk to the final node and then append our new node to it
		adjNode* walker = arr[index].head;
		while(walker->next)
			walker = walker->next;
		walker->next = newNode;
	}
	

}
void printGraph(adjList* &arr, int size)
{

    int v;

    for (v = 0; v < size+1; ++v)

    {

	    adjNode* pCrawl = arr[v].head;

        cout<<"\n Adjacency list of vertex "<<v<<"\n head ";

        while (pCrawl)
        {

            cout<<"-> "<<pCrawl->val;

            pCrawl = pCrawl->next;

        }

        cout<<endl;

    }

}
int inSet(adjList* &arr, int x, int index)//Check to see if a value exists within the current index
{
	adjNode* walker = arr[index].head;
	while(walker->next)
	{
		if(walker->val == x)
			return 1;
		walker = walker->next;
	}
	return 0;
}

void addToSolution(int* &solution, adjList* &arr, int index)//add the current index's values to our list
{
	adjNode* walker = arr[index].head;
	while(walker)
	{
		solution[walker->val] = walker->val;
		walker = walker->next;
	}
}

int solutionFound(int* &solution, int size)
{
	int i = 0;
	while(i < size +1)
	{
		if( solution[i] != i)
			return 0;
		i++;
	}
	return 1;
}

void clearSolution(int* &solution, int size)
{
	int i;
	for(i = 0; i < size +1; i++)
		solution[i] = 0;
	
}

int nonTakenVert(int* &solutionSet)
{
	int i = 1;
	while(i < size +1)
	{
		if(solution[i] != i)
			return i;
		i++;
	}
	return 0;
}

typedef struct solToken{
	int *sol;
}solToken;


void minDomSet(adjList* &arr, int size)//fuctin currently being worked on...
{
	//see if any pairs match up for small numbers and store all possible small values
	//as the result. You won't need to go any higher since we're only looking for the min
	int enabled = 1;
	int currentSetSize = 1;
	int *solution = (int*)malloc(sizeof(int)*currentSetSize);//to have the co-ords of the solution
	int solutionSet[size+1];
	clearSolution(solutionSet);
	int currentVert = nonTakenVert(solutionSet);
	adjNode* temp;
	solToken *
	int i = 0;
	if(currentVert > 0)
	{
		//find the next arr element that contains that current vert
		temp = arr[currentVert].head
		while(!inSet(arr, currentVert, size))
			currentVert++;
		addToSolution(arr, solutionSet, currentVert);
		solution[i++] = currentVert
	}

	//while(enabled)
	//{
		//If(inset)
			//addVerts()tosultion
	//}
	//check for solutions of size 1, then move on if you don't find anything.

}

int main(int argc, char* argv[])
{
	int size;
	int tempVal[2] = {0};
	char filename[15];
	adjList* adjArray;// = (elem*)malloc(sizeof(elem)*size);
	cout << "Pleae enter the file name: ";
	cin.getline(filename, 15, '\n');
	//cout << filename;
	ifstream file(filename);
	int i = 1;
	int newIdxBool = 1;


	file >> size;
	initGraph(adjArray, size);
	cout << size << endl;

	while(file >> tempVal[1])//as long as there are values being read from the files )
	{

		//cout << tempVal;
		if(tempVal[1] > tempVal[0])//If our current value is greater than our previous value
		{
			//continue adding the element to our current adjacency list index
			addNode(adjArray, tempVal[1], i);
			tempVal[0] = tempVal[1];
		}
		else
		{
			if(newIdxBool)//if we're starting at the beginning or just going through the points
			{
				i++;
				newIdxBool = 0;
			}
			else
				newIdxBool = 1;

			addNode(adjArray, tempVal[1], i);
			tempVal[0] = tempVal[1];
			//else increment index and start adding elements to that index
		}
	}
	printGraph(adjArray, size);

	//system("PAUSE");
	return 0;

}
