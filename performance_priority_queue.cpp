#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>


// defined in performance.cpp
void usage();


void priority_queue_sort(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  if (type == "string") {
    // load the data into a priority queue of strings
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      pq.push(s);
      input_count++;
      output_count++;
    }

    while (!pq.empty()) {
      ostr << pq.top() << "\n";
      pq.pop();
    }

  } else if (type == "integer") {
    // load the data into a priority queue of integers
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      pq.push(i);
      input_count++;
      output_count++;

    }

    while (!pq.empty()) {
      ostr << pq.top() << "\n";
      pq.pop();
    }

  }

}


void priority_queue_remove_duplicates(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) { 

  if (type == "string") {
    // load the data into a priority queue of strings
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      pq.push(s);
      input_count++;
      output_count++;
    }

    ostr << pq.top() << "\n";
    std::string popped = pq.top();
    pq.pop();
    while (!pq.empty()) {
      if (pq.top() != popped) {
        ostr << pq.top() << "\n";
      }
      popped = pq.top();
      pq.pop();
    }

  } else if (type == "integer") {
    // load the data into a priority queue of integers
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      pq.push(i);
      input_count++;
      output_count++;

    }

    ostr << pq.top() << "\n";
    int popped = pq.top();
    pq.pop();
    while (!pq.empty()) {
      if (pq.top() != popped) {
        ostr << pq.top() << "\n";
      }
      popped = pq.top();
      pq.pop();
    }

  }


}


void priority_queue_mode(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  if (type == "string") {
    // load the data into a priority queue of strings
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      pq.push(s);
      input_count++;
      output_count++;
    }

    int max = 0;
    int occurences = 0;
    std::string mode = pq.top();
    std::string popped = pq.top();
    pq.pop();
    while (!pq.empty()) {
      if (pq.top() == popped) {
        occurences += 1;
      } else {
        if (occurences > max) {
          max = occurences;
          mode = popped;
          occurences = 0;
        }
      }
      popped = pq.top();
      pq.pop();
    }

    output_count = 1;
    ostr << mode << "\n";


  } else if (type == "integer") {
    // load the data into a priority queue of integers
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      pq.push(i);
      input_count++;
      output_count++;
    }

    int max = 0;
    int occurences = 0;
    int mode = pq.top();
    int popped = pq.top();
    pq.pop();
    while (!pq.empty()) {
      if (pq.top() == popped) {
        occurences += 1;
      } else {
        if (occurences > max) {
          max = occurences;
          mode = pq.top();
          occurences = 0;
        }
      }
      popped = pq.top();
      pq.pop();
    }

    output_count = 1;
    ostr << mode << "\n";

  }


}


// note: closest_pair is only available for integer data (not string data)
void priority_queue_closest_pair(std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  // load the data into a priority queue of integers
  std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
  int i;
  input_count = 0;
  output_count = 0;
  while (istr >> i) {
    pq.push(i);
    input_count++;
  }

  assert (pq.size() >= 2);

  int best;
  int item1 = NULL;
  int item2;
  // the two elements with closest value must be next to each other in sorted order
  // keep track of two iterators into the structure

  int popped = pq.top();
  pq.pop();
  while (!pq.empty()) {
    if (pq.top() == popped) {
      item1 = popped;
      item2 = pq.top();
      break;
    } else {
      int diff = pq.top() - popped;
      if (item1 == NULL || diff < best) {
        best = diff;
        item1 = popped;
        item2 = pq.top();
      }
    }
    popped = pq.top();
    pq.pop();
  } 
    

  // print the two elements
  output_count = 2;
  ostr << item1 << "\n";
  ostr << item2 << "\n";

}



void priority_queue_first_sorted(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int optional_arg, int &input_count) {
  assert (optional_arg >= 1);

  if (type == "string") {
    // load the data into a priority queue of strings
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      pq.push(s);
      input_count++;
      output_count++;
    }
    assert ((int)pq.size() >= optional_arg);
    output_count = optional_arg;
    int count = 0;

    while (!pq.empty()) {
      ostr << pq.top() << "\n";
      pq.pop();
      count++;
      if(count == output_count) {
        break;
      }
    }

  } else if (type == "integer") {
    // load the data into a priority queue of integers
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      pq.push(i);
      input_count++;
      output_count++;
    }
    assert ((int)pq.size() >= optional_arg);
    output_count = optional_arg;
    int count = 0;

    while (!pq.empty()) {
      ostr << pq.top() << "\n";
      pq.pop();
      count++;
      if(count == output_count) {
        break;
      }
    }

  }

}


// note: longest_substring is only available for string data (not integer data)
void priority_queue_longest_substring(std::ostream &ostr, int &output_count, int &input_count) {

  input_count = 0;
  output_count = 0;
  ostr << "It is not feasible/sensible to implement this operation in this data structure.\n";
  
}


void priority_queue_test(const std::string &operation, const std::string &type,
                         std::istream &istr, std::ostream &ostr,
                         int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your priority_queue like this:

  // std::priority_queue<std::string,std::vector<std::string> > pq;
  // (this will make a "max" priority queue, with big values at the top)

  // OR
  
  // std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pq;
  // (this will make a "min" priority queue, with big values at the bottom)

  if (type == "string") {

    if      (operation == "sort")              { priority_queue_sort              (type,istr,ostr,output_count,input_count); }
    else if (operation == "remove_duplicates") { priority_queue_remove_duplicates (type,istr,ostr,output_count,input_count); }
    else if (operation == "mode")              { priority_queue_mode              (type,istr,ostr,output_count,input_count); }
    // "closest_pair" not available for strings
    else if (operation == "first_sorted")      { priority_queue_first_sorted      (type,istr,ostr,output_count,optional_arg,input_count); }
    else if (operation == "longest_substring") { priority_queue_longest_substring (ostr,output_count,input_count); }
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  else {
    assert (type == "integer");

    if      (operation == "sort")              { priority_queue_sort              (type,istr,ostr,output_count,input_count); }
    else if (operation == "remove_duplicates") { priority_queue_remove_duplicates (type,istr,ostr,output_count,input_count); }
    else if (operation == "mode")              { priority_queue_mode              (type,istr,ostr,output_count,input_count); }
    else if (operation == "closest_pair")      { priority_queue_closest_pair      (istr,ostr,output_count,input_count); }
    else if (operation == "first_sorted")      { priority_queue_first_sorted      (type,istr,ostr,output_count,optional_arg,input_count); }
    // "longest_substring" not available for integers
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

}
