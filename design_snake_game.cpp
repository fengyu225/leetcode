/*
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)
*/

#include "header.h"

class SnakeGame {
    vector<pair<int,int> > food;
    int width;
    int height;
    int curr_food;
    unordered_set<int> occupied;
    deque<pair<int,int> > body;
    unordered_map<string, pair<int,int> > pos_map = {
        {"U", {-1, 0}},
        {"L", {0, -1}},
        {"R", {0, 1}},
        {"D", {1, 0}}
    };
    bool valid(string direction, pair<int,int>& next_pos){
        pair<int,int> p = pos_map[direction]; 
        pair<int,int> curr_pos = this->body.front();
        next_pos.first = curr_pos.first+p.first;
        next_pos.second = curr_pos.second+p.second;
        if(next_pos.first<0 || next_pos.first>=this->height) return false;
        if(next_pos.second<0 || next_pos.second>=this->width) return false;
        return true;
    }
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        this->body.push_back(make_pair(0,0));
        this->occupied.insert(0);
        this->curr_food = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int> new_pos;
        bool res = this->valid(direction, new_pos);
        if(!res) return -1;
        if(this->curr_food<this->food.size() && new_pos.first == this->food[this->curr_food].first && new_pos.second == this->food[this->curr_food].second){
            this->curr_food++;
        }
        else{
            pair<int,int> tail = this->body.back();
            this->body.pop_back();
            this->occupied.erase(this->occupied.find(tail.first*this->width+tail.second));
            if(this->occupied.find(new_pos.first*this->width+new_pos.second) != this->occupied.end()) return -1;
        }
        this->body.push_front(new_pos);
        this->occupied.insert(new_pos.first*this->width + new_pos.second);
        return this->curr_food;    
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

int main(){
//    SnakeGame* obj = new SnakeGame(3, 2, vector<pair<int,int> >{{1, 2}, {0, 1}});
//    cout<<obj->move("R")<<endl;
//    cout<<obj->move("D")<<endl;
//    cout<<obj->move("R")<<endl;
//    cout<<obj->move("U")<<endl;
//    cout<<obj->move("L")<<endl;
//    cout<<obj->move("U")<<endl;
    
    SnakeGame* obj = new SnakeGame(3, 3, vector<pair<int,int> >{{2, 0}, {0, 0}, {0, 2}, {2, 2}});
    cout<<obj->move("D")<<endl;
    cout<<obj->move("D")<<endl;
    cout<<obj->move("R")<<endl;
    cout<<obj->move("U")<<endl;
    cout<<obj->move("U")<<endl;
    cout<<obj->move("L")<<endl;
    cout<<obj->move("D")<<endl;
    cout<<obj->move("R")<<endl;
    cout<<obj->move("R")<<endl;
    cout<<obj->move("U")<<endl;
    cout<<obj->move("L")<<endl;
    cout<<obj->move("D")<<endl;
    return 0;
}
