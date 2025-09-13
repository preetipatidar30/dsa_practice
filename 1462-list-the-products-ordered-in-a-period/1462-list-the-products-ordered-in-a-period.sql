# Write your MySQL query statement below
with temp as(select product_id,sum(unit) as unit
from orders

where (order_date between "2020-02-01" and "2020-02-29") 
group by product_id)

select p.product_name ,t.unit
from temp t
left join products p
on p.product_id = t.product_id
where t.unit>99