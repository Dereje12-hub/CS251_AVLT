 
//Name : Dereje Gudeta
//NetId: 653396018
/*avlt.h*/

//
// Threaded AVL tree
//

#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>  // std::max

using namespace std;

template<typename KeyT, typename ValueT>
class avlt
{
private:
  struct NODE
  {
    KeyT   Key;
    ValueT Value;
    NODE*  Left;
    NODE*  Right;
    bool   isThreaded; // true => Right is a thread, false => non-threaded
    int    Height;     // height of tree rooted at this node
  };

  NODE* Root;  // pointer to root node of tree (nullptr if empty)
  int   Size;  // # of nodes in the tree (0 if empty)
  NODE* Begin;  //Begin pointer to pointing the Key
  
  
/* HELPER FUNCTIONS */


  //
  // insert
  //
  // Inserts the given (key, value) pair into the tree; if the key has 
  // already been inserted then the function returns without changing 
  // the tree.
  //
  void _insertHelper(KeyT key, ValueT value)
  {
    NODE* prev = nullptr;
    NODE* cur = Root;

    //
    // stack the nodes we visit so we can walk back up
    // the search path later, adjusting heights:
    //
    stack<NODE*> nodes;

    //
    // Search to see if tree already contains key:
    //
    while (cur != NULL)
	{
	
		if (key == cur->Key)   //already in tree thus return without change the tree
			return;
			 
		 prev = cur;          // updating parent pointer 
		 nodes.push(cur);  // stack so we can return later:
		
		
		if (key < cur->Key)     //search left subtree
			 cur = cur->Left;
	      
		else                      //serarch right
			{
			  if (cur->isThreaded==true) //there is no Right pointer in traditional traversal
			    cur = NULL;
			     
			  else
			       cur=cur->Right;
				  
			}
	}//end while

    //if we get here, key is not in tree, so allocate
    // a new node to insert:
    // 
    NODE* newNode;
    newNode = new NODE();
    newNode->Key = key;
    newNode->Value = value;
	newNode->isThreaded = true;  
	newNode->Height = 0;     // leaf node -> sub-tree of height 0:

	
    //
    //link in the new node:
    //
    // NOTE: cur is null, and parent denotes node where
    // we fell out of the tree.  if parent is null, then
    // the tree is empty and the Root pointer needs 
    // to be updated.
    //
    if (prev == NULL){
		Root = newNode;   //set the Root as newNode
		newNode->Left = NULL;
        newNode->Right = NULL;
		
      }
	  
    else if (key < prev->Key) {
        newNode->Right = prev;       //set the newNode right as prev
        prev->Left = newNode;		   //set the pre left as newNode
		
		}
		
    else  {  //(key > prev->Key)
		newNode->Right = prev->Right;  //newNode is pointeing whatever pre is pointing 
		prev->isThreaded = false;      //make prev threaded false 
		prev->Right = newNode;          //set the pre right as newNode			
	}
	
    // 
    // update size:
    //
    Size++;
	
	//
    // walk back up tree using stack and update heights:
    //
   
    while (!nodes.empty())
    {
	
      cur = nodes.top();
      nodes.pop();

      int hL = (cur->Left == nullptr) ? -1 : cur->Left->Height;
      int hR = (cur->Right == nullptr) ? -1 : (cur->isThreaded==true) ? -1 : cur->Right->Height;
	 // hR = (cur->isThreaded==true) ? 0 : cur->Right->Height;  //if it is threaded
	  
	  cur->Height = 1 + std::max(hL, hR);
	  
    // done!
    }
	
  }//end insert helper



void _copyavlt(NODE* othercur)
	{
	  if (othercur == NULL)
        return;
      else
		{
		  //
		  // To copy and build an exact copy, cur first will be "visit" and insert that (key, value) pair first. 
		  // That way all the nodes to the left will properly go to the left,
		  // if there is a right key copy first all the node to the left .
		  //
		  _insertHelper(othercur->Key, othercur->Value);

		  _copyavlt(othercur->Left);
		  
		  if (othercur->isThreaded)
		     othercur = NULL;
		   
		   else 
			   _copyavlt(othercur->Right);
		}
  
	} //end _copybstt
	

//Funciton used to delate all nodes
//
void _makeEmpty(NODE* cur)
	{
		if (cur == NULL)
		   return;
		   
		else 
		{
		    // conditions that check if the cur is not threaded or cur right is NULL 
		    // 
			if (!(cur->isThreaded)){        // cu not Threaded
                  _makeEmpty(cur->Left);       //recursively call left
				  _makeEmpty(cur->Right);      //call recursively call right 
				  delete(cur);                //delete cur			  			  
			}
			else
			     {
				   _makeEmpty(cur->Left);    //recursively call left 
				    delete(cur);           //delete cur
					
				   }
		
		}//end else
			 
	}//end _makeEmpty
 
// _inorderTraversal does the actual inorder traversal and output 
// to console.  Each key is output to the console followed
// by " ", including the last key.
//	
void _inorderTraversal(ostream& output, NODE* cur) const
	{
	//if cur is NUll return 
	//
	if (cur == NULL) {
      return;
	  }
    
	else
    {
          if ((cur->isThreaded) && (cur->Right != NULL)){
		  
			  //call inorder traversal to the left
			   //print the output respectively
			   //
			   _inorderTraversal(output, cur->Left);      //call inorder traverse to the left 

			   output << "(" << cur->Key << "," << cur->Value 
			   << "," << cur->Height<< ","<< cur->Right->Key << ")" << endl;
		           
			  }
			   
			else 
			   {
				  //call inorder traversal to the left
				  //print the output 
				  ////call inorder traversal to the right respectively 
				  //
			   _inorderTraversal(output, cur->Left);                  
			   output << "(" << cur->Key << "," << cur->Value << "," << cur->Height<< ")" <<endl;

			   _inorderTraversal(output, cur->Right);
			   } 
			   
	 }//end else
	
  }//end 
  
  
  
