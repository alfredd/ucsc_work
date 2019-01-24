# Usage:
```bash
deadline_cloner.sh cruzid_list.txt DEADLINE_DateString DEST_BRANCH_NAME
```
* `cruzid_list.txt`: File containing CruzIDs of enrolled students (one per line). 
* `DEADLINE_DateString`: Date and time of checkout. Should be an acceptable date time: "YYYY-MM-DD HH:MM:SS"
* `DEST_BRANCH_NAME`: Name of the destination branch where the checked out files will be available.

Example:
```bash
sh deadline_cloner.sh CruzID_EnrolledStudents.txt "2019-23-01 23:59:59" pa1
```
