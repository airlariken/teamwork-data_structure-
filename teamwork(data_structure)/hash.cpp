//
//  hash.h
//  teamwork_graph
//
//  Created by 陈梓玮 on 2020/12/21.
//

//#ifndef hash_cpp
//#define hash_cpp

int hash1(int n, int v)
{
//    return ((v*n)%999553+v*v+n*n)%999553;//193
    return (int)(((long int)v*n)%999553);
}

int hash2(int n, int v)
{
//    return ((v*n)%999553+v*v+n*n)%999553;//193
    return (int)(((long int)v*n)%19379);
}
//#endif

