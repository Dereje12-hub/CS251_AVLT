/*test01.cpp*/

//
// Unit tests for threaded AVL tree
//

#include <iostream>
#include <vector>

#include "avlt.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("(1) empty tree") 
{
  avlt<int, int>  tree;

  REQUIRE(tree.size() == 0);
  REQUIRE(tree.height() == -1);
	
	
	cout << "(1) empty tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
	cout << endl;
	cout << endl;
	
}


TEST_CASE("(2) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	

	
// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"..............1.................."<< endl;
}


TEST_CASE("(3) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	
	
	
	
	
	
	
	
// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"...............2................."<< endl << endl;
}


TEST_CASE("(4) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }

	
	
// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"..............3.................."<< endl;
}

TEST_CASE("(5) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
// 	cout << endl;
// 	cout << endl;
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"..............4.................."<< endl;
}



TEST_CASE("(6) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	

// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"..............5.................."<< endl;
}



TEST_CASE("(7) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	
	
// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
	//cout << endl;
	//cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"...................6............."<< endl;
}



TEST_CASE("(8) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
	//cout << endl;
	//cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	

// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
	//cout << endl;
	//cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"..................7.............."<< endl;
}


TEST_CASE("(9) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
	//cout << endl;
	//cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	
	

	
//	cout << endl;
	//cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<".................8..............."<< endl;
}


TEST_CASE("(10) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
	cout << endl;
	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	

	
// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
	//cout << " ..........tree..................."<< endl;
	//tree.inorder(std::cout);
	//cout << " ..........tree...................."<< endl<<endl;
	//cout << " ..........c...................."<< endl;
	c.dump(std::cout);
	//cout << " ..........c...................."<< endl;
// 	cout << endl;
// 	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
 	t = c.range_search(90,90);
// 	t = c.range_search(90,100);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<"...................9............."<< endl;
}


TEST_CASE("(11) copy constructor ")
{
  avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
	//bir
//   vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,146,149};
//   vector<int> heights = {0,1,0,2,0,4,0,1,0,3,0,1,2,1,0 };
	
// 	 vector<int> keys = { 19, 20,21,22,23,24,51,101,140,141,142,143,144,145,146,149};
//   vector<int> heights = {0,1,0,2,0,1,0,4,0,1,0,3,0,2,1,0 };

// 	 vector<int> keys = { 19 20 21 22      23 24    51 140 141 142 143      144 145 146 149  101};
//   vector<int> heights = {0,1,0, 2,     0,1,    0,4,0,1,0,3,         0,2,1,0 };
	
	
	
// 	 19 20 21 22      23 24          51     140 141 142 143      144 145 146       101   149
	
// 		 24          51   101     19 20 21 22      23   146 145 144 143      142 141 140         149    ///
	   
// 		  24          51       23 22 21 20 19   146 145 144 143      142 141 140  101       149 
		 
	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	  
//   vector<int> keys = { 47,30,18,13,6,21,32,77,101 };
//   vector<int> heights = { 2,1,3,1,0,0,0,1,0};
	
	//diffi
	//
	
//   vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
	
	  vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
//   vector<int> keys = { 500, 100, 200, 125,130,135 };
//   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
//   vector<int> heights = { 0,1,1,2,0,0};
	
	
	// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
// 
// 
  for (int key : keys)
  {
    tree.insert(key, -key);
  }
	
	
	
	
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(tree.size() == keys.size());

  auto max1H = std::max_element(heights.begin(), heights.end());
  REQUIRE(tree.height() == *max1H);
  // 
  // values inserted?
  //
  int value;

  for (int key : keys)
  {
    REQUIRE(tree.search(key, value));
    REQUIRE(value == -key);
  }

	cout << "(3) 2 node tree " << endl;
	cout << "Size: " << tree.size() << endl;
    cout << "Height: " << tree.height() << endl; 
	//tree.inorder(std::cout);
	
	cout << endl;
	cout << endl;
	
	
	
  //
  // heights correct after rebalance?
  //
  for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	
	

	
// 	cout << endl;
// 	cout << endl;
	
	
	
	

	avlt<int, int> c(tree);
	
	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

  //
  // size and height?  after rebalance should be 1:
  //
  REQUIRE(c.size() == keys.size());

  auto maxH = std::max_element(heights.begin(), heights.end());
  REQUIRE(c.height() == *maxH);
  // 
  // values inserted?
  //
    int value1;

  for (int key : keys)
  {
    REQUIRE(c.search(key, value1));
    REQUIRE(value1 == -key);
  }

	cout << "(4) 3 node tree " << endl;
	cout << "Size: c.size=" << c.size() << endl;
    cout << "Height: c.height=" << c.height() << endl; 
// 	cout << " ..........tree..................."<< endl;
// 	tree.inorder(std::cout);
// 	cout << " ..........tree...................."<< endl<<endl;
// 	cout << " ..........c...................."<< endl;
	c.dump(std::cout);
//	cout << " ..........c...................."<< endl;
	cout << endl;
	cout << endl;
	
	
	vector<int> t;
			//t = c.range_search(5,100);
			//t = c.range_search(5,20);
			//t = c.range_search(12,100);
 	       //t = c.range_search(20,20);
 	       //t = c.range_search(78,80);
	        //t = c.range_search(24,28);
 	        //t = c.range_search(78,79);
//	t = c.range_search(90,100);
// 	t = c.range_search(90,100);
 	t = c.range_search(5,5);
	
	cout << "the range file is" << endl;
	cout <<  "t.size() = "<< t.size() << endl;
	
	
  for (size_t i = 0; i < t.size(); ++i)
   {
    cout << t[i]<< " ";
   }
	

  //
  // heights correct after rebalance?
  //
 for (size_t i = 0; i < keys.size(); ++i)
  {
    REQUIRE((tree % keys[i]) == heights[i]);
  }
	
	cout <<".................10..............."<< endl;
}
// TEST_CASE("(2) 2 nodes")
// {
	
