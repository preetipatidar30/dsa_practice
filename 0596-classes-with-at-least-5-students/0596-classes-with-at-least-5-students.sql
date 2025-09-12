# Write your MySQL query statement below
with temp as(
select class,count(student) as cnt
    from courses
    group by class
)
    
select class
from temp 
where cnt>4

