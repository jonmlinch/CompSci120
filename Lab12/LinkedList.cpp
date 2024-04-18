/* 
    Jonathan Linch
    Course Section #08
    04/18/24
    Lab 12
    Additional work:
        - 
*/

#include <iostream>
using namespace std;

class Node {
  private:
    double data;
    Node* next;
  public:
    Node();
    Node* getNext();
    void setNext(Node* nextNode);
    double getData();
    void setData(double dataDouble);
    double incValue();
    int size();
    double largest();
    double smallest();
    double average();
    void print();
    void clear();
};

Node::Node() {
  data = 0;
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* nextNode) {
  next = nextNode;
}

double Node::getData() {
  return data;
}

void Node::setData(double dataDouble) {
  data = dataDouble;
}

double Node::incValue() {
  double oldData = data;
  data++;
  return oldData;
}

int Node::size() {
  if (next == NULL) {
    return 1;
  } else {
    return 1 + next->size();
  }
}

double Node::largest() {
  if (next == NULL) {
    return data;
  } else {
    double nextLargest = next->largest();
    if (data > nextLargest) {
      return data;
    } else {
      return nextLargest;
    }
  }
}

double Node::smallest() {
  if (next == NULL) {
    return data;
  } else {
    double nextSmallest = next->smallest();
    if (data < nextSmallest) {
      return data;
    } else {
      return nextSmallest;
    }
  }
}

double Node::average() {
  double sum = data;
  int count = 1;
  Node* nextNode = next;
  
  if (next == NULL) {
    return data;
  } 

  while(nextNode != NULL) {
    sum += nextNode->getData();
    count++;
    nextNode = nextNode->getNext();
  }

  return sum/count;
}

void Node::print() {
  if (next == NULL) {
    cout << data << endl;
    
  } else {
    cout << data << " -> ";
    next->print();
  }
}

void Node::clear() {
  if (next == NULL) {
    delete this;
  } else {
    next->clear();
  }
}


int main() {
  int numNodes = 10;
  Node* head = NULL;
  cout << "Enter the number of Nodes to create and link in a list: ";
  cin >> numNodes;

  cout << "Creating a list of " << numNodes << " nodes..." << endl;
  for (int i = 0; i < numNodes; i++) {
    Node* newNode = new Node();

    newNode->setData(i);
    newNode->setNext(head);

    head = newNode;
    
  }

  cout << "Printing the list..." << endl;
  head->print();

  cout << "The size of the list: " << head->size() << endl;
  cout << "The largest value in the list: " << head->largest() << endl;
  cout << "The smallest value in the list: " << head->smallest() << endl;
  cout << "The average of the values in the list: " << head->average() << endl;

  cout << "Incrementing the head of the list..." << endl;
  head->incValue();
  head->print();

  cout << "Clearing the list..." << endl;
  head->clear();
  head->print();
}
