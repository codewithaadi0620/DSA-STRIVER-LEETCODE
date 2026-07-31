SELECT euni.unique_id , e.name
FROM employees e left join EmployeeUNI euni 
on
e.id=euni.id; 