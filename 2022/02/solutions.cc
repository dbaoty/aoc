#include <iostream>
#include <fstream>

int part_one(std::fstream &input){
  input.open("input.txt");
  int score = 0;
  std::string line = "";

  while(std::getline(input, line)){
    char opp = line[0];
    char you = line[2];

    switch(opp){
      case 'A':
        switch(you){
          case 'X': score += 4; break;
          case 'Y': score += 8; break;
          case 'Z': score += 3; break;
        }; break;
      case 'B':
        switch(you){
          case 'X': score += 1; break;
          case 'Y': score += 5; break;
          case 'Z': score += 9; break;
        }; break;
      case 'C':
        switch(you){
          case 'X': score += 7; break;
          case 'Y': score += 2; break;
          case 'Z': score += 6; break;
        }; break;
    };
  }

  input.close();
  return score;
}

int part_two(std::fstream &input){
  input.open("input.txt");
  int score = 0;
  std::string line = "";

  while(std::getline(input, line)){
    char opp = line[0];
    char out = line[2];
    char you {};

    switch(out){
      case 'X':
        switch(opp){
          case 'A': you = 'Z'; break;
          case 'B': you = 'X'; break;
          case 'C': you = 'Y'; break;
        }; break;
      case 'Y':
        switch(opp){
          case 'A': you = 'X'; break;
          case 'B': you = 'Y'; break;
          case 'C': you = 'Z'; break;
        }; break;
      case 'Z':
        switch(opp){
          case 'A': you = 'Y'; break;
          case 'B': you = 'Z'; break;
          case 'C': you = 'X'; break;
        }; break;
    };

    switch(opp){
      case 'A':
        switch(you){
          case 'X': score += 4; break;
          case 'Y': score += 8; break;
          case 'Z': score += 3; break;
        }; break;
      case 'B':
        switch(you){
          case 'X': score += 1; break;
          case 'Y': score += 5; break;
          case 'Z': score += 9; break;
        }; break;
      case 'C':
        switch(you){
          case 'X': score += 7; break;
          case 'Y': score += 2; break;
          case 'Z': score += 6; break;
        }; break;
    };
  }

  input.close();
  return score;
}

int main(int argc, char **argv){
  std::fstream input;
  std::cout << "Part one solution: " << part_one(input) << std::endl;
  std::cout << "Part two solution: " << part_two(input) << std::endl;

  return 0;
}
