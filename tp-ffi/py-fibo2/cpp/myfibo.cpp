#include <cassert>

int fiboNaive(int n) {
    assert(n => 0);
    return n < 2 ? n : fiboNaive(n-1) + fiboNaive(n-2);
}

// TODO implement fiboIterative
int fiboIteratif(int n){
    if (n<=0) return 0;
    int i=1,k=0,l=1;
    while(i<n){
        int temp=l;
        l=l+k;
        k=temp;
        i++;
    }
    return l;
}


#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m) {

    m.def("fibo_naive",&fiboNaive,"Fibo Naive");
    m.def("fibo_iterative",&fiboIteratif,"Fibo Iteratif");

    // TODO export fiboNaive (as fibo_naive)

    // TODO export fiboIterative (as fibo_iterative)

}