// 	//two nodes
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 100, 50 };
//   vector<int> heights = { 1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

// 	cout << "(3) 2 node tree " << endl;
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
//  }








// TEST_CASE("(3) copy constructor ")
// {
//   avlt<int, int>  tree;
	
	
// 	vector<int> keys = { 100,50,150 };
//    vector<int> heights = { 1, 0, 0 };
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
// //   vector<int> keys = { 500, 100, 200, 125,130,135 };
// //   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }
	
	
	
	
// 	avlt<int, int> c(tree);
	
// 	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(c.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(c.height() == *maxH);
//   // 
//   // values inserted?
//   //
//     int value;

//   for (int key : keys)
//   {
//     REQUIRE(c.search(key, value));
//     REQUIRE(value == -key);
//   }

// 	cout << "(4) 3 node tree " << endl;
// 	cout << "Size: c.size=" << c.size() << endl;
//     cout << "Height: c.height=" << c.height() << endl; 
// 	//tree.inorder(std::cout);
// 	c.dump(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// 	vector<int> t;
// 	t = c.range_search(2,125);
	
// 	cout << "the range file is" << endl;
// 	cout <<  "t.size() = "<< t.size() << endl;
	
	
//   for (size_t i = 0; i < t.size(); ++i)
//    {
//     cout << t[i]<< " ";
//    }
	
// }
	
	
	
// TEST_CASE("(4) copy constructor ")
// {
//   avlt<int, int>  tree;
	
	
// // 	vector<int> keys = { 100,50,150 };
// //    vector<int> heights = { 1, 0, 0 };
// 	//bir
//   vector<int> keys = { 100, 120, 80, 60,40 };
//   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
// //   vector<int> keys = { 500, 100, 200, 125,130,135 };
// //   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// //   vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
	
	
	
//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }
	
	
	
	
// 	avlt<int, int> c(tree);
	
