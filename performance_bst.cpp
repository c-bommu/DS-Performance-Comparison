#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>


// defined in performance.cpp
void usage();


void bst_sort(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {
  if (type == "string") {
    // load the data into a map of strings
    std::map<std::string, int> mp;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      ++mp[s];
      input_count++;
      output_count++;
  	}

	for (typename std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
		for (int i = 0; i < itr->second; i++) {
			ostr << itr->first << "\n";
		}
	}

  } else if (type == "integer") {
    // load the data into a map of integers
    std::map<int, int> mp;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      ++mp[i];
      input_count++;
      output_count++;
    }

	for (typename std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
		for (int i = 0; i < itr->second; i++) {
			ostr << itr->first << "\n";
		}
	}

  }

}


void bst_remove_duplicates(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) { 

  if (type == "string") {
    // load the data into a map of strings
    std::map<std::string, int> mp;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      ++mp[s];
      input_count++;
      output_count++;
      typename std::map<std::string, int>::iterator itr = mp.find(s);
      if (itr->second == 1) {
      	ostr << itr->first << "\n"; // printing as strings are being inputted so that order is preserved
      }
  	}

  } else if (type == "integer") {
    // load the data into a map of integers
    std::map<int, int> mp;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      ++mp[i];
      input_count++;
      output_count++;
      typename std::map<int, int>::iterator itr = mp.find(i);
      if (itr->second == 1) {
      	ostr << itr->first << "\n"; // printing as integers are being inputted so that order is preserved
      }
    }

  }


}


void bst_mode(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  if (type == "string") {
    // load the data into a map of strings
    std::map<std::string, int> mp;
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
	std::map<std::string, int>::iterator itr = mp.begin();
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
    std::map<int, int> mp;
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
	std::map<int, int>::iterator itr = mp.begin();
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
void bst_closest_pair(std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {

  // load the data into a map of integers
  std::map<int, int> mp;
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
  typename std::map<int, int>::iterator current = mp.begin();
  ++current;
  typename std::map<int, int>::iterator previous = mp.begin();
  for (; current != mp.end(); ++current, ++previous) {
    int diff = (current->first)-(previous->first);
    if (previous->second > 1) {
      item1 = previous->first;
      item2 = previous->first;
      break;
    } else if (item1 == NULL || diff < best) {
      best = diff;
      item1 = previous->first;
      item2 = current->first;
    }
  }
  // print the two elements
  output_count = 2;
  ostr << item1 << "\n";
  ostr << item2 << "\n";

}



void bst_first_sorted(const std::string &type, std::istream &istr, std::ostream &ostr, int &output_count, int optional_arg, int &input_count) {
  assert (optional_arg >= 1);

  if (type == "string") {
    // load the data into a map of strings
    std::map<std::string, int> mp;
    std::string s;
    input_count = 0;
    output_count = 0;
    while (istr >> s) {
      ++mp[s];
      input_count++;
  	}
  	assert ((int)mp.size() >= optional_arg);
  	output_count = optional_arg;
  	int count = 0;

	for (typename std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
		ostr << itr->first << "\n";
		count++;
		if (count == output_count) {
			break;
		}
	}

  } else if (type == "integer") {
    // load the data into a map of integers
    std::map<int, int> mp;
    int i;
    input_count = 0;
    output_count = 0;
    while (istr >> i) {
      ++mp[i];
      input_count++;
    }
    assert ((int)mp.size() >= optional_arg);
    output_count = optional_arg;
    int count = 0;

	for (typename std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
		ostr << itr->first << "\n";
		count++;
		if (count == output_count) {
			break;
		}
	}

  }


}


// note: longest_substring is only available for string data (not integer data)
void bst_longest_substring(std::istream &istr, std::ostream &ostr, int &output_count, int &input_count) {
  
  // load the data into a map of strings
  std::map<std::string, int> mp;
  std::string s;
  input_count = 0;
  while (istr >> s) {
  	++mp[s];
  	input_count++;
  }
  output_count = 1;

  std::string result = "";

  for (typename std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    std::string str = itr->first;

    for (int i = 0; i < str.length(); i++) {
      for (int j = i + 1; j <= str.length(); j++) {
        std::string sub = str.substr(i, j);
        int match = 0;

        for (typename std::map<std::string, int>::iterator itr2 = mp.begin(); itr2 != mp.end(); ++itr2) {
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


void bst_test(const std::string &operation, const std::string &type,
              std::istream &istr, std::ostream &ostr,
              int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your binary search tree (BST) like this:
  // std::set<std::string> st;
  // OR 
  // std::map<std::string,int> mp;

  if (type == "string") {

    if      (operation == "sort")              { bst_sort              (type,istr,ostr,output_count,input_count); }
    else if (operation == "remove_duplicates") { bst_remove_duplicates (type,istr,ostr,output_count,input_count); }
    else if (operation == "mode")              { bst_mode              (type,istr,ostr,output_count,input_count); }
    // "closest_pair" not available for strings
    else if (operation == "first_sorted")      { bst_first_sorted      (type,istr,ostr,output_count,optional_arg,input_count); }
    else if (operation == "longest_substring") { bst_longest_substring (istr,ostr,output_count,input_count); }
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  else {
    assert (type == "integer");

    if      (operation == "sort")              { bst_sort              (type,istr,ostr,output_count,input_count); }
    else if (operation == "remove_duplicates") { bst_remove_duplicates (type,istr,ostr,output_count,input_count); }
    else if (operation == "mode")              { bst_mode              (type,istr,ostr,output_count,input_count); }
    else if (operation == "closest_pair")      { bst_closest_pair      (istr,ostr,output_count,input_count); }
    else if (operation == "first_sorted")      { bst_first_sorted      (type,istr,ostr,output_count,optional_arg,input_count); }
    // "longest_substring" not available for integers
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }


}
