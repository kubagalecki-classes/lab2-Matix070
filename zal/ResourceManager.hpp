#include "include/Resource.hpp"
#include <iostream>

using namespace std;

class ResourceManager
{
    // Twoja implementacja tutaj
private:
    Resource* wsk;

public:
    // konstruktor i destruktor
    ResourceManager() { wsk = new Resource; }

    ~ResourceManager() { delete wsk; }

   ResourceManager(const ResourceManager& rs) // copying constructor
    {
        cout << "copying_constr" << endl;
        wsk = new Resource{*rs.wsk};
        cout << wsk << endl;
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        if (!(wsk == nullptr)) {
            cout << "selfDeleting" << endl;
            delete wsk;
        }
        cout << "copying_operator" << endl;
        wsk = new Resource{*rs.wsk};
        cout << wsk << endl;
        return *this;
    }

    // konstrktor przesuniecia
    ResourceManager(ResourceManager&& prze)
    {
        wsk      = prze.wsk;
        prze.wsk = nullptr;
    }    

    // operator std::move
    ResourceManager& operator=(ResourceManager&& prze)
    {
        if (&prze == this) {
            return *this;
        }
        delete wsk;
        wsk      = prze.wsk;
        prze.wsk = nullptr;
        return *this;
    }

    double get()
    {
        return wsk->get();
    }
};
