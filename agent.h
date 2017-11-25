#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "tinyRandomMap.h"

class Agent {
public:
  Agent(unsigned int, tinyRandomMap *);
  ~Agent();
  void print_nodes();
  //void matrix_DFS(unsigned int init_x, unsigned int init_y);
  void update_current(unsigned int, unsigned int);
  void move(char);
  void found_wumpus();
  void print_m_map();
  unsigned char get_bits(unsigned int, unsigned int);
private:
  class Node {
  public:
    Node(unsigned int, unsigned int, int);
    int m_value;
    enum Color {white, gray, black};
    enum State {present, clear, unknown};
    State wumpus;
    State pit;
    bool safe; 
    Node * parent;
    Color color;
    unsigned int node_x_position;
    unsigned int node_y_position;
  };
  std::vector< std::vector< Node * > > internal_map;
  unsigned int agent_x_position;
  unsigned int agent_y_position;
  unsigned int m_dimension;
  tinyRandomMap * m_map;
protected:
};
#endif