# Write your MySQL query statement below
Select e.name as Employee,d.name as Department , e.salary  as Salary 
from Employee as e LEFT JOIN Department as d ON e.departmentId=d.id 
Where 3 > (
    Select Count(Distinct e2.salary)
    from Employee e2 
    Where e2.salary >e.salary
    AND e2.departmentID=e.departmentId
)