# Write your MySQL query statement below
with temp as(
    select employee_id,department_id ,count(distinct department_id) as cnt
    from employee
    group by employee_id
)
select employee_id,department_id
from employee
where primary_flag='Y'
union
select employee_id,department_id
from temp
where cnt=1
