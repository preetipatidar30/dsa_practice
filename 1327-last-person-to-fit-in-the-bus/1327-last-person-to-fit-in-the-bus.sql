# Write your MySQL query statemenwith a
with temp as(
     select person_name, sum(weight) over(order by turn) as bus_weight from Queue
)
select person_name from temp
where bus_weight<=1000 
order by bus_weight desc
limit 1
