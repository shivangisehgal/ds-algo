class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(target - nums[i])){ //if (map.find(target - nums[i]) != map.end())
                return new int[]{i, map.get(target - nums[i])}; //{i, map[k - nums[i]]}
            }

            map.put(nums[i], i); //map[nums[i]] = i;
        }

        return new int[]{-1, -1}; //{-1, -1};
    }
}