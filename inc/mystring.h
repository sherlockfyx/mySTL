//
// Created by Fangyx on 2021/12/4.
//

#ifndef HELLOWORLD_MYSTRING_H
#define HELLOWORLD_MYSTRING_H
#include <cstring>

class mystring {
public:
    mystring(const char* str = nullptr){
        if(str== nullptr){
            len = 0;
            m_data = new char[1];
            *m_data = '\0';
        }else{
            len = strlen(str);
            m_data = new char[len+1];
            strcpy(m_data,str);
        }
    }
    mystring(const mystring& other){
        len = other.size();
        m_data = new char[len+1];
        strcpy(m_data,other.c_str());
    }

    mystring& operator=(const mystring& other){
        if(this == &other) return *this;
        delete [] m_data;
        len = other.size();
        m_data = new char[len+1];
        strcpy(m_data,other.c_str());
        return *this;
    }

    const char* c_str() const{
        return m_data;
    }

    int size() const{
        return len;
    }

    ~mystring(){
        delete [] m_data;
        len = 0;
    }

private:
    char* m_data;
    int len;

};


#endif //HELLOWORLD_MYSTRING_H
