#ifndef CAT_H_
#define CAT_H_

class Cat 
{
private:
    bool happy;
public:
    Cat();
    ~Cat();
    void speak();
    void jump();
    bool isHappy();
    void setHappy(bool happy);
};

#endif