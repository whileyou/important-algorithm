/*
1.对于类似问题将n个数分成m段......考虑dp，
且状态转移方程中一般含枚举k。
对枚举k一般采取记忆化的方式优化其时间复杂度。
对n*m进行空间复杂度优化采用滚动数组。
2.对于dp方程的定义方式，一般有两种：
(1)dp[i][j]:前i个数j个划分的解。
将最终问题子问题化，通过求解子问题的解得最终解，即dp[n][m]
(2)当(1)方法不可行，考虑此方法。
dp[i][j]:前i个数j个划分的解，且必须含第i个数。
通过dp解最终问题的所有情况，用ans对每个dp[i][j]的解检测，得出最终解，即ans

(两种定义方式可推广至所有dp方程的定义)

方式(1)参考：https://github.com/whileyou/important-algorithm/blob/master/dp/%E6%95%B0%E7%BB%84%E5%88%86%E5%89%B2%E6%88%90m%E6%AE%B5%E9%9D%9E%E7%A9%BA%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84%EF%BC%8C%E5%85%B6%E5%90%84%E8%87%AA%E5%92%8C%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%80%BC.cpp
方式(2)参考：https://github.com/whileyou/important-algorithm/blob/master/dp/%E6%9C%80%E5%A4%A7m%E5%AD%90%E6%AE%B5%E5%92%8C.cpp
*/