  //
  // _RightRotate
  //
  // Rotates the tree around the node N, where Parent is N's parent.  Note that
  // Parent could be null, which means N is the root of the entire tree.  If 
  // Parent denotes a node, note that N could be to the left of Parent, or to
  // the right. We need to take all this into account when linking in the
  // new root after the rotation. At lase update the heights as well.
  //
  void _RightRotate(NODE* Parent, NODE* N)
  {         
	 
	    NODE* L = N->Left;
		NODE* A = L->Left;
		NODE* B = L->Right;
		NODE* C = N->Right;
		
		
		L->Left = A;
		N->Right = C;		
		N->Left = B;
		L->Right = N;
		

		if (L->isThreaded )
			 N->Left = NULL;

		
		L->isThreaded = false;      // always this is true

		if (Parent == nullptr)
			Root = L;
           
		else if (L->Key < Parent->Key)                        
			Parent->Left = L;
		    
		else                                   
		   Parent->Right = L;
          
	   //update height
	   //

	    int NL = (N->Left == nullptr) ? -1: N->Left->Height;
		int NR = (N->Right == nullptr || N->isThreaded==true) ? -1 : N->Right->Height;
		N->Height = 1 + std::max(NL, NR);


		int LL = (L->Left ==nullptr) ? -1 : L->Left->Height; 
        int LR = (L->Right==nullptr) ? -1: L->Right->Height;
		L->Height = 1 + std::max(LL, LR);
       
  }//end Right Rotate

