// 11. Container With Most Water
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize -1;
    int max = 0;

    while(left < right){
        int width = right - left;
        int current_height = (height[left] < height[right] ? height[left] : height[right]);
        int current_area = width * current_height;
        if(current_area > max){
            max = current_area;
        }

        if(height[left] < height[right]){
            left++;
        } else{
            right--;
        }
    }

    return max;
}