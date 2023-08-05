echo "Menu"
echo "1. create employee record"
echo "2. delete employee record"
echo "3. search employee record"
echo "4. display employee details"
echo "5. sort details"
echo "6. list all records"
echo "7. Exit"

read -p "Enter yout choice (1-7):" choiceNumber

case $choiceNumber in
	1)
		read -p "Enter the name of empployee" emplName
		read -p "Enter the empoyee Id" eid
		cat $emplName $eid > emp.txt
	;;
esac
	