  //
  // _LeftRotate
  //
  // Rotates the tree around the node N, where Parent is N's parent.  Note that
  // Parent could be null, which means N is the root of the entire tree.  If 
  // Parent denotes a node, note that N could be to the left of Parent, or to
  // the right.  it need to take all this into account when linking in the
  // new root after the rotation.  Don't forget to update the heights as well.
  //
  void _LeftRotate(NODE* Parent, NODE* N)
  {
	 
	//Node initialize
	//
	NODE* R = N->Right;
	NODE* B = R->Left;            
	NODE* A = N->Left;
	NODE* C = R->Right;                        
      
   //Nodes successor after rotation 
   //
       
   N->Right = B; 
   R->Left = N;
   R->Right = C;                         
   N->Left = A;                   
		 
   //conditions that sets after the rotation
   //
    if (N->Right==NULL)
        {
		   N->Right = R;
		   N->isThreaded = true;
		   
		 }
		 	
	 if (N->Left==NULL)
	   N->Left = NULL; 
		 
	//conditions for parent when it is NULL
	//
    if(Parent == NULL)
		   Root = R;
	 
    else if (Parent->Key > R->Key)
		 Parent->Left = R;
	
   else 
	   Parent->Right = R;
     
     //update height
     //
   
     	int NL = (N->Left == NULL) ? -1 : N->Left->Height;
		int NR = (N->Right == NULL || N->isThreaded) ? -1 : N->Right->Height;
		N->Height = 1 + std::max(NL, NR);


		int RL = (R->Left == NULL) ? -1 : R->Left->Height;
		int RR = (R->Right == NULL || R->isThreaded) ? -1 : R->Right->Height;
		R->Height = 1 + std::max(RL, RR);
		
		
 }//end Left rotation
  
//
//Rotates the tree around the node N, where Parent is N's parent. Rotate to fix 
//calls right rotation or left rotation to fix the unbalanced tree.
//
//
void _RotateToFix(NODE* Parent, NODE* N)
	{
		
		int hL = (N->Left == NULL ) ? -1 : N->Left->Height;
		int hR = (N->Right == nullptr || N->isThreaded==true) ? -1 : N->Right->Height;
		
		if (std::abs(hL - hR) > 1){	
		    if (hL > hR )
		     {
 
			   int hLL = (N->Left->Left == NULL) ? -1 : N->Left->Left->Height;
		       int hLR = (N->Left->Right == NULL || N->Left->isThreaded) ? -1 : N->Left->Right->Height;
			 

			  if (hLL > hLR)   // condition that check for far Left 
				 _RightRotate(Parent, N);     
			
			  else            //if (hLL < hLR) {  // case 2 condition that check for middle Left  
			    {	
				 _LeftRotate(N, N->Left);
				 _RightRotate(Parent, N);
			   }
			
		     } 
			
		    else               //case 3 or case 4 for right 
		     {
		
             int hRL = (N->Right->Left == NULL) ? -1 : N->Right->Left->Height;
//              int hRR = ((N->Right->Right == NULL) || (N->Right->Right->isThreaded)) ? -1 : N->Right->Right->Height;
             int hRR = ((N->Right->Right == NULL) || (N->Right->isThreaded)) ? -1 : N->Right->Right->Height;
			if (hRL > hRR)   // condition that check for middle right 
			   {
			     
			     _RightRotate(N, N->Right);
				 _LeftRotate(Parent, N);
				
				}
			
			
			else  // condition that check for far right 
				_LeftRotate(Parent, N);
		}
	  }	
	}//end _RotateToFix
	
/*END HELPER FUNCTIONS */ 

public:

  //
  // default constructor:
  //
  // Creates an empty tree.
  //
  avlt()
  {
    Root = NULL;
    Size = 0;
	Begin = NULL;
	
  }
  
  
  //
  // copy constructor
  //
  // NOTE: makes an exact copy of the "other" tree, such that making the
  // copy requires no rotations.
  //
  avlt (const avlt& other)
  {
     Root = NULL;
	 Size = 0;
	 Begin = NULL;
	 _copyavlt(other.Root);
	 this->Begin = other.Begin;     // copy the Begin too
	
  }
///////////////////////////////////////////////////
// void inorder(ostream& output)
// {

// //output <<"in+++++++++"<< endl;
//  _inorderTraversal(output, Root);

 
// }
// ////////////////////////////////////////////////////


