# Write your MySQL query statement below
Select d.name as Department,e.name as Employee,e.salary as Salary from Employee as e inner join Department as d on e.departmentId=d.id
where e.salary= (
    select max(salary) from employee where departmentId=e.departmentId
)