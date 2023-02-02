#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>


// defined in performance.cpp
void usage();


void hash_table_sort(std::ostream &ostr, int &output_count, int &input_count) {
  
  input_count = 0;
  output_count = 0;
  ostr << "It is not feasible/sensible to implement this operation in this data structure.\n";

}


void hash_table_remove_duplicates(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) { 

  if (type == "string") {
    // load the data into an unordered map of strings
    std::unordered_map<std::string, int> mp;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      ++mp[s];
      input_count++;
      output_count++;
      typename std::unordered_map<std::string, int>::iterator itr = mp.find(s);
      if (itr->second == 1) {
      	ostr << itr->first << "\n";
      }
  	}

  } else if (type == "integer") {
    // load the data into a map of integers
    std::unordered_map<int, int> mp;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      ++mp[i];
      input_count++;
      output_count++;
      typename std::unordered_map<int, int>::iterator itr = mp.find(i);
      if (itr->second == 1) {
      	ostr << itr->first << "\n";
      }
    }

  }


}


void hash_table_mode(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  if (type == "string") {
    // load the data into a map of strings
    std::unordered_map<std::string, int> mp;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      ++mp[s];
      input_count++;
      output_count++;
  	}

	std::string mode = (mp.begin())->first;
	int occurences = (mp.begin())->second;
	std::unordered_map<std::string, int>::iterator itr = mp.begin();
	++itr;
	for (; itr != mp.end(); ++itr) {
		if (itr->second > occurences) {
			mode = itr->first;
			occurences = itr->second;
		}
	}

	output_count = 1;
    ostr << mode << "\n";


  } else if (type == "integer") {
    // load the data into a map of integers
    std::unordered_map<int, int> mp;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      ++mp[i];
      input_count++;
      output_count++;
    }

	int mode = (mp.begin())->first;
	int occurences = (mp.begin())->second;
	std::unordered_map<int, int>::iterator itr = mp.begin();
	++itr;
	for (; itr != mp.end(); ++itr) {
		if (itr->second > occurences) {
			mode = itr->first;
			occurences = itr->second;
		}
	}

	output_count = 1;
    ostr << mode << "\n";

  }


}


// note: closest_pair is only available for integer data (not string data)
void hash_table_closest_pair(std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  // load the data into a map of integers
  std::unordered_map<int, int> mp;
  int i;
  input_count = 0;
  output_count = 0;
  while (istr >> i) {
  	++mp[i];
  	input_count++;
  	output_count++;
  }

  assert (mp.size() >= 2);

  output_count = 2;
  int best;
  int item1 = NULL;
  int item2;
  // the two elements with closest value must be next to each other in sorted order
  // keep track of two iterators into the structure

  for (std::unordered_map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    if (itr->second > 1) {
      item1 = itr->first;
      item2 = itr->first;
      break;
    } else {
    	for (std::unordered_map<int, int>::iterator itr2 = mp.begin(); itr2 != mp.end(); ++itr2) {
    		if (itr2->first == itr->first) {
    			continue;
    		} else {
    			int big;
    			int small;
    			if ((itr->first) > (itr2 -> first)) {
    				big = itr->first;
    				small = itr2->first;
    			} else {
    				big = itr2->first;
    				small = itr->first;
    			}
    			int diff = big-small;
    			if (item1 == NULL || diff < best) {
			        best = diff;
			        item1 = small;
			        item2 = big;
		    	}
    		}
    	}
    }

  }
  // print the two elements
  output_count = 2;
  ostr << item1 << "\n";
  ostr << item2 << "\n";

}



void hash_table_first_sorted(std::ostream &ostr, int &output_count, int &input_count) {

  input_count = 0;
  output_count = 0;
  ostr << "It is not feasible/sensible to implement this operation in this data structure.\n";

}


// note: longest_substring is only available for string data (not integer data)
void hash_table_longest_substring(std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {
  
  // load the data into an unordered map of strings
  std::unordered_map<std::string, int> mp;
  std::string s;
  input_count = 0;
  while (istr >> s) {
  	++mp[s];
  	input_count++;
  }
  output_count = 1;

  std::string result = "";

  for (typename std::unordered_map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    std::string str = itr->first;

    for (int i = 0; i < str.length(); i++) {
      for (int j = i + 1; j <= str.length(); j++) {
        std::string sub = str.substr(i, j);
        int match = 0;

        for (typename std::unordered_map<std::string, int>::iterator itr2 = mp.begin(); itr2 != mp.end(); ++itr2) {
          if (((itr2->first).find(sub) != std::string::npos) && ((itr2->first) != str)) {
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

  ostr << result << "\n";
  
}


void hash_table_test(const std::string &operation, const std::string &type,
                     std::istream &istr, std::ostream &ostr,
                     int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your hash table like this:
  // std::unordered_set<std::string> ht;
  // OR 
  // std::unordered_map<std::string,int> ht;

  if (type == "string") {

    if      (operation == "sort")              { hash_table_sort              (ostr,output_count,input_count); }
    else if (operation == "remove_duplicates") { hash_table_remove_duplicates (type,istr,ostr,output_count,input_count); }
    else if (operation == "mode")              { hash_table_mode              (type,istr,ostr,output_count,input_count); }
    // "closest_pair" not available for strings
    else if (operation == "first_sorted")      { hash_table_first_sorted      (ostr,output_count,input_count); }
    else if (operation == "longest_substring") { hash_table_longest_substring (istr,ostr,output_count,input_count); }
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  else {
    assert (type == "integer");

    if      (operation == "sort")              { hash_table_sort              (ostr,output_count,input_count); }
    else if (operation == "remove_duplicates") { hash_table_remove_duplicates (type,istr,ostr,output_count,input_count); }
    else if (operation == "mode")              { hash_table_mode              (type,istr,ostr,output_count,input_count); }
    else if (operation == "closest_pair")      { hash_table_closest_pair      (istr,ostr,output_count,input_count); }
    else if (operation == "first_sorted")      { hash_table_first_sorted      (ostr,output_count,input_count); }
    // "longest_substring" not available for integers
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

}
