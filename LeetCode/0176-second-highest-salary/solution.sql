# Write your MySQL query statement below
-- select (
--     select Distinct salary   from Employee as w1
-- where 1= (
--     select COUNT(Distinct (w2.salary))
--     from Employee w2
--     where w2.salary>w1.salary
-- )
-- ) as SecondHighestSalary
Select max(salary) as SecondHighestSalary from Employee
where salary not in (select max(salary) from Employee);