  //
  // destructor:
  //
  // Called automatically by system when tree is about to be destroyed;
  // this is our last chance to free any resources / memory used by
  // this tree.
  //
  virtual ~avlt()
  {
	//clear();
    _makeEmpty(Root);
  }

 //
  // operator=
  //
  // Clears "this" tree and then makes a copy of the "other" tree.
  //
  // NOTE: makes an exact copy of the "other" tree, such that making the
  // copy requires no rotations.
  //
  avlt& operator=(const avlt& other)
  {
	this->clear();
	
	//now copy the other 
	//
	_copyavlt(other.Root);
	this->Begin = other.Begin;
	
    //this->Height = other.Height;
	
	return *this;
  }//end avlt

 
 
  //
  // clear:
  //
  // Clears the contents of the tree, resetting the tree to empty.
  //
  void clear()
  {
    
    // call _makeEmpty to empty 
    // set Root nullpt and size 0
    // 
     _makeEmpty(Root);
	 
	 //Reset all
	 //
   	 Root = NULL;
	 Size = 0;
	 Begin = NULL;
	
  }

  // 
  // size:
  //
  // Returns the # of nodes in the tree, 0 if empty.
  //
  // Time complexity:  O(1)
  int size() const
  {
    return Size;
  }

  // 
  // height:
  //
  // Returns the height of the tree, -1 if empty.
  //
  // Time complexity:  O(1)
  int height() const
  {
    if (Root == nullptr)
      return -1;
    else
      return Root->Height;
  }

 
  // 
  // search:
  //
  // Searches the tree for the given key, returning true if found
  // and false if not.  If the key is found, the corresponding value
  // is returned via the reference parameter.
  //
  // Time complexity:  O(lgN) worst-case
  //
  bool search(KeyT key, ValueT& value) const
  {
  
	//search for key, return true if found 
	//
	NODE* cur = Root;
	
	//iterate until the cur is not NUll
	//mean while if the key is found update the value 
	//and return true otherwise return false
	//
	while(cur != NULL){
		if (cur->Key == key){
		  value = cur->Value;
		  return true;
		}
			
		else if (key < cur->Key)
			cur = cur->Left;
		else
		{
			if (cur->isThreaded)      //there is no Right pointer in traditional traversal:
				cur = NULL;
			else 
			   cur = cur->Right;
		}
	}//end while
	
    return false;
  }//end bool


//   //
//   // range_search
//   //
//   // Searches the tree for all keys in the range [lower..upper], inclusive.
//   // It is assumed that lower <= upper.  The keys are returned in a vector;
//   // if no keys are found, then the returned vector is empty.
//   //
//   // Time complexity: O(lgN + M), where M is the # of keys in the range
//   // [lower..upper], inclusive.
//   //
//   // NOTE: do not simply traverse the entire tree and select the keys
//   // that fall within the range.  That would be O(N), and thus invalid.
//   // Be smarter, you have the technology.
//   //
//   vector<KeyT> range_search(KeyT lower, KeyT upper)
//   {
//     vector<KeyT>  keys;

//     NODE* cur = Root; //initialize a pointer 
//    // NODE* r = Root;  //pointer that is poisting the ROOT
// 	NODE* prev; 
	
// 	int key;
  
// 	//condition when the Root is a nullptr
// 	//
// 	if (Root == NULL)
// 	  return keys;


//      if (upper < lower)       // condition for upper key < lower key
// 	   return keys;
	   
	   
// 	//iterate until the cur is not NUll
// 	//mean while if the key is found update the value 
// 	//and return true otherwise return false
// 	//
// 	while(cur != NULL)
// 	{
	
// 	   if (lower == cur->Key){  
//             Begin=cur;         
//             break;                        	   	
// 		}

//         prev = cur;
		
// 		if (lower < cur->Key)
// 			cur = cur->Left;
			
// 		else
// 		{
// 			if (cur->isThreaded){
			
// 			       if (cur->Right != NULL){
			
// 			            if (cur->Right->Key > lower && cur->Right->Key <= upper)
// 			                Begin = cur->Right;
				            
// 				        else
// 				             Begin = cur;
					  
// 				    }
// 				 else         //there is no key 
// 				     Begin=NULL;
		 
// 				  break;    //break 
// 				 }
				 
// 			else                       //cur is not Threaded
// 			   cur = cur->Right;
			   
// 		  }
		
		
// 		//condition which check for lower is the beginning of the key 
// 		//
// 		//
// 		if ((cur == NULL) && (prev->Key > lower) && (prev->Key <= upper))
// 		  {
// 		    Begin = prev;
// 		    break;
// 		  }
      
// 	}//end while
	
	
// 	  // if the lower = upper and it is in the tree
// 	  // 
// 	    if ( lower == upper){
// 		  if (Begin->Key==lower)          
// 		     keys.push_back(lower);      //push pack the only key  
		    
// 		   return keys;      
// 		}
		
		
// 		if (lower < upper )
// 		 {
// 		   if (Begin != NULL)
// 		    { }
		   
// 		   else 
// 		     return keys;
// 		 }

	
// // 	if (cur != NULL ){  
// // 		if ( cur->Key == lower)   //condition if lower found in tree set is pointer on the lower
// // 		   Begin = cur;

// // 		if (cur->Key < lower)    //condition if lower not in tree set is pointer below the lower
// // 		   Begin = prev;
// //       }


//    //iterate the next key until it get exactly the upper key of 
//    //lower than that key 
//    //
// 	while (next(key))
// 	{
// 	     if (key > upper)   //condition to exit the while loop until the key is greater
// 		   break;
	   
// 	   keys.push_back(key);
       
      
// 	}
	
	
// 	//cout << endl;
	
//     return keys;
//   }//end range_search





//
  // range_search
  //
  // Searches the tree for all keys in the range [lower..upper], inclusive.
  // It is assumed that lower <= upper.  The keys are returned in a vector;
  // if no keys are found, then the returned vector is empty.
  //
  // Time complexity: O(lgN + M), where M is the # of keys in the range
  // [lower..upper], inclusive.
  //
  // NOTE: do not simply traverse the entire tree and select the keys
  // that fall within the range.  That would be O(N), and thus invalid.
  // Be smarter, you have the technology.
  //
  vector<KeyT> range_search(KeyT lower, KeyT upper)
  {
    vector<KeyT>  keys;

    NODE* cur = Root; //initialize a pointer 
   // NODE* r = Root;  //pointer that is poisting the ROOT
	NODE* prev; 
	
	int key;
  
	//condition when the Root is a nullptr
	//
	if (Root == NULL)
	  return keys;


     if (upper < lower)       // condition for upper key < lower key
	   return keys;
	   
	   
	//iterate until the cur is not NUll
	//mean while if the key is found update the value 
	//and return true otherwise return false
	//
	while(cur != NULL)
	{
	
	   if (lower == cur->Key){           
            break;                        	   	
		}

        prev = cur;
		
		if (lower < cur->Key)
			cur = cur->Left;
			
		else
		{
			 if (cur->isThreaded){
			     cur=NULL;
		  
				 }
				 
			else                       //cur is not Threaded
			   cur = cur->Right;
			   
		  }
		

      
	}//end while
	
   //here the cur pointing on the lower or NULL
   //
		if (cur != NULL && cur->Key== lower)
			   Begin = cur;



		if (cur == NULL)
		{
			//condition which check for lower and upper key for null ptr
			//
			//cout << "cur==NULL" << endl;
		  
		  if((prev->Key > lower) && (prev->Key <= upper))
			 {
			  //cout << "in-----1" << endl;
			   Begin = prev;
               
             }
			 
         else if((prev->Right != NULL) && (prev->Key < lower) && (prev->Right->Key > lower))
			 { 
			 //cout << "in-----2" << endl;
			   Begin = prev->Right;
               
             }
			else 
			{
			  //cout << " else " << endl;
			  return keys;
			  }

		}

	  // if the lower = upper and it is in the tree
	  // 
//		if ( lower == upper && Begin->Key==lower)  {        
//			 keys.push_back(lower);      //push pack the only key  

//		   return keys;      
//		}
		

   //iterate the next key until it get exactly the upper key of 
   //lower than that key 
   //
	while (next(key))
	{
	     if (key > upper)   //condition to exit the while loop until the key is greater
		   break;
	   
	   keys.push_back(key);
       
      
	}
	
	
	//cout << endl;
	
    return keys;
  }//end range_search


