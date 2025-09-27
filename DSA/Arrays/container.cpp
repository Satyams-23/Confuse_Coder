class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int maxRight =  height[rightIndex];
        int maxLeft =  height[leftIndex];
        int result = 0;
        int temp = 0;
        while(leftIndex < rightIndex){

            temp = (rightIndex - leftIndex)*min(height[leftIndex], height[rightIndex]);

            result = max(result, temp);

            if(height[leftIndex]<height[rightIndex]){
                leftIndex++;
            }else{
                rightIndex--;
            }
        }
        return result;
        
    }
};