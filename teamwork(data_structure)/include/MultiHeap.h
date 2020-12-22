//
//  MultiHeap.h
//  teamwork(data_structure)
//
//  Created by 陈梓玮 on 2020/12/22.
//

#ifndef MultiHeap_h
#define MultiHeap_h
#define heap_num 5
template<class T>
class multiHeap {
private:
    T *data = nullptr;
    int num = 0;
public:
    void iniHeap(T *da, int n)//堆的初始化
    {
        data = da;
        num = n;
    }
    
};
#endif /* MultiHeap_h */
