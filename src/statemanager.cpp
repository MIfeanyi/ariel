#include "statemanager.hpp"
#include <iostream>

void StateManager::AddState(State & s){
    States.push_back(s);
}

void StateManager::init(){

}

void StateManager::Run(){

}

bool StateManager::SwitchState(std::string n){
    for(State S : States){
        if(S.GetName()==n){
            CurrentState = S.GetName();
            return true;
        }
    }
    return false;
}
std::string StateManager::GetState(){
    return CurrentState;
}

void StateManager::Update(sf::Event & e){
    for(State S : States){
        if(S.GetName()==CurrentState){
            S.Update(e);
            //std::cout<<"Found: "<<CurrentState<<"/n";
        }
    }
}
void StateManager::Render(sf::RenderWindow & w){
    for(State S : States){
        if(S.GetName()==CurrentState){
            S.Render(w);
            //std::cout<<"Rendering: "<<CurrentState<<"/n";
        }
    }
}