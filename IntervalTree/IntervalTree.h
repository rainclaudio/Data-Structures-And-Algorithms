#include <utility>
#include <string>
typedef struct Node{
  std::pair<int,int> intervalY;
  std::pair<int,int> intervalX;
  int key;
  int height;
  Node* left;
  Node* right;
  Node* father;
} Node;

class IntervalTree{
private:
  Node* root;
  Node* createNode(int,int,int,int,Node*);

  void printNode(Node*);

  void insertWithFather(int,int,int,int,Node*,Node**);
  void updateKey(Node*);
  // funciones útiles para balancear un árbol
  bool balanced(int,int);
  void balanceTree(Node*,Node*,Node*,bool,bool);
  int comp_keys(int,int);

  void  right_right_Solve(Node*, Node*, Node* );
  void  left_left_Solve(Node*, Node*, Node* );
  void  right_left_Solve(Node*, Node*, Node* );
  void  left_right_Solve(Node*, Node*, Node*);

  Node* getNode(Node*, bool*);

  void updateHeight(Node*);

  // actualiza tanto la altura como la key
  void updateNode(Node*,bool);
  bool isExternal(Node*);
  Node* getSucessor(Node*);
  // funciones para eliminar un nodo
  void destroyNode(Node*);
  void swapAndDestroy(Node*,Node*,bool,bool);
  bool areClose(Node*,Node*);
  void deleteInterval(Node*,int,int,int,int);
  void printIntevalTree(Node*,std::string);
  // search functions
  bool intersection(Node* currentNode,int ymin, int ymax,int xmin,int xmax);
  bool completeIntersection(Node* currentNode,int ymin, int ymax,int xmin,int xmax);
  bool search(int,int,int,int,Node*);
public:
  IntervalTree();
  ~IntervalTree();
  void insert(int,int,int,int);
  void deleteInterval(int,int,int,int);
  bool search(int,int,int,int);
  void printIntevalTree();
};
