package main

import "fmt"

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, num := range nums {
		complement := target - num
		if j, exists := m[complement]; exists {
			return []int{j, i}
		}
		m[num] = i
	}
	return nil
}

func main() {
	nums := []int{2, 7, 11, 15} // I put a demo for now.
	target := 9
	result := twoSum(nums, target)
	fmt.Println(result)
}

// End of Go Solution for TwoSum(), LeetCode #1, Easy
// https://leetcode.com/problems/two-sum/