  //
  // insert
  //
  // Inserts the given key into the tree; if the key has already been insert then
  // the function returns without changing the tree.  Rotations are performed
  // as necessary to keep the tree balanced according to AVL definition.
  //
  // Time complexity:  O(lgN) worst-case
  //
  void insert(KeyT key, ValueT value)
  {
    
    //initialize of previous and current pointers
    //
    NODE* prev = NULL;
	NODE* cur = Root;
	
	// stack the nodes we visit so we can walk back up
    // the search path later, adjusting heights:
    //
    stack<NODE*> nodes;
	
   
   // search to see already contains key:
   // 
    while (cur != NULL)
	{
	
	
		if (key == cur->Key)   //already in tree thus return without change the tree
			return;
			 
		 prev = cur;          // updating parent pointer 
		 nodes.push(cur);  // stack so we can return later:
		
		
		// cout << "++++++stack puched+++++++++ " << endl;
        // cout << cur->Key << endl;
		 
		
		if (key < cur->Key)     //search left subtree
			 {
			 cur = cur->Left;
			 
			 }
	      
		else                      //serarch right
			{
			  if (cur->isThreaded==true) //there is no Right pointer in traditional traversal
			    cur = NULL;
			     
			  else
			       cur=cur->Right;
				  
			}
	}//end while 
	
	
    //if we get here, key is not in tree, so allocate
    // a new node to insert:
    // 
    NODE* newNode;
    newNode = new NODE();
    newNode->Key = key;
    newNode->Value = value;
	newNode->isThreaded = true;  
	newNode->Height = 0;  // leaf node -> sub-tree of height 0:

	
	
    //
    //link in the new node:
    //
    // NOTE: cur is null, and parent denotes node where
    // we fell out of the tree.  if parent is null, then
    // the tree is empty and the Root pointer needs 
    // to be updated.
    //
    if (prev == NULL){
		Root = newNode;   //set the Root as newNode
		newNode->Left = NULL;
        newNode->Right = NULL;
		
      }
    else if (key < prev->Key) {
        newNode->Right = prev;       //set the newNode right as prev
        prev->Left = newNode;		   //set the pre left as newNode
		
		}
		
    else  {  //(key > prev->Key)
		newNode->Right = prev->Right;  //newNode is pointeing whatever pre is pointing 
		prev->isThreaded = false;      //make prev threaded false 
		prev->Right = newNode;          //set the pre right as newNode	
			
	}
	
	
	
    // 
    // update size:
    //
    Size++;
	
	//int count=0;
	//int count2=0;
	//
    // walk back up tree using stack and update heights:
    //
    //
    //
  
	//cout << endl;
   // cout << " stack size = " << nodes.size() << endl;

    while (!nodes.empty())
    {
	 // cout << " stack size = " << nodes.size() << endl;
      cur = nodes.top();
      nodes.pop();
// 	     cout << "++++++stack top in while+++++++++ " << endl;
//          cout << cur->Key << endl;
// 		 cout << "++++++stack top +++++++++ " <<endl;

      int hL = (cur->Left == nullptr) ? -1 : cur->Left->Height;
      int hR = (cur->Right == nullptr) ? -1 : (cur->isThreaded==true) ? -1 : cur->Right->Height;
	 // hR = (cur->isThreaded==true) ? 0 : cur->Right->Height;  //if it is threaded
	  
	 int hCur = 1 + std::max(hL, hR);
	  

// //////
//       cout << " cur->Key ====> " << cur->Key << endl;
//       cout << " int hL ====> " << hL << endl;
// 	  cout << "int hR ====> " << hR << endl;
// 	  cout << "int hCur ====> " << hCur<< endl << endl;
// ////
	  
  // update height 
      if (cur->Height == hCur)  // didn't change, so no need to go further:
        break;
		
      else  // update and keep going up the tree using stack:
        cur->Height = hCur;  
		
//////
 //     cout << "cur->Height ====> " << cur->Height << endl;
//	  cout << "hCur ====> " << hCur  << endl;
//// 	
		//cout << "......................................................... "<< endl<< endl << endl <<endl;
// 	  //
	  /*Condition that call rotate to fix faction when AVL is broken*/
	  //
 	  //if (std::abs(hL - hR) > 1)
	   if (hCur > 1)
	  {
         if(nodes.empty()){
		  //  cout << "RotateToFix    nodes.empty"<<++count<<endl<<endl;
			_RotateToFix(nullptr, cur);
			//cout << "return count "<<++count<<endl<<endl;
           }
		else {   
		    // cout << "RotateToFix     else "<<++count2<<endl<<endl;
			  _RotateToFix(nodes.top(),cur);
			}	
      }// end fixed condition
	
	//cout << "......................................................... "<< endl<< endl << endl <<endl;
	
// //////
//      cout << "AFTER ROTATED" <<endl;
//       cout << "cur->Height ====> " << cur->Height << endl;
// 	  cout << "hCur ====> " << hCur << endl << endl;
// //// 
    			
     }//while

	
	
    // done!
    
  } //end insert funciton 

