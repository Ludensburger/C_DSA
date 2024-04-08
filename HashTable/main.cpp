#include <iostream>
#include "LinearProbing.h"
using namespace std;

int main()
{
    LinearProbing *lp = new LinearProbing();

    lp->insert(1, 10);
    lp->insert(1, 20);
    lp->insert(2, 20);
    lp->insert(3, 30);
    lp->insert(4, 40);

    // putang ina theres a bug, dapat sa sentinel 7 ning boang
    lp->insert(1567, 79);

    lp->hash(1567);
    lp->print();
    return 0;
}
