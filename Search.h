#ifndef __SEARCH_H__
#define __SEARCH_H__

#include <math.h>

namespace Search 
{
    //Linear Sarch ----------------------------------------------------------
    //   Search for value in a linear maner, one element at a time, usualy from left to right
    template<typename T>
    static int Linear(const T* const arr, int size, const T& value)
    {
        for (int i=0; i<size; i++)
            if (arr[i] == value)
                return i;
        return -1;
    }

    //   Search for value in a linear maner, by looking for it at beginning and end, and
    //   iteratively reducing the search length
    template<typename T>
    static int ImprovedLinear(const T* const arr, int size, const T& value)
    {
        int l = 0;
        int r = size-1;

        while(l<=r)
        {
            if(arr[l] == value) return l;
            
            if(arr[r] == value) return r;
            
            l++; r--;
        }
        return -1;
    }
    //-----------------------------------------------------------------------
    //Binary Search ---------------------------------------------------------
    //   Search for value in a SORTED array by choosing the middle given a left and right element,
    //   if the search value is above or bellow our middle element search in higher or lower half of 
    //   array. 
    template<typename T>
    static int RecursiveBinary(const T* const arr, int l , int r, const T& value)
    {
        if(r >= l)
        {
            int mid = l + (r - 1) / 2;

            if(arr[mid] == value) return mid;

            if(arr[mid] > value) 
                return RecursiveBinary<T>(arr, l, mid-1, value);

            return RecursiveBinary<T>(arr, mid+1, r, value);
        }

        return -1;
    }

    template<typename T>
    static int IterativeBinary(const T* const arr, int l , int r, const T& value)
    {
        while(l <= r)
        {
            int mid = l + (r - 1) / 2;

            if(arr[mid] == value) 
                return mid;

            if(arr[mid] > value) 
                r = mid + 1;
            else
                l = mid - 1;
        }
        return -1;
    }
    //-----------------------------------------------------------------------
    //Jump Search -----------------------------------------------------------
    //   Search for value in a SORTED array by jumping a set number of elements forward, and
    //   when an element bigger than search value is found, jump back to previous step and search linearly
    //   between this step and latest found element.
    template<typename T>
    static int Jump(const T* const arr, int size, const T& value)
    {
        int step = sqrt(size);

        int prev = 0;
        while (arr[std::min(step, size)-1] < value)
        {
            prev = step;
            step += sqrt(size);
            if(prev >= size)
                return -1;
        }

        while (arr[prev] < value)
        {
            prev++;
            if(prev == std::min(step, size))
                return -1;
        }

        if(arr[prev] == value)
            return prev;
        
        return -1;
    }

    //-----------------------------------------------------------------------
    //TODO: Interpolation Search --------------------------------------------
    //   Improvement on binary search. Where binary search goes to the middle element, 
    //   this algorithm may go to different values depending on search value, by interpolating for value
    //   between higher position and lower position
    template<typename T>
    static int Interpolation(const T* const arr, int l , int r, const T& value)
    {
        while(l <= r && value >= arr[l] && value <= arr[r])
        {
            if( l == r)
            {
                if(arr[l] == value) 
                    return l;
                return -1;
            }

            int pos = l + (((double)(r-l) / (arr[r] - arr[l])) * (value - arr[l]));

            if(arr[pos] == value) 
                return pos;

            if(arr[pos] < value)
                l = pos + 1;
            else
                r = pos -1;
        }
        return -1;
    }

    //-----------------------------------------------------------------------
    //TODO: Exponential Search ----------------------------------------------

    //-----------------------------------------------------------------------
    //TODO: Sublist Search --------------------------------------------------

    //-----------------------------------------------------------------------
    //TODO: Fibonacci Search ------------------------------------------------

    //-----------------------------------------------------------------------
    //TODO: Ubiquous Binary Search --------------------------------------------
}

#endif