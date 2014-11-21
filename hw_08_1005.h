/*************************************************************************
	> File Name: hw_08_1005.h
	> Author: zhushh
	> Mail: 
	> Created Time: Fri 21 Nov 2014 08:04:43 PM CST
*************************************************************************/

#ifndef _HW_08_1005_H
#define _HW_08_1005_H

template <typename Record>
void quick_sort(Record* startPointer, Record *endPointer) {
    if (startPointer != endPointer) {
        Record * low = startPointer, *high = endPointer, temp = *startPointer;
        high--;
        while (low != high) {
            while (low < high && *high > temp) high--;
            if (low != high) *low++ = *high;
            while (low < high && *low < temp) low++;
            if (low != high) *high-- = *low;
        }
        *low = temp;
        quick_sort(startPointer, low--);
        low++;
        quick_sort(++low, endPointer);
    }
}

#endif

