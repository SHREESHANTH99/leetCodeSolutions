/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndex(MountainArray &mountainArr){
        int n = mountainArr.length();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) low=mid+1;
            else high=mid;
        }
        return low;
    }
    int binarySearchLeft(MountainArray &mountainArr,int low,int high,int target){
        int n = mountainArr.length();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int binarySearchRight(MountainArray &mountainArr,int low,int high,int target){
        int n = mountainArr.length();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)>target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=peakIndex(mountainArr);
        int n = mountainArr.length();
        int low=binarySearchLeft(mountainArr,0,peak,target);
        if(low!=-1){
            return low;
        }
        int high=binarySearchRight(mountainArr,peak+1,n-1,target);
        return high;
    }
};