  //
  // []
  //
  // Returns the value for the given key; if the key is not found,
  // the default value ValueT{} is returned.
  //
  // Time complexity:  O(lgN) worst-case
  //
  ValueT operator[](KeyT key) const
  {
    //
    // TODO
    
	ValueT value;  //declare value
	 
	 //call search function if the key is found it returns true and
	 //update the value thus it return the value otherwise it returns
	 //false
	 //
	 if(search(key,value))    
		 return value;

    return ValueT{ };
  }

  //
  // ()
  //
  // Finds the key in the tree, and returns the key to the "right".
  // If the right is threaded, this will be the next inorder key.
  // if the right is not threaded, it will be the key of whatever
  // node is immediately to the right.
  //
  // If no such key exists, or there is no key to the "right", the
  // default key value KeyT{} is returned.
  //
  // Time complexity:  O(lgN) worst-case
  //
  KeyT operator()(KeyT key) const
  {
    //
    //search for key, return true if found 
	//
	NODE* cur = Root; 
	
	while(cur != NULL){
	
		if (cur->Key == key){    
		    if (cur->Right != NULL)
		       return cur->Right->Key;
			   
		     else 
			    return KeyT{ };
			
		}
			
		else if (key < cur->Key)
			cur = cur->Left;
			
		else
		{
			if (cur->isThreaded)      //there is no Right pointer in traditional traversal:
				cur = NULL;
			else 
			   cur = cur->Right;
		}
	}//end while
	
	// Here no key is found
    // thus 
    return KeyT{ };
  } //end keyT

