# Write your MySQL query statement below
with temp as(
    select customer_id,count(distinct product_key) as pm
    from customer
    group by customer_id
), prod as(
    select count(product_key) as pd
    from product
)
select t.customer_id
from temp t
inner join prod p
on t.pm=p.pd
