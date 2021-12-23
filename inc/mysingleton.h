//
// Created by Fangyx on 2021/12/4.
//

#ifndef HELLOWORLD_MYSINGLETON_H
#define HELLOWORLD_MYSINGLETON_H
#include <iostream>
#include <thread>
#include <mutex>
//============================设计模式实现=========================================//
//单例模式，懒汉式与饿汉式

//懒汉式
//class Singleton {
//public:
//    static Singleton* GetInstance(){
//        static Singleton instance;
//        return &instance;
//    }
//private:
//    Singleton(){}
//    Singleton(const Singleton& other){};
//    Singleton& operator=(const Singleton& other){ return *this;};
//};

//线程安全的饿汉式
//class Singleton {
//public:
//    static Singleton* GetInstance(){
//        if(instance== nullptr){
//            {
//                std::unique_lock<std::mutex> lk(mtx);
//                if(instance== nullptr){
//                    instance = new Singleton();
//                }
//            }
//        }
//        return instance;
//    }
//    static std::mutex mtx;
//private:
//    Singleton(){}
//    Singleton(const Singleton& other){};
//    Singleton& operator=(const Singleton& other){ return *this;};
//    static Singleton* instance;
//};
//
//Singleton* Singleton::instance = nullptr;
//std::mutex Singleton::mtx;



#endif //HELLOWORLD_MYSINGLETON_H
