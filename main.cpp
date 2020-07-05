#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<vector>
#include<utility>
#include<iterator>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<ctime>
using std::pair;using std::vector;using std::string;
#include"wall.h"
#include"piece.h"
int main(){
    bool turn=true,is_over=false,red_wins=false,blue_wins=false;
    sf::RenderWindow window(sf::VideoMode(500,500),"Tic Tac Toe");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
        int turn_count=1;
        Wall v_wall1(50,400,150,50),v_wall2(50,400,300,50),h_wall1(400,50,50,150),h_wall2(400,50,50,300);
        window.clear(sf::Color::White);
        window.draw(v_wall1.getRectangle());
        window.draw(v_wall2.getRectangle());
        window.draw(h_wall1.getRectangle());
        window.draw(h_wall2.getRectangle());
        static Piece x1(1,50,50),x2(1,200,50),x3(1,350,50),x4(1,50,200),x5(1,200,200),x6(1,350,200),x7(1,50,350),x8(1,200,350),x9(1,350,350),
        o1(0,50,50),o2(0,200,50),o3(0,350,50),o4(0,50,200),o5(0,200,200),o6(0,350,200),o7(0,50,350),o8(0,200,350),o9(0,350,350);
        vector<Piece*>pieces;
        pieces.push_back(&x1);pieces.push_back(&x2);pieces.push_back(&x3);pieces.push_back(&x4);pieces.push_back(&x5);
        pieces.push_back(&x6);pieces.push_back(&x7);pieces.push_back(&x8);pieces.push_back(&x9);
        pieces.push_back(&o1);pieces.push_back(&o2);pieces.push_back(&o3);pieces.push_back(&o4);pieces.push_back(&o5);
        pieces.push_back(&o6);pieces.push_back(&o7);pieces.push_back(&o8);pieces.push_back(&o9);
        for(auto iter=pieces.begin();iter!=pieces.end();++iter){
            if((**iter).is_played){
                (**iter).draw_piece(window);
                ++turn_count;
            }
        }
        turn=turn_count%2;
        string turn_name=std::to_string(turn_count);
        if(is_over==false){
            window.setTitle("Tic Tac Toe (Turn "+turn_name+")");
        }
        if(turn_count==10 && !red_wins && !blue_wins){
            window.setTitle("Tie!");
            is_over=true;
        }
        if(turn){
            for(auto iter=pieces.begin();iter!=pieces.begin()+9;++iter){
                if((**iter).hover(window)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        (**iter).draw_piece(window);
                        (**(iter+9)).disable();
                    }
                }
            }
        }else{
            if(!is_over){
                srand(time(NULL));
                if(((o2.is_played && o3.is_played) || (o4.is_played && o7.is_played) || (o5.is_played && x9.is_played)) && o1.is_played==false && x1.is_played==false){
                    o1.draw_piece(window);
                    x1.disable();
                }else if(((o1.is_played && o3.is_played) || (o5.is_played && o8.is_played)) && o2.is_played==false && x2.is_played==false){
                    o2.draw_piece(window);
                    x2.disable();
                }else if(((o1.is_played && o2.is_played) || (o6.is_played && o9.is_played) || (o5.is_played && o7.is_played)) && o3.is_played==false && x3.is_played==false){
                    o3.draw_piece(window);
                    x3.disable();
                }else if(((o1.is_played && o7.is_played) || (o5.is_played && o6.is_played)) && o4.is_played==false && x4.is_played==false){
                    o4.draw_piece(window);
                    x4.disable();
                }else if(((o1.is_played && o9.is_played) || (o2.is_played && o8.is_played) || (o3.is_played && o7.is_played) || (o4.is_played && o6.is_played)) && o5.is_played==false && x5.is_played==false){
                    o5.draw_piece(window);
                    x5.disable();
                }else if(((o4.is_played && o5.is_played) || (o3.is_played && o9.is_played)) && o6.is_played==false && x6.is_played==false){
                    o6.draw_piece(window);
                    x6.disable();
                }else if(((o1.is_played && o4.is_played) || (o8.is_played && o9.is_played) || (o3.is_played && o5.is_played)) && o7.is_played==false && x7.is_played==false){
                    o7.draw_piece(window);
                    x7.disable();
                }else if(((o7.is_played && o9.is_played) || (o2.is_played && o5.is_played)) && o8.is_played==false && x8.is_played==false){
                    o8.draw_piece(window);
                    x8.disable();
                }else if(((o7.is_played && o8.is_played) || (o1.is_played && o5.is_played) || (o3.is_played && o6.is_played)) && o9.is_played==false && x9.is_played==false){
                    o9.draw_piece(window);
                    x9.disable();
                }else if(((x2.is_played && x3.is_played) || (x4.is_played && x7.is_played) || (x5.is_played && x9.is_played)) && o1.is_played==false && x1.is_played==false){
                    o1.draw_piece(window);
                    x1.disable();
                }else if(((x1.is_played && x3.is_played) || (x5.is_played && x8.is_played)) && o2.is_played==false && x2.is_played==false){
                    o2.draw_piece(window);
                    x2.disable();
                }else if(((x1.is_played && x2.is_played) || (x6.is_played && x9.is_played) || (x5.is_played && x7.is_played)) && o3.is_played==false && x3.is_played==false){
                    o3.draw_piece(window);
                    x3.disable();
                }else if(((x1.is_played && x7.is_played) || (x5.is_played && x6.is_played)) && o4.is_played==false && x4.is_played==false){
                    o4.draw_piece(window);
                    x4.disable();
                }else if(((x1.is_played && x9.is_played) || (x2.is_played && x8.is_played) || (x3.is_played && x7.is_played) || (x4.is_played && x6.is_played)) && o5.is_played==false && x5.is_played==false){
                    o5.draw_piece(window);
                    x5.disable();
                }else if(((x4.is_played && x5.is_played) || (x3.is_played && x9.is_played)) && o6.is_played==false && x6.is_played==false){
                    o6.draw_piece(window);
                    x6.disable();
                }else if(((x1.is_played && x4.is_played) || (x8.is_played && x9.is_played) || (x3.is_played && x5.is_played)) && o7.is_played==false && x7.is_played==false){
                    o7.draw_piece(window);
                    x7.disable();
                }else if(((x7.is_played && x9.is_played) || (x2.is_played && x5.is_played)) && o8.is_played==false && x8.is_played==false){
                    o8.draw_piece(window);
                    x8.disable();
                }else if(((x7.is_played && x8.is_played) || (x1.is_played && x5.is_played) || (x3.is_played && x6.is_played)) && o9.is_played==false && x9.is_played==false){
                    o9.draw_piece(window);
                    x9.disable();
                }else{
                    int random;
                    do{
                        random=(rand()%9);
                    }while((**(pieces.begin()+9+random)).is_played || (**(pieces.begin()+9+random)).is_disabled);
                    auto random_iterator=(pieces.begin()+9+random);
                    (**random_iterator).draw_piece(window);
                    (**(random_iterator-9)).disable();
                }
            }

        }
        if(is_over){
            for(auto iter=pieces.begin();iter!=pieces.end();++iter){
                if((**iter).is_played==false){
                    (**iter).disable();
                }
            }
        }
        if((x1.is_played && x2.is_played && x3.is_played) || (x4.is_played && x5.is_played && x6.is_played) || (x7.is_played && x8.is_played && x9.is_played) ||
           (x1.is_played && x4.is_played && x7.is_played) || (x2.is_played && x5.is_played && x8.is_played) || (x3.is_played && x6.is_played && x9.is_played) ||
           (x1.is_played && x5.is_played && x9.is_played) || (x3.is_played && x5.is_played && x7.is_played)){
                window.setTitle("Red Wins!");
                is_over=true;
                red_wins=true;
        }
        if((o1.is_played && o2.is_played && o3.is_played) || (o4.is_played && o5.is_played && o6.is_played) || (o7.is_played && o8.is_played && o9.is_played) ||
           (o1.is_played && o4.is_played && o7.is_played) || (o2.is_played && o5.is_played && o8.is_played) || (o3.is_played && o6.is_played && o9.is_played) ||
           (o1.is_played && o5.is_played && o9.is_played) || (o3.is_played && o5.is_played && o7.is_played)){
                window.setTitle("Blue Wins!");
                is_over=true;
                blue_wins=true;
        }
        window.display();
    }
}
