#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>


// defined in performance.cpp
void usage();

template <class T>
void list_sort(std::list<T> &lst, std::ostream &ostr, int &output_count) {
  // use  list sort
  lst.sort();
  
  output_count = lst.size();
  for (typename std::list<T>::const_iterator itr = lst.begin(); itr != lst.end(); itr++) {
  	ostr << *itr << "\n";
  }

}


template <class T>
void list_remove_duplicates(const std::list<T> &lst, std::ostream &ostr, int &output_count) { 
  // don't reorder the elements, just do all pairwise comparisons
  output_count = 0;
  for (typename std::list<T>::const_iterator itr = lst.begin(); itr != lst.end(); itr++) {
    bool dup = false;
    for (typename std::list<T>::const_iterator itr2 = lst.begin(); itr2 != itr; itr2++) {
      if (*itr == *itr2) {
        dup = true;
        break;
      }
    }
    // if it has not already been added to the output list
    if (!dup) {
      ostr << *itr << "\n";
      output_count++;
    }
  }
}


template <class T>
void list_mode(std::list<T> &lst, std::ostream &ostr, int &output_count) {
  // use list sort
  lst.sort();
  int current_count = 1;
  T mode;
  int mode_count = 0;
  // keep track of two iterators into the structure
  typename std::list<T>::const_iterator current = lst.begin();
  ++current;
  typename std::list<T>::const_iterator previous = lst.begin();
  for (; current != lst.end(); ++current, ++previous) {
    if (*current == *previous) {
      // if they are the same element increment the count
      current_count++;
    } else if (current_count >= mode_count) {
      // found a new mode!
      mode = *previous;
      mode_count = current_count;
      current_count = 1;
    } else {
      current_count = 1;
    }
  }
  if (current_count >= mode_count) {
    // last entry is a new mode!
    mode = *previous;
    mode_count = current_count;
  }
  // save the mode to the output vector
  output_count = 1;
  ostr << mode << "\n";
}


// note: closest_pair is only available for integer data (not string data)
void list_closest_pair(std::list<int> &lst, std::ostream &ostr, int &output_count) {
  assert (lst.size() >= 2);
  // use list sort
  lst.sort();
  output_count = 2;
  int best;
  int item1 = NULL;
  int item2;
  // the two elements with closest value must be next to each other in sorted order
  // keep track of two iterators into the structure
  typename std::list<int>::const_iterator current = lst.begin();
  ++current;
  typename std::list<int>::const_iterator previous = lst.begin();
  for (; current != lst.end(); ++current, ++previous) {
    int diff = *current-*previous;
    if (item1 == NULL || diff < best) {
      best = diff;
      item1 = *previous;
      item2 = *current;
    }
  }
  // print the two elements
  output_count = 2;
  ostr << item1 << "\n";
  ostr << item2 << "\n";
}


template <class T>
void list_first_sorted(std::list<T> &lst, std::ostream &ostr, int &output_count, int optional_arg) {
  assert (optional_arg >= 1);
  assert ((int)lst.size() >= optional_arg);
  // use list sort
  lst.sort();
  output_count = optional_arg;
  int count = 0;
  for (typename std::list<T>::const_iterator itr = lst.begin(); itr != lst.end(); itr++) {
    ostr << *itr << "\n";
    count++;
    if (count == output_count) {
    	break;
    }
  }
}


// note: longest_substring is only available for string data (not integer data)
void list_longest_substring(std::list<std::string> &lst, std::ostream &ostr, int &output_count) {
  std::string result = "";

  for (typename std::list<std::string>::const_iterator itr = lst.begin(); itr != lst.end(); itr++) {
    std::string str = *itr;

    for (int i = 0; i < str.length(); i++) {
      for (int j = i + 1; j <= str.length(); j++) {
        std::string sub = str.substr(i, j);
        int match = 0;

        for (typename std::list<std::string>::const_iterator itr2 = lst.begin(); itr2 != lst.end(); itr2++) {
          if (((*itr2).find(sub) != std::string::npos) && (*itr2 != str)) {
            match += 1;
            break;
          }
        }
        if ((result.length() < sub.length()) && (match != 0)) {
          result = sub;
        }

      }
    }

  }

  output_count = 1;

  ostr << result << "\n";
  
}


void list_test(const std::string &operation, const std::string &type,
                 std::istream &istr, std::ostream &ostr,
                 int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your list like this:
  // std::list<std::string> lst;

  if (type == "string") {
    // load the data into a list of strings
    std::list<std::string> lst;
    std::string s;
    input_count = 0;
    while (istr >> s) {
      lst.push_back(s);
      input_count++;
    }
    if      (operation == "sort")              { list_sort              (lst,ostr,output_count); }
    else if (operation == "remove_duplicates") { list_remove_duplicates (lst,ostr,output_count); }
    else if (operation == "mode")              { list_mode              (lst,ostr,output_count); }
    // "closest_pair" not available for strings
    else if (operation == "first_sorted")      { list_first_sorted      (lst,ostr,output_count,optional_arg); }
    else if (operation == "longest_substring") { list_longest_substring (lst,ostr,output_count); }
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  else {
    assert (type == "integer");
    // load the data into a list of integers
    std::list<int> lst;
    int i;
    input_count = 0;
    while (istr >> i) {
      lst.push_back(i);
      input_count++;
    }
    if      (operation == "sort")              { list_sort              (lst,ostr,output_count); }
    else if (operation == "remove_duplicates") { list_remove_duplicates (lst,ostr,output_count); }
    else if (operation == "mode")              { list_mode              (lst,ostr,output_count); }
    else if (operation == "closest_pair")      { list_closest_pair      (lst,ostr,output_count); }
    else if (operation == "first_sorted")      { list_first_sorted      (lst,ostr,output_count,optional_arg); }
    // "longest_substring" not available for integers
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }
}
