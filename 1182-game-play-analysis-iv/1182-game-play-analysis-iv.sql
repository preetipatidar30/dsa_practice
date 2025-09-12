# Write your MySQL query statement bel
with temp as(
    select player_id,min(event_date) as first_d
    from activity
    group by player_id
)
select round(
   ( count(distinct case when datediff(a.event_date,t.first_d)=1  then t.player_id end)/count(distinct t.player_id))

,2)
as fraction
from temp t
left join activity a
on t.player_id=a.player_id
