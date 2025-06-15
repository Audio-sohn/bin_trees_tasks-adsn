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
        this->height_value = 1 + (left->height_value > right->height_value ? left->height_value : right->height_value); 
        return;
    }

    // steer right
    if (key_ > this->key)
    {
        right->insert(key_, value);
        this->height_value = 1 + (left->height_value > right->height_value ? left->height_value : right->height_value); 
        return;
    }

    // steer left
    if (key_ < this->key)
    {
        left->insert(key_, value);
        this->height_value = 1 + (left->height_value > right->height_value ? left->height_value : right->height_value); 
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
        return this->value;
    }

    // anchor: not found
    if (this->empty())
    {
        return false;
    }
    
    //steer left
    if (key_ < this->key)
    {
        return left->get(key_);
    }

    if (key_ > this->key)
    {
        return right->get(key_);
    }

    
    return false;
}

int Element::height()
{

    return this->height_value;
}