// 	cout << "avlt<int, int> c(tree)= " << c.size() << endl; 
	
	

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(c.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(c.height() == *maxH);
//   // 
//   // values inserted?
//   //
//     int value;

//   for (int key : keys)
//   {
//     REQUIRE(c.search(key, value));
//     REQUIRE(value == -key);
//   }

// 	cout << "(4) 3 node tree " << endl;
// 	cout << "Size: c.size=" << c.size() << endl;
//     cout << "Height: c.height=" << c.height() << endl; 
// 	//tree.inorder(std::cout);
// 	c.dump(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// 	vector<int> t;
// 	t = c.range_search(2,125);
	
// 	cout << "the range file is" << endl;
// 	cout <<  "t.size() = "<< t.size() << endl;
	
	
//   for (size_t i = 0; i < t.size(); ++i)
//    {
//     cout << t[i]<< " ";
//    }
	

//   //
//   // heights correct after rebalance?
//   //
//  for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
// }




	


// TEST_CASE("(5) 3 nodes ")
// {
//   avlt<int, int>  tree;
	
// //   vector<int> keys = { 100 };
// //   vector<int> heights = { 0};
 

// // 	  vector<int> keys = { 100, 50 };
// //   vector<int> heights = { 1,0};
	

// // 	  vector<int> keys = { 20, 40 };
// //   vector<int> heights = { 1,0};
	
//   vector<int> keys = { 100,50,150 };
//   vector<int> heights = { 1, 0, 0 };
	
// //   vector<int> keys = { 300,200,100 };
// //   vector<int> heights = { 0, 1, 0 };
	

// //   vector<int> keys = { 200, 300, 100 };
// //   vector<int> heights = { 1,0,0};
	

// //   vector<int> keys = { 100,200,300};
// //   vector<int> heights = { 0, 1, 0 };	
	
	
// 	//1
// //  vector<int> keys = { 300, 200, 100,50,25 };
// //   vector<int> heights = { 0, 2, 0, 1, 0 };
 
	
// 	//2
// // 	vector<int> keys = { 80, 60, 30, 90, 100, 120};                 
// //   vector<int> heights = { 0,1,0,2,1,0};                           	
 
// 	//3
// //  vector<int> keys = { 300, 200, 100, 50,25,400,150 };
// //   vector<int> heights = { 1, 3, 1, 2, 0 ,0,0};
	
// 	//4
// //    vector<int> keys = { 46,76,29,100,31,17,12,5};
// //    vector<int> heights = { 3,1,2,0,0,0,1,0};	
	
//    //5
// //   vector<int> keys = { 100,80,120,60,40,20};
// //   vector<int> heights = { 1,0,0,2,1,0};

// 	//6
// //   vector<int> keys = { 100,80,120,60,40 }; //,20,70};
// //   vector<int> heights = { 2,0,0,1,0}; //, 0};


// // 	//7
// //   vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
// //    vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
// //   vector<int> keys = { 500, 100, 200, 125,130,135 };
// //   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// // 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
	


	
//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//     int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

// 	cout << "(4) 3 node tree " << endl;
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	//tree.inorder(std::cout);
// 	tree.dump(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// 	vector<int> t;
// 	t = tree.range_search(80,400);
	
// 	cout << "the range file is" << endl;
// 	cout <<  "t.size() = "<< t.size() << endl;
	
	
//   for (size_t i = 0; i < t.size(); ++i)
//    {
//     cout << t[i]<< " ";
//    }
	
	
	
//   //
//   // heights correct after rebalance?
//   //
//  for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
// }



// 	TEST_CASE("(6) 3 nodes ")
// {
//   avlt<int, int>  tree;
	
// //   vector<int> keys = { 100 };
// //   vector<int> heights = { 0};
 

// // 	  vector<int> keys = { 100, 50 };
// //   vector<int> heights = { 1,0};
	

// // 	  vector<int> keys = { 20, 40 };
// //   vector<int> heights = { 1,0};
	
// //   vector<int> keys = { 100,50,150 };
// //   vector<int> heights = { 1, 0, 0 };
	
// //   vector<int> keys = { 300,200,100 };
// //   vector<int> heights = { 0, 1, 0 };
	

// //   vector<int> keys = { 200, 300, 100 };
// //   vector<int> heights = { 1,0,0};
	

// //   vector<int> keys = { 100,200,300};
// //   vector<int> heights = { 0, 1, 0 };	
	
	
// 	//1
//  vector<int> keys = { 300, 200, 100,50,25 };
//   vector<int> heights = { 0, 2, 0, 1, 0 };
 
	
// 	//2
// // 	vector<int> keys = { 80, 60, 30, 90, 100, 120};                 
// //   vector<int> heights = { 0,1,0,2,1,0};                           	
 
// 	//3
// //  vector<int> keys = { 300, 200, 100, 50,25,400,150 };
// //   vector<int> heights = { 1, 3, 1, 2, 0 ,0,0};
	
// 	//4
// //    vector<int> keys = { 46,76,29,100,31,17,12,5};
// //    vector<int> heights = { 3,1,2,0,0,0,1,0};	
	
//    //5
// //   vector<int> keys = { 100,80,120,60,40,20};
// //   vector<int> heights = { 1,0,0,2,1,0};

// 	//6
// //   vector<int> keys = { 100,80,120,60,40 }; //,20,70};
// //   vector<int> heights = { 2,0,0,1,0}; //, 0};


// // 	//7
// //   vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
// //    vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

	
	
	
// 	//bir
// //   vector<int> keys = { 100, 120, 80, 60,40 };
// //   vector<int> heights = { 2, 0, 0, 1, 0};
	
	
// 	//diffi
	
// //   vector<int> keys = { 500, 100, 200, 125,130,135 };
// //   vector<int> heights = { 0,0,1,1,2,0};
	
	
// 	//diffi
// 	//
	
// // 	  vector<int> keys = { 500, 100, 200, 125,130,50 };
// //   vector<int> heights = { 0,1,1,2,0,0};
	


	
//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//     int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

// 	cout << "(4) 3 node tree " << endl;
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	//tree.inorder(std::cout);
// 	tree.dump(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// 	vector<int> t;
// 	t = tree.range_search(80,400);
	
// 	cout << "the range file is" << endl;
// 	cout <<  "t.size() = "<< t.size() << endl;
	
	
//   for (size_t i = 0; i < t.size(); ++i)
//    {
//     cout << t[i]<< " ";
//    }
	
	
	
//   //
//   // heights correct after rebalance?
//   //
//  for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
// }



	
	
	
	
	
// TEST_CASE("(7) case 3 at the root")
// {
// 	//case 2 two rotation 
// 	//1LR at the middle 
// 	//1RR at the Root
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 100,80,90 };
//   vector<int> heights = { 0, 0, 1 };

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
  
