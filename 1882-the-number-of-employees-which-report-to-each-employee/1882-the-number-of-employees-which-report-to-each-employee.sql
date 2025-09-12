# Write your MySQL query statement below
with temp as(
    select employee_id,name
    from employees
),
report as(
    select reports_to ,count(reports_to) as cnt ,round(avg(age)) as average_age
    from employees
    group by reports_to
)
select t.employee_id,t.name,r.cnt as reports_count,r.average_age
from temp t
inner join report r
on t.employee_id=r.reports_to
order by t.employee_id
