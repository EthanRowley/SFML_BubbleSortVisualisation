#include "SFML/Graphics.hpp"
#include "headers/Bar.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>


void doBubble(sf::RenderWindow &window,std::vector<Bar*> *bars, bool &sorted);

int main(int argc, char* argv[]){
    
    std::srand(std::time(0));
    sf::RenderWindow window(sf::VideoMode(1280,720), "Bubble Sort Visualisation");

    std::vector<Bar*> bars;
    std::vector<Bar*> *barPtr = &bars;
    int counter = 0;
    bool sorted = false;
    

    for (int i = 0; i < 128; i++){
        Bar* b = new Bar(sf::Vector2f(10.f * i, 720.f));
        b->height = -((std::rand() % 720) + 1);
        b->body.setSize(sf::Vector2f(b->width, b->height));
        bars.push_back(b);
    }

    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
            }

        }

        if (counter == 0){
            // Bubble handles draw
            doBubble(window, barPtr, sorted);
            counter++;
            
        } 
        

    }
    
    return 0;
}


void doBubble(sf::RenderWindow& window, std::vector<Bar*> *bars, bool& sorted){

    window.clear(sf::Color::White);
    for (int i = 0; i < 128; i++){
        window.draw((*bars).at(i)->body);
    }
    window.display();
            
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Start" << std::endl;

    Bar* temp;
    int i, j;
    for (i = (*bars).size()-1; i > 0; i--){
        for (j = 0; j < i; j++){
            
            window.clear(sf::Color::White);
            for (int i = 0; i < 128; i++){
                window.draw((*bars).at(i)->body);
            }
            window.display();
            
            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            if (temp != NULL){
                temp->body.setFillColor(sf::Color::White);
            }


            if ((*bars).at(j)->body.getSize().y > (*bars).at(j+1)->body.getSize().y){
                temp = (*bars).at(j);
                sf::Vector2f tempPos = (*bars).at(j)->body.getPosition();
                (*bars).at(j)->body.setPosition((*bars).at(j+1)->body.getPosition());
                (*bars).at(j+1)->body.setPosition(tempPos);
                (*bars).at(j) = (*bars).at(j+1);
                (*bars).at(j+1) = temp;
                temp->body.setFillColor(sf::Color::Blue);
            }
            

        }
    }

    sorted = true;



}

