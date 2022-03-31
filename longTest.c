#include <stdio.h>
#include <string.h>

typedef long T;
#include "OrderedSet.h"

OrderedSet* construire_multime(long a, long b, long x) // [a,b] - interval , x - nr din interval
{
    OrderedSet *multime = createOrderedSet(100);
    long i = a ;
    for(i=a ; i<=b ; i++)
    {
        if(i % x == 0)
        {
            add(multime,i);
        }
    }
    return multime;

}

void afisare_multime(OrderedSet *set)
{
long i;
for(i=0 ; i<(set->size) ; i++)
{
    printf("%ld ",set->elements[i]);
    
}
printf("\n");
}

int main()
{
    OrderedSet *multime1 = construire_multime(4,25,3);
    afisare_multime(multime1);
    OrderedSet *multime2 = construire_multime(5,30,4);
    afisare_multime(multime2);

    OrderedSet *reuniune , *intersectie;
    reuniune = unionOrderedSets(multime1,multime2);
    intersectie = intersectOrderedSets(multime1,multime2);

    afisare_multime(intersectie);
    afisare_multime(reuniune);
    
    return 0;
}