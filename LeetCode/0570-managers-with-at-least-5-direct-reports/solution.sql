# Write your MySQL query statement below
Select name from Employee
Where id IN (
    Select managerId from employee group by managerId
    having Count(*) >=5
)
