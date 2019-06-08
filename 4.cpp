#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        while (i+1 != vec[i] && vec[i] > 0 && vec[i] <= vec.size()) {
            swap(vec[i], vec[vec[i] - 1]);

            if (vec[i] == vec[vec[i] = 1])
                break;
        }
    }

    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] != i + 1)
            return i + 1;

    return vec.size() + 1;
}

int main() {
    vector<int> vec = {3,-1,1,4};
    vector<int> vec2 = {1,2,0};
    cout << missing(vec) << endl;
    cout << missing(vec2) << endl;
}

/*
 * Given an array, find the first missing positive integer in the sequence.
 * 
 * Recognize that the missing integer must be in bounds (1, len(arr) + 1)
 * Knowing this, we rearrange the array such that arr[i] is equal to i + 1.
 * That is, 1 is in index 1, 3 is in index 3, and so on.
 * We can ignore numbers out of the bounds (numbers less than 0 or greater than the length of the array)
 * Iterate over the processed array and end when we found a spot that does not have the right number in place.
 * If we do not find any number out of place, return the len(arr) + 1
 *
 * Base case: empty array -> return 1
 *
 * Runtime is linear because we will swap an element at most once.
 *
 * Source: daily coding problem #4
 */