  //
  // %
  //
  // Returns the height stored in the node that contains key; if key is
  // not found, -1 is returned.
  //
  // Example:  cout << tree%12345 << endl;
  //
  // Time complexity:  O(lgN) worst-case
  //
  int operator%(KeyT key) const
  {
	  
     //call search function if the key is found it 
     //returns the height of the key
	
	NODE* cur = Root; 
	
	while(cur != NULL){
	
		if (cur->Key == key){    
		   //now key is found
		   //
		   
		   return cur->Height;  //return height of the key
			
		}
			
		else if (key < cur->Key)
			cur = cur->Left;
			
		else
		{
			if (cur->isThreaded)      //there is no Right pointer in traditional traversal:
				cur = NULL;
			else 
			   cur = cur->Right;
		}
	}//end while
		
	
    // now the key is not found 
    // 
    return -1;
  }

  //
  // begin
  //
  // Resets internal state for an inorder traversal.  After the 
  // call to begin(), the internal state denotes the first inorder
  // key; this ensure that first call to next() function returns
  // the first inorder key.
  //
  // Space complexity: O(1)
  // Time complexity:  O(lgN) worst-case
  //
  // Example usage:
  //    tree.begin();
  //    while (tree.next(key))
  //      cout << key << endl;
  //
//   void begin()
//   {
//        //
//     // if the Root is NULL
//     // 
// 	if(Root == NULL)
// 	{
// 	   Begin = NULL;
// 	    return;
// 	}
	  
// 	//Here Root is not NULL 
// 	//initialize pointer as Root
// 	//if Root left is NULL
	
// 	if(Root->Left == NULL)
// 	 {
// 	    Begin = Root;
// 	    return;
// 	 }
	 
// 	 //Here Root Left is not NULL
// 	 //
	
// 	NODE* curPtr = Root;

// 	//loop to reach out far left down 
// 	//
	
// 	  while (curPtr->Left != NULL)
// 		{
// 		   curPtr = curPtr->Left; 
//          }
    
// 	 //now pointer is far left
// 	 //
//      Begin = curPtr; 
   
//   }//end begin

void begin()
  {
      
	Begin = Root;
	
	//
    // if the Root is NOT NULL
    //
     if (Begin != NULL){
	  while (Begin->Left != NULL)
		   Begin = Begin->Left; 
     }    
    
   
  }//end begin



