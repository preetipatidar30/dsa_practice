# Write your MySQL query statement below
with temp as(
    select movie_id,round(avg(rating),2) as rating
    from movierating
   
    where created_at>"2020-01-31" and created_at <"2020-03-01"
     group by movie_id
)
, temp2 as(
    select m.movie_id, mm.title,m.rating
    from temp m
    inner join movies mm
    on m.movie_id=mm.movie_id
)
,temp3 as(
    select user_id,count(user_id) as cnt  from movierating group by user_id
)

(select u.name as results 
from temp3 t3
left join users u
on t3.user_id=u.user_id
order by t3.cnt desc ,u.name asc
limit 1)
union all
(select title as results from temp2
order by rating desc, title asc
limit 1)

