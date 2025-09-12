# Write your MySQL query statement belowwith7
with temp as(
    select product_id,min(year) as f_year
    from sales
    group by product_id

)
select  t.product_id,t.f_year as first_year,s.quantity,s.price
from temp t
left join sales s
on t.product_id=s.product_id
where t.f_year=s.year