  //
  // next
  //
  // Uses the internal state to return the next inorder key, and 
  // then advances the internal state in anticipation of future
  // calls.  If a key is in fact returned (via the reference 
  // parameter), true is also returned.
  //
  // False is returned when the internal state has reached null,
  // meaning no more keys are available.  This is the end of the
  // inorder traversal.
  //
  // Space complexity: O(1)
  // Time complexity:  O(lgN) worst-case
  //
  // Example usage:
  //    tree.begin();
  //    while (tree.next(key))
  //      cout << key << endl;
  //
  bool next(KeyT& key)
  {
  //condition to check if Begin is not NULL 
  //and if it not update the ke and assign the next Begin pointer
  //
  if (Begin != NULL)
    {
		key = Begin->Key;	 //update the begin key
		  //if Begin is not threaded and begin Right is not NULL
		  //
		 if (!(Begin->isThreaded) && ((Begin->Right) != NULL)){ 
		   
			    Begin = Begin->Right;   //Make the pointer to right
				
				while(Begin->Left)
					Begin = Begin->Left;     // set Begin all the way left
			
				return true;
			
			}
			
			//if pointer is threaded
			//
            if (Begin->isThreaded) {
			      Begin = Begin->Right;
			      return true;
			     }
				  
             else 
				return false;		
		 
		 }//end outer if	 	

    //if we get here     
    return false;
  }

  //
  // dump
  // 
  // Dumps the contents of the tree to the output stream, using a
  // recursive inorder traversal.
  //
  void dump(ostream& output) const
  {
    output << "**************************************************" << endl;
    output << "********************* AVLT ***********************" << endl;

    output << "** size: " << this->size() << endl;
    output << "** height: " << this->height() << endl;

    //
    // inorder traversal, with one output per line: either 
    // (key,value,height) or (key,value,height,THREAD)
    //
    // (key,value,height) if the node is not threaded OR thread==nullptr
    // (key,value,height,THREAD) if the node is threaded and THREAD denotes the next inorder key
    //

    //call _inorderTraversal Helper function inorder to print out the data
    //
	 _inorderTraversal(output, Root);
	 
    output << "**************************************************" << endl;
  }
	
	
	

};