//   //values inserted?
  
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// 	//tree.dump(std::cout);
	
// }




// TEST_CASE("(6) case 3 at the root")
// {
// 	//case 3 two rotation 
// 	//1RR at the middle 
// 	//1LR at the Root
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20, 80, 100 };
//   vector<int> heights = { 0, 1, 0 };

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

// //   //
// //   // size and height?  after rebalance should be 1:
// //   //
//    REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	

// cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
// }












// TEST_CASE("(7) case 6 at the root")
// {
	
// 	//two nodes
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20,40 };
//   vector<int> heights = { 1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }






// TEST_CASE("(9) case 8 at the root")
// {
	
// 	//all repeated nodes
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 40, 40, 40 };
//   vector<int> heights = { 0,0,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() != keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
// //   // 
// //   // values inserted?
// //   //
// //   int value;

// //   for (int key : keys)
// //   {
// //     REQUIRE(tree.search(key, value));
// //     REQUIRE(value == -key);
// //   }

	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }



// TEST_CASE("(10) case 9 at the root")
// {
	
// 	//Two RR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 100,80,120,60,40,20};
//   vector<int> heights = { 1,0,0,2,1,0};
// // //   vector<int> keys = { 100,80,120,60,40 }; //,20,70};
// // //   vector<int> heights = { 2,0,0,3,1,0}; //, 0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

// // //   auto maxH = std::max_element(heights.begin(), heights.end());
// // //   REQUIRE(tree.height() == *maxH);
// // //   // 
// // //   // values inserted?
// // //   //


// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
//   }



// TEST_CASE("(11) case 10 at the root")
// {
	
// 	//Two LR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20,40,60,80,100};
//   vector<int> heights = { 0,2,0,1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
//  }


// TEST_CASE("(12) case 11 at the root")
// {
	
// 	//Two 1RR & 2LR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 80, 60, 30, 90, 100, 120};
//   vector<int> heights = { 0,1,0,2,1,0};
//  // vector<int> heights = { 3,1,0,2,1,0};
	
//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }


// TEST_CASE("(13) case 12 at the root")
// {
	
// 	//Two 2RR & 2LR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
//   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }


































// TEST_CASE("(1) empty tree") 
// {
//   avlt<int, int>  tree;

//   REQUIRE(tree.size() == 0);
//   REQUIRE(tree.height() == -1);
// }


// TEST_CASE("(2) case 1 at the root")
// {
//   avlt<int, int>  tree;

//   vector<int> keys = { 100, 80, 60 };
//   vector<int> heights = { 0, 1, 0 };

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
// //   // 
// //   // values inserted?
// //   //
// //    int value;

// //   for (int key : keys)
// //   {
// //     REQUIRE(tree.search(key, value));
// //     REQUIRE(value == -key);
// //   }

	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
// //   //
// //   // heights correct after rebalance?
// //   //
// //   for (size_t i = 0; i < keys.size(); ++i)
// //   {
// //     REQUIRE((tree % keys[i]) == heights[i]);
// //   }
// }



// TEST_CASE("(3) case 2 at the root")
// {
// 	//case 2 two rotation 
// 	//1LR at the middle 
// 	//1RR at the Root
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 100,80,90 };
//   vector<int> heights = { 0, 0, 1 };

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   //int value;

// //   for (int key : keys)
// //   {
// //     REQUIRE(tree.search(key, value));
// //     REQUIRE(value == -key);
// //   }

// //   //
// //   // heights correct after rebalance?
// //   //
// //   for (size_t i = 0; i < keys.size(); ++i)
// //   {
// //     REQUIRE((tree % keys[i]) == heights[i]);
// //   }
	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// 	//tree.dump(std::cout);
	
// }




// TEST_CASE("(4) case 3 at the root")
// {
// 	//case 3 two rotation 
// 	//1RR at the middle 
// 	//1LR at the Root
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20, 100, 80 };
//   vector<int> heights = { 0, 0, 1 };

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

// //   //
// //   // size and height?  after rebalance should be 1:
// //   //
//    REQUIRE(tree.size() == keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
// //   // 
// //   // values inserted?
// //   //
// //   int value;

// //   for (int key : keys)
// //   {
// //     REQUIRE(tree.search(key, value));
// //     REQUIRE(value == -key);
// //   }

// //   //
// //   // heights correct after rebalance?
// //   //
// //   for (size_t i = 0; i < keys.size(); ++i)
// //   {
// //     REQUIRE((tree % keys[i]) == heights[i]);
// //   }
	

// cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
// }



// TEST_CASE("(5) case 4 at the root")
// {
// 	//case 4 one rotation 
// 	//1LR at the Root 
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20,80, 100 };
//   vector<int> heights = { 0, 1, 0 };

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
// //   int value;

// //   for (int key : keys)
// //   {
// //     REQUIRE(tree.search(key, value));
// //     REQUIRE(value == -key);
// //   }

// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// //   //
// //   // heights correct after rebalance?
// //   //
// //   for (size_t i = 0; i < keys.size(); ++i)
// //   {
// //     REQUIRE((tree % keys[i]) == heights[i]);
// //   }
	
	
	
	
// }




// TEST_CASE("(6) case 5 at the root")
// {
	
// 	//one node
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20 };
//   vector<int> heights = { 0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
// //   // 
// //   // values inserted?
// //   //
// // //   int value;

// // //   for (int key : keys)
// // //   {
// // //     REQUIRE(tree.search(key, value));
// // //     REQUIRE(value == -key);
// // //   }

	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
	
