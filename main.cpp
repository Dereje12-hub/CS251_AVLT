
// 
// Interactive program for calling AVL insert.  Let's you insert nodes and 
// watch tree rotate...
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "avlt.h"

using namespace std;

int main()
{
  avlt<int, int>  avl;
  int  x;
	// avl.insert(123, 88);
	
// int dist = 0;
  cout << "Enter a key to insert into tree (0 to stop)> ";
  cin >> x;

  while (x > 0)
  {
    avl.insert(x, x);
    cout << "Size: " << avl.size() << endl;
    cout << "Height: " << avl.height() << endl;  
    //avl.inorder(std::cout);
    avl.dump(std::cout);
  	
    cout << endl;
    cout << "Enter a key to insert into tree (0 to stop)> ";
    cin >> x;
	  
	  	
	  
  } //end while

// 	dist = avl.distance(20, 120);
//     cout << " Distance = " << dist << endl;
	  
	  

  // done:
  //
  return 0;
}










