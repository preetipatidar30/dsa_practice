# Write your MySQL query statement below
with temp as (
    select num, count(num) as cnt
    from mynumbers
    group by num
)
select max(num) as num
from temp
where cnt=1