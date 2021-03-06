/*
176. Second Highest Salary
SQL架构
Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
*/

select (select Salary from Employee group by Salary order by Salary desc limit 1,1) as SecondHighestSalary ;

select (select distinct Salary from Employee order by Salary desc limit 1,1) as SecondHighestSalary ;

select ifnull((select distinct Salary from Employee order by Salary desc limit 1,1), NULL) as SecondHighestSalary ;
