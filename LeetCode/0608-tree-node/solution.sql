# Write your MySQL query statement below
select id,
Case 
when p_id is NULL then 'Root'
When id in (Select p_id from tree) Then 'Inner'
Else 'Leaf'
End as type
from tree
