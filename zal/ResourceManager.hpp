#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    private:
    Resource* resource;

    public:
    ResourceManager(){
    this->resource=new Resource{};
    }
    ~ResourceManager(){
    delete resource;
    }
    double get(){
    return resource->get();
    }
};