// //   //
// //   // heights correct after rebalance?
// //   //
// //   for (size_t i = 0; i < keys.size(); ++i)
// //   {
// //     REQUIRE((tree % keys[i]) == heights[i]);
// //   }
	
	
	
	
// }




// TEST_CASE("(7) case 6 at the root")
// {
	
// 	//two nodes
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20,40 };
//   vector<int> heights = { 1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }



// TEST_CASE("(8) case 7 at the root")
// {
	
// 	//two nodes
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 40, 20 };
//   vector<int> heights = { 1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
	
//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
//}



// TEST_CASE("(9) case 8 at the root")
// {
	
// 	//all repeated nodes
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 40, 40, 40 };
//   vector<int> heights = { 0,0,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() != keys.size());

// //   auto maxH = std::max_element(heights.begin(), heights.end());
// //   REQUIRE(tree.height() == *maxH);
// //   // 
// //   // values inserted?
// //   //
// //   int value;

// //   for (int key : keys)
// //   {
// //     REQUIRE(tree.search(key, value));
// //     REQUIRE(value == -key);
// //   }

	
// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// //   //
// //   // heights correct after rebalance?
// //   //
// //   for (size_t i = 0; i < keys.size(); ++i)
// //   {
// //     REQUIRE((tree % keys[i]) == heights[i]);
// //   }
	
	
	
	
// }



// TEST_CASE("(10) case 9 at the root")
// {
	
// 	//Two RR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 100,80,120,60,40,20};
//   vector<int> heights = { 1,0,0,2,1,0};
// // //   vector<int> keys = { 100,80,120,60,40 }; //,20,70};
// // //   vector<int> heights = { 2,0,0,3,1,0}; //, 0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

// // //   auto maxH = std::max_element(heights.begin(), heights.end());
// // //   REQUIRE(tree.height() == *maxH);
// // //   // 
// // //   // values inserted?
// // //   //
// // //   int value;

// // //   for (int key : keys)
// // //   {
// // //     REQUIRE(tree.search(key, value));
// // //     REQUIRE(value == -key);
// // //   }

// 	cout << "Size: " << tree.size() << endl;
//     cout << "Height: " << tree.height() << endl; 
// 	tree.inorder(std::cout);
	
// 	cout << endl;
// 	cout << endl;
	
	
// // //   //
// // //   // heights correct after rebalance?
// // //   //
// // //   for (size_t i = 0; i < keys.size(); ++i)
// // //   {
// // //     REQUIRE((tree % keys[i]) == heights[i]);
// // //   }
	
	
	
	
//   }



// TEST_CASE("(11) case 10 at the root")
// {
	
// 	//Two LR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 20,40,60,80,100};
//   vector<int> heights = { 0,2,0,1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }


// TEST_CASE("(12) case 11 at the root")
// {
	
// 	//Two 1RR & 2LR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 80, 60, 30, 90, 100, 120};
//   vector<int> heights = { 0,1,0,2,1,0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
// }


// TEST_CASE("(13) case 12 at the root")
// {
	
// 	//Two 2RR & 2LR rotation
	
//   avlt<int, int>  tree;
   	
//   vector<int> keys = { 30, 60, 80, 40, 50, 20, 10 };
//   vector<int> heights = { 0, 1, 0, 2, 0, 1, 0};

//   for (int key : keys)
//   {
//     tree.insert(key, -key);
//   }

//   //
//   // size and height?  after rebalance should be 1:
//   //
//   REQUIRE(tree.size() == keys.size());

//   auto maxH = std::max_element(heights.begin(), heights.end());
//   REQUIRE(tree.height() == *maxH);
//   // 
//   // values inserted?
//   //
//   int value;

//   for (int key : keys)
//   {
//     REQUIRE(tree.search(key, value));
//     REQUIRE(value == -key);
//   }

//   //
//   // heights correct after rebalance?
//   //
//   for (size_t i = 0; i < keys.size(); ++i)
//   {
//     REQUIRE((tree % keys[i]) == heights[i]);
//   }
	
	
	
	
//}
