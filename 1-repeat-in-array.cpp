int findDuplicate(int* nums, int numsSize){
    
   // for (int i = 0 ; i<numsSize ; i++ ) {
   //     nums[nums[i] % numsSize] = nums[nums[i] % numsSize]+ numsSize;
   // }
    int repeat;
    for (int i = 0 ; i<numsSize ; i++ ) {
        repeat ^= nums[i];
            
        }
    int b;
    for (int i = 0 ; i<numsSize-1 ; i++ ) {
         b ^= nums[i];
    }
    
    return repeat ^b;
}
