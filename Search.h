#ifndef __SEARCH_H__
#define __SEARCH_H__

namespace Search 
{
    //Linear Sarch ----------------------------------------------------------
    template<typename T>
    static int Linear(const T* const arr, int size, const T& value)
    {
        for (int i=0; i<size; i++)
            if (arr[i] == value)
                return i;
        return -1;
    }

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
    //TODO: Jump Search -----------------------------------------------------

    //-----------------------------------------------------------------------
    //TODO: Interpolation Search --------------------------------------------

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