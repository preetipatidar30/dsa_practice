# Write your MySQL q

with temp as (select  customer_id,min(order_date) as first_order,min(customer_pref_delivery_date)as pd
from delivery
group by customer_id
)
select round((sum(if(first_order=pd,1,0)))*100/count(first_order),2)as immediate_percentage
from temp


