# Write your MySQL query statement below
Select S.score,COUNT(S2.Score) as 'rank' from Scores S,
(Select Distinct Score from Scores) S2
Where S.Score<=S2.Score
Group BY S.id
Order By S.Score DESC;