#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label;
    list<int> neighbors;
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=9;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=1;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        nodes[u].neighbors.push_back(v);
        nodes[v].neighbors.push_back(u);
        //select node v and push u into v's neighbour
    }

    void print(){
        for (int i = 1; i < n; i++){
            cout << nodes[i].label ;
            for (int j : nodes[i].neighbors){
                cout <<" -> "<< j;
            }
            cout << endl;
        }
        //lets iterate through each node and print its neighbours

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(2,3);
    g->addedge(2,6);
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);


    //add edges for the graphs here.
    
    //print the graph adjaceny list
    g->print();
}
