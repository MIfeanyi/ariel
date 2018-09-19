#include "statemanager.hpp"
#include <iostream>
template <class T>
void StateManager::AddState(T & s){
    States.push_back(&s);
    std::cout<<"Total States: "<<States.size()<<std::endl<<"State: "<<States[States.size()-1]->GetName()<<" added."<<std::endl;
}
template <class T>
void StateManager<T>::Init(){
    std::cout<<"Initialized State"<<std::endl<<"Size: "<<States.size()<<std::endl;
}
template <class T>
void StateManager<T>::Run(){

}

template <class T>
bool StateManager<T>::SwitchState(std::string n){
    for(T* S : States){
        if(S->GetName()==n){
            CurrentState = S->GetName();
            return true;
        }
    }
    return false;
}
template <class T>
T StateManager<T>::GetState(){
    return CurrentState;
}
template <class T>
void StateManager<T>::Update(sf::Event & e){
    for(S: States){
        if(S->GetName()==CurrentState){
            S->Update<T>(e);
            //std::cout<<"Found: "<<CurrentState<<"/n";
        }
        else{
            std::cout<<"State not found \n";
        }
    }
}
template <class T>
void StateManager<T>::Render(sf::RenderWindow &w){
    for(S: States){
        if(S->GetName()==CurrentState){
            S->Render<T>(w);
            //std::cout<<"Rendering: "<<S.GetName()<<" graphics \n";
        }
    }
}