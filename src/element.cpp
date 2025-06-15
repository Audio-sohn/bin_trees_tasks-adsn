#include "element.h"
#include <algorithm>

bool Element::empty()
{
    return left == nullptr || right == nullptr;
}

void Element::insert(int key_, bool value)
{
    // anchor: key in use 
    if (this->key == key_)
    {
        this->value = value;
        return;
    }

    // anchor: key not in use
    if (this->empty())
    {
        this->key = key_;
        this->value = value;
        this->left = new Element;
        this->right = new Element;
        updateNodeMetrics(); 
        return;
    }

    // steer right
    if (key_ > this->key)
    {
        right->insert(key_, value);
        updateNodeMetrics(); 
        return;
    }

    // steer left
    if (key_ < this->key)
    {
        left->insert(key_, value);
        updateNodeMetrics(); 
        return;
    }

    return;
}

void Element::add(int key, bool value)
{
    insert(key, value);
    return;
}

bool Element::get(int key_)
{
    
    // anchor: found
    if (this->key == key_)
    {
        this->updateNodeMetrics();
        return this->value;
    }

    // anchor: not found
    if (this->empty())
    {
        this->updateNodeMetrics();
        return false;
    }
    
    //steer left
    if (key_ < this->key)
    {
        auto result_left = left->get(key_);
        this->updateNodeMetrics();
        return result_left;
    }

    if (key_ > this->key)
    {
        auto result_right = right->get(key_);
        this->updateNodeMetrics();
        return result_right;
    }

    
    return false;
}

void Element::updateHeight()
{
    if (this->empty())
    {
        return;
    }
    this->height_value = 1 + (left->height_value > right->height_value ? left->height_value : right->height_value); 
        
    
}

int Element::height()
{

    return this->height_value;
}


void Element::updateBalance()
{
    if (this->empty())
    {
        return;
    }
    this->balance_value = right->height_value - left->height_value;

}

int Element::balance()
{
    return this->balance_value;
}

void Element::updateNodeMetrics()
{
    this->updateHeight();
    this->updateBalance();

}

Element* Element::rotationLogic()
{
    // check for left heavyness
    if(this->balance_value <= -2)
    {
        return this->rotateRight();
    }

    return this;

}


Element* Element::rotateRight()
{
    // current root
    Element* W = this;

    // current left child
    Element* K = this->left;

    // right child of left child
    Element* ER = this->left->right;


    K->right = W;
    W->left = ER;

    W->updateNodeMetrics();
    K->updateNodeMetrics();

    return K;

} 