# Write your MySQL query statement 
select distinct  l1.num as ConsecutiveNums
from logs l1,
logs l2 ,
logs l3
where l1.id+1=l2.id
and l2.id+1=l3.id
and l2.num=l1.num
and l3.num=l1.num